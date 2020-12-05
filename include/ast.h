#ifndef _DF_AST_H_
#define _DF_AST_H_

#include "difengine.h"

/**
 * @file
 * Abstract syntax tree
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    N_MINUS,
    N_PLUS,
    N_DIVIDE,
    N_MULTIPLY,
    N_GREATER,
    N_LESS,
    N_EQUAL,
    N_GREATEREQ,
    N_LESSEQ,
    N_EQUALEQ,
    N_NOTEQUAL,
    N_IDENTIFIER,
    N_STRING,
    N_NUMBER,
    N_IF,
    N_OR,
    N_IN,
    N_AND,
    N_NOT,
    N_FOR,
    N_NULL,
    N_TRUE,
    N_FALSE,
    N_DEF,
    N_WHILE,
    N_BREAK,
    N_CLASS,
    N_RETURN,
    N_CONTINUE,
    N_EOF
} DfNodeTypes;

typedef struct syntax_tree {
    int type;
    struct syntax_tree *left;
    struct syntax_tree *right;
    char *value;
} DfTree;

/**
 * Create new AST node.
 *
 * @return
 *   new AST node
 */
extern DfTree* df_ast_new_node(int type, DfTree *left,
                               DfTree *right);

/**
 * Create new AST leaf.
 *
 * @return
 *   new AST leaf
 */
extern DfTree* df_ast_new_leaf(int type, const char *value);

/**
 * Print AST in a pretty way.
 * For development only.
 */
extern void df_ast_print(DfTree *t, int lvl);

#ifdef __cplusplus
}
#endif

#endif /* DF_AST_H_ */
