#include <stdio.h>
#include "difengine.h"
#include "intobject.h"
#include "objectops.h"

int main(int argc, char *argv[])
{
    DfObject *a = df_int_from_str("638948316270763516948362566075654005225118239383839565678078546167173355023724249376445150745033165431013971237794374481340179773498313825438278388749918008424946842480162549731346849721898625184232310482889684844084043181360385061534518509586575980341857862451507313571307708859201955535185296477935");
    DfObject *b = df_int_from_str("7548343232442301810848189510846489993080910241334605409913652581750145492748679829376780573414536279033932417377133470171961361579281293880770264438582239146114691905887907617791806672074982855431");
    DfObject *m;
    DfObject *y;
    DfObject *z;
    DfObject *s;
    DfObject *q;
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

    printf("a mod b = ");
    m = df_num_mod(a, b);
    df_obj_print(m, 0);
    printf(";\n");

    printf("a div b = ");
    q = df_num_divmod(a, b);
    df_obj_print(q, 0);
    printf(";\n");

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
    df_obj_destroy(m);
    df_obj_destroy(q);
    printf("\nRES: Success\n");

    return 0;
}
