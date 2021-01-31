#include "object.h"
#include "memory.h"

DfObject*
df_obj_new(DfType *type)
{
    DfObject *obj;

    obj = (DfObject *)DF_MEM_ALLOC(type->size);

    if (obj == NULL)
        return NULL;

    obj->type = type;
    obj->rfcnt = 1;

    return obj;
}

DfObject*
df_obj_new_cont(DfType *type, int size)
{
    DfContObject *cont;

    cont = (DfContObject *)DF_MEM_ALLOC(type->size + size * type->item_size);

    if (cont == NULL)
        return NULL;

    cont->obj.type = type;
    cont->obj.rfcnt = 1;
    cont->count = size;
    cont->capacity = size;

    return (DfObject *)cont;
}

uint32_t
df_obj_hash(DfObject *obj)
{
    if (obj->type->hash != NULL)
        return (*obj->type->hash)(obj);

    return 0;
}

int
df_obj_compare(DfObject *a, DfObject *b)
{
    if (a->type == b->type)
        return (*a->type->compare)(a, b);

    /* TODO: handle error there and everywhere else */
    return -1;
}

int
df_obj_print(DfObject *obj, int flags)
{
    int ret_val;

    if (obj == NULL)
    {
        printf("df object: Null");
    }
    else if (obj->type->print != NULL)
    {
        ret_val = (*obj->type->print)(obj);

        if (ret_val == 0 && flags == 1)
            printf("\n");

        return ret_val;
    }
    else
    {
        printf("df object: %s at %p", obj->type->name, obj);
    }

    if (flags == 1)
        printf("\n");

    return 0;
}

void
df_obj_destroy(DfObject *obj)
{
    (*obj->type->destroy)(obj);
}
