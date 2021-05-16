#include "stringobject.h"
#include "memory.h"
#include "defines.h"

/* FNV-1 hash function. Cache hash after computing.
 * TODO: make sure that 0 value is reserved for special use.
 * */
static uint32_t
str_hash(DfStrObj *str)
{
    uint32_t hash = 2166136261ul;
    const char *bytes = str->chars;

    if (str->hash != 0)
        return str->hash;

    while (*bytes != 0)
    {
        hash ^= *bytes;
        hash *= 0x01000193;
        bytes++;
    }

    str->hash = hash;

    return hash;
}

DfObject*
df_str_obj_from_str(char *chars)
{
    int ret_val;
    int size = strlen(chars);
    DfStrObj *str = (DfStrObj *)df_obj_new(&DfStrType);

    if (str == NULL)
        return NULL;

    str->size = size;
    str->chars = DF_MEM_ALLOC(size + 1);
    if (str->chars == NULL)
        return NULL;

    memcpy(str->chars, chars, size);
    str->chars[size] = '\0';

    ret_val = str_hash(str);
    UNUSED(ret_val);

    return (DfObject *)str;
}

/* Let's keep it simple for now */
static int
str_print(DfStrObj *str)
{
    printf("'%s'", str->chars);
    return 0;
}

static int
str_length(DfStrObj *str)
{
    return str->size;
}

static int
str_compare(DfStrObj *a, DfStrObj *b)
{
    int ret_val;

    /* At least one of strings is empty */
    if (a->size + b->size == 0)
        return 0;

    if (a->size == 0 && b->size > 0)
        return -1;

    if (b->size == 0 && a->size > 0)
        return 1;

    /* Both string are filled */
    ret_val = strcmp(a->chars, b->chars);

    return ret_val > 0 ? 1 : ret_val < 0 ? -1 : 0;
}

static DfObject*
str_concat(DfObject *a, DfObject *b)
{
    DfStrObj *res;
    int size;

    if (a->type != &DfStrType)
        return NULL;

    if (b->type != &DfStrType)
        return NULL;

    if (((DfStrObj *)a)->size == 0)
    {
        DF_INC_RF(a);
        return a;
    }

    if (((DfStrObj *)b)->size == 0)
    {
        DF_INC_RF(b);
        return b;
    }

    size = ((DfStrObj *)a)->size + ((DfStrObj *)b)->size;
    res = (DfStrObj *)df_obj_new(&DfStrType);
    res->size = size;
    res->chars = DF_MEM_ALLOC(size + 1);

    if (res == NULL)
       return NULL;

    memcpy(res->chars, ((DfStrObj *)a)->chars, ((DfStrObj *)a)->size);
    memcpy(res->chars + ((DfStrObj *)a)->size, ((DfStrObj *)b)->chars,
           ((DfStrObj *)b)->size);
    res->chars[size] = '\0';

    return (DfObject *)res;
}

void
str_destroy(DfObject *s)
{
    DF_DEC_RF(s);
    DF_MEM_FREE(((DfStrObj *)s)->chars);
    DF_MEM_FREE((DfStrObj *)s);
}

static DfContOps as_container = {
    (intunaryop)str_length,
    (binaryop)str_concat
};

DfType DfStrType = {
    "string",
    sizeof(DfStrObj),
    0,
    (voidunaryop)str_destroy,
    (hashop)str_hash,
    (intunaryop)str_print,
    (intbinaryop)str_compare,
    NULL, /* TODO: (getter)str_get */
    NULL,
    NULL,
    &as_container,
    NULL
};
