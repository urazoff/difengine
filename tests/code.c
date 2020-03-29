#include <stdio.h>
#include "difengine.h"
#include "intobject.h"
#include "opcode.h"
#include "code.h"
#include "dis.h"
#include "memory.h"

int main(int argc, char *argv[])
{
    DfCodeObj *code;
    DfIntObj *opcode;
    DfIntObj *const_obj = DF_MEM_ALLOC(sizeof(DfIntObj));
    int i;

    code = df_code_obj_init();

    df_code_obj_add_op(code, RETURN_VALUE);
    opcode = (DfIntObj *)code->opcodes->items[code->opcodes->count - 1]; 

    printf("Code:\n---- count: %u \n"
           "---- capacity %u \n"
           "---- opcode: %d \n",
           code->opcodes->count,
           code->opcodes->capacity,
           opcode->val);

    i =  df_code_obj_add_const(code, (DfObject *)const_obj);
    printf("Consts index: ---- i = %d\n", i);

    df_dis_code_obj(code, "test_code");

    df_code_obj_clear(code);

    printf("Success");
}
