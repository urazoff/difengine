#ifndef _DF_COMPLEXOBJECT_H_
#define _DF_COMPLEXOBJECT_H_

#include "object.h"
#include "difengine.h"

/**
 * @file
 * Complex numbers with double-precision floating point parts.
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    DfObject obj;
    double real;
    double im;
} DfComplexObj;

extern DfType DfComplexType;

/**
 * Create complex object from two doubles.
 *
 * @return
 *   new complex object
 */
extern DfObject* df_complex_obj_init(double real, double im);

#ifdef __cplusplus
}
#endif

#endif /* DF_COMPLEXOBJECT_H_ */
