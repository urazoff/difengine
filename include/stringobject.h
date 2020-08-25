#ifndef _DF_STRINGOBJECT_H_
#define _DF_STRINGOBJECT_H_

#include "object.h"
#include "difengine.h"

/**
 * @file
 * String objects
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    DfObject obj;
    int size;
    uint32_t hash;
    char *chars;
} DfStrObj;

extern DfType DfStrType;

/**
 * Create string object out of C string
 *
 * @return
 *   string object
 */
DfStrObj* df_str_obj_from_str(char *chars);

#ifdef __cplusplus
}
#endif

#endif /* DF_STRINGOBJECT_H_ */
