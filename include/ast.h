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
    N_SEQUENCE,
    N_MINUS,
    N_PLUS,
    N_DIVIDE,
    N_MULTIPLY,
    N_GREATER,
    N_LESS,
    N_ASSIGNMENT,
    N_GREATEREQ,
    N_LESSEQ,
    N_EQUAL,
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
    N_CALL,
    N_LIST,
    N_ITEM,
    N_WHILE,
    N_BREAK,
    N_CLASS,
    N_RETURN,
    N_CONTINUE,
    N_EOF
} DfNodeTypes;

typedef struct syntax_tree {
    int type;
    char *value;
    int degree;
    struct syntax_tree **children;
} DfTree;

/**
 * Create new AST node.
 *
 * @return
 *   new AST node
 */
extern DfTree* df_ast_new_node(int type, const char *value);

/**
 * Add AST child.
 *
 * @return
 *   AST parent
 */
extern DfTree* df_ast_add_child(DfTree *parent, DfTree *child);

/**
 * Print AST in a pretty way.
 * For development only.
 */
extern void df_ast_print(DfTree *t, int lvl);

/**
 * Free whole tree
 */
extern void df_ast_free(DfTree *t);

#ifdef __cplusplus
}
#endif

#endif /* DF_AST_H_ */
