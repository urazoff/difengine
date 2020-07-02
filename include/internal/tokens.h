#ifndef _DF_TOKENS_H_
#define _DF_TOKENS_H_

#include "difengine.h"

/**
 * @file
 * Difengine token types
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int type;
    const char *start;
    ssize_t length;
    ssize_t line;
} DfToken;

typedef struct {
    char *str;   /* keyword itself */
    int token;   /* corresponding token type, see internal/tokens.h */
} DfKeyWord;

typedef enum {
    /* character tokens */
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    SLASH,
    ASTERISK,
    GREATER,
    LESS,
    EQUAL,
    GREATEREQ,
    LESSEQ,
    EQUALEQ,
    NOTEQUAL,
    /* literals */
    IDENTIFIER,
    STRING,
    NUMBER,
    /* reserved keywords */
    K_IF,
    K_OR,
    K_IN,
    K_AND,
    K_NOT,
    K_FOR,
    K_DEF,
    K_NULL,
    K_TRUE,
    K_FALSE,
    K_WHILE,
    K_BREAK,
    K_CLASS,
    K_RETURN,
    K_CONTINUE,
    /* utility tokens */
    TERROR,
    TENDOF
} DfTokens;

#ifdef __cplusplus
}
#endif

#endif /* DF_TOKENS_H_ */
