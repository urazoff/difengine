#include "objectops.h"
#include "intobject.h"
#include "memory.h"

DfObject*
df_num_add(DfObject *a, DfObject *b)
{
    DfIntObj *sum = df_int_obj_new(((DfIntObj *)a)->val +
                                   ((DfIntObj *)b)->val);

    return sum;
}
