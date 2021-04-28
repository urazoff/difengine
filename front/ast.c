#include "ast.h"
#include "memory.h"

const char * const NodeTypes[] = {
    "SEQUENCE",
    "MINUS",
    "PLUS",
    "DIVIDE",
    "MULTIPLY",
    "GREATER",
    "LESS",
    "ASSIGNMENT",
    "GREATEREQ",
    "LESSEQ",
    "EQUAL",
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
    "CALL",
    "LIST",
    "ITEM",
    "HASH",
    "WHILE",
    "BREAK",
    "CLASS",
    "RETURN",
    "CONTINUE",
    "EOF"
};

DfTree*
df_ast_new_node(int type, const char *value, int line)
{
    DfTree *t = DF_MEM_ALLOC(sizeof(DfTree));
    if (t == NULL)
        return NULL;

    t->type = type;
    t->children = NULL;
    t->degree = 0;
    t->value = (char *)value;
    t->line = line;

    return t;
}

#define AST_COEF 2
#define AST_CAPACITY(_x) \
    ((_x) == 1 ? 1 : ((_x) + AST_COEF - 1) / AST_COEF * AST_COEF)

DfTree*
df_ast_add_child(DfTree *parent, DfTree *child)
{
    if (AST_CAPACITY(parent->degree) < parent->degree + 1)
    {
        parent->children = DF_MEM_GROW_ARRAY(DfTree *, parent->children,
                                             parent->degree,
                                             AST_CAPACITY(parent->degree + 1));
    }

    parent->children[parent->degree++] = child;

    return parent;
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
        printf(" = %s\n", t->value);
    else
        printf("\n");

    for (i = 0; i < t->degree; i++)
        df_ast_print(t->children[i], lvl);
}

void
df_ast_free(DfTree *t)
{
	int i;

	for (i = t->degree; i > 0; i--)
		df_ast_free(t->children[i - 1]);

	if (t->children != NULL)
		DF_MEM_FREE(t->children);

	if (t->value != NULL)
		DF_MEM_FREE(t->value);

    DF_MEM_FREE(t);
}
