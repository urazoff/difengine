#ifndef _DF_CONTAINER_H_
#define _DF_CONTAINER_H_

#include "difengine.h"

/**
 * @file
 * Common defines for containers
 */

#ifdef __cplusplus
extern "C" {
#endif

#define CONT_UPD_CAPACITY(_capacity) \
    ((_capacity) < 8 ? 8 : (_capacity) * 2)

#ifdef __cplusplus
}
#endif

#endif /* DF_CONTAINER_H_ */
