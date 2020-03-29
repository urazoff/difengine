#include "code.h"
#include "object.h"
#include "intobject.h"
#include "memory.h"

DfCodeObj*
df_code_obj_init()
{
    DfCodeObj *code = DF_MEM_ALLOC(sizeof(DfCodeObj));

    code->opcodes = df_list_obj_init();
    code->consts = df_list_obj_init();

    return code;
}

void
df_code_obj_add_op(DfCodeObj *code, uint8_t opcode)
{
    DfIntObj *opcode_obj =  DF_MEM_ALLOC(sizeof(DfIntObj));
    opcode_obj->val = opcode;

    df_list_obj_extend(code->opcodes, (DfObject *)opcode_obj);
}

int
df_code_obj_add_const(DfCodeObj *code, DfObject *const_obj)
{
    df_list_obj_extend(code->consts, const_obj);

    return code->consts->count - 1;
}

void
df_code_obj_clear(DfCodeObj *code)
{
    df_list_obj_clear(code->opcodes);
    df_list_obj_clear(code->consts);
    DF_MEM_FREE(code);
    code = df_code_obj_init();
}