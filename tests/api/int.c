#include <stdio.h>
#include "difengine.h"
#include "intobject.h"
#include "objectops.h"

int main(int argc, char *argv[])
{
    DfObject *a = df_int_from_str("-592354389134840583450042193245793247638");
    DfObject *b = df_int_from_str("384564829324834943845729324590573401234");
    DfObject *y;
    DfObject *z;
    DfObject *s;
    int cmp;

    printf("a = ");
    df_obj_print(a, 0);
    printf(";\n");
    printf("b = ");
    df_obj_print(b, 0);
    printf(";\n");

    cmp = df_obj_compare(a, b);
    if (cmp == 0)
        printf("a = b\n");
    else if (cmp == -1)
        printf("a < b\n");
    else
        printf("a > b\n");

    printf("a * b = ");
    y = df_num_multiply(a, b);
    df_obj_print(y, 0);
    printf(";\n");

    printf("a + a*b = ");
    z = df_num_add(a, y);
    df_obj_print(z, 0);
    printf(";\n");

    printf("a - a*b = ");
    s = df_num_sub(a, y);
    df_obj_print(s, 0);
    printf(";\n");

    df_obj_destroy(a);
    df_obj_destroy(b);
    df_obj_destroy(y);
    df_obj_destroy(z);
    df_obj_destroy(s);
    printf("\nRES: Success\n");

    return 0;
}
