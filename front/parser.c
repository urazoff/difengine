#include "parser.h"
#include "memory.h"
#include "dferror.h"

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
static DfTree* atomic_rule(DfParser *parser);

/* Ordered according to internal/tokens.h */
DfParseRule parse_rules[] = {
  { grouping_rule, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1 },
  { NULL, NULL, P_NONE, -1 },
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { unary_rule, binary_rule, P_TERM, N_MINUS},
  { NULL, binary_rule, P_TERM, N_PLUS},
  { NULL, NULL, P_NONE, -1},
  { NULL, binary_rule, P_FACTOR, N_DIVIDE},
  { NULL, binary_rule, P_FACTOR, N_MULTIPLY},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, binary_rule, P_ASSIGNMENT, N_EQUAL},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { atomic_rule, NULL, P_NONE, N_IDENTIFIER},
  { atomic_rule, NULL, P_NONE, N_STRING},
  { atomic_rule, NULL, P_NONE, N_NUMBER},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
  { NULL, NULL, P_NONE, -1},
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
        x = df_ast_new_node(node_type, x, node);
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

    x = df_ast_new_node(node_type, node, NULL);

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
    x = df_ast_new_leaf(node_type, value);

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
