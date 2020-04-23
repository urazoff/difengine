#include "internal/tokens.h"
#include "memory.h"
#include "lexer.h"

/**
 * Recognize single character token.
 *
 * @return
 *   token type
 */
static int
df_token_single(char c)
{
    switch (c)
    {
        case '(': return LPAREN;
        case ')': return RPAREN;
        case '{': return LBRACE;
        case '}': return RBRACE;
        case ',': return COMMA;
        case '.': return DOT;
        case '-': return MINUS;
        case '+': return PLUS;
        case ';': return SEMICOLON;
        case '/': return SLASH;
        case '*': return ASTERISK;
        case '>': return GREATER;
        case '<': return LESS;
        case '=': return EQUAL;
    }

    return TERROR;
}

/**
 * Recognize two-character token.
 *
 * @return
 *   token type
 */
static int
df_token_two(char c1, char c2)
{
#define WITH_EQUAL(_token) \
    do {                              \
        if (c2 == '=') return _token; \
        break;                        \
    } while (0)

    switch(c1)
    {
        case '>': WITH_EQUAL(GREATEREQ);
        case '<': WITH_EQUAL(LESSEQ);
        case '=': WITH_EQUAL(EQUALEQ);
        case '!': WITH_EQUAL(NOTEQUAL);
    }

    return TERROR;
}

DfLexer*
df_lexer_init()
{
    DfLexer *lexer = DF_MEM_ALLOC(sizeof(DfLexer));

    lexer->buf = NULL;
    lexer->cur = NULL;
    lexer->start = NULL;
    lexer->line = 0;
    lexer->fp = NULL;

    return lexer;
}
