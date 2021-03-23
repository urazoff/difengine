#include <stdio.h>
#include "defines.h"
#include "hashobject.h"
#include "stringobject.h"
#include "intobject.h"

int main(int argc, char *argv[])
{
    int ret_val;
    DfObject *ret_p;
    DfStrObj *str1 = df_str_obj_from_str("string #1");
    DfStrObj *str2 = df_str_obj_from_str("string #2");
    DfObject *x = df_int_from_str("53923543891348405834500421932457932476387");
    DfObject *y = df_int_from_str("95892348909345987134092364758391002349874");
    DfObject *ht = df_hash_obj_init();

    ret_p = df_hash_obj_insert(ht, (DfObject *)str1, y);
    ret_p = df_hash_obj_insert(ht, x, (DfObject *)str2);
    ret_val = df_obj_print(ht, 1);

    ret_p = df_hash_obj_get(ht, x);
    ret_val = df_obj_print(ret_p, 1);

    ret_val = df_hash_obj_delete(ht, x);
    ret_p = df_hash_obj_get(ht, x);
    ret_val = df_obj_print(ret_p, 1);

    UNUSED(ret_val);

    printf("RES: Success\n");

    return 0;
}
