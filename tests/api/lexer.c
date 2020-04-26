#include "difengine.h"
#include "internal/tokens.h"
#include "lexer.h"

int main(int argc, char *argv[])
{
    DfLexer *lexer = df_lexer_init_from_str("(x + 1);");
    const char *start = NULL;
    const char *end = NULL;
    int token;

    printf("expr: \"(x+1);\"\n");
    for (;;)
    {
        token = df_lexer_get(lexer, &start, &end);
        printf("RES: %s\n", df_lexer_token_name(token));

        if (token == TENDOF)
            break;
    }

    printf("RES: Success\n");

    return 0;
}
