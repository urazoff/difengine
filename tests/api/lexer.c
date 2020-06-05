#include "difengine.h"
#include "internal/tokens.h"
#include "lexer.h"

int main(int argc, char *argv[])
{
    const char *inp_str = "if (x != y) y = x + 3.1415; print(\'Hello\')";
    DfLexer *lexer = df_lexer_init_from_str(inp_str);
    const char *start = NULL;
    const char *end = NULL;
    int token;

    printf("expr: %s;\n", inp_str);
    for (;;)
    {
        token = df_lexer_get(lexer, &start, &end);
        printf("RES: %s\n", df_lexer_token_name(token));

        if (token == TENDOF || token == TERROR)
            break;
    }

    df_lexer_free(lexer);

    printf("RES: Success\n");

    return 0;
}
