#ifndef PRINTER_HEADER
#define PRINTER_HEADER

#include "Absyn.h"

/* Certain applications may improve performance by changing the buffer size */
#define BUFFER_INITIAL 2000
/* You may wish to change _L_PAREN or _R_PAREN */
#define _L_PAREN '('
#define _R_PAREN ')'

/* The following are simple heuristics for rendering terminals */
/* You may wish to change them */
void renderCC(Char c);
void renderCS(String s);
void indent(void);
void backup(void);


char *printProgram(Program p);
char *printListExternal_declaration(ListExternal_declaration p);
char *printExternal_declaration(External_declaration p);
char *printFunction(Function p);
char *printArg(Arg p);
char *printDecl(Decl p);
char *printListFunction(ListFunction p);
char *printListStm(ListStm p);
char *printListDecl(ListDecl p);
char *printListArg(ListArg p);
char *printListIdent(ListIdent p);
char *printStm(Stm p);
char *printExp(Exp p);
char *printListExp(ListExp p);
char *printType(Type p);

void ppProgram(Program p, int i);
void ppListExternal_declaration(ListExternal_declaration p, int i);
void ppExternal_declaration(External_declaration p, int i);
void ppFunction(Function p, int i);
void ppArg(Arg p, int i);
void ppDecl(Decl p, int i);
void ppListFunction(ListFunction p, int i);
void ppListStm(ListStm p, int i);
void ppListDecl(ListDecl p, int i);
void ppListArg(ListArg p, int i);
void ppListIdent(ListIdent p, int i);
void ppStm(Stm p, int i);
void ppExp(Exp p, int i);
void ppListExp(ListExp p, int i);
void ppType(Type p, int i);

char *showProgram(Program p);
char *showListExternal_declaration(ListExternal_declaration p);
char *showExternal_declaration(External_declaration p);
char *showFunction(Function p);
char *showArg(Arg p);
char *showDecl(Decl p);
char *showListFunction(ListFunction p);
char *showListStm(ListStm p);
char *showListDecl(ListDecl p);
char *showListArg(ListArg p);
char *showListIdent(ListIdent p);
char *showStm(Stm p);
char *showExp(Exp p);
char *showListExp(ListExp p);
char *showType(Type p);

void shProgram(Program p);
void shListExternal_declaration(ListExternal_declaration p);
void shExternal_declaration(External_declaration p);
void shFunction(Function p);
void shArg(Arg p);
void shDecl(Decl p);
void shListFunction(ListFunction p);
void shListStm(ListStm p);
void shListDecl(ListDecl p);
void shListArg(ListArg p);
void shListIdent(ListIdent p);
void shStm(Stm p);
void shExp(Exp p);
void shListExp(ListExp p);
void shType(Type p);

void ppIdent(String s, int i);
void shIdent(String s);
void ppInteger(Integer n, int i);
void ppDouble(Double d, int i);
void ppChar(Char c, int i);
void ppString(String s, int i);
void ppIdent(String s, int i);
void shInteger(Integer n);
void shDouble(Double d);
void shChar(Char c);
void shString(String s);
void shIdent(String s);
void bufAppendS(const char *s);
void bufAppendC(const char c);
void bufReset(void);
void resizeBuffer(void);

#endif

