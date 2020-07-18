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
