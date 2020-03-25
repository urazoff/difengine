#include "code.h"
#include "memory.h"

#define CODE_UPD_CAPACITY(_capacity) \
    ((_capacity) < 8 ? 8 : (_capacity) * 2)

DfCodeObj*
df_code_obj_init()
{
    DfCodeObj *new_code = df_realloc(NULL, 0, sizeof(DfCodeObj));

    new_code->count= 0;
    new_code->capacity = 0;
    new_code->opcodes = NULL;

    return new_code;
}

void
df_code_obj_upd(DfCodeObj *code, uint8_t opcode)
{
    if (code->capacity < code->count + 1)
    {
        int old_capacity = code->capacity;
        code->capacity = CODE_UPD_CAPACITY(old_capacity);
        code->opcodes = DF_MEM_GROW_ARRAY(uint8_t, code->opcodes,
                                          old_capacity, code->capacity);
    }

    code->opcodes[code->count] = opcode;
    code->count++;
}
