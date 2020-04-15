#include "evaluate.h"
#include "opcode.h"
#include "intobject.h"
#include <stdio.h>

#define PUSH(_value) \
    do {                            \
        *frame->stack_top = _value; \
        frame->stack_top++;         \
    } while (0)

#define POP() (*--frame->stack_top) \

DfObject*
df_eval_frame(DfFrameObj *frame)
{
    DfCodeObj *code = frame->code;
    DfObject *ret_value = NULL; /* return value */
    uint8_t *instruction = code->opcodes->items; /* instruction to be executed */
    uint8_t opcode; /* current operation code */
    uint8_t oparg; /* current operation argument if any */

#define NOPCODE() (*instruction++)
#define NOPARG() (*instruction++)

#define GETCONST(_oparg) (code->consts->items[_oparg])

    /* main loop */
    for (;;)
    {
#ifdef DF_DEBUG
        /* For the sake of simplicity for now while debuging
         * assume that all consts are of type int.
         * Debugging is unconditional for now.
         */
        printf("----\n");
        for (DfObject **value = frame->stack; value < frame->stack_top; value++)
            printf("[ %d ]\n", ((DfIntObj *)*value)->val);
#endif
        opcode = NOPCODE();
        if (HAS_ARG(opcode))
            oparg = NOPARG();
        switch (opcode)
        {
            case LOAD_CONST:
            {
                DfObject *constant = GETCONST(oparg);
                PUSH(constant);
                break;
            }
            case RETURN_VALUE:
            {
                ret_value = POP();
                return NULL;
            }
        }
    }
}