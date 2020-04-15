#include "intobject.h"
#include "memory.h"

DfIntObj*
df_int_obj_new(int val)
{
    DfIntObj *int_obj = DF_MEM_ALLOC(sizeof(DfIntObj));

    int_obj->val = val;

    return int_obj;
}
