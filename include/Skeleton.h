#ifndef SKELETON_HEADER
#define SKELETON_HEADER
/* You might want to change the above name. */

#include "Absyn.h"


void visitProgram(Program p);
void visitListExternal_declaration(ListExternal_declaration p);
void visitExternal_declaration(External_declaration p);
void visitFunction(Function p);
void visitArg(Arg p);
void visitDecl(Decl p);
void visitListFunction(ListFunction p);
void visitListStm(ListStm p);
void visitListDecl(ListDecl p);
void visitListArg(ListArg p);
void visitListIdent(ListIdent p);
void visitStm(Stm p);
void visitExp(Exp p);
void visitListExp(ListExp p);
void visitType(Type p);

void visitIdent(Ident p);
void visitIdent(Ident i);
void visitInteger(Integer i);
void visitDouble(Double d);
void visitChar(Char c);
void visitString(String s);

#endif

