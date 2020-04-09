#include "evaluate.h"
#include "opcode.h"

DfObject*
df_eval_frame(DfFrameObj *frame)
{
    DfCodeObj *code = frame->code;
    uint8_t *instruction = code->opcodes->items; /* instruction to be executed */
    uint8_t opcode; /* current operation code */
    uint8_t oparg; /* current operation argument if any*/

#define NOPCODE() (*instruction++)
#define NOPARG() (*instruction++)

#define GETCONST(_oparg) (code->consts->items[_oparg])

    /* main loop */
    for (;;)
    {
        opcode = NOPCODE();
        if (HAS_ARG(opcode))
            oparg = NOPARG();
        switch (opcode)
        {
            case LOAD_CONST:
            {
                DfObject *constant = GETCONST(oparg);
                break;
            }
            case RETURN_VALUE:
            {
               return NULL;
            }
        }
    }
}
