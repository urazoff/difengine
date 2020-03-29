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

#ifdef __cplusplus
}
#endif

#endif /* DF_INTOBJECT_H_ */
