#include "internal/container.h"
#include "listobject.h"
#include "memory.h"

DfObject*
df_list_obj_init()
{
    DfListObj *list = (DfListObj *)df_obj_new(&DfListType);

    if (list == NULL)
        return NULL;

    list->items = NULL;
    list->count= 0;
    list->capacity = 0;
    list->overallocate = 0;

    return (DfObject *)list;
}

void
df_list_obj_extend(DfObject *list, DfObject *item)
{
    DfListObj *listp = (DfListObj *)list;

    if (listp->capacity < listp->count + 1)
    {
        int old_capacity = listp->capacity;

        if (listp->overallocate != 0)
            listp->capacity = CONT_UPD_CAPACITY(old_capacity);
        else
            listp->capacity++;

        listp->items = DF_MEM_GROW_ARRAY(DfObject *, listp->items,
                                         old_capacity, listp->capacity);
    }

    listp->items[listp->count] = item;
    DF_INC_RF(item);
    listp->count++;
}

void
df_list_obj_clear(DfListObj *list)
{
    DF_MEM_FREE_ARRAY(DfObject *, list->items, list->capacity);

    DF_MEM_FREE(list);

    list = (DfListObj *)df_list_obj_init();
}

static int
list_print(DfObject *list)
{
    int i;
    DfListObj *listp = (DfListObj *)list;

    printf("[");
    if (listp->items != NULL)
    {
        for (i = 0; i < listp->count; i++)
        {
             if (i > 0)
                 printf(", ");

             if (df_obj_print(listp->items[i], 0) != 0)
                return -1;
        }
    }
    printf("]");

    return 0;
}

static int
list_length(DfObject *list)
{
    return ((DfListObj *)list)->count;
}

static void
list_destroy(DfObject *list)
{
    int i;
    DfListObj *listp = (DfListObj *)list;

    if (listp->items != NULL)
    {
        for (i = 0; i < listp->count; i++)
            DF_DEC_RF(listp->items[i]);

        DF_MEM_FREE_ARRAY(DfObject *, listp->items, listp->capacity);
    }
    DF_MEM_FREE(listp);
}

static DfContOps as_container = {
    (intunaryop)list_length,
    NULL
};

DfType DfListType = {
    "list",
    sizeof(DfListObj),
    sizeof(DfObject *),
    (voidunaryop)list_destroy,
    NULL,
    (intunaryop)list_print,
    NULL,
    NULL,
    NULL,
    NULL,
    &as_container,
    NULL
};
