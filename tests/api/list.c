#include <stdio.h>
#include "difengine.h"
#include "defines.h"
#include "memory.h"
#include "object.h"
#include "hashobject.h"
#include "stringobject.h"
#include "listobject.h"

int main(int argc, char *argv[])
{
    int ret_val;
    DfObject *ret_p;
    DfObject *str1 = df_str_obj_from_str("string #1");
    DfObject *str2 = df_str_obj_from_str("string #2");
    DfObject *ht = df_hash_obj_init();
    DfObject *list = df_list_obj_init();

    df_list_obj_extend(list, str1);
    df_list_obj_extend(list, str2);

    ret_p = df_hash_obj_insert(ht, str1, str2);

    df_list_obj_extend(list, ht);

    ret_val = df_obj_print(list, 1);

    UNUSED(ret_val);
    UNUSED(ret_p);

    printf("RES: Success\n");

    return 0;
}
