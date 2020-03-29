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
