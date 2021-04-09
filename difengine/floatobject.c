#include "floatobject.h"
#include "defines.h"
#include "memory.h"

DfObject*
df_float_obj_init(double val)
{
    DfFloatObj *x = (DfFloatObj *)df_obj_new(&DfFloatType);

    if (x == NULL)
        return NULL;

    x->val = val;

    return (DfObject *)x;
}

static DfObject*
float_negate(DfObject *a)
{
    DfFloatObj *x = (DfFloatObj *)a;

    return df_float_obj_init(-x->val);
}

static DfObject*
float_abs(DfObject *a)
{
    DfFloatObj *x = (DfFloatObj *)a;

    return df_float_obj_init(DF_ABS(x->val));
}

static int
float_compare(DfObject *a, DfObject *b)
{
    double x = ((DfFloatObj *)a)->val;
    double y = ((DfFloatObj *)b)->val;

    return (x < y) ? -1 : (x > y) ? 1 : 0;
}

static DfObject*
float_add(DfObject *a, DfObject *b)
{
    double x = ((DfFloatObj *)a)->val;
    double y = ((DfFloatObj *)b)->val;

    return df_float_obj_init(x + y);
}

static DfObject*
float_sub(DfObject *a, DfObject *b)
{
    double x = ((DfFloatObj *)a)->val;
    double y = ((DfFloatObj *)b)->val;

    return df_float_obj_init(x - y);
}

static DfObject*
float_multiply(DfObject *a, DfObject *b)
{
    double x = ((DfFloatObj *)a)->val;
    double y = ((DfFloatObj *)b)->val;

    return df_float_obj_init(x * y);
}

static DfObject*
float_divide(DfObject *a, DfObject *b)
{
    double x = ((DfFloatObj *)a)->val;
    double y = ((DfFloatObj *)b)->val;

    /* TODO: handle the error */
    if (y == 0)
        return NULL;

    return df_float_obj_init(x / y);
}

static int
float_print(DfObject *a)
{
    printf("%lf", ((DfFloatObj *)a)->val);
    return 0;
}

/* TODO: proper hash function which coincides with
 * hash of int if values are the same.
 */
static uint32_t
float_hash(DfObject *a)
{
    UNUSED(a);
    return 0;
}

static void
float_destroy(DfObject *a)
{
    DF_MEM_FREE(a);
}

static DfNumOps as_numeric = {
    (unaryop)float_negate,
    (unaryop)float_abs,
    (binaryop)float_add,
    (binaryop)float_sub,
    (binaryop)float_multiply,
    (binaryop)float_divide,
};

DfType DfFloatType = {
    "float",
    sizeof(DfFloatObj),
    0,
    (voidunaryop)float_destroy,
    (hashop)float_hash,
    (intunaryop)float_print,
    (intbinaryop)float_compare,
    NULL,
    NULL,
    &as_numeric,
    NULL,
    NULL
};
