#ifndef _DF_PARSER_H_
#define _DF_PARSER_H_

#include "difengine.h"
#include "lexer.h"
#include "internal/tokens.h"
#include "ast.h"

/**
 * @file
 * Parser interface
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  P_NONE,
  P_ASSIGNMENT,
  P_OR,
  P_AND,
  P_EQUALITY,
  P_COMPARISON,
  P_TERM,
  P_FACTOR,
  P_UNARY,
  P_CALL,
  P_PRIMARY
} DfPrecedence;

struct df_parser;

typedef DfTree* (*func)(struct df_parser*);

typedef struct {
    func prefix;
    func infix;
    int precedence;
    int node_type; /* see ast.h */
} DfParseRule;

typedef struct df_parser {
    DfLexer *lexer;      /* lexer state */
    DfToken *tok_cur;    /* current token */
    DfToken *tok_prev;   /* previous token */
    int error_indicator; /* if error occured */
    int panic_mode;      /* panic mode error recovery */
} DfParser;

/**
 * Allocate new parser struct and initialize it.
 *
 * @return
 *   new parser
 */
extern DfParser* df_parser_init(DfLexer *lexer);

/**
 * Get next token.
 */
extern void df_parser_proceed(DfParser *parser);

/**
 * Expect some token.
 */
extern void df_parser_expect(DfParser *parser, int token, const char *err_msg);

/**
 * Parse code according to precedence.
 *
 * @return
 *   Abstract syntax tree
 */
extern DfTree* df_parser_precedence(DfParser *parser, int precedence);

#ifdef __cplusplus
}
#endif

#endif /* DF_PARSER_H_ */
