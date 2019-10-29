#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

#include "Absyn.h"

typedef union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Program program_;
  ListExternal_declaration listexternal_declaration_;
  External_declaration external_declaration_;
  Function function_;
  Arg arg_;
  Decl decl_;
  ListFunction listfunction_;
  ListStm liststm_;
  ListDecl listdecl_;
  ListArg listarg_;
  ListIdent listident_;
  Stm stm_;
  Exp exp_;
  ListExp listexp_;
  Type type_;
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
#define _SYMB_6 265
#define _SYMB_7 266
#define _SYMB_8 267
#define _SYMB_9 268
#define _SYMB_10 269
#define _SYMB_11 270
#define _SYMB_12 271
#define _SYMB_13 272
#define _SYMB_14 273
#define _SYMB_15 274
#define _SYMB_16 275
#define _SYMB_17 276
#define _SYMB_18 277
#define _SYMB_19 278
#define _SYMB_20 279
#define _SYMB_21 280
#define _SYMB_22 281
#define _SYMB_23 282
#define _SYMB_24 283
#define _SYMB_25 284
#define _SYMB_26 285
#define _SYMB_27 286
#define _SYMB_28 287
#define _SYMB_29 288
#define _SYMB_30 289
#define _SYMB_31 290
#define _INTEGER_ 291
#define _DOUBLE_ 292
#define _IDENT_ 293

extern YYLTYPE yylloc;
extern YYSTYPE yylval;
Program  pProgram(FILE *inp);
Program psProgram(const char *str);
ListExternal_declaration  pListExternal_declaration(FILE *inp);
ListExternal_declaration psListExternal_declaration(const char *str);
External_declaration  pExternal_declaration(FILE *inp);
External_declaration psExternal_declaration(const char *str);
Function  pFunction(FILE *inp);
Function psFunction(const char *str);
Arg  pArg(FILE *inp);
Arg psArg(const char *str);
Decl  pDecl(FILE *inp);
Decl psDecl(const char *str);
ListFunction  pListFunction(FILE *inp);
ListFunction psListFunction(const char *str);
ListStm  pListStm(FILE *inp);
ListStm psListStm(const char *str);
ListDecl  pListDecl(FILE *inp);
ListDecl psListDecl(const char *str);
ListArg  pListArg(FILE *inp);
ListArg psListArg(const char *str);
ListIdent  pListIdent(FILE *inp);
ListIdent psListIdent(const char *str);
Stm  pStm(FILE *inp);
Stm psStm(const char *str);
Exp  pExp15(FILE *inp);
Exp psExp15(const char *str);
Exp  pExp14(FILE *inp);
Exp psExp14(const char *str);
Exp  pExp13(FILE *inp);
Exp psExp13(const char *str);
Exp  pExp12(FILE *inp);
Exp psExp12(const char *str);
Exp  pExp11(FILE *inp);
Exp psExp11(const char *str);
Exp  pExp9(FILE *inp);
Exp psExp9(const char *str);
Exp  pExp8(FILE *inp);
Exp psExp8(const char *str);
Exp  pExp4(FILE *inp);
Exp psExp4(const char *str);
Exp  pExp3(FILE *inp);
Exp psExp3(const char *str);
Exp  pExp2(FILE *inp);
Exp psExp2(const char *str);
Exp  pExp(FILE *inp);
Exp psExp(const char *str);
Exp  pExp1(FILE *inp);
Exp psExp1(const char *str);
Exp  pExp5(FILE *inp);
Exp psExp5(const char *str);
Exp  pExp6(FILE *inp);
Exp psExp6(const char *str);
Exp  pExp7(FILE *inp);
Exp psExp7(const char *str);
Exp  pExp10(FILE *inp);
Exp psExp10(const char *str);
ListExp  pListExp(FILE *inp);
ListExp psListExp(const char *str);
Type  pType(FILE *inp);
Type psType(const char *str);


#endif
