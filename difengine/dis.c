#include <stdio.h>
#include "dis.h"
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
    uint8_t op;
    
    printf("%04d ", offset);

    op = code->opcodes[offset];
    switch (op)
    {
        case RETURN_VALUE:
            return df_dis_op("RETURN_VALUE", offset);
        default:
            printf("Unknown opcode: %d", op);
            return ++offset;
    }
}

void
df_dis_code_obj(DfCodeObj *code, const char *name)
{
    int offset;

    printf("DISASSEMBLE %s \n", name);

    for (offset = 0; offset < code->count; )
         offset = df_dis_code_obj_op(code, offset);
}
