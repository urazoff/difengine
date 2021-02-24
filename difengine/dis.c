#include <stdio.h>
#include "dis.h"
#include "intobject.h"
#include "bytesobject.h"
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
    DfObject *const_obj;
    uint8_t const_index;

    const_index = code->opcodes->items[offset + 1];
    const_obj = code->consts->items[const_index];

    /* There are no types yet. So assume that const_obj is of int type. */
    printf("%s %4d ", name, const_index);
    df_int_print_digits(const_obj);
    printf("\n");

    return offset + 2;
}

int
df_dis_code_obj_op(DfCodeObj *code, int offset)
{
    uint8_t op;

    printf("%04d    %d ", offset, df_code_obj_get_line(code, offset));

    op = code->opcodes->items[offset];
    switch (op)
    {
        case RETURN_VALUE:
            return df_dis_op("RETURN_VALUE", offset);
        case LOAD_CONST:
            return df_dis_load_const("LOAD_CONST", code, offset);
        default:
            printf("Unknown opcode: %d", op);
            return ++offset;
    }
}

void
df_dis_code_obj(DfCodeObj *code, const char *name)
{
    DfBytesObj *bytes = code->opcodes;
    int offset;

    printf("DISASSEMBLE %s \n", name);

    for (offset = 0; offset < bytes->count; )
         offset = df_dis_code_obj_op(code, offset);
}
