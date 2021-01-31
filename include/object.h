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

#define DF_INC_RF(obj) ((obj)->rfcnt++)
#define DF_DEC_RF(obj) ((obj)->rfcnt--)

typedef struct df_container
{
    DfObject_CONT_HEAD;
} DfContObject;

typedef DfObject* (*unaryop)(DfObject*);
typedef DfObject* (*binaryop)(DfObject*, DfObject*);
typedef DfObject* (*ternaryop)(DfObject*, DfObject*);
typedef void (*voidunaryop)(DfObject*);
typedef int (*intunaryop)(DfObject*);
typedef int (*intbinaryop)(DfObject*, DfObject*);
typedef int (*intternaryop)(DfObject*, DfObject*, DfObject*);
typedef uint32_t (*hashop)(DfObject*);
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
    intbinaryop del;
    ternaryop insert;
} DfAssContOps;

typedef struct df_type
{
    char *name; /* type name*/
    int size; /* size of an object of this type*/
    int item_size; /* size of an item of an object of this type */

    voidunaryop destroy;
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
 * Allocate new object of given type.
 *
 * @return
 *   new object of given type
 */
extern DfObject *df_obj_new(DfType *type);

/**
 * Allocate new container object of given type and size.
 *
 * @return
 *   new & empty container object of given size and type
 */
extern DfObject *df_obj_new_cont(DfType *type, int size);

/**
 * Calculate hash code of an object
 *
 * @return
 *   hash code of an object
 */
extern uint32_t df_obj_hash(DfObject *obj);

/**
 * Compare two objects
 *
 * @return
 *   0 if obj(a) == obj(b), -1 if obj(a) < obj(b), 1 if obj(a) > obj(b)
 */
extern int df_obj_compare(DfObject *a, DfObject *b);

/**
 * Print string representation of an object to stdout.
 * Flags are now just one flag whether to put newline or not.
 * Use flags = 1 to get newline.
 *
 * @return
 *   error code
 */
extern int df_obj_print(DfObject *obj, int flags);

/**
 * Destroy an object.
 */
extern void df_obj_destroy(DfObject *obj);

#ifdef __cplusplus
}
#endif

#endif /* DF_OBJECT_H_ */
