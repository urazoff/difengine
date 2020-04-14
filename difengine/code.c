#include "code.h"
#include "object.h"
#include "bytesobject.h"
#include "memory.h"

#define RLE_LIMIT 255

DfCodeObj*
df_code_obj_init(int stack_size)
{
    DfCodeObj *code = DF_MEM_ALLOC(sizeof(DfCodeObj));

    code->opcodes = df_bytes_obj_init();
    code->consts = df_list_obj_init();
    code->lines = df_bytes_obj_init();
    code->stack_size = stack_size;

    return code;
}

void
df_code_obj_add_op(DfCodeObj *code, uint8_t opcode, int line)
{
    int prev_line = 0;
    int run_len = 0;
    int i;
    int k;

    df_bytes_obj_extend(code->opcodes, opcode);
/* Lines routine efficiency is an open issue. */
#define NEW_LINE() \
    do {                                                    \
        /* New line. Hence, run-length is 1. */             \
        df_bytes_obj_extend(code->lines, 1);                \
        while (line > 0)                                    \
        {                                                   \
            /* Line number exceeds one byte size.           \
             * So more than one pair shall be written.      \
             */                                             \
            if (line > RLE_LIMIT)                           \
            {                                               \
                df_bytes_obj_extend(code->lines, RLE_LIMIT);\
                df_bytes_obj_extend(code->lines, 0);        \
                line -= RLE_LIMIT;                          \
            }                                               \
            else                                            \
            {                                               \
               df_bytes_obj_extend(code->lines, line);      \
               line = 0;                                    \
            }                                               \
         }                                                  \
    } while (0)

    /* RLE encoding */
    if (code->lines->count == 0)
    {
        NEW_LINE();
    }
    else
    {
        /* Here's interesting part, there is at
         * least one pair in lines array.
         */
         i = code->lines->count - 2; /* The second last element index */
         while (run_len == 0 && i >= 0)
         {
             run_len += code->lines->items[i];
             prev_line += code->lines->items[i + 1];
             i -= 2;
         }

         if (prev_line == line)
         {
             if (run_len + 1 > RLE_LIMIT)
             {
                 /* Run-length exceeds byte size.
                  * So increment it by copying line number.
                  */
                 df_bytes_obj_extend(code->lines, 1);
                 for (k = i + 1; k < code->lines->count; k++)
                     df_bytes_obj_extend(code->lines, code->lines->items[k]);
             }
         }
         else
             NEW_LINE();
    }
}

int
df_code_obj_add_const(DfCodeObj *code, DfObject *const_obj)
{
    df_list_obj_extend(code->consts, const_obj);

    return code->consts->count - 1;
}

int
df_code_obj_get_line(DfCodeObj *code, int op_index)
{
    int i;
    int k;
    int line = 0;
    int line_index = 0;
    uint8_t check_el;

    /* RLE decoding */
    for (i = 0; i < code->lines->count; i += 2)
    {
        line_index += code->lines->items[i];
        if (op_index < line_index)
        {
            for (k = i + 1; k < code->lines->count; k++)
            {
                check_el = (k + 2 < code->lines->count) ?
                           code->lines->items[k + 2] : -1;
                if (code->lines->items[k] == 0 &&
                    check_el != 0)
                {
                    line += code->lines->items[k + 1];
                    return line;
                }

                line += code->lines->items[k];

                check_el = (k + 1 < code->lines->count) ?
                           code->lines->items[k + 1] : -1;
                if (check_el != 0)
                    return line;
            }
        }
    }

    return -1;
}

void
df_code_obj_clear(DfCodeObj *code)
{
    int stack_size = code->stack_size;

    df_bytes_obj_clear(code->opcodes);
    df_list_obj_clear(code->consts);
    df_bytes_obj_clear(code->lines);
    DF_MEM_FREE(code);
    code = df_code_obj_init(stack_size);
}
