#include "parser.h"
#include "memory.h"
#include "dferror.h"

#define LINENO parser->tok_prev->line

static void
df_parser_error(DfParser *parser, DfToken *token, const char *err_msg,
                ...)
{
    va_list va;
    char buf[1000];

    if (parser->panic_mode == 1)
        return;

    parser->panic_mode = 1;
    parser->error_indicator = 1;

    va_start(va, err_msg);
    vsprintf(buf, err_msg, va);
    va_end(va);

    fprintf(stderr, "SYNTAX_ERROR at %zd: %s", token->line, buf);
}

static int
df_lexer_error(DfParser *parser, DfToken *token)
{
    const char *err_msg = NULL;

    switch (parser->lexer->error)
    {
        case ETOKEN:
        {
            err_msg = "Invalid token";
            break;
        }

        case ESTRING:
        {
            err_msg = "Error in string processing";
            break;
        }
    }

    df_parser_error(parser, token, err_msg);
    return -1;
}

static int
df_parser_fill_token(DfParser *parser)
{
    const char *start;
    const char *end;
    DfToken *token = DF_MEM_ALLOC(sizeof(DfToken));
    int type = df_lexer_get(parser->lexer, &start, &end);

    token->type = type;
    token->start = start;
    token->length = (int)(end - start);
    token->line = parser->lexer->line;

    parser->tok_prev = parser->tok_cur;
    parser->tok_cur = token;

    if (type == TERROR)
        return df_lexer_error(parser, token);

    return 0;
}

static DfTree* unary_rule(DfParser *parser);
static DfTree* binary_rule(DfParser *parser);
static DfTree* grouping_rule(DfParser *parser);
static DfTree* list_rule(DfParser *parser);
static DfTree* hash_rule(DfParser *parser);
static DfTree* call_rule(DfParser *parser);
static DfTree* item_rule(DfParser *parser);
static DfTree* atomic_rule(DfParser *parser);

/* Ordered according to internal/tokens.h */
DfParseRule parse_rules[] = {
  { grouping_rule, call_rule, P_CALL, N_CALL},
  { NULL, NULL, P_NONE, -1 },
  { hash_rule, NULL, P_NONE, -1 },
  { NULL, NULL, P_NONE, -1 },
  { list_rule, item_rule, P_CALL, N_ITEM},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { unary_rule, binary_rule, P_TERM, N_MINUS},
  { NULL, binary_rule, P_TERM, N_PLUS},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, binary_rule, P_FACTOR, N_DIVIDE},
  { NULL, binary_rule, P_FACTOR, N_MULTIPLY},
  { NULL, binary_rule, P_COMPARISON, N_GREATER},
  { NULL, binary_rule, P_COMPARISON, N_LESS},
  { NULL, binary_rule, P_ASSIGNMENT, N_ASSIGNMENT},
  { NULL, binary_rule, P_COMPARISON, N_GREATEREQ},
  { NULL, binary_rule, P_COMPARISON, N_LESSEQ},
  { NULL, binary_rule, P_COMPARISON, N_EQUAL},
  { NULL, binary_rule, P_COMPARISON, N_NOTEQUAL},
  { atomic_rule, NULL, P_NONE, N_IDENTIFIER},
  { atomic_rule, NULL, P_NONE, N_STRING},
  { atomic_rule, NULL, P_NONE, N_NUMBER},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, binary_rule, P_OR, N_OR},
  { NULL, NULL, P_NONE, -1},
  { NULL, binary_rule, P_AND, N_AND},
  { unary_rule, NULL, P_NONE, N_NOT},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { atomic_rule, NULL, P_NONE, N_NULL},
  { atomic_rule, NULL, P_NONE, N_TRUE},
  { atomic_rule, NULL, P_NONE, N_FALSE},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, N_EOF}
};

void
df_parser_proceed(DfParser *parser)
{
    int ret;

    for (ret = -1; ret == -1; ret = df_parser_fill_token(parser));
}

void
df_parser_expect(DfParser *parser, int token, const char *err_msg)
{
    if (parser->tok_cur->type == token)
    {
        df_parser_proceed(parser);
        return;
    }

    df_parser_error(parser, parser->tok_cur, "Expected %s", err_msg);
}

static DfParseRule*
df_parser_get_rule(int token)
{
    return &parse_rules[token];
}

DfTree*
df_parser_precedence(DfParser *parser, int precedence)
{
    DfTree *x = NULL;
    DfTree *node = NULL;
    int node_type;

    df_parser_proceed(parser);

    func prefix = df_parser_get_rule(parser->tok_prev->type)->prefix;
    if (prefix == NULL)
    {
        df_parser_error(parser, parser->tok_prev, "Expected expression");
        return NULL;
    }

    x = prefix(parser);

    while (precedence <= df_parser_get_rule(parser->tok_cur->type)->precedence)
    {
        df_parser_proceed(parser);
        func infix = df_parser_get_rule(parser->tok_prev->type)->infix;
        node_type = df_parser_get_rule(parser->tok_prev->type)->node_type;
        node = infix(parser);
        DfTree *y = df_ast_new_node(node_type, NULL, LINENO);
        y = df_ast_add_child(y, x);
        x = df_ast_add_child(y, node);
    }

    return x;
}

static DfTree*
unary_rule(DfParser *parser)
{
    DfTree *x = NULL;
    DfTree *node = NULL;
    int type = parser->tok_prev->type;
    int node_type;

    node = df_parser_precedence(parser, P_UNARY);
    node_type = df_parser_get_rule(type)->node_type;

    x = df_ast_new_node(node_type, NULL, LINENO);
    x = df_ast_add_child(x, node);

    return x;
}

static DfTree*
binary_rule(DfParser *parser)
{
    DfTree *node = NULL;
    int type = parser->tok_prev->type;

    node = df_parser_precedence(parser, df_parser_get_rule(type)->precedence + 1);

    return node;
}

static DfTree*
grouping_rule(DfParser *parser)
{
    DfTree *x = NULL;

    x = df_parser_precedence(parser, P_OR);
    df_parser_expect(parser, RPAREN, "')' after expression");

    return x;
}

static DfTree*
atomic_rule(DfParser *parser)
{
    DfTree *x = NULL;
    int type = parser->tok_prev->type;
    int node_type;
    char *value;

    node_type = df_parser_get_rule(type)->node_type;

    value = DF_MEM_ALLOC((parser->tok_prev->length + 1) * sizeof(char));
    strncpy(value, parser->tok_prev->start, parser->tok_prev->length);
    value[parser->tok_prev->length] = '\0';
    x = df_ast_new_node(node_type, value, LINENO);

    return x;
}

static DfTree*
call_rule(DfParser *parser)
{
    DfTree *x = NULL;
    DfTree *arg = NULL;

    x = df_ast_new_node(N_SEQUENCE, NULL, LINENO);

    if (parser->tok_cur->type != RPAREN)
    {
        do {
            /* Skip comma */
            if (arg != NULL)
                df_parser_proceed(parser);
            arg = df_parser_precedence(parser, P_ASSIGNMENT);
            x = df_ast_add_child(x, arg);
        } while (parser->tok_cur->type == COMMA);
    }
    df_parser_expect(parser, RPAREN, "closing ')'");

    return x;
}

static DfTree*
list_rule(DfParser *parser)
{
    DfTree *x = NULL;
    DfTree *item = NULL;

    x = df_ast_new_node(N_LIST, NULL, LINENO);

    if (parser->tok_cur->type != RBRACKET)
    {
        do {
            /* Skip comma */
            if (item != NULL)
                df_parser_proceed(parser);
            item = df_parser_precedence(parser, P_ASSIGNMENT);
            x = df_ast_add_child(x, item);
        } while (parser->tok_cur->type == COMMA);
    }
    df_parser_expect(parser, RBRACKET, "closing ']'");

    return x;
}

static DfTree*
hash_rule(DfParser *parser)
{
    DfTree *x = NULL;
    DfTree *key = NULL;
    DfTree *value = NULL;

    x = df_ast_new_node(N_HASH, NULL, LINENO);

    if (parser->tok_cur->type != RBRACE)
    {
        do {
            /* Skip comma */
            if (value != NULL)
                df_parser_proceed(parser);
            key = df_parser_precedence(parser, P_ASSIGNMENT);
            df_parser_expect(parser, COLON, "':' between key and value");
            value = df_parser_precedence(parser, P_ASSIGNMENT);
            key = df_ast_add_child(key, value);
            x = df_ast_add_child(x, key);
        } while (parser->tok_cur->type == COMMA);
    }
    df_parser_expect(parser, RBRACE, "closing '}'");

    return x;
}

/* TODO: support slice here */
static DfTree*
item_rule(DfParser *parser)
{
    DfTree *x = NULL;

    x = df_parser_precedence(parser, P_ASSIGNMENT);

    df_parser_expect(parser, RBRACKET, "closing ']'");

    return x;
}

DfParser*
df_parser_init(DfLexer *lexer)
{
    DfParser *parser = DF_MEM_ALLOC(sizeof(DfParser));

    parser->lexer = lexer;
    parser->error_indicator = 0;
    parser->panic_mode = 0;
    parser->tok_cur = NULL;
    parser->tok_prev = NULL;

    return parser;
}

DfTree* df_parser_stmt(DfParser *parser);

DfTree*
df_parser_stmt_block(DfParser *parser)
{
    DfTree *x = NULL;
    DfTree *s = NULL;

    x = df_ast_new_node(N_SEQUENCE, NULL, LINENO);
    df_parser_proceed(parser);
    while (parser->tok_cur->type != TENDOF && parser->tok_cur->type != RBRACE)
    {
        s = df_parser_stmt(parser);
        x = df_ast_add_child(x, s);
    }
    df_parser_expect(parser, RBRACE, "closing '}'");

    return x;
}

DfTree*
df_parser_stmt(DfParser *parser)
{
    DfTree *x = NULL;
    DfTree *e = NULL;
    DfTree *s = NULL;
    DfTree *y = NULL;

#define PARSE_CONDITION(_k) \
    do {                                                            \
        df_parser_proceed(parser);                                  \
        df_parser_expect(parser, LPAREN, "'(' after "_k" keyword"); \
        e = df_parser_precedence(parser, P_ASSIGNMENT);             \
        df_parser_expect(parser, RPAREN, "closing ')'");            \
    } while (0)

    switch (parser->tok_cur->type)
    {
        case LBRACE:
            x = df_parser_stmt_block(parser);
            break;

        case K_IF:
            PARSE_CONDITION("IF");
            s = df_parser_stmt(parser);
            x = df_ast_add_child(df_ast_new_node(N_IF, NULL, LINENO), e);
            x = df_ast_add_child(x, s);

            while (parser->tok_cur->type == K_ELIF)
            {
                PARSE_CONDITION("ELIF");
                s = df_parser_stmt(parser);
                y = df_ast_add_child(df_ast_new_node(N_IF, NULL, LINENO), e);
                y = df_ast_add_child(y, s);
                x = df_ast_add_child(x, y);
            }

            if (parser->tok_cur->type == K_ELSE)
            {
                df_parser_proceed(parser);
                s = df_parser_stmt(parser);
                x = df_ast_add_child(x, s);
            }
            break;

        case K_FOR:
            df_parser_proceed(parser);
            e = df_parser_precedence(parser, P_ASSIGNMENT);
            if (e->type != N_IDENTIFIER)
                df_parser_expect(parser, -1,
                                "IDENTIFIER after FOR keyword");
            df_parser_expect(parser, K_IN, "IN in FOR statement");
            y = df_parser_precedence(parser, P_ASSIGNMENT);
            x = df_ast_add_child(df_ast_new_node(N_FOR, NULL, LINENO), e);
            x = df_ast_add_child(x, y);
            s = df_parser_stmt(parser);
            x = df_ast_add_child(x, s);
            break;

        case K_WHILE:
            PARSE_CONDITION("WHILE");
            s = df_parser_stmt(parser);
            x = df_ast_add_child(df_ast_new_node(N_WHILE, NULL, LINENO), e);
            x = df_ast_add_child(x, s);
            break;

        case K_RETURN:
            df_parser_proceed(parser);
            x = df_ast_new_node(N_RETURN, NULL, LINENO);
            if (parser->tok_cur->type == SEMICOLON)
            {
                df_parser_proceed(parser);
                break;
            }

            e = df_parser_precedence(parser, P_ASSIGNMENT);
            df_parser_expect(parser, SEMICOLON, "';' after expression");
            x = df_ast_add_child(x, e);
            break;

        case TENDOF:
            return NULL;

        default:
            x = df_parser_precedence(parser, P_ASSIGNMENT);
            df_parser_expect(parser, SEMICOLON, "';' after expression");
    }

    return x;
}

DfTree* df_parser_decl(DfParser *parser);

DfTree*
df_parser_decl_block(DfParser *parser)
{
    DfTree *x = NULL;
    DfTree *d = NULL;

    x = df_ast_new_node(N_SEQUENCE, NULL, LINENO);
    while (parser->tok_cur->type != TENDOF && parser->tok_cur->type != RBRACE)
    {
        d = df_parser_decl(parser);
        x = df_ast_add_child(x, d);
    }
    df_parser_expect(parser, RBRACE, "closing '}'");

    return x;
}

DfTree*
df_parser_decl(DfParser *parser)
{
    DfTree *x = NULL;
    DfTree *e = NULL;
    DfTree *d = NULL;

    switch (parser->tok_cur->type)
    {
        case K_CLASS:
            break;

        case K_DEF:
            df_parser_proceed(parser);
            e = df_parser_precedence(parser, P_ASSIGNMENT);
            if (e->type != N_CALL)
                df_parser_expect(parser, -1,
                                "'<name>(<args>)' after DEF keyword");
            x = df_ast_add_child(df_ast_new_node(N_DEF, NULL, LINENO), e);
            df_parser_expect(parser, LBRACE,
                                "'{' in function declaration");
            d = df_parser_decl_block(parser);
            x = df_ast_add_child(x, d);
            break;

        default:
            x = df_parser_stmt(parser);
    }

    return x;
}

DfTree*
df_parser_parse(DfParser *parser)
{
    DfTree *x = NULL;

    x = df_ast_new_node(N_SEQUENCE, NULL, 0);

    for (df_parser_proceed(parser); parser->tok_cur->type != TENDOF; )
        x = df_ast_add_child(x, df_parser_decl(parser));

    return x;
}
