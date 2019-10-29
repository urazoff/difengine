/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse dfngparse
#define yylex   dfnglex
#define yyerror dfngerror
#define yylval  dfnglval
#define yychar  dfngchar
#define yydebug dfngdebug
#define yynerrs dfngnerrs
#define yylloc dfnglloc

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _ERROR_ = 258,
     _SYMB_0 = 259,
     _SYMB_1 = 260,
     _SYMB_2 = 261,
     _SYMB_3 = 262,
     _SYMB_4 = 263,
     _SYMB_5 = 264,
     _SYMB_6 = 265,
     _SYMB_7 = 266,
     _SYMB_8 = 267,
     _SYMB_9 = 268,
     _SYMB_10 = 269,
     _SYMB_11 = 270,
     _SYMB_12 = 271,
     _SYMB_13 = 272,
     _SYMB_14 = 273,
     _SYMB_15 = 274,
     _SYMB_16 = 275,
     _SYMB_17 = 276,
     _SYMB_18 = 277,
     _SYMB_19 = 278,
     _SYMB_20 = 279,
     _SYMB_21 = 280,
     _SYMB_22 = 281,
     _SYMB_23 = 282,
     _SYMB_24 = 283,
     _SYMB_25 = 284,
     _SYMB_26 = 285,
     _SYMB_27 = 286,
     _SYMB_28 = 287,
     _SYMB_29 = 288,
     _SYMB_30 = 289,
     _SYMB_31 = 290,
     _INTEGER_ = 291,
     _DOUBLE_ = 292,
     _IDENT_ = 293
   };
#endif
/* Tokens.  */
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




/* Copy the first part of user declarations.  */
#line 3 "dfng.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Absyn.h"
typedef struct dfng_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE dfng_scan_string(const char *str);
void dfng_delete_buffer(YY_BUFFER_STATE buf);
extern int yyparse(void);
extern int yylex(void);
extern int dfng_init_lexer(FILE * inp);
extern void yyerror(const char *str);

Program YY_RESULT_Program_ = 0;
ListExternal_declaration YY_RESULT_ListExternal_declaration_ = 0;
External_declaration YY_RESULT_External_declaration_ = 0;
Function YY_RESULT_Function_ = 0;
Arg YY_RESULT_Arg_ = 0;
Decl YY_RESULT_Decl_ = 0;
ListFunction YY_RESULT_ListFunction_ = 0;
ListStm YY_RESULT_ListStm_ = 0;
ListDecl YY_RESULT_ListDecl_ = 0;
ListArg YY_RESULT_ListArg_ = 0;
ListIdent YY_RESULT_ListIdent_ = 0;
Stm YY_RESULT_Stm_ = 0;
Exp YY_RESULT_Exp_ = 0;
ListExp YY_RESULT_ListExp_ = 0;
Type YY_RESULT_Type_ = 0;

Program pProgram(FILE *inp)
{
  dfng_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Program_;
  }
}
Program psProgram(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Program_;
  }
}

ListExternal_declaration pListExternal_declaration(FILE *inp)
{
  dfng_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExternal_declaration_;
  }
}
ListExternal_declaration psListExternal_declaration(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExternal_declaration_;
  }
}

External_declaration pExternal_declaration(FILE *inp)
{
  dfng_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_External_declaration_;
  }
}
External_declaration psExternal_declaration(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_External_declaration_;
  }
}

Function pFunction(FILE *inp)
{
  dfng_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Function_;
  }
}
Function psFunction(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Function_;
  }
}

Arg pArg(FILE *inp)
{
  dfng_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Arg_;
  }
}
Arg psArg(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Arg_;
  }
}

Decl pDecl(FILE *inp)
{
  dfng_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Decl_;
  }
}
Decl psDecl(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Decl_;
  }
}

ListFunction pListFunction(FILE *inp)
{
  dfng_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListFunction_;
  }
}
ListFunction psListFunction(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListFunction_;
  }
}

ListStm pListStm(FILE *inp)
{
  dfng_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStm_;
  }
}
ListStm psListStm(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStm_;
  }
}

ListDecl pListDecl(FILE *inp)
{
  dfng_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListDecl_;
  }
}
ListDecl psListDecl(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListDecl_;
  }
}

ListArg pListArg(FILE *inp)
{
  dfng_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListArg_;
  }
}
ListArg psListArg(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListArg_;
  }
}

ListIdent pListIdent(FILE *inp)
{
  dfng_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListIdent_;
  }
}
ListIdent psListIdent(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListIdent_;
  }
}

Stm pStm(FILE *inp)
{
  dfng_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Stm_;
  }
}
Stm psStm(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Stm_;
  }
}

Exp pExp15(FILE *inp)
{
  dfng_init_lexer(inp);
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
Exp psExp15(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp14(FILE *inp)
{
  dfng_init_lexer(inp);
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
Exp psExp14(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp13(FILE *inp)
{
  dfng_init_lexer(inp);
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
Exp psExp13(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp12(FILE *inp)
{
  dfng_init_lexer(inp);
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
Exp psExp12(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp11(FILE *inp)
{
  dfng_init_lexer(inp);
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
Exp psExp11(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp9(FILE *inp)
{
  dfng_init_lexer(inp);
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
Exp psExp9(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp8(FILE *inp)
{
  dfng_init_lexer(inp);
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
Exp psExp8(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp4(FILE *inp)
{
  dfng_init_lexer(inp);
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
Exp psExp4(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp3(FILE *inp)
{
  dfng_init_lexer(inp);
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
Exp psExp3(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
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
  dfng_init_lexer(inp);
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
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp(FILE *inp)
{
  dfng_init_lexer(inp);
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
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
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
  dfng_init_lexer(inp);
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
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp5(FILE *inp)
{
  dfng_init_lexer(inp);
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
Exp psExp5(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp6(FILE *inp)
{
  dfng_init_lexer(inp);
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
Exp psExp6(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp7(FILE *inp)
{
  dfng_init_lexer(inp);
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
Exp psExp7(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Exp pExp10(FILE *inp)
{
  dfng_init_lexer(inp);
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
Exp psExp10(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

ListExp pListExp(FILE *inp)
{
  dfng_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExp_;
  }
}
ListExp psListExp(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExp_;
  }
}

Type pType(FILE *inp)
{
  dfng_init_lexer(inp);
  int result = yyparse();
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}
Type psType(const char *str)
{
  YY_BUFFER_STATE buf;
  dfng_init_lexer(0);
  buf = dfng_scan_string(str);
  int result = yyparse();
  dfng_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}


ListExternal_declaration reverseListExternal_declaration(ListExternal_declaration l)
{
  ListExternal_declaration prev = 0;
  ListExternal_declaration tmp = 0;
  while (l)
  {
    tmp = l->listexternal_declaration_;
    l->listexternal_declaration_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}
ListFunction reverseListFunction(ListFunction l)
{
  ListFunction prev = 0;
  ListFunction tmp = 0;
  while (l)
  {
    tmp = l->listfunction_;
    l->listfunction_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}
ListStm reverseListStm(ListStm l)
{
  ListStm prev = 0;
  ListStm tmp = 0;
  while (l)
  {
    tmp = l->liststm_;
    l->liststm_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}
ListDecl reverseListDecl(ListDecl l)
{
  ListDecl prev = 0;
  ListDecl tmp = 0;
  while (l)
  {
    tmp = l->listdecl_;
    l->listdecl_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}
ListArg reverseListArg(ListArg l)
{
  ListArg prev = 0;
  ListArg tmp = 0;
  while (l)
  {
    tmp = l->listarg_;
    l->listarg_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}
ListIdent reverseListIdent(ListIdent l)
{
  ListIdent prev = 0;
  ListIdent tmp = 0;
  while (l)
  {
    tmp = l->listident_;
    l->listident_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}
ListExp reverseListExp(ListExp l)
{
  ListExp prev = 0;
  ListExp tmp = 0;
  while (l)
  {
    tmp = l->listexp_;
    l->listexp_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 1028 "dfng.y"
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

}
/* Line 193 of yacc.c.  */
#line 1227 "Parser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 1252 "Parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  121

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    13,    22,    25,
      30,    33,    34,    37,    38,    40,    44,    46,    50,    53,
      58,    63,    66,    70,    76,    80,    88,    90,    92,    94,
      96,    98,   103,   107,   110,   113,   115,   118,   121,   123,
     127,   131,   133,   137,   141,   143,   147,   151,   155,   159,
     161,   165,   169,   171,   175,   177,   181,   183,   187,   189,
     191,   193,   195,   197,   199,   201,   202,   204,   208,   210,
     212,   214
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    41,    -1,    -1,    41,    42,    -1,    43,
      -1,    49,    -1,    67,    35,     4,    47,     5,     6,    46,
       7,    -1,    67,    35,    -1,    67,    35,     8,    60,    -1,
      67,    48,    -1,    -1,    46,    49,    -1,    -1,    44,    -1,
      44,     9,    47,    -1,    35,    -1,    35,     9,    48,    -1,
      45,    10,    -1,    45,     9,    48,    10,    -1,    45,     8,
      60,    10,    -1,    60,    10,    -1,     6,    46,     7,    -1,
      34,     4,    60,     5,    49,    -1,    31,    60,    10,    -1,
      29,     4,    60,     5,    49,    27,    49,    -1,    36,    -1,
      37,    -1,    32,    -1,    28,    -1,    35,    -1,    35,     4,
      66,     5,    -1,     4,    60,     5,    -1,    50,    11,    -1,
      50,    12,    -1,    50,    -1,    11,    51,    -1,    12,    51,
      -1,    51,    -1,    53,    13,    52,    -1,    53,    14,    52,
      -1,    52,    -1,    54,    15,    53,    -1,    54,    16,    53,
      -1,    53,    -1,    55,    17,    65,    -1,    55,    18,    65,
      -1,    55,    19,    65,    -1,    55,    20,    65,    -1,    65,
      -1,    56,    21,    55,    -1,    56,    22,    55,    -1,    55,
      -1,    57,    23,    62,    -1,    62,    -1,    58,    24,    57,
      -1,    57,    -1,    58,     8,    59,    -1,    58,    -1,    61,
      -1,    59,    -1,    63,    -1,    64,    -1,    56,    -1,    54,
      -1,    -1,    60,    -1,    60,     9,    66,    -1,    25,    -1,
      26,    -1,    30,    -1,    33,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1122,  1122,  1124,  1125,  1127,  1128,  1130,  1132,  1133,
    1135,  1140,  1141,  1147,  1148,  1149,  1151,  1152,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1163,  1164,  1165,  1166,
    1167,  1168,  1169,  1171,  1172,  1173,  1175,  1176,  1177,  1179,
    1180,  1181,  1183,  1184,  1185,  1187,  1188,  1189,  1190,  1191,
    1193,  1194,  1195,  1197,  1198,  1200,  1201,  1203,  1204,  1206,
    1208,  1210,  1212,  1214,  1216,  1218,  1219,  1220,  1222,  1223,
    1224,  1225
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ERROR_", "_SYMB_0", "_SYMB_1",
  "_SYMB_2", "_SYMB_3", "_SYMB_4", "_SYMB_5", "_SYMB_6", "_SYMB_7",
  "_SYMB_8", "_SYMB_9", "_SYMB_10", "_SYMB_11", "_SYMB_12", "_SYMB_13",
  "_SYMB_14", "_SYMB_15", "_SYMB_16", "_SYMB_17", "_SYMB_18", "_SYMB_19",
  "_SYMB_20", "_SYMB_21", "_SYMB_22", "_SYMB_23", "_SYMB_24", "_SYMB_25",
  "_SYMB_26", "_SYMB_27", "_SYMB_28", "_SYMB_29", "_SYMB_30", "_SYMB_31",
  "_INTEGER_", "_DOUBLE_", "_IDENT_", "$accept", "Program",
  "ListExternal_declaration", "External_declaration", "Function", "Arg",
  "Decl", "ListStm", "ListArg", "ListIdent", "Stm", "Exp15", "Exp14",
  "Exp13", "Exp12", "Exp11", "Exp9", "Exp8", "Exp4", "Exp3", "Exp2", "Exp",
  "Exp1", "Exp5", "Exp6", "Exp7", "Exp10", "ListExp", "Type", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    43,    44,    44,
      45,    46,    46,    47,    47,    47,    48,    48,    49,    49,
      49,    49,    49,    49,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    51,    52,    52,    52,    53,
      53,    53,    54,    54,    54,    55,    55,    55,    55,    55,
      56,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      61,    62,    63,    64,    65,    66,    66,    66,    67,    67,
      67,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     8,     2,     4,
       2,     0,     2,     0,     1,     3,     1,     3,     2,     4,
       4,     2,     3,     5,     3,     7,     1,     1,     1,     1,
       1,     4,     3,     2,     2,     1,     2,     2,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     3,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,    11,     0,     0,    68,    69,
      29,     0,    70,     0,    28,    71,     0,    30,    26,    27,
       4,     5,     0,     6,    35,    38,    41,    44,    64,    52,
      63,    56,    58,    60,     0,    59,    54,    61,    62,    49,
       0,     0,     0,    36,    37,     0,     0,     0,    65,     0,
       0,    18,    33,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    16,    10,
      32,    22,    12,     0,     0,    24,     0,    66,     0,     0,
      16,     0,    39,    40,    42,    43,    45,    46,    47,    48,
      50,    51,    53,    57,    55,    13,     0,     0,     0,    65,
      31,    20,    19,    14,     0,     0,    17,     0,    23,    67,
      13,     0,     8,     0,    15,    11,     0,    25,     0,     9,
       7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    20,    21,   103,    22,    42,   104,    69,
      72,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    78,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -48
static const yytype_int8 yypact[] =
{
     -48,     4,    95,   -48,    54,   -48,   106,   106,   -48,   -48,
     -48,    38,   -48,    54,   -48,   -48,    50,    53,   -48,   -48,
     -48,   -48,    15,   -48,     5,   -48,   -48,     7,    24,    42,
      25,    48,    -2,   -48,    18,   -48,   -48,   -48,   -48,   -48,
      52,    80,     1,   -48,   -48,    54,    78,    54,    54,    54,
      57,   -48,   -48,   -48,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,   -48,    10,   -48,
     -48,   -48,   -48,    57,    88,   -48,    91,    93,    98,    90,
      96,    94,   -48,   -48,     7,     7,   -48,   -48,   -48,   -48,
      42,    42,   -48,   -48,    48,   -15,    57,    95,    95,    54,
     -48,   -48,   -48,    99,   113,    76,   -48,    92,   -48,   -48,
     -15,   116,   125,    95,   -48,   -48,    54,   -48,    44,   -48,
     -48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -48,   -48,   -48,   -48,   -48,    20,    26,   -47,
       0,   -48,    46,     9,    11,   -48,    21,   -48,    71,   -48,
      74,    -4,   -48,    81,   -48,   -48,    56,    41,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      41,    40,    23,    81,     3,     4,    65,     5,    71,    46,
       8,     9,     6,     7,    95,    12,    52,    53,    15,    96,
      54,    55,    66,    49,    50,    51,     8,     9,    67,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    56,
      57,    74,    45,    76,    77,    79,    62,    63,     4,   106,
       5,   120,    43,    44,    47,     6,     7,    48,     4,    58,
      59,    60,    61,    82,    83,     6,     7,    84,    85,     8,
       9,    64,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    10,    90,    91,    70,    14,    68,    75,    17,
      18,    19,    80,    97,   105,    77,    98,   107,   108,     4,
     101,     5,    99,   100,   102,    96,     6,     7,   110,   105,
       4,   112,   119,   117,    86,    87,    88,    89,   111,   113,
       8,     9,   115,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   116,    10,   118,   114,    94,    14,    93,
     109,    17,    18,    19,     0,    92
};

static const yytype_int8 yycheck[] =
{
       4,     2,     2,    50,     0,     4,     8,     6,     7,    13,
      25,    26,    11,    12,     4,    30,    11,    12,    33,     9,
      13,    14,    24,     8,     9,    10,    25,    26,    10,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    45,     4,    47,    48,    49,    21,    22,     4,    96,
       6,     7,     6,     7,     4,    11,    12,     4,     4,    17,
      18,    19,    20,    54,    55,    11,    12,    56,    57,    25,
      26,    23,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    28,    62,    63,     5,    32,    35,    10,    35,
      36,    37,    35,     5,    95,    99,     5,    97,    98,     4,
      10,     6,     9,     5,    10,     9,    11,    12,     9,   110,
       4,    35,   116,   113,    58,    59,    60,    61,     5,    27,
      25,    26,     6,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,     8,    28,   115,   110,    66,    32,    65,
      99,    35,    36,    37,    -1,    64
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,     0,     4,     6,    11,    12,    25,    26,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      42,    43,    45,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      67,    60,    46,    51,    51,     4,    60,     4,     4,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     8,    24,    10,    35,    48,
       5,     7,    49,    67,    60,    10,    60,    60,    66,    60,
      35,    48,    52,    52,    53,    53,    65,    65,    65,    65,
      55,    55,    62,    59,    57,     4,     9,     5,     5,     9,
       5,    10,    10,    44,    47,    67,    48,    49,    49,    66,
       9,     5,    35,    27,    47,     6,     8,    49,    46,    60,
       7
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 1122 "dfng.y"
    { (yyval.program_) = make_Prog(reverseListExternal_declaration((yyvsp[(1) - (1)].listexternal_declaration_))); YY_RESULT_Program_= (yyval.program_); ;}
    break;

  case 3:
#line 1124 "dfng.y"
    { (yyval.listexternal_declaration_) = 0; YY_RESULT_ListExternal_declaration_= (yyval.listexternal_declaration_); ;}
    break;

  case 4:
#line 1125 "dfng.y"
    { (yyval.listexternal_declaration_) = make_ListExternal_declaration((yyvsp[(2) - (2)].external_declaration_), (yyvsp[(1) - (2)].listexternal_declaration_)); YY_RESULT_ListExternal_declaration_= (yyval.listexternal_declaration_); ;}
    break;

  case 5:
#line 1127 "dfng.y"
    { (yyval.external_declaration_) = make_Afunc((yyvsp[(1) - (1)].function_)); YY_RESULT_External_declaration_= (yyval.external_declaration_); ;}
    break;

  case 6:
#line 1128 "dfng.y"
    { (yyval.external_declaration_) = make_Global((yyvsp[(1) - (1)].stm_)); YY_RESULT_External_declaration_= (yyval.external_declaration_); ;}
    break;

  case 7:
#line 1130 "dfng.y"
    { (yyval.function_) = make_Fun((yyvsp[(1) - (8)].type_), (yyvsp[(2) - (8)].string_), (yyvsp[(4) - (8)].listarg_), reverseListStm((yyvsp[(7) - (8)].liststm_))); YY_RESULT_Function_= (yyval.function_); ;}
    break;

  case 8:
#line 1132 "dfng.y"
    { (yyval.arg_) = make_ADecl((yyvsp[(1) - (2)].type_), (yyvsp[(2) - (2)].string_)); YY_RESULT_Arg_= (yyval.arg_); ;}
    break;

  case 9:
#line 1133 "dfng.y"
    { (yyval.arg_) = make_APred((yyvsp[(1) - (4)].type_), (yyvsp[(2) - (4)].string_), (yyvsp[(4) - (4)].exp_)); YY_RESULT_Arg_= (yyval.arg_); ;}
    break;

  case 10:
#line 1135 "dfng.y"
    { (yyval.decl_) = make_Dec((yyvsp[(1) - (2)].type_), (yyvsp[(2) - (2)].listident_)); YY_RESULT_Decl_= (yyval.decl_); ;}
    break;

  case 11:
#line 1140 "dfng.y"
    { (yyval.liststm_) = 0; YY_RESULT_ListStm_= (yyval.liststm_); ;}
    break;

  case 12:
#line 1141 "dfng.y"
    { (yyval.liststm_) = make_ListStm((yyvsp[(2) - (2)].stm_), (yyvsp[(1) - (2)].liststm_)); YY_RESULT_ListStm_= (yyval.liststm_); ;}
    break;

  case 13:
#line 1147 "dfng.y"
    { (yyval.listarg_) = 0; YY_RESULT_ListArg_= (yyval.listarg_); ;}
    break;

  case 14:
#line 1148 "dfng.y"
    { (yyval.listarg_) = make_ListArg((yyvsp[(1) - (1)].arg_), 0); YY_RESULT_ListArg_= (yyval.listarg_); ;}
    break;

  case 15:
#line 1149 "dfng.y"
    { (yyval.listarg_) = make_ListArg((yyvsp[(1) - (3)].arg_), (yyvsp[(3) - (3)].listarg_)); YY_RESULT_ListArg_= (yyval.listarg_); ;}
    break;

  case 16:
#line 1151 "dfng.y"
    { (yyval.listident_) = make_ListIdent((yyvsp[(1) - (1)].string_), 0); YY_RESULT_ListIdent_= (yyval.listident_); ;}
    break;

  case 17:
#line 1152 "dfng.y"
    { (yyval.listident_) = make_ListIdent((yyvsp[(1) - (3)].string_), (yyvsp[(3) - (3)].listident_)); YY_RESULT_ListIdent_= (yyval.listident_); ;}
    break;

  case 18:
#line 1154 "dfng.y"
    { (yyval.stm_) = make_SDecl((yyvsp[(1) - (2)].decl_)); YY_RESULT_Stm_= (yyval.stm_); ;}
    break;

  case 19:
#line 1155 "dfng.y"
    { (yyval.stm_) = make_SDecls((yyvsp[(1) - (4)].decl_), (yyvsp[(3) - (4)].listident_)); YY_RESULT_Stm_= (yyval.stm_); ;}
    break;

  case 20:
#line 1156 "dfng.y"
    { (yyval.stm_) = make_SInit((yyvsp[(1) - (4)].decl_), (yyvsp[(3) - (4)].exp_)); YY_RESULT_Stm_= (yyval.stm_); ;}
    break;

  case 21:
#line 1157 "dfng.y"
    { (yyval.stm_) = make_SExp((yyvsp[(1) - (2)].exp_)); YY_RESULT_Stm_= (yyval.stm_); ;}
    break;

  case 22:
#line 1158 "dfng.y"
    { (yyval.stm_) = make_SBlock(reverseListStm((yyvsp[(2) - (3)].liststm_))); YY_RESULT_Stm_= (yyval.stm_); ;}
    break;

  case 23:
#line 1159 "dfng.y"
    { (yyval.stm_) = make_SWhile((yyvsp[(3) - (5)].exp_), (yyvsp[(5) - (5)].stm_)); YY_RESULT_Stm_= (yyval.stm_); ;}
    break;

  case 24:
#line 1160 "dfng.y"
    { (yyval.stm_) = make_SReturn((yyvsp[(2) - (3)].exp_)); YY_RESULT_Stm_= (yyval.stm_); ;}
    break;

  case 25:
#line 1161 "dfng.y"
    { (yyval.stm_) = make_SIfElse((yyvsp[(3) - (7)].exp_), (yyvsp[(5) - (7)].stm_), (yyvsp[(7) - (7)].stm_)); YY_RESULT_Stm_= (yyval.stm_); ;}
    break;

  case 26:
#line 1163 "dfng.y"
    { (yyval.exp_) = make_EInt((yyvsp[(1) - (1)].int_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 27:
#line 1164 "dfng.y"
    { (yyval.exp_) = make_EDouble((yyvsp[(1) - (1)].double_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 28:
#line 1165 "dfng.y"
    { (yyval.exp_) = make_ETrue(); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 29:
#line 1166 "dfng.y"
    { (yyval.exp_) = make_EFalse(); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 30:
#line 1167 "dfng.y"
    { (yyval.exp_) = make_EIdent((yyvsp[(1) - (1)].string_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 31:
#line 1168 "dfng.y"
    { (yyval.exp_) = make_EApp((yyvsp[(1) - (4)].string_), (yyvsp[(3) - (4)].listexp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 32:
#line 1169 "dfng.y"
    { (yyval.exp_) = (yyvsp[(2) - (3)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 33:
#line 1171 "dfng.y"
    { (yyval.exp_) = make_EPIncr((yyvsp[(1) - (2)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 34:
#line 1172 "dfng.y"
    { (yyval.exp_) = make_EPDecr((yyvsp[(1) - (2)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 35:
#line 1173 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 36:
#line 1175 "dfng.y"
    { (yyval.exp_) = make_EIncr((yyvsp[(2) - (2)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 37:
#line 1176 "dfng.y"
    { (yyval.exp_) = make_EDecr((yyvsp[(2) - (2)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 38:
#line 1177 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 39:
#line 1179 "dfng.y"
    { (yyval.exp_) = make_ETimes((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 40:
#line 1180 "dfng.y"
    { (yyval.exp_) = make_EDiv((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 41:
#line 1181 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 42:
#line 1183 "dfng.y"
    { (yyval.exp_) = make_EPlus((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 43:
#line 1184 "dfng.y"
    { (yyval.exp_) = make_EMinus((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 44:
#line 1185 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 45:
#line 1187 "dfng.y"
    { (yyval.exp_) = make_ELt((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 46:
#line 1188 "dfng.y"
    { (yyval.exp_) = make_EGt((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 47:
#line 1189 "dfng.y"
    { (yyval.exp_) = make_ELtEq((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 48:
#line 1190 "dfng.y"
    { (yyval.exp_) = make_EGtWq((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 49:
#line 1191 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 50:
#line 1193 "dfng.y"
    { (yyval.exp_) = make_EEq((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 51:
#line 1194 "dfng.y"
    { (yyval.exp_) = make_ENEq((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 52:
#line 1195 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 53:
#line 1197 "dfng.y"
    { (yyval.exp_) = make_EAnd((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 54:
#line 1198 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 55:
#line 1200 "dfng.y"
    { (yyval.exp_) = make_EOr((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 56:
#line 1201 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 57:
#line 1203 "dfng.y"
    { (yyval.exp_) = make_EAss((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 58:
#line 1204 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 59:
#line 1206 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 60:
#line 1208 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 61:
#line 1210 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 62:
#line 1212 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 63:
#line 1214 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 64:
#line 1216 "dfng.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); ;}
    break;

  case 65:
#line 1218 "dfng.y"
    { (yyval.listexp_) = 0; YY_RESULT_ListExp_= (yyval.listexp_); ;}
    break;

  case 66:
#line 1219 "dfng.y"
    { (yyval.listexp_) = make_ListExp((yyvsp[(1) - (1)].exp_), 0); YY_RESULT_ListExp_= (yyval.listexp_); ;}
    break;

  case 67:
#line 1220 "dfng.y"
    { (yyval.listexp_) = make_ListExp((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].listexp_)); YY_RESULT_ListExp_= (yyval.listexp_); ;}
    break;

  case 68:
#line 1222 "dfng.y"
    { (yyval.type_) = make_Tbool(); YY_RESULT_Type_= (yyval.type_); ;}
    break;

  case 69:
#line 1223 "dfng.y"
    { (yyval.type_) = make_Tdouble(); YY_RESULT_Type_= (yyval.type_); ;}
    break;

  case 70:
#line 1224 "dfng.y"
    { (yyval.type_) = make_Tint(); YY_RESULT_Type_= (yyval.type_); ;}
    break;

  case 71:
#line 1225 "dfng.y"
    { (yyval.type_) = make_Tvoid(); YY_RESULT_Type_= (yyval.type_); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2938 "Parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1228 "dfng.y"

void yyerror(const char *str)
{
  extern char *dfngtext;
  fprintf(stderr,"error: %d,%d: %s at %s\n",
  dfnglloc.first_line, dfnglloc.first_column, str, dfngtext);
}


