/* for hypot() */
#include <math.h>
#include "complexobject.h"
#include "floatobject.h"
#include "defines.h"
#include "memory.h"

DfObject*
df_complex_obj_init(double real, double im)
{
    DfComplexObj *x = (DfComplexObj *)df_obj_new(&DfComplexType);

    if (x == NULL)
        return NULL;

    x->real = real;
    x->im = im;

    return (DfObject *)x;
}

static DfObject*
complex_negate(DfObject *a)
{
    DfComplexObj *x = (DfComplexObj *)a;

    return df_complex_obj_init(-x->real, -x->im);
}

static DfObject*
complex_abs(DfObject *a)
{
    DfComplexObj *x = (DfComplexObj *)a;

    return df_float_obj_init(hypot(x->real, x->im));
}

/* Actually only check for equality is senseful
 * but we need to return something if a != b.
 * */
static int
complex_compare(DfObject *a, DfObject *b)
{

    DfComplexObj *x = (DfComplexObj *)a;
    DfComplexObj *y = (DfComplexObj *)b;

    if (x->real == y->real)
    {
        if (x->im == y->im)
            return 0;
        else
            return (x->im < y->im) ? -1 : 1;
    }
    else
    {
        return (x->real < y->real) ? -1 : 1;
    }
}

static DfObject*
complex_add(DfObject *a, DfObject *b)
{
    DfComplexObj *x = (DfComplexObj *)a;
    DfComplexObj *y = (DfComplexObj *)b;

    return df_complex_obj_init(x->real + y->real, x->im + y->im);
}

static DfObject*
complex_sub(DfObject *a, DfObject *b)
{
    DfComplexObj *x = (DfComplexObj *)a;
    DfComplexObj *y = (DfComplexObj *)b;

    return df_complex_obj_init(x->real - y->real, x->im - y->im);
}

static DfObject*
complex_multiply(DfObject *a, DfObject *b)
{
    DfComplexObj *x = (DfComplexObj *)a;
    DfComplexObj *y = (DfComplexObj *)b;

    return df_complex_obj_init(x->real * y->real - x->im * y->im,
                               x->real * y->im + x->im * y->real);
}

static DfObject*
complex_divide(DfObject *a, DfObject *b)
{
    DfComplexObj *x = (DfComplexObj *)a;
    DfComplexObj *y = (DfComplexObj *)b;
    double r2;

    /* TODO: handle the error */
    if (y->real == 0.0 && y->im == 0.0)
        return NULL;

    r2 = y->real * y->real + y->im * y->im;

    return df_complex_obj_init((x->real * y->real + x->im * y->im)/r2,
                               (x->im * y->real - x->real * y->im)/r2);
}

static int
complex_print(DfObject *a)
{
    DfComplexObj *x = (DfComplexObj *)a;

    /* Imaginary number */
    if (x->real == 0.0)
        printf("%lfi", x->im);
    else
        printf("%lf + %lfi", x->real, x->im);

    return 0;
}

/* TODO: proper hash function which coincides with
 * hash of int if values are the same.
 */
static uint32_t
complex_hash(DfObject *a)
{
    UNUSED(a);
    return 0;
}

static void
complex_destroy(DfObject *a)
{
    DF_MEM_FREE(a);
}

static DfNumOps as_numeric = {
    (unaryop)complex_negate,
    (unaryop)complex_abs,
    (binaryop)complex_add,
    (binaryop)complex_sub,
    (binaryop)complex_multiply,
    (binaryop)complex_divide,
};

DfType DfComplexType = {
    "complex",
    sizeof(DfComplexObj),
    0,
    (voidunaryop)complex_destroy,
    (hashop)complex_hash,
    (intunaryop)complex_print,
    (intbinaryop)complex_compare,
    NULL,
    NULL,
    &as_numeric,
    NULL,
    NULL
};
