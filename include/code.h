#ifndef _DF_CODE_H_
#define _DF_CODE_H_

#include "object.h"
#include "listobject.h"
#include "difengine.h"

/**
 * @file
 * Code object
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    DfObject obj;
    DfListObj *opcodes; /* list of DfIntObj */
    DfListObj *consts; /* list of any objects) */
} DfCodeObj;

/**
 * Allocate new code object and initialize it.
 *
 * @return
 *   new&empty code object
 */
extern DfCodeObj* df_code_obj_init();

extern void df_code_obj_add_op(DfCodeObj *code, uint8_t opcode);

extern int df_code_obj_add_const(DfCodeObj *code, DfObject *const_object);

extern void df_code_obj_clear(DfCodeObj *code);

#ifdef __cplusplus
}
#endif

#endif /* DF_CODE_H_ */
