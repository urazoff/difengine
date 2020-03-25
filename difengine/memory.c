#include <stdlib.h>
#include "difengine.h"
#include "memory.h"

void *
df_realloc(void *prev, size_t old_size, size_t new_size)
{
    if (new_size == 0)
    {
        free(prev);
        return NULL;
    }

    return realloc(prev, new_size);
}
