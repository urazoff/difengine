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
    DfIntObj *const_obj = DF_MEM_ALLOC(sizeof(DfIntObj));
    int i;

    code = df_code_obj_init(100);

    const_obj->val = 17;
    i =  df_code_obj_add_const(code, (DfObject *)const_obj);

    df_code_obj_add_op(code, LOAD_CONST, 1);
    df_code_obj_add_op(code, i, 1);

    df_code_obj_add_op(code, LOAD_CONST, 1);
    df_code_obj_add_op(code, i, 1);

    df_code_obj_add_op(code, RETURN_VALUE, 2);

    frame = df_frame_obj_init(code);

    df_eval_frame(frame);

    df_code_obj_clear(frame->code);

    printf("RES: Success\n");

    return 0;
}
