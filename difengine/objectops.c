#include "objectops.h"
#include "intobject.h"
#include "memory.h"

/* High level numeric operations */
DfObject*
df_num_negative(DfObject *a)
{
    if (a->type->as_numeric != NULL && a->type->as_numeric->neg != NULL)
        return (*a->type->as_numeric->neg)(a);

    /* TODO: Handle error */
    return NULL;
}

DfObject*
df_num_abs(DfObject *a)
{
    if (a->type->as_numeric != NULL && a->type->as_numeric->abs != NULL)
        return (*a->type->as_numeric->abs)(a);

    /* TODO: Handle error */
    return NULL;
}

DfObject*
df_num_add(DfObject *a, DfObject *b)
{
    /* TODO: type checks must be more complex
     * to operate args of different types */
    if (a->type->as_numeric != NULL && a->type->as_numeric->add != NULL &&
        a->type == b->type)
        return (*a->type->as_numeric->add)(a, b);

    /* TODO: Handle error */
    return NULL;
}

DfObject*
df_num_sub(DfObject *a, DfObject *b)
{
    /* TODO: type checks must be more complex
     * to operate args of different types */
    if (a->type->as_numeric != NULL && a->type->as_numeric->sub != NULL &&
        a->type == b->type)
        return (*a->type->as_numeric->sub)(a, b);

    /* TODO: Handle error */
    return NULL;
}

DfObject*
df_num_multiply(DfObject *a, DfObject *b)
{
    /* TODO: type checks must be more complex
     * to operate args of different types */
    if (a->type->as_numeric != NULL && a->type->as_numeric->mul != NULL &&
        a->type == b->type)
        return (*a->type->as_numeric->mul)(a, b);

    /* TODO: Handle error */
    return NULL;
}

DfObject*
df_num_divide(DfObject *a, DfObject *b)
{
    /* TODO: type checks must be more complex
     * to operate args of different types */
    if (a->type->as_numeric != NULL && a->type->as_numeric->div != NULL &&
        a->type == b->type)
        return (*a->type->as_numeric->div)(a, b);

    /* TODO: Handle error */
    return NULL;
}

DfObject*
df_num_mod(DfObject *a, DfObject *b)
{
    /* TODO: type checks must be more complex
     * to operate args of different types */
    if (a->type->as_numeric != NULL && a->type->as_numeric->mod != NULL &&
        a->type == b->type)
        return (*a->type->as_numeric->mod)(a, b);

    /* TODO: Handle error */
    return NULL;
}

DfObject*
df_num_divmod(DfObject *a, DfObject *b)
{
    /* TODO: type checks must be more complex
     * to operate args of different types */
    if (a->type->as_numeric != NULL && a->type->as_numeric->divmod != NULL &&
        a->type == b->type)
        return (*a->type->as_numeric->divmod)(a, b);

    /* TODO: Handle error */
    return NULL;
}

DfObject*
df_num_pow(DfObject *a, DfObject *b)
{
    /* TODO: type checks must be more complex
     * to operate args of different types */
    if (a->type->as_numeric != NULL && a->type->as_numeric->pow != NULL &&
        a->type == b->type)
        return (*a->type->as_numeric->pow)(a, b);

    /* TODO: Handle error */
    return NULL;
}
