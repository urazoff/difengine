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
 * Get token name.
 *
 * @return
 *   token name
 */
extern char* df_lexer_token_name(int token);

/**
 * Allocate new lexer state struct and initialize it.
 *
 * @return
 *   new&empty lexer state struct
 */
extern DfLexer* df_lexer_init();

/**
 * Free lexer.
 */
extern void df_lexer_free(DfLexer *lexer);

/**
 * Create and set up lexer for string processing.
 *
 * @return
 *   new lexer state struct
 */
extern DfLexer* df_lexer_init_from_str(const char *str);

/**
 * Get next token from lexer
 *
 * @return
 *   next token
 */
extern int df_lexer_get(DfLexer *lexer, const char **start, const char **end);

#ifdef __cplusplus
}
#endif

#endif /* DF_LEXER_H_ */
