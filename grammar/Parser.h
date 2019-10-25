#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

#include "Absyn.h"

typedef union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Exp exp_;
} YYSTYPE;

typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
#define _ERROR_ 258
#define _SYMB_0 259
#define _SYMB_1 260
#define _SYMB_2 261
#define _SYMB_3 262
#define _SYMB_4 263
#define _SYMB_5 264
#define _INTEGER_ 265

extern YYLTYPE yylloc;
extern YYSTYPE yylval;
Exp  pExp(FILE *inp);
Exp psExp(const char *str);
Exp  pExp1(FILE *inp);
Exp psExp1(const char *str);
Exp  pExp2(FILE *inp);
Exp psExp2(const char *str);


#endif
