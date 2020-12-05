#include "difengine.h"
#include "defines.h"
#include "parser.h"

int main(int argc, char *argv[])
{
    DfTree *x = NULL;
    const char *inp_str = "val = (-12 + 2)*val - 31/2 + \"str\"";

    printf("expr: %s;\n", inp_str);
    DfLexer *lexer = df_lexer_init_from_str(inp_str);

    DfParser *parser = df_parser_init(lexer);

    df_parser_proceed(parser);
    x = df_parser_precedence(parser, P_ASSIGNMENT);
    df_parser_expect(parser, TENDOF, "end of file");

    df_ast_print(x, 0);

    printf("RES: Success\n");

    return 0;
}
