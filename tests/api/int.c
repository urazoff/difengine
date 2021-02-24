#include <stdio.h>
#include "difengine.h"
#include "intobject.h"
#include "objectops.h"

int main(int argc, char *argv[])
{
    DfObject *a = df_int_from_str("53923543891348405834500421932457932476387");
    DfObject *b = df_int_from_str("13845648293248349438457293245905734012349");
    DfObject *y;
    DfObject *z;
    DfObject *s;

    printf("a = ");
    df_obj_print(a, 0);
    printf(";\n");
    printf("b = ");
    df_obj_print(b, 0);
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
    printf("\nRES: Success\n");

    return 0;
}
