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

typedef struct df_type DfType;

#define Df_size_t size_t

#define DfObject_CONT_HEAD \
    DfObject obj;          \
    int count;             \
    int capacity;          \
    int overallocate

#define DfDLList \
    struct df_object *next; \
    struct df_object *prev

typedef struct df_object
{   DfDLList;
    Df_size_t rfcnt;
    DfType *type;
} DfObject;

typedef struct df_container
{
    DfObject_CONT_HEAD;
} DfContObject;

typedef DfObject* (*unaryop)(DfObject*);
typedef DfObject* (*binaryop)(DfObject*, DfObject*);
typedef int (*intunaryop)(DfObject*);
typedef int (*intbinaryop)(DfObject*, DfObject*);
typedef int (*intternaryop)(DfObject*, DfObject*, DfObject*);
typedef long (*hashop)(DfObject*);
typedef DfObject* (*getter)(DfObject*, char*);
typedef int (*setter)(DfObject*, DfObject*, char*);

/* operations for numeric types */
typedef struct
{
    unaryop neg;
    unaryop abs;
    binaryop add;
    binaryop sub;
    binaryop mul;
    binaryop div;
} DfNumOps;

typedef struct
{
    intunaryop length;
    binaryop concat;
} DfContOps;

typedef struct
{
    binaryop find;
    intternaryop insert;
} DfAssContOps;

typedef struct df_type
{
    char *name; /* type name*/
    int size; /* size of an object of this type*/
    int item_size; /* size of an item of an object of this type */

    intunaryop destroy;
    hashop hash;
    intunaryop print;
    intbinaryop compare;
    getter get;
    setter set;

    DfNumOps *as_numeric;
    DfContOps *as_container;
    DfAssContOps *as_associative;
} DfType;

/**
 * Allocate new list object and initialize it.
 *
 * @return
 *   new&empty list object
 */
extern DfObject *df_obj_new(DfType *type);

/**
 * Allocate new list object and initialize it.
 *
 * @return
 *   new&empty list object
 */
extern DfObject *df_obj_new_cont(DfType *type, int size);

#ifdef __cplusplus
}
#endif

#endif /* DF_OBJECT_H_ */
