#include <stdio.h>
#include "difengine.h"
#include "memory.h"
#include "object.h"
#include "intobject.h"
#include "floatobject.h"
#include "listobject.h"

int main(int argc, char *argv[])
{
    DfListObj *list;
    DfListObj *get_list;
    DfObject *object = NULL;
    DfIntObj *num = DF_MEM_ALLOC(sizeof(DfIntObj));
    DfIntObj *get_num;
    DfFloatObj *f_num =  DF_MEM_ALLOC(sizeof(DfFloatObj));
    DfFloatObj *get_f_num;

    printf("List object test starts...\n");

    num->val = 1923;
    f_num->val = 3.1415;
    list = df_list_obj_init();
    list->overallocate = true;

    df_list_obj_extend(list, object);
    df_list_obj_extend(list, (DfObject *)num);
    df_list_obj_extend(list, (DfObject *)f_num);
    /* Put the list as an element of itself */
    df_list_obj_extend(list, (DfObject *)list);

    printf("Code:\n---- count: %u \n"
           "---- capacity %u \n",
           list->count,
           list->capacity);

    get_num = (DfIntObj *)list->items[list->count - 3];
    printf("Integer:\n ---- n=%d\n", get_num->val);

    get_f_num = (DfFloatObj *)list->items[list->count - 2]; 
    printf("Float:\n ---- n=%f\n", get_f_num->val);

    get_list = (DfListObj *)list->items[list->count - 1];
    get_num = (DfIntObj *)get_list->items[get_list->count - 3]; 
    printf("Integer again:\n ---- n=%d\n", get_num->val);

    DF_MEM_FREE(num);
    DF_MEM_FREE(f_num);
    df_list_obj_clear(list);

    printf("Success");

    return 0;
}
