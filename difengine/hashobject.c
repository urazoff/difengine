#include "hashobject.h"
#include "object.h"
#include "memory.h"
#include "stringobject.h"

static const struct {
    unsigned int maxload;
    unsigned int size;
} hash_primes[]= {
        { 2,            5},
        { 4,            7},
        { 8,            13},
        { 16,           19},
        { 32,           43},
        { 64,           73},
        { 128,          151},
        { 256,          283},
        { 512,          571},
        { 1024,         1153},
        { 2048,         2269},
        { 4096,         4519},
        { 8192,         9013},
        { 16384,        18043},
        { 32768,        36109},
        { 65536,        72091},
        { 131072,       144409},
        { 262144,       288361},
        { 524288,       576883},
        { 1048576,      1153459},
        { 2097152,      2307163},
        { 4194304,      4613893},
        { 8388608,      9227641},
        { 16777216,     18455029},
        { 33554432,     36911011},
        { 67108864,     73819861},
        { 134217728,    147639589},
        { 268435456,    295279081},
        { 536870912,    590559793},
        { 1073741824,   1181116273},
};

static const unsigned int prime_length = sizeof(hash_primes)/sizeof(hash_primes[0]);

/* An object to mark entry as deleted */
static DfObject *bogus;

static int
is_free(DfHashEntry *e)
{
    return e->key == NULL;
}

static int
is_deleted(DfHashEntry *e)
{
    return e->key == bogus;
}

static int
is_present(DfHashEntry *e)
{
    return e->key != NULL && e->key != bogus;
}

DfObject*
df_hash_obj_init()
{
    DfHashObj *ht = (DfHashObj *)df_obj_new(&DfHashType);

    /* Initialize bogus key */
    if (bogus == NULL)
    {
        bogus = df_str_obj_from_str("bogus");
        if (bogus == NULL)
            return NULL;
    }

    if (ht == NULL)
        return NULL;

    ht->iprime = 0;
    ht->size = hash_primes[ht->iprime].size;
    ht->count = 0;
    ht->deleted = 0;
    ht->entries = (DfHashEntry *)DF_MEM_ALLOC(ht->size * sizeof(DfHashEntry));

    return (DfObject *)ht;
}

/* One search routine to rule them all */
static DfHashEntry*
hash_search(DfHashObj *ht, DfObject *key, uint32_t hash)
{
    DfHashEntry *e;
    DfHashEntry *available = NULL;
    uint32_t i;
    uint32_t start;

    start = hash % ht->size;
    i = start;

    do {
        e = ht->entries + i;

        if (is_present(e) == 0)
        {
             if (available == NULL)
                 available = e;
             if (is_free(e))
                 break;
        }

        if (is_deleted(e) == 0 && e->hash == hash &&
            df_obj_compare(e->key, key) == 0)
            return e;

        i = (i + hash % (ht->size - 2) + 1) % ht->size;
    } while(i != start);

    if (available != NULL)
        return available;

    return NULL;
}

static DfHashEntry*
hash_insert(DfHashObj *ht, DfObject *key, DfObject *value, uint32_t hash);

/** Expand hash table.
 *  NB: this function rearranges entries.
 */
static DfHashObj*
hash_rehash(DfHashObj *ht, int newiprime)
{
    DfHashEntry *table;
    DfHashEntry *e;
    DfHashEntry *oldtable = ht->entries;
    unsigned int newsize;
    unsigned int oldsize;
    int i;

    if (newiprime >= prime_length)
        return NULL;

    oldsize = ht->size;
    newsize = hash_primes[newiprime].size;
    table = (DfHashEntry *)DF_MEM_ALLOC(newsize * sizeof(DfHashEntry));
    if (table == NULL)
        return NULL;

    memset(table, 0, newsize * sizeof(DfHashEntry));
    ht->entries = table;
    ht->size = newsize;
    ht->iprime = newiprime;
    ht->count = 0;

    for (i = 0, e = oldtable; i < oldsize; i++, e++)
    {
        if (is_present(e))
            hash_insert(ht, e->key, e->value, e->hash);
    }

    return ht;
}

static DfHashEntry*
hash_insert(DfHashObj *ht, DfObject *key, DfObject *value, uint32_t hash)
{
    DfHashEntry *e;

    if (ht->count >= hash_primes[ht->iprime].maxload)
        hash_rehash(ht, ht->iprime + 1);

    e = hash_search(ht, key, hash);

    if (is_present(e))
    {
        DF_DEC_RF(e->key);
        DF_DEC_RF(e->value);
        e->value = value;
        e->key = key;
    }
    else
    {
        if (is_free(e) == 0)
             DF_DEC_RF(e->key);
        e->hash = hash;
        e->key = key;
        e->value = value;
        ht->count++;
    }

    return e;
}

/* Delete found entry */
static void
hash_delete_entry(DfHashObj *ht, DfHashEntry *e)
{
    /* check if entry either free or deleted*/
    if (e->key == NULL || e->key == bogus)
        return;

    e->key = bogus;
    ht->count--;
    ht->deleted--;

    DF_INC_RF(bogus);
    DF_DEC_RF(e->key);
    DF_DEC_RF(e->value);

    e->value = NULL;
}

DfObject*
df_hash_obj_get(DfObject *ht, DfObject *key)
{
    uint32_t hash;

    if (ht->type != &DfHashType)
        return NULL;

    if (((DfHashObj *)ht)->entries == NULL)
        return NULL;

    hash = df_obj_hash(key);
    /* Not hashable key */
    if (hash == 0)
       return NULL;

    return hash_search((DfHashObj *)ht, key, hash)->value;
}

DfObject*
df_hash_obj_insert(DfObject *ht, DfObject *key, DfObject *value)
{
    uint32_t hash;

    if (((DfObject *)ht)->type != &DfHashType)
        return NULL;

    hash = df_obj_hash(key);
    if (hash == 0)
       return NULL;

    DF_INC_RF(key);
    DF_INC_RF(value);
    return hash_insert((DfHashObj *)ht, key, value, hash)->value;
}

int
df_hash_obj_delete(DfObject *ht, DfObject *key)
{
    DfHashEntry *e;
    uint32_t hash;

    if (ht->type != &DfHashType)
        return -1;

    if (((DfHashObj *)ht)->entries == NULL)
        return -1;

    hash = df_obj_hash(key);
    if (hash == 0)
        return -1;

    e = hash_search((DfHashObj *)ht, key, hash);
    if (e == NULL)
        return -1;

    hash_delete_entry((DfHashObj *)ht, e);

    return 0;
}

static int
hash_print(DfHashObj *ht)
{
    int comma = 0;
    int i;
    DfHashEntry *e;

    printf("{");
    for (i = 0, e = ht->entries; i < ht->size; i++, e++)
    {
        if (is_present(e))
        {
            if (comma > 0)
                printf(", ");

            if (df_obj_print(e->key, 0) != 0)
                return -1;

            printf(" : ");

            if (df_obj_print(e->value, 0) != 0)
                return -1;

            comma++;
        }
    }
    printf("}");
    return 0;
}

/* How many entries with no bogus neither NULL keys? */
static int
hash_length(DfHashObj *ht)
{
    return ht->count;
}

static void
hash_destroy(DfObject *ht)
{
    int i;
    DfHashEntry *e;
    DfHashObj *htp = (DfHashObj *)ht;

    for (i = 0, e = htp->entries; i < htp->size; i++, e++)
    {
        if (is_present(e))
        {
            DF_DEC_RF(e->key);
            DF_DEC_RF(e->value);
        }
    }

    DF_MEM_FREE(htp->entries);
    DF_MEM_FREE(htp);
}

static DfContOps as_container = {
    (intunaryop)hash_length,
    NULL
};

static DfAssContOps as_associative = {
    (binaryop)df_hash_obj_get,
    (intbinaryop)df_hash_obj_delete,
    (ternaryop)df_hash_obj_insert
};

DfType DfHashType = {
    "hash table",
    sizeof(DfHashObj),
    0,
    (voidunaryop)hash_destroy,
    NULL,
    (intunaryop)hash_print,
    NULL, /* TODO: (intbinaryop)hash_compare */
    NULL, /* TODO: (getter)hash_get */
    NULL,
    NULL,
    &as_container,
    &as_associative
};
