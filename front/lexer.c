#include "internal/tokens.h"
#include "memory.h"
#include "lexer.h"
#include "dferror.h"

const char * const DfTokenNames[] = {
    "LPAREN",
    "RPAREN",
    "LBRACE",
    "RBRACE",
    "COMMA",
    "DOT",
    "MINUS",
    "PLUS",
    "SEMICOLON",
    "SLASH",
    "ASTERISK",
    "GREATER",
    "LESS",
    "EQUAL",
    "GREATEREQ",
    "LESSEQ",
    "EQUALEQ",
    "NOTEQUAL",
    "IDENTIFIER",
    "STRING",
    "NUMBER",
    "K_IF",
    "K_OR",
    "K_IN",
    "K_AND",
    "K_NOT",
    "K_FOR",
    "K_DEF",
    "K_NULL",
    "K_TRUE",
    "K_FALSE",
    "K_WHILE",
    "K_BREAK",
    "K_CLASS",
    "K_RETURN",
    "K_CONTINUE",
    "TERROR",
    "TENDOF"
};

static int max_keyword_len = 8;
static DfKeyWord *keywords[] = {
    NULL,
    NULL,
    (DfKeyWord[]) {
        {"if", K_IF},
        {"or", K_OR},
        {"in", K_IN},
        {NULL, -1}
    },
    (DfKeyWord[]) {
        {"and", K_AND},
        {"not", K_NOT},
        {"for", K_FOR},
        {"def", K_DEF},
        {NULL, -1}
    },
    (DfKeyWord[]) {
        {"Null", K_NULL},
        {"True", K_TRUE},
        {NULL, -1}
    },
    (DfKeyWord[]) {
        {"False", K_FALSE},
        {"while", K_WHILE},
        {"break", K_BREAK},
        {"class", K_CLASS},
        {NULL, -1}
    },
    (DfKeyWord[]) {
        {"return", K_RETURN},
        {NULL, -1}
    },
    NULL,
    (DfKeyWord[]) {
        {"continue", K_CONTINUE},
        {NULL, -1}
    }
};

char *
df_lexer_token_name(int token)
{
    return (char *)DfTokenNames[token];
}

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
    lexer->error = 0;

    return lexer;
}

void
df_lexer_free(DfLexer *lexer)
{
    if (lexer->fp != NULL && lexer->buf != NULL)
        DF_MEM_FREE(lexer->buf);

    DF_MEM_FREE(lexer);
}

DfLexer*
df_lexer_init_from_str(const char *str)
{
    DfLexer *lexer = df_lexer_init();

    lexer->buf = lexer->cur = (char *)str;
    lexer->start = str;
    lexer->line = 1;

    return lexer;
}

DfLexer*
df_lexer_init_from_file(FILE *fp)
{
    DfLexer *lexer = df_lexer_init();

    if (lexer == NULL)
        return NULL;

    lexer->buf = (char *)DF_MEM_ALLOC(BUFSIZ);
    if (lexer->buf == NULL)
    {
        df_lexer_free(lexer);
        return NULL;
    }

    lexer->cur = lexer->buf;
    lexer->fp = fp;

    return lexer;
}

static char
df_lexer_nextc(DfLexer *lexer)
{
    lexer->cur++;
    return lexer->cur[-1];
}

static void
df_lexer_back(DfLexer *lexer)
{
    lexer->cur--;
}

static void
df_lexer_skip(DfLexer *lexer)
{
    char c;

#define SKIP_CHAR() \
    do {              \
        lexer->cur++; \
    } while (0)

    for (;;)
    {
        c = *lexer->cur;

        /* Encounter new line */
        if (c == '\n')
        {
            lexer->line++;
            SKIP_CHAR();
            continue;
        }

        /* Skip spaces */
        if (c == ' ' || c == '\r' || c == '\t' || c == '\014')
        {
            SKIP_CHAR();
            continue;
        }

        /* Skip comments. Comment ends when line ends. */
        if (c == '#')
        {
            do {
                SKIP_CHAR();
                c = *lexer->cur;
            } while (c != '\n');
            continue;
        }

        return;
    }
#undef SKIP_CHAR
}

static int
can_be_ident_start(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
            c == '_';
}

static int
can_be_ident_char(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9') ||
            c == '_';
}

static int
is_digit(char c)
{
    return c >= '0' && c <= '9';
}

static int
tok_if_keyword(const char *ident, int len)
{
    /* can be a keyword? */
    if (keywords[len] == NULL || len > max_keyword_len)
        return IDENTIFIER;

    for (DfKeyWord *keyword = keywords[len]; keyword->token != -1; keyword++)
    {
        if (strncmp(keyword->str, ident, len) == 0)
            return keyword->token;
    }

    return IDENTIFIER;
}

int
df_lexer_get(DfLexer *lexer, const char **start, const char **end)
{
    char c;
    char c2;
    int token;

    *start = *end = NULL;

    /* Skip spaces and comments */
    df_lexer_skip(lexer);
    lexer->start = lexer->cur;

    c = df_lexer_nextc(lexer);

    if (c == '\0')
        return TENDOF;

    /* Handle identifier */
    if (can_be_ident_start(c))
    {
        while(can_be_ident_char(c))
            c = df_lexer_nextc(lexer);

        df_lexer_back(lexer);
        *start = lexer->start;
        *end = lexer->cur;

        return tok_if_keyword(*start, (int)(*end - *start));
    }

    /* Handle number */
    if (is_digit(c))
    {
        do {
            c = df_lexer_nextc(lexer);
        } while (is_digit(c));

        if (c == '.')
        {
            do {
                c = df_lexer_nextc(lexer);
            } while (is_digit(c));
        }

        df_lexer_back(lexer);
        *start = lexer->start;
        *end = lexer->cur;

        return NUMBER;
    }

    /* Handle string */
    if (c == '\'' || c == '"')
    {
        char quote = c;
        do {
            c = df_lexer_nextc(lexer);
        } while (c != quote && c != '\0');

        if (c == '\0')
        {
            lexer->error = ESTRING;
            return TERROR;
        }

        *start = lexer->start;
        *end = lexer->cur;

        return STRING;
    }

    /* Two-character token */
    c2 = df_lexer_nextc(lexer);
    token = df_token_two(c, c2);
    if (token != TERROR)
    {
        return token;
    }
    df_lexer_back(lexer);

    /* Punctuation character */
    *start = lexer->start;
    *end = lexer->cur;
    return df_token_single(c);
}
