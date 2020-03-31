#include "internal/container.h"
#include "bytesobject.h"
#include "memory.h"

/* Definition and implementation for now
 * are the same as DfListObj.
 * May be needs some generalization.
*/

DfBytesObj*
df_bytes_obj_init()
{
    DfBytesObj *bytes = DF_MEM_ALLOC(sizeof(DfBytesObj));

    bytes->items = NULL;
    bytes->count= 0;
    bytes->capacity = 0;
    bytes->overallocate = 0;

    return bytes;
}

void
df_bytes_obj_extend(DfBytesObj *bytes, uint8_t byte)
{
    if (bytes->capacity < bytes->count + 1)
    {
        int old_capacity = bytes->capacity;

        if (bytes->overallocate != 0)
            bytes->capacity = CONT_UPD_CAPACITY(old_capacity);
        else
            bytes->capacity++;

        bytes->items = DF_MEM_GROW_ARRAY(uint8_t, bytes->items,
                                        old_capacity, bytes->capacity);
    }

    bytes->items[bytes->count] = byte;
    bytes->count++;
}

void
df_bytes_obj_clear(DfBytesObj *bytes)
{
    DF_MEM_FREE_ARRAY(uint8_t, bytes->items, bytes->capacity);

    DF_MEM_FREE(bytes);

    bytes = df_bytes_obj_init();
}
