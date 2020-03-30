#include <stdio.h>
#include "dis.h"
#include "listobject.h"
#include "intobject.h"
#include "opcode.h"

static int
df_dis_op(const char *op_name, int offset)
{
    printf("%s\n", op_name);

    return ++offset;
}

static int
df_dis_load_const(const char *name, DfCodeObj *code, int offset)
{
    DfIntObj *operand;
    DfObject *const_obj;
    uint8_t const_index;

    operand = (DfIntObj *)code->opcodes->items[offset + 1];
    const_index = operand->val;
    const_obj = code->consts->items[const_index];

    /* There are no types yet. So assume that const_obj is of int type. */
    printf("%s %4d %d\n", name, const_index, ((DfIntObj *)const_obj)->val);

    return offset + 2;
}

int
df_dis_code_obj_op(DfCodeObj *code, int offset)
{
    DfIntObj *op;

    printf("%04d ", offset);

    op = (DfIntObj *)code->opcodes->items[offset];
    switch (op->val)
    {
        case RETURN_VALUE:
            return df_dis_op("RETURN_VALUE", offset);
        case LOAD_CONST:
            return df_dis_load_const("LOAD_CONST", code, offset);
        default:
            printf("Unknown opcode: %d", op->val);
            return ++offset;
    }
}

void
df_dis_code_obj(DfCodeObj *code, const char *name)
{
    DfListObj *list = code->opcodes;
    int offset;

    printf("DISASSEMBLE %s \n", name);

    for (offset = 0; offset < list->count; )
         offset = df_dis_code_obj_op(code, offset);
}
