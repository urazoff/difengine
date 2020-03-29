#ifndef _DF_LISTOBJECT_H_
#define _DF_LISTOBJECT_H_

#include "difengine.h"
#include "object.h"

/**
 * @file
 * List of objects
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    DfObject obj;
    DfObject **items;
    int count;
    int capacity;
} DfListObj;    

/**
 * Allocate new list object and initialize it.
 *
 * @return
 *   new&empty list object
 */
extern DfListObj *df_list_obj_init();

/**
 * Extend the list by adding new item.
 */
extern void df_list_obj_extend(DfListObj *list, DfObject *item);

/**
 * Clear out the list.
 */
extern void df_list_obj_clear(DfListObj *list);

#ifdef __cplusplus
}
#endif

#endif /* DF_LISTOBJECT_H_ */
