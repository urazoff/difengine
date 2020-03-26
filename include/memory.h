#ifndef _DF_MEMORY_H_
#define _DF_MEMORY_H_

/**
 * @file
 * Memory allocation routine
 */

#ifdef __cplusplus
extern "C" {
#endif

#define DF_MEM_ALLOC(_size) \
    df_realloc(NULL, 0, _size);

#define DF_MEM_FREE(_ptr) \
    df_realloc(_ptr, 0, 0);

#define DF_MEM_FREE_ARRAY(_type, _ptr, _num) \
    df_realloc(_ptr, sizeof(_type) * _num, 0);

#define DF_MEM_GROW_ARRAY(_type, _prev, _old_num, _num)  \
    (_type*) df_realloc(_prev, sizeof(_type) * _old_num, \
                        sizeof(_type) * _num)

void *df_realloc(void *prev, size_t old_size, size_t new_size);

#ifdef __cplusplus
}
#endif

#endif /* DF_MEMORY_H_ */
