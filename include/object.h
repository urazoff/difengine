#ifndef _DF_OBJECT_H_
#define _DF_OBJECT_H_

#include "difengine.h"

/**
 * @file
 * General object interface
 */

#ifdef __cplusplus
extern "C" {
#endif

#define Df_size_t size_t
#define DfType void*

#define DfDLList \
    struct df_object *next; \
    struct df_object *prev

typedef struct df_object
{   DfDLList;
    Df_size_t rfcnt;
    DfType    type;
} DfObject;

#ifdef __cplusplus
}
#endif

#endif /* DF_OBJECT_H_ */
