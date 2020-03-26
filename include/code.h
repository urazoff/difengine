#ifndef _DF_CODE_H_
#define _DF_CODE_H_

#include "difengine.h"

/**
 * @file
 * Code object
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t      *opcodes;
    unsigned int count;
    unsigned int capacity;
} DfCodeObj;

/**
 * Allocate new code object and initialize it.
 *
 * @return
 *   new&empty code object
 */
extern DfCodeObj* df_code_obj_init();

extern void df_code_obj_upd(DfCodeObj *code, uint8_t opcode);

extern void df_code_obj_free(DfCodeObj *code);

#ifdef __cplusplus
}
#endif

#endif /* DF_CODE_H_ */
