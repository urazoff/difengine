#ifndef _DF_MEMORY_H_
#define _DF_MEMORY_H_

/**
 * @file
 * Memory allocation routine
 */

#ifdef __cplusplus
extern "C" {
#endif

#define DF_MEM_GROW_ARRAY(_type, _prev, _old_num, _num) \
        (_type*) df_realloc(_prev, sizeof(_type) * _old_num, \
                            sizeof(_type) * _num)

void *df_realloc(void *prev, size_t old_size, size_t new_size);

#ifdef __cplusplus
}
#endif

#endif /* DF_MEMORY_H_ */
