#ifndef _DF_CODE_H_
#define _DF_CODE_H_

#include "object.h"
#include "listobject.h"
#include "bytesobject.h"
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
    DfBytesObj *opcodes; /* list of opcode bytes */
    DfListObj *consts;   /* list of any objects */
    DfBytesObj *lines;   /* list of opcodes lines */
} DfCodeObj;

/**
 * Allocate new code object and initialize it.
 *
 * @return
 *   new&empty code object
 */
extern DfCodeObj* df_code_obj_init();

/**
 * Add opcode to the code's opcodes list.
 */
extern void df_code_obj_add_op(DfCodeObj *code, uint8_t opcode, int line);

/**
 * Add constant to the code's consts list.
 *
 * @return
 *   new const index
 */
extern int df_code_obj_add_const(DfCodeObj *code, DfObject *const_object);

/**
 * Get line number of an opcode by its index in code->opcodes.
 *
 * @return
 *   opcodes's line number
 */
extern int df_code_obj_get_line(DfCodeObj *code, int op_index);

/**
 * Clear out the code object.
 */
extern void df_code_obj_clear(DfCodeObj *code);

#ifdef __cplusplus
}
#endif

#endif /* DF_CODE_H_ */
