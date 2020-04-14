#include "frame.h"
#include "memory.h"

DfFrameObj*
df_frame_obj_init(DfCodeObj *code)
{
    DfFrameObj *frame = DF_MEM_ALLOC(sizeof(DfFrameObj));

    frame->stack = DF_MEM_ALLOC(code->stack_size * sizeof(DfObject *));
    frame->stack_size = code->stack_size;
    /* top points to the bottom of the stack which is thus empty */
    frame->stack_top = frame->stack;

    frame->code = code;
    frame->ip = 0;

    return frame;
}
