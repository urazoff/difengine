#include <stdio.h>
#include "difengine.h"
#include "opcode.h"
#include "code.h"
#include "dis.h"

int main(int argc, char *argv[])
{
    DfCodeObj *code;

    code = df_code_obj_init();

    df_code_obj_upd(code, RETURN_VALUE);

    printf("Code:\n---- count: %u \n"
           "---- capacity %u \n"
           "---- opcode: %u \n",
           code->count,
           code->capacity,
           code->opcodes[code->count - 1]);

    df_dis_code_obj(code, "test_code");

    df_code_obj_free(code);

    printf("Success");
}
