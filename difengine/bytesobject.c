#include "internal/container.h"
#include "bytesobject.h"
#include "memory.h"

/* Definition and implementation for now
 * are the same as DfListObj.
 * May be needs some generalization.
*/

DfObject*
df_bytes_obj_init()
{
    DfBytesObj *bytes = (DfBytesObj *)df_obj_new(&DfBytesType);

    bytes->items = NULL;
    bytes->count= 0;
    bytes->capacity = 0;
    bytes->overallocate = 0;

    return (DfObject *)bytes;
}

void
df_bytes_obj_extend(DfObject *bytes, uint8_t byte)
{
    DfBytesObj *bytesp = (DfBytesObj *)bytes;

    if (bytesp->capacity < bytesp->count + 1)
    {
        int old_capacity = bytesp->capacity;

        if (bytesp->overallocate != 0)
            bytesp->capacity = CONT_UPD_CAPACITY(old_capacity);
        else
            bytesp->capacity++;

        bytesp->items = DF_MEM_GROW_ARRAY(uint8_t, bytesp->items,
                                          old_capacity, bytesp->capacity);
    }

    bytesp->items[bytesp->count] = byte;
    bytesp->count++;
}

void
df_bytes_obj_clear(DfBytesObj *bytes)
{
    DF_MEM_FREE_ARRAY(uint8_t, bytes->items, bytes->capacity);

    DF_MEM_FREE(bytes);

    bytes = (DfBytesObj *)df_bytes_obj_init();
}

const char *bin[16] = {
    [0] = "0000",  [1] = "0001",  [2] = "0010",  [3] = "0011",
    [4] = "0100",  [5] = "0101",  [6] = "0110",  [7] = "0111",
    [8] = "1000",  [9] = "1001",  [10] = "1010", [11] = "1011",
    [12] = "1100", [13] = "1101", [14] = "1110", [15] = "1111",
};

static int
bytes_print(DfObject *bytes)
{
    int i;
    DfBytesObj *bytesp = (DfBytesObj *)bytes;

    printf("[");
    if (bytesp->items != NULL)
    {
        for (i = 0; i < bytesp->count; i++)
        {
             if (i > 0)
                 printf(", ");

             printf("%s%s", bin[bytesp->items[i] >> 4],
                    bin[bytesp->items[i] & 0x0F]);
        }
    }
    printf("]");

    return 0;
}

static int
bytes_length(DfObject *bytes)
{
    return ((DfBytesObj *)bytes)->count;
}

static void
bytes_destroy(DfObject *bytes)
{
    DfBytesObj *bytesp = (DfBytesObj *)bytes;

    DF_MEM_FREE_ARRAY(uint8_t, bytesp->items, bytesp->capacity);
    DF_MEM_FREE(bytesp);
}

static DfContOps as_container = {
    (intunaryop)bytes_length,
    NULL
};

DfType DfBytesType = {
    "bytes",
    sizeof(DfBytesObj),
    sizeof(uint8_t),
    (voidunaryop)bytes_destroy,
    NULL,
    (intunaryop)bytes_print,
    NULL,
    NULL,
    NULL,
    NULL,
    &as_container,
    NULL
};
