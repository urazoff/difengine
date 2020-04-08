#include "frame.h"
#include "memory.h"

DfFrameObj*
df_frame_obj_init(DfCodeObj *code)
{
    DfFrameObj *frame = DF_MEM_ALLOC(sizeof(DfFrameObj));

    frame->code = code;
    frame->ip = 0;

    return frame;
}
