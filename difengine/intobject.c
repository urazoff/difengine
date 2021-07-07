#include "intobject.h"
#include "defines.h"
#include "memory.h"

DfObject*
df_int_obj_init(int size)
{
    DfIntObj *x = (DfIntObj *)df_obj_new(&DfIntType);

    if (x == NULL)
        return NULL;

    x->digits = DF_MEM_ALLOC(size * sizeof(df_digit));
    if (x->digits == NULL)
        return NULL;
    memset(x->digits, 0, size * sizeof(df_digit));
    x->count = size;
    x->capacity = size;
    x->overallocate = 0;

    return (DfObject *)x;
}

void
df_int_print_digits(DfObject *a)
{
    DfIntObj *x = (DfIntObj *)a;
    int i;
    int size = DF_ABS(x->count);

    if (x->count < 0)
        printf("-");
    printf("[");
    for (i = 0; i < size; ++i)
    {
             if (i > 0)
                 printf(", ");

             printf("%d", x->digits[i]);
    }
    printf("]");
}

static DfIntObj*
remove_leading_zeros(DfIntObj *a)
{
    int i;
    int size = DF_ABS(a->count);

    for (i = size; (i > 0) && (a->digits[i - 1] == 0); --i);

    if (i != size)
    {
        if (i == 0)
            i = 1;

        a->count = (a->count >= 0) ? i : -i;
    }

    return a;
}

static DfObject*
int_negate(DfObject *a)
{
    DfIntObj *x = (DfIntObj *)a;
    int size_x = DF_ABS(x->count);
    int i;

    DfIntObj *neg = (DfIntObj *)df_int_obj_init(size_x);
    for (i = 0; i < size_x; ++i)
        neg->digits[i] = x->digits[i];
    neg->count = -size_x;

    return (DfObject *)neg;
}

/* GNU style compare function for absolute values.
 * Return -1 if |x| < |y|, 0 if |x| == |y|, 1 if |x| > |y|.
 * */
static int
int_compare_abs(DfIntObj *x, DfIntObj *y)
{
    int size_x = DF_ABS(x->count);
    int size_y = DF_ABS(y->count);
    int i;

    /* The more significant figures the bigger absolute value */
    if (size_x != size_y)
        return size_x > size_y ? 1 : -1;

    /* Compare per digit starting from the most significant one */
    for (i = size_x; i-- > 0;)
    {
       if (x->digits[i] != y->digits[i])
           return x->digits[i] > y->digits[i] ? 1 : -1;
    }

    return 0;
}

static int
int_compare(DfObject *a, DfObject *b)
{
    DfIntObj *x = (DfIntObj *)a;
    DfIntObj *y = (DfIntObj *)b;
    int sgn_x;
    int sgn_y;
    int res;

    sgn_x = DF_SGN(x->count);
    sgn_y = DF_SGN(y->count);

    if (sgn_x != sgn_y)
        return sgn_x > sgn_y ? 1 : -1;

    if (sgn_x == 0)
        return 0;

    res = int_compare_abs(x, y);
    if (sgn_x < 0)
        return -res;

    return res;
}

/* Primary school method ~ O(n).
 * Doesn't handle signs. Assume |x->count| >= |y->count|.
 * */
static DfIntObj*
int_add_s(DfIntObj *x, DfIntObj *y)
{
    df_digit carry = 0;
    int i;
    int size_x;
    int size_y;

    size_x = DF_ABS(x->count);
    size_y = DF_ABS(y->count);

    DfIntObj *s = (DfIntObj *)df_int_obj_init(size_x + 1);
    if (s == NULL)
        return NULL;

    for (i = 0; i < size_y; ++i)
    {
        carry += x->digits[i] + y->digits[i];
        s->digits[i] = carry % DF_INT_BASE;
        /* carry = carry / DF_INT_BASE via bitwise shift */
        carry >>= DF_INT_BITS;
    }

    for (; i < size_x; ++i)
    {
        carry += x->digits[i];
        s->digits[i] = carry % DF_INT_BASE;
        carry >>= DF_INT_BITS;
    }

    s->digits[size_x] = carry;
    return remove_leading_zeros(s);
}

/* Substract absolute values. Assume |x| > |y|. */
static DfIntObj*
int_sub_s(DfIntObj *x, DfIntObj *y)
{
    df_digit carry = 0;
    int i;
    int size_x;
    int size_y;

    size_x = DF_ABS(x->count);
    size_y = DF_ABS(y->count);

    DfIntObj *s = (DfIntObj *)df_int_obj_init(size_x);
    if (s == NULL)
        return NULL;

    for (i = 0; i < size_y; ++i)
    {
        s->digits[i] = x->digits[i] - y->digits[i] - carry;
        carry = s->digits[i] >> (DF_INT_DIGIT_SIZE - 1u);
        s->digits[i] &= DF_INT_MASK;
    }

    for (; i < size_x; ++i)
    {
        s->digits[i] = x->digits[i] - carry;
        carry = s->digits[i] >> (DF_INT_DIGIT_SIZE - 1u);
        s->digits[i] &= DF_INT_MASK;
    }

    return remove_leading_zeros(s);
}

/* Addition wrapper. Handles signs. */
static DfObject*
int_add(DfObject *a, DfObject *b)
{
    DfIntObj *x = (DfIntObj *)a;
    DfIntObj *y = (DfIntObj *)b;
    DfIntObj *z;

    if (DF_SGN(x->count) == DF_SGN(y->count))
    {
        /* Make sure |x->count| >= |y->count| */
        if (DF_ABS(x->count) < DF_ABS(y->count))
        {
            x = (DfIntObj *)b;
            y = (DfIntObj *)a;
        }
        z = int_add_s(x, y);
    }
    else
    {
        /* Make sure |x| >= |y| */
        if (int_compare_abs(x, y) < 0)
        {
            x = (DfIntObj *)b;
            y = (DfIntObj *)a;
        }
        z = int_sub_s(x, y);
    }

    z->count = x->count < 0 ? -z->count : z->count;
    return (DfObject *)z;
}

/* Substraction wrapper. Handles signs. */
static DfObject*
int_sub(DfObject *a, DfObject *b)
{
    DfIntObj *x = (DfIntObj *)a;
    DfIntObj *y = (DfIntObj *)b;
    DfIntObj *z;
    int sign = 0;

    if (DF_SGN(x->count) != DF_SGN(y->count))
    {
        /* Make sure |x->count| >= |y->count| */
        if (DF_ABS(x->count) < DF_ABS(y->count))
        {
            x = (DfIntObj *)b;
            y = (DfIntObj *)a;
        }
        z = int_add_s(x, y);
        z->count = x->count < 0 ? -z->count : z->count;
    }
    else
    {
        sign = x->count < 0 ? -1 : 1;
        /* Make sure |x| >= |y| */
        if (int_compare_abs(x, y) < 0)
        {
            sign = -sign;
            x = (DfIntObj *)b;
            y = (DfIntObj *)a;
        }
        z = int_sub_s(x, y);
        z->count = sign*z->count;
    }

    return (DfObject *)z;
}

/* Primary school method ~ O(n^2). */
static DfIntObj*
int_multiply_s(DfIntObj *x, DfIntObj *y)
{
    df_word carry;
    df_digit c;
    int ix;
    int iy;
    int size_x;
    int size_y;

    size_x = DF_ABS(x->count);
    size_y = DF_ABS(y->count);

    DfIntObj *p = (DfIntObj *)df_int_obj_init(size_x + size_y);
    if (p == NULL)
        return NULL;

    for (ix = 0; ix < size_x; ++ix)
    {
        c = 0;
        for (iy = 0; iy < size_y; ++iy)
        {
            carry = (df_word)p->digits[ix + iy] +
                    ((df_word)x->digits[ix] * (df_word)y->digits[iy]) +
                    (df_word)c;
            p->digits[ix + iy] = (df_digit)(carry & (df_word)DF_INT_MASK);
            c = (df_digit)(carry >> (df_word)DF_INT_BITS);
        }
        p->digits[ix + size_y] = c;
    }

    return remove_leading_zeros(p);
}

/* Multiplication wrapper.
 * TODO: implement Karatsuba and Toom-3 algorithms and add
 * to this function depending on the length of a and b.
 * */
static DfObject*
int_multiply(DfObject *a, DfObject *b)
{
    DfIntObj *x = (DfIntObj *)a;
    DfIntObj *y = (DfIntObj *)b;
    DfIntObj *p;

    p = int_multiply_s(x, y);
    p->count = p->count * DF_SGN(x->count) *
               DF_SGN(y->count);

    return (DfObject *)p;
}

/* Make copy of x. */
static DfIntObj*
int_copy(DfIntObj *x)
{
    int i;
    int size_x = DF_ABS(x->count);
    DfIntObj *z = (DfIntObj *)df_int_obj_init(size_x);
    if (z == NULL)
        return NULL;

    for (i = 0; i < size_x; ++i)
        z->digits[i] = x->digits[i];

    z->count = x->count;

    return z;
}

/* a^b */
static DfObject*
int_pow(DfObject *a, DfObject *b)
{
    DfIntObj *x = (DfIntObj *)a;
    DfIntObj *y = (DfIntObj *)b;
    df_digit d;
    int size_y;
    int i;
    int j;
    DfObject *r = df_int_obj_init(1);
    ((DfIntObj *)r)->digits[0] = 1;
    DfObject *tmp = (DfObject *)int_copy(x);
    DfObject *tmp_f;

    if (y->count < 0)
        /* int in negative power must be done using DfFloatObj */
        return NULL;

    size_y = DF_ABS(y->count);
    for (i = 0; i < size_y; ++i)
    {
        d = y->digits[i];

        for (j = 0; j < DF_INT_DIGIT_SIZE; ++j)
        {
            if (d & 1)
            {
                tmp_f = r;
                r = int_multiply(r, tmp);
                df_obj_destroy(tmp_f);
            }

            d >>= 1;
            if (d == 0 && i + 1 == size_y)
                break;
            tmp_f = tmp;
            tmp = int_multiply(tmp, tmp);
            df_obj_destroy(tmp_f);
        }
    }

    df_obj_destroy((DfObject *)tmp);
    return (DfObject *)r;
}

static DfObject*
int_abs(DfObject *a)
{
    DfIntObj *x = (DfIntObj *)a;
    DfIntObj *z;

    z = int_copy(x);
    if (z == NULL)
        return NULL;
    z->count = z->count < 0 ? -z->count : z->count;

    return (DfObject *)z;
}

/* bignum + digit. Make sure a is big enough to hold a*b! */
static void
int_add_digit(DfIntObj *a, df_digit b)
{
    int i;
    df_digit carry = b;
    int size = DF_ABS(a->count);

    for (i = 0; i < size; ++i)
    {
       a->digits[i] = a->digits[i] + carry;
       carry = a->digits[i] >> DF_INT_BITS;
       a->digits[i] &= DF_INT_MASK;
    }
    a->digits[i] = carry;
}

/* bignum * digit. Make sure a is big enough to hold a*b! */
static void
int_mult_digit(DfIntObj *a, df_digit b)
{
    int i;
    df_word carry;
    df_digit c = 0;
    int size = DF_ABS(a->count);

    for (i = 0; i < size; ++i)
    {
        carry = (df_word)a->digits[i] * (df_word)b + (df_word)c;
        a->digits[i] = carry & DF_INT_MASK;
        c = carry >> DF_INT_BITS;
    }
    a->digits[i] = c;
}

static void int_destroy(DfObject *a);
static void int_div_digit(DfIntObj *x, df_digit b, df_digit *mod);

/* Knuth V. 2 Chapter 4.3.1 Algorithm D.
 * Returns quotient and writes remainder as r.
 * */
static DfIntObj*
int_div_s(DfIntObj *a, DfIntObj *b, DfIntObj **r, int remainder)
{
    DfIntObj *x = NULL;
    DfIntObj *y = NULL;
    DfIntObj *q = NULL;
    DfIntObj *tmp = NULL;
    df_word p;
    df_word w;
    df_word rh;
    df_digit d;
    df_digit qh;
    df_digit yn;
    df_sword k;
    df_sword t;
    int size_x;
    int size_y;
    int j;
    int i;

    size_x = DF_ABS(a->count);

    /* Allocate more space for x to have one more digit */
    x = (DfIntObj *)df_int_obj_init(size_x + 1);

    for (i = 0; i < size_x; ++i)
        x->digits[i] = a->digits[i];

    x->digits[size_x] = 0;

    y = int_copy(b);
    size_y = DF_ABS(y->count);

    q = (DfIntObj *)df_int_obj_init(size_x - size_y + 1);

    /* Step 1. Normalize. */
    /* d = DF_INT_MASK / b->digits[size_y - 1]; */
    d = (DF_INT_BASE / 2) / b->digits[size_y - 1] + 1;
    int_mult_digit(x, d);
    int_mult_digit(y, d);

    /* Step 3 (initializaitons is Step 2). Main loop. */
    yn = y->digits[size_y - 1];

    assert(yn > DF_INT_BASE / 2);

    for (j = size_x; j >= size_y; --j)
    {
        w = (df_word)x->digits[j] << (df_word)DF_INT_BITS;
        w |= (df_word)x->digits[j - 1];
        rh = w % (df_word)yn;
        w /= (df_word)yn;
        qh = (df_digit)(w & (df_word)DF_INT_MASK);

again:
        /* Subloop in Step 3. */
        if (qh >= DF_INT_BASE ||
            (df_word)qh*(df_word)y->digits[size_y - 2] >
            DF_INT_BASE*rh + x->digits[j - 2])
        {
            qh -= 1;
            rh += yn;

            if (rh < DF_INT_BASE)
                goto again;
        }

        /* Step 4. Multiply and subtract. */
        k = 0;
        for (i = 0; i < size_y; ++i)
        {
            p = (df_word)qh*(df_word)y->digits[i];
            t = x->digits[i + j - size_y] - k - (p & (df_word)DF_INT_MASK);
            x->digits[i + j - size_y] = (df_digit)(t & (df_word)DF_INT_MASK);
            k = (p >> (df_word)DF_INT_BITS) - (t >> (df_word)DF_INT_BITS);
        }
        t = x->digits[j] - k;
        x->digits[j] = (df_digit)(t & (df_word)DF_INT_MASK);

        /* Step 5. */
        q->digits[j - size_y] = qh;
        if (t < 0)
        {
            /* Step 6. */
            q->digits[j - size_y] -= 1;
            k = 0;
            for (i = 0; i < size_y; ++i)
            {
                t = x->digits[i + j - size_y] + y->digits[i] + k;
                x->digits[i + j - size_y] =
                    (df_digit)(t & (df_word)DF_INT_MASK);
                k = t >> DF_INT_BITS;
            }
            x->digits[j] += (df_digit)k;
        }

        /* Step 7. */
    }
    /* Step 8. We want the remainder. Unnormalize it. */
    if (remainder)
    {
        tmp = (DfIntObj *)df_int_obj_init(size_y);
        for (i = 0; i < size_y; ++i)
            tmp->digits[i] = x->digits[i];

        int_div_digit(tmp, d, &p);

        *r = tmp;
    }

    int_destroy((DfObject *)x);
    int_destroy((DfObject *)y);
    return q;
}

static DfObject*
int_mod(DfObject *a, DfObject *b)
{
    DfIntObj *x = (DfIntObj *)a;
    DfIntObj *y = (DfIntObj *)b;
    DfIntObj *tmp = NULL;
    DfIntObj *q = NULL;
    DfIntObj *r = NULL;
    df_digit mod;
    int size_x;
    int size_y;

    size_x = DF_ABS(x->count);
    size_y = DF_ABS(y->count);

    if (size_y == 0)
        return NULL;

    if (size_x < size_y)
    {
        DF_INC_RF(a);
        return a;
    }

    if (size_y == 1)
    {
        if (y->digits[0] == 0)
            return NULL;

        tmp = int_copy(x);
        int_div_digit(tmp, y->digits[0], &mod);
        r = (DfIntObj *)df_int_obj_init(1);
        r->digits[0] = mod;
        int_destroy((DfObject *)tmp);
    }
    else
    {
        q = int_div_s(x, y, &r, 1);
        int_destroy((DfObject *)q);
    }

    if (x->count < 0)
        r->count = -r->count;

    return (DfObject *)remove_leading_zeros(r);
}

static DfObject*
int_div(DfObject *a, DfObject *b)
{
    DfIntObj *x = (DfIntObj *)a;
    DfIntObj *y = (DfIntObj *)b;
    DfIntObj *q = NULL;
    df_digit mod;
    int size_x;
    int size_y;

    size_x = DF_ABS(x->count);
    size_y = DF_ABS(y->count);

    if (size_y == 0)
        return NULL;

    if (size_x < size_y)
        return df_int_obj_init(0);

    if (size_y == 1)
    {
        if (y->digits[0] == 0)
            return NULL;

        q = int_copy(x);
        int_div_digit(q, y->digits[0], &mod);
    }
    else
    {
        q = int_div_s(x, y, NULL, 0);
    }

    if ((x->count < 0) != (y->count < 0))
        q->count = -q->count;

    return (DfObject *)remove_leading_zeros(q);
}

/* bignum div digit, bignum mod digit */
static void
int_div_digit(DfIntObj *x, df_digit b, df_digit *mod)
{
    int size_x = DF_ABS(x->count);
    df_word z = 0;
    df_digit q;
    int i;

    for (i = size_x; i-- > 0; )
    {
        q = 0;
        z = (z << (df_word)DF_INT_BITS) | (df_word)x->digits[i];
        if (z >= b)
        {
            q = (df_digit)(z / b);
            z -= (df_word)q * (df_word)b;
        }
        x->digits[i] = q;
    }

    *mod = (df_digit)z;
}

/* Let X be an integer. Let V be a number of digits
 * in X in base b. W = number of digits in X in base B
 * can be found by:
 *                 W = V * (ln(b)/ln(B)) + 1.
 * B = 2^n => ln(b) = n*ln(2)
 * => q = ln(b)/ln(2) can be precalcuated. So we can found V
 * as round up of V*q + 1.
 * */
#define DF_SIZE_FROM_DEC(_len) (int)(_len * 3.32192 / DF_INT_BITS + 1 + 0.5)
#define DF_SIZE_TO_DEC(_len) (int)(_len * DF_INT_BITS * 0.30103 + 1 + 0.5)

DfObject*
df_int_from_str(char *digits)
{
    /* TODO: support different radices */
    int b = 10; /* digits are decimal */
    int i;
    int neg = 0;
    int len = strlen(digits);
    int size = DF_SIZE_FROM_DEC(len);

    DfIntObj *x = (DfIntObj *)df_int_obj_init(size);

    if (digits[0] == '-')
       neg = 1;

    /* Just evaluate the number */
    x->digits[0] = digits[neg] - '0';
    for (i = neg + 1; i < len; ++i)
    {
        int_mult_digit(x, b);
        int_add_digit(x, digits[i] - '0');
    }

    if (neg)
        x->count = -x->count;

    return (DfObject *)remove_leading_zeros(x);
}

static int
is_zero(DfIntObj *x)
{
    int size_x = DF_ABS(x->count);
    int i;

    for (i = 0; i < size_x; ++i)
    {
        if (x->digits[i] != 0)
            return 0;
    }

    return 1;
}

static char*
int_to_decimal_str(DfIntObj *x)
{
    int size_x = DF_ABS(x->count);
    int len = DF_SIZE_TO_DEC(size_x);
    int count = 0;
    int i;
    int k;
    int neg = 0;
    char *str;
    df_digit mod = -1;
    df_digit b = 10;
    DfIntObj *tmp = int_copy(x);
    if (tmp == NULL)
        return NULL;

    df_digit *dec = DF_MEM_ALLOC(len * sizeof(df_digit));
    df_digit *to_free = dec;
    if (dec == NULL)
        return NULL;

    if (is_zero(tmp))
        count = 1;

    for (k = 0; !is_zero(tmp); )
    {
        int_div_digit(tmp, b, &mod);
        dec[k++] = mod;
        ++count;
    }

    if (x->count < 0)
    {
        ++count;
        neg = 1;
    }

    str = DF_MEM_ALLOC((count + 1) * sizeof(char));
    if (str == NULL)
        return NULL;

    i = 0;
    if (neg)
    {
        str[0] = '-';
        i = 1;
    }
    for (; i < count; ++i)
        str[i] = dec[count - 1 - i] + '0';

    str[i] = '\0';

    DF_MEM_FREE(to_free);
    df_obj_destroy((DfObject *)tmp);
    return str;
}

static int
int_print(DfObject *a)
{
    char *str = int_to_decimal_str((DfIntObj *)a);
    if (str == NULL)
        return ENOMEM;

    printf("%s", str);
    DF_MEM_FREE(str);
    return 0;
}

/* The main idea is to represent bugnum as array of bytes
 * and just apply FNV. Here representation as decimal
 * string is used.
 * */
static uint32_t
int_hash(DfObject *a)
{
    char *str = int_to_decimal_str((DfIntObj *)a);
    if (str == NULL)
        return ENOMEM;
    char *to_free = str;

    uint32_t hash = 2166136261ul;
    while (*str != 0)
    {
        hash ^= *str;
        hash *= 0x01000193;
        str++;
    }

    DF_MEM_FREE(to_free);
    return hash;
}

static int
int_length(DfObject *a)
{
    return ((DfIntObj *)a)->count;
}

static void
int_destroy(DfObject *a)
{
    DfIntObj *x = (DfIntObj *)a;

    DF_MEM_FREE_ARRAY(df_digit, x->digits, x->capacity);
    DF_MEM_FREE(x);
}

static DfNumOps as_numeric = {
    (unaryop)int_negate,
    (unaryop)int_abs,
    (binaryop)int_add,
    (binaryop)int_sub,
    (binaryop)int_multiply,
    (binaryop)int_div,
    (binaryop)int_mod,
    (binaryop)int_pow
};

static DfContOps as_container = {
    (intunaryop)int_length,
    NULL
};

DfType DfIntType = {
    "integer",
    sizeof(DfIntObj),
    DF_WSIZE/16,
    (voidunaryop)int_destroy,
    (hashop)int_hash,
    (intunaryop)int_print,
    (intbinaryop)int_compare,
    NULL,
    NULL,
    &as_numeric,
    &as_container,
    NULL
};
