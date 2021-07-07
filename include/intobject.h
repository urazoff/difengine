#ifndef _DF_INTOBJECT_H_
#define _DF_INTOBJECT_H_

#include "object.h"
#include "difengine.h"

/**
 * @file
 * Integer numbers
 */

#ifdef __cplusplus
extern "C" {
#endif

#if DF_WSIZE == 64
typedef uint32_t df_digit;
typedef uint64_t df_word;
typedef int64_t df_sword;
#define DF_INT_BITS 30
#define DF_INT_DIGIT_SIZE 32
#elif DF_WSIZE == 32
typedef uint16_t df_digit;
typedef uint32_t df_word;
typedef int32_t df_sword;
#define DF_INT_BITS 15
#define DF_INT_DIGIT_SIZE 16
#endif
#define DF_INT_BASE ((df_digit)1 << DF_INT_BITS)
#define DF_INT_MASK (DF_INT_BASE - (df_digit)1)

typedef struct {
    DfObject_CONT_HEAD;
    df_digit *digits;
} DfIntObj;

extern DfType DfIntType;

/**
 * Create an integer object with <size> digits = 0.
 *
 * @return
 *   new integer object
 */
extern DfObject* df_int_obj_init(int size);

/**
 * Create an integer object from string of digits.
 * Works only for decimal strings now.
 *
 * @return
 *   new integer object
 */
extern DfObject* df_int_from_str(char *digits);

/**
 * Print number's digits in  DF_INT_BASE.
 * For debug purposes only.
 */
extern void df_int_print_digits(DfObject *a);

#ifdef __cplusplus
}
#endif

#endif /* DF_INTOBJECT_H_ */
