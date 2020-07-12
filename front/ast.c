#include "ast.h"
#include "memory.h"

const char * const NodeTypes[] = {
    "MINUS",
    "PLUS",
    "DIVIDE",
    "MULTIPLY",
    "GREATER",
    "LESS",
    "GREATEREQ",
    "LESSEQ",
    "EQUALEQ",
    "NOTEQUAL",
    "IDENTIFIER",
    "STRING",
    "NUMBER",
    "IF",
    "OR",
    "IN",
    "AND",
    "NOT",
    "FOR",
    "NULL",
    "TRUE",
    "FALSE",
    "DEF",
    "WHILE",
    "BREAK",
    "CLASS",
    "RETURN",
    "CONTINUE",
    "EOF"
};

DfTree*
df_ast_new_node(int type, DfTree *left, DfTree *right)
{
    DfTree *t = DF_MEM_ALLOC(sizeof(DfTree));
    t->type = type;
    t->left = left;
    t->right = right;
    t->value = NULL;

    return t;
}

DfTree*
df_ast_new_leaf(int type, const char *value)
{
    DfTree *t = DF_MEM_ALLOC(sizeof(DfTree));
    t->type = type;
    t->left = NULL;
    t->right = NULL;
    t->value = (char *)value;

    return t;
}

void
df_ast_print(DfTree *t, int lvl)
{
    int i;

    for (i = 0; i < lvl; i++)
        printf("\t");

    printf("%d ", lvl++);
    if (t == NULL)
    {
        printf("None\n");
        return;
    }

    printf("%s", NodeTypes[t->type]);

    if (t->value != NULL)
    {
        printf(" = %s\n", t->value);
    }
    else
    {
        printf("\n");
        df_ast_print(t->left, lvl);
        df_ast_print(t->right, lvl);
    }
}
