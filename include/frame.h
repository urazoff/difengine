#ifndef _DF_FRAME_H_
#define _DF_FRAME_H_

#include "object.h"
#include "code.h"
#include "difengine.h"

/**
 * @file
 * Stack frame object
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    DfObject obj;
    DfCodeObj *code;     /* code object */
    DfObject **stack;    /* value stack */
    DfObject *stack_top; /* points to location of an element to be pushed */
    int stack_size;      /* value stack size */
    int ip;              /* instruction index about to be evaluated */
} DfFrameObj;

/**
 * Allocate new frame object and initialize it.
 *
 * @return
 *   new frame object
 */
extern DfFrameObj* df_frame_obj_init(DfCodeObj *code);

#ifdef __cplusplus
}
#endif

#endif /* DF_FRAME_H_ */
