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
    DfIntObj *const_obj = DF_MEM_ALLOC(sizeof(DfIntObj));
    int i;

    code = df_code_obj_init();
    df_code_obj_add_op(code, RETURN_VALUE);

    const_obj->val = 17;
    i =  df_code_obj_add_const(code, (DfObject *)const_obj);

    df_code_obj_add_op(code, LOAD_CONST);
    df_code_obj_add_op(code, i);

    df_dis_code_obj(code, "test_code");

    df_code_obj_clear(code);

    printf("Success");
}
