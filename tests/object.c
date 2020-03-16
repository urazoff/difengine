#include <stddef.h>
#include <stdio.h>
#include "../include/object.h"
#include "../include/defines.h"

int main(int argc, char *argv[])
{
    DfObject unused_object;
    DfObject object;

    UNUSED(unused_object); 

    object.rfcnt = 4;

    printf("Object layout:\n ---- rfcnt:  %zu \n",
           object.rfcnt);  
 
    printf("Success");
}
