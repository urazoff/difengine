#include "objectops.h"
#include "intobject.h"
#include "memory.h"

DfObject*
df_num_negative(DfObject *a)
{
    DfIntObj *negative = df_int_obj_new(-((DfIntObj *)a)->val);

    return (DfObject *)negative;
}

DfObject*
df_num_add(DfObject *a, DfObject *b)
{
    DfIntObj *sum = df_int_obj_new(((DfIntObj *)a)->val +
                                   ((DfIntObj *)b)->val);

    return (DfObject *)sum;
}

DfObject*
df_num_multiply(DfObject *a, DfObject *b)
{
    DfIntObj *multiply = df_int_obj_new(((DfIntObj *)a)->val *
                                        ((DfIntObj *)b)->val);

    return (DfObject *)multiply;
}
