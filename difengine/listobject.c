#include "internal/container.h"
#include "listobject.h"
#include "memory.h"

DfListObj*
df_list_obj_init()
{
    DfListObj *list = DF_MEM_ALLOC(sizeof(DfListObj));

    list->items = NULL;
    list->count= 0;
    list->capacity = 0;
    list->overallocate = 0;

    return list;
}

void
df_list_obj_extend(DfListObj *list, DfObject *item)
{
    if (list->capacity < list->count + 1)
    {
        int old_capacity = list->capacity;

        if (list->overallocate != 0)
            list->capacity = CONT_UPD_CAPACITY(old_capacity);
        else
            list->capacity++;

        list->items = DF_MEM_GROW_ARRAY(DfObject *, list->items,
                                        old_capacity, list->capacity);
    }

    list->items[list->count] = item;
    list->count++;
}

void
df_list_obj_clear(DfListObj *list)
{
    DF_MEM_FREE_ARRAY(DfObject *, list->items, list->capacity);

    DF_MEM_FREE(list);

    list = df_list_obj_init();
}
