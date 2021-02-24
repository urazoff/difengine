#include <stdio.h>
#include "difengine.h"
#include "intobject.h"
#include "opcode.h"
#include "code.h"
#include "frame.h"
#include "dis.h"
#include "memory.h"

int main(int argc, char *argv[])
{
    DfCodeObj *code;
    DfFrameObj *frame;
    DfIntObj *const_obj = (DfIntObj *)df_int_obj_init(1);
    int i;

    code = df_code_obj_init(100);
    df_code_obj_add_op(code, RETURN_VALUE, 1);

    const_obj->digits[0] = 17;
    i =  df_code_obj_add_const(code, (DfObject *)const_obj);

    df_code_obj_add_op(code, LOAD_CONST, 2);
    df_code_obj_add_op(code, i, 2);

    frame = df_frame_obj_init(code);

    df_dis_code_obj(frame->code, "test_frame->code");

    df_code_obj_clear(frame->code);

    printf("RES: Success\n");

    return 0;
}
