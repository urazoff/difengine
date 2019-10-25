/* This Bison file was machine-generated by BNFC */
%locations
%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Absyn.h"
typedef struct calc_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE calc_scan_string(const char *str);
void calc_delete_buffer(YY_BUFFER_STATE buf);
extern int yyparse(void);
extern int yylex(void);
extern int calc_init_lexer(FILE * inp);
extern void yyerror(const char *str);

Exp YY_RESULT_Exp_ = 0;

Exp pExp(FILE *inp)
{
  calc_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}
Exp psExp(const char *str)
{
  YY_BUFFER_STATE buf;
  calc_init_lexer(0);
  buf = calc_scan_string(str);
  int result = yyparse();
  calc_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp1(FILE *inp)
{
  calc_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}
Exp psExp1(const char *str)
{
  YY_BUFFER_STATE buf;
  calc_init_lexer(0);
  buf = calc_scan_string(str);
  int result = yyparse();
  calc_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp2(FILE *inp)
{
  calc_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}
Exp psExp2(const char *str)
{
  YY_BUFFER_STATE buf;
  calc_init_lexer(0);
  buf = calc_scan_string(str);
  int result = yyparse();
  calc_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}



%}

%union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Exp exp_;

}

%token _ERROR_
%token _SYMB_0    /*   +   */
%token _SYMB_1    /*   -   */
%token _SYMB_2    /*   *   */
%token _SYMB_3    /*   /   */
%token _SYMB_4    /*   (   */
%token _SYMB_5    /*   )   */

%type <exp_> Exp
%type <exp_> Exp1
%type <exp_> Exp2

%token<int_> _INTEGER_

%start Exp
%%
Exp : Exp _SYMB_0 Exp1 { $$ = make_EAdd($1, $3); YY_RESULT_Exp_= $$; }
  | Exp _SYMB_1 Exp1 { $$ = make_ESub($1, $3); YY_RESULT_Exp_= $$; }
  | Exp1 { $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp1 : Exp1 _SYMB_2 Exp2 { $$ = make_EMul($1, $3); YY_RESULT_Exp_= $$; }
  | Exp1 _SYMB_3 Exp2 { $$ = make_EDiv($1, $3); YY_RESULT_Exp_= $$; }
  | Exp2 { $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp2 : _INTEGER_ { $$ = make_EInt($1); YY_RESULT_Exp_= $$; }
  | _SYMB_4 Exp _SYMB_5 { $$ = $2; YY_RESULT_Exp_= $$; }
;

%%
void yyerror(const char *str)
{
  extern char *calctext;
  fprintf(stderr,"error: %d,%d: %s at %s\n",
  calclloc.first_line, calclloc.first_column, str, calctext);
}

