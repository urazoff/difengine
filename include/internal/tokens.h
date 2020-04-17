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
    /* utility tokens */
    ERROR,
    ENDOF
} DfTokens;

#ifdef __cplusplus
}
#endif

#endif /* DF_TOKENS_H_ */
