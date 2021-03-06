#include <stdio.h>
#include "difengine.h"
#include "intobject.h"
#include "opcode.h"
#include "code.h"
#include "frame.h"
#include "evaluate.h"
#include "memory.h"

int main(int argc, char *argv[])
{
    DfCodeObj *code;
    DfFrameObj *frame;
    DfIntObj *const_obj_a = (DfIntObj *)df_int_obj_init(1);
    DfIntObj *const_obj_b = (DfIntObj *)df_int_obj_init(1);
    int i;

    code = df_code_obj_init(100);

    const_obj_a->digits[0] = 17;
    i =  df_code_obj_add_const(code, (DfObject *)const_obj_a);

    df_code_obj_add_op(code, LOAD_CONST, 1);
    df_code_obj_add_op(code, i, 1);

    const_obj_b->digits[0] = 5;
    i =  df_code_obj_add_const(code, (DfObject *)const_obj_b);

    df_code_obj_add_op(code, LOAD_CONST, 1);
    df_code_obj_add_op(code, i, 1);

    df_code_obj_add_op(code, LOAD_CONST, 1);
    df_code_obj_add_op(code, i, 1);

    df_code_obj_add_op(code, BIN_ADD, 2);

    df_code_obj_add_op(code, BIN_MULTIPLY, 2);

    df_code_obj_add_op(code, UNARY_NEG, 2);

    df_code_obj_add_op(code, RETURN_VALUE, 2);

    frame = df_frame_obj_init(code);

    df_eval_frame(frame);

    df_code_obj_clear(frame->code);

    printf("RES: Success\n");

    return 0;
}
