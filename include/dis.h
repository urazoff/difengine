#ifndef _DF_DIS_H_
#define _DF_DIS_H_

#include "code.h"

/**
 * @file
 * Disassembler for code object
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Disassemble single opcode.
 *
 * @return
 *   new offset 
 */
extern int df_dis_code_obj_op(DfCodeObj *code, int offset);

/**
 * Disassebmle all opcodes of the code object.
 */
extern void df_dis_code_obj(DfCodeObj *code, const char *name);

#ifdef __cplusplus
}
#endif

#endif /* DF_DIS_H_ */
