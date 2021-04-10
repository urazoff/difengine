#include "difengine.h"
#include "defines.h"
#include "parser.h"

int main(int argc, char *argv[])
{
    DfTree *x = NULL;
    const char *inp_str = "x = \"string\";"
                          "\nA = [[1, y], [3.5, 3*4-2]];"
                          "\ndef foo(x)\n"
                          "{\n    return 2/x;\n}"
                          "\nfor x in A\n"
                          "\nprint(foo(x));"
                          "\nH = {a : b, 'str' : 4};";

    printf("block:\n%s\n", inp_str);
    DfLexer *lexer = df_lexer_init_from_str(inp_str);

    DfParser *parser = df_parser_init(lexer);

    x = df_parser_parse(parser);

    printf("AST:\n");
    df_ast_print(x, 0);
    df_ast_free(x);

    printf("RES: Success\n");

    return 0;
}
