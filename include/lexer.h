#ifndef _DF_LEXER_H_
#define _DF_LEXER_H_

#include "difengine.h"

/**
 * @file
 * Lexer interface
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char *buf;         /* input buffer */
    char *cur;         /* current character */
    const char *start; /* start of an lexeme */
    int line;          /* current line number */
    FILE *fp;          /* source code file if any*/
} DfLexer;

/**
 * Allocate new frame object and initialize it.
 *
 * @return
 *   new frame object
 */
extern DfLexer* df_lexer_init();

#ifdef __cplusplus
}
#endif

#endif /* DF_LEXER_H_ */
