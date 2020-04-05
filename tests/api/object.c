#include <stdio.h>
#include "difengine.h"
#include "object.h"

int main(int argc, char *argv[])
{
    DfObject object;

    object.rfcnt = 4;

    printf("Object layout:\n ---- rfcnt:  %zu \n",
           object.rfcnt);

    printf("RES: Success\n");

    return 0;
}
