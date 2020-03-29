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

extern DfListObj *df_list_obj_init();

extern void df_list_obj_extend(DfListObj *list, DfObject *item);

extern void df_list_obj_clear(DfListObj *list);

#ifdef __cplusplus
}
#endif

#endif /* DF_LISTOBJECT_H_ */
