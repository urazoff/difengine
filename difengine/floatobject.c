#include <math.h>
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

/* modulo operation */
static DfObject*
float_mod(DfObject *a, DfObject *b)
{
    double x = ((DfFloatObj *)a)->val;
    double y = ((DfFloatObj *)b)->val;
    double mod;

    /* TODO: handle the error */
    if (y == 0)
        return NULL;

    mod = fmod(x, y);
    return df_float_obj_init(mod);
}

/* a^b */
static DfObject*
float_pow(DfObject *a, DfObject *b)
{
    double x = ((DfFloatObj *)a)->val;
    double y = ((DfFloatObj *)b)->val;
    long iy = (long)y;
    long exp;
    double r;

    /* x^0 */
    if (y == 0)
    {
        if (x == 0)
            /* 0^0 undefined */
            return NULL;

        r = 1.0;
        return df_float_obj_init(r);
    }

    /* 0^y */
    if (x == 0)
    {
        if (y < 0)
            /* 0^y undefined for y < 0 */
            return NULL;

        r = 0.0;
        return df_float_obj_init(r);
    }

    /* 1^y or x^1 */
    if (x == 1.0 || y == 1.0)
    {
        r = x;
        return df_float_obj_init(r);
    }

    /* integer power:
     * y = 2^b_1 + ... + 2^b_k => x^y = x^(2^b_1) * ... * x^(2^b_k)
     */
    if (y == iy)
    {
        r = 1.0;
        if (iy < 0)
            exp = -iy;
        else
            exp = iy;

        while (exp > 0)
        {
            if (exp & 1)
                r *= x;
            x *= x;
            exp >>= 1;
        }

        if (iy < 0)
            r = 1.0 / r;

        return df_float_obj_init(r);
    }

    if (x < 0)
        /* negative number in float power must be done using DfComplexObj */
        return NULL;

    r = pow(x, y);
    return df_float_obj_init(r);
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
    (binaryop)float_mod,
    NULL,
    (binaryop)float_pow
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
