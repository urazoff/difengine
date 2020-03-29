#ifndef _DF_FLOATOBJECT_H_
#define _DF_FLOATOBJECT_H_

#include "object.h"
#include "difengine.h"

/**
 * @file
 * Double-precision floating point numbers
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    DfObject obj;
    double val;
} DfFloatObj;

#ifdef __cplusplus
}
#endif

#endif /* DF_FLOATOBJECT_H_ */
