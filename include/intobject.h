#ifndef _DF_INTOBJECT_H_
#define _DF_INTOBJECT_H_

#include "object.h"
#include "difengine.h"

/**
 * @file
 * Integer numbers
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    DfObject obj;
    int val;
} DfIntObj;

/**
 * Create new integer object.
 *
 * @return
 *   new integer object
 */
extern DfIntObj* df_int_obj_new(int val);

#ifdef __cplusplus
}
#endif

#endif /* DF_INTOBJECT_H_ */
