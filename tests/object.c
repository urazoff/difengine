#include <stdio.h>
#include "difengine.h"
#include "object.h"

int main(int argc, char *argv[])
{
    DfObject object;

    printf("Object test starts...");

    object.rfcnt = 4;

    printf("Object layout:\n ---- rfcnt:  %zu \n",
           object.rfcnt);

    printf("Success");

    return 0;
}
