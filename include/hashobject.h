#ifndef _DF_LISTOBJECT_H_
#define _DF_LISTOBJECT_H_

#include "difengine.h"
#include "object.h"

/**
 * @file
 * Hash table
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint32_t hash;
    DfObject *key;
    DfObject *value;
} DfHashEntry;

typedef struct {
    DfObject obj;
    unsigned int size;
    int iprime;
    unsigned int count;
    unsigned int deleted;
    DfHashEntry *entries;
} DfHashObj; 

extern DfType DfHashType;

/**
 * Allocate new hash object and initialize it.
 *
 * @return
 *   new & empty hash object
 */
extern DfObject *df_hash_obj_init();

/**
 * Find value by key.
 *
 * @return
 *   found value by key or NULL
 */
extern DfObject *df_hash_obj_get(DfObject *ht, DfObject *key);

/**
 * Insert new key-value pair.
 *
 * @return
 *   inserted value or NULL
 */
extern DfObject *df_hash_obj_insert(DfObject *ht, DfObject *key,
                                    DfObject *value);

/**
 * Delete entry by key.
 *
 * @return
 *   0 on successful search and deletion, -1 otherwise 
 */
extern int df_hash_obj_delete(DfObject *ht, DfObject *key);

#ifdef __cplusplus
}
#endif

#endif /* DF_LISTOBJECT_H_ */
