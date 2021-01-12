#ifndef _DF_BYTESOBJECT_H_
#define _DF_BYTESOBJECT_H_

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
    DfObject_CONT_HEAD;
    uint8_t *items;
} DfBytesObj;

extern DfType DfBytesType;

/**
 * Allocate new bytes object and initialize it.
 *
 * @return
 *   new&empty bytes object
 */
extern DfObject *df_bytes_obj_init();

/**
 * Add new byte.
 */
extern void df_bytes_obj_extend(DfObject *bytes, uint8_t byte);

/**
 * Clear out the bytes object.
 */
extern void df_bytes_obj_clear(DfBytesObj *bytes);

#ifdef __cplusplus
}
#endif

#endif /* DF_BYTESOBJECT_H_ */
