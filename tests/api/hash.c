#include <stdio.h>
#include "defines.h"
#include "hashobject.h"
#include "stringobject.h"

int main(int argc, char *argv[])
{
    int ret_val;
    DfObject *ret_p;
    DfStrObj *str1 = df_str_obj_from_str("string #1");
    DfStrObj *str2 = df_str_obj_from_str("string #2");
    DfObject *ht = df_hash_obj_init();

    ret_val = df_obj_print((DfObject *)str1);
    printf("%u\n", str1->hash);

    ret_val = df_obj_print((DfObject *)str2);
    printf("%u\n", str2->hash);

    ret_p = df_hash_obj_insert(ht, (DfObject *)str1, (DfObject *)str2);
    ret_val = df_obj_print(ret_p);

    ret_p = df_hash_obj_get(ht, (DfObject *)str1);
    ret_val = df_obj_print(ret_p);

    ret_val = df_hash_obj_delete(ht, (DfObject *)str1);
    ret_p = df_hash_obj_get(ht, (DfObject *)str1);
    ret_val = df_obj_print(ret_p);

    UNUSED(ret_val);

    printf("RES: Success\n");

    return 0;
}
