#ifndef _DF_OBJECTOPS_H_
#define _DF_OBJECTOPS_H_

#include "object.h"
#include "difengine.h"

/**
 * @file
 * Abstract object operations interface
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Add two objects of numeric type.
 *
 * @return
 *   new numeric object containing sum
 */
extern DfObject* df_num_add(DfObject *a, DfObject *b);

#ifdef __cplusplus
}
#endif

#endif /* DF_OBJECTOPS_H_ */
