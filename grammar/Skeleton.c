/*** BNFC-Generated Visitor Traversal Skeleton. ***/
/* This traverses the abstract syntax tree.
   To use, copy Skeleton.h and Skeleton.c to
   new files. */

#include <stdlib.h>
#include <stdio.h>

#include "Skeleton.h"

void visitProgram(Program p)
{
  switch(p->kind)
  {
  case is_Prog:
    /* Code for Prog Goes Here */
    visitListExternal_declaration(p->u.prog_.listexternal_declaration_);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Program!\n");
    exit(1);
  }
}

void visitListExternal_declaration(ListExternal_declaration listexternal_declaration)
{
  while(listexternal_declaration  != 0)
  {
    /* Code For ListExternal_declaration Goes Here */
    visitExternal_declaration(listexternal_declaration->external_declaration_);
    listexternal_declaration = listexternal_declaration->listexternal_declaration_;
  }
}

void visitExternal_declaration(External_declaration p)
{
  switch(p->kind)
  {
  case is_Afunc:
    /* Code for Afunc Goes Here */
    visitFunction(p->u.afunc_.function_);
    break;
  case is_Global:
    /* Code for Global Goes Here */
    visitStm(p->u.global_.stm_);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing External_declaration!\n");
    exit(1);
  }
}

void visitFunction(Function p)
{
  switch(p->kind)
  {
  case is_Fun:
    /* Code for Fun Goes Here */
    visitType(p->u.fun_.type_);
    visitIdent(p->u.fun_.ident_);
    visitListArg(p->u.fun_.listarg_);
    visitListStm(p->u.fun_.liststm_);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Function!\n");
    exit(1);
  }
}

void visitArg(Arg p)
{
  switch(p->kind)
  {
  case is_ADecl:
    /* Code for ADecl Goes Here */
    visitType(p->u.adecl_.type_);
    visitIdent(p->u.adecl_.ident_);
    break;
  case is_APred:
    /* Code for APred Goes Here */
    visitType(p->u.apred_.type_);
    visitIdent(p->u.apred_.ident_);
    visitExp(p->u.apred_.exp_);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Arg!\n");
    exit(1);
  }
}

void visitDecl(Decl p)
{
  switch(p->kind)
  {
  case is_Dec:
    /* Code for Dec Goes Here */
    visitType(p->u.dec_.type_);
    visitListIdent(p->u.dec_.listident_);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Decl!\n");
    exit(1);
  }
}

void visitListFunction(ListFunction listfunction)
{
  while(listfunction  != 0)
  {
    /* Code For ListFunction Goes Here */
    visitFunction(listfunction->function_);
    listfunction = listfunction->listfunction_;
  }
}

void visitListStm(ListStm liststm)
{
  while(liststm  != 0)
  {
    /* Code For ListStm Goes Here */
    visitStm(liststm->stm_);
    liststm = liststm->liststm_;
  }
}

void visitListDecl(ListDecl listdecl)
{
  while(listdecl  != 0)
  {
    /* Code For ListDecl Goes Here */
    visitDecl(listdecl->decl_);
    listdecl = listdecl->listdecl_;
  }
}

void visitListArg(ListArg listarg)
{
  while(listarg  != 0)
  {
    /* Code For ListArg Goes Here */
    visitArg(listarg->arg_);
    listarg = listarg->listarg_;
  }
}

void visitListIdent(ListIdent listident)
{
  while(listident  != 0)
  {
    /* Code For ListIdent Goes Here */
    visitIdent(listident->ident_);
    listident = listident->listident_;
  }
}

void visitStm(Stm p)
{
  switch(p->kind)
  {
  case is_SDecl:
    /* Code for SDecl Goes Here */
    visitDecl(p->u.sdecl_.decl_);
    break;
  case is_SDecls:
    /* Code for SDecls Goes Here */
    visitDecl(p->u.sdecls_.decl_);
    visitListIdent(p->u.sdecls_.listident_);
    break;
  case is_SInit:
    /* Code for SInit Goes Here */
    visitDecl(p->u.sinit_.decl_);
    visitExp(p->u.sinit_.exp_);
    break;
  case is_SExp:
    /* Code for SExp Goes Here */
    visitExp(p->u.sexp_.exp_);
    break;
  case is_SBlock:
    /* Code for SBlock Goes Here */
    visitListStm(p->u.sblock_.liststm_);
    break;
  case is_SWhile:
    /* Code for SWhile Goes Here */
    visitExp(p->u.swhile_.exp_);
    visitStm(p->u.swhile_.stm_);
    break;
  case is_SReturn:
    /* Code for SReturn Goes Here */
    visitExp(p->u.sreturn_.exp_);
    break;
  case is_SIfElse:
    /* Code for SIfElse Goes Here */
    visitExp(p->u.sifelse_.exp_);
    visitStm(p->u.sifelse_.stm_1);
    visitStm(p->u.sifelse_.stm_2);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Stm!\n");
    exit(1);
  }
}

void visitExp(Exp p)
{
  switch(p->kind)
  {
  case is_EInt:
    /* Code for EInt Goes Here */
    visitInteger(p->u.eint_.integer_);
    break;
  case is_EDouble:
    /* Code for EDouble Goes Here */
    visitDouble(p->u.edouble_.double_);
    break;
  case is_ETrue:
    /* Code for ETrue Goes Here */
    break;
  case is_EFalse:
    /* Code for EFalse Goes Here */
    break;
  case is_EIdent:
    /* Code for EIdent Goes Here */
    visitIdent(p->u.eident_.ident_);
    break;
  case is_EApp:
    /* Code for EApp Goes Here */
    visitIdent(p->u.eapp_.ident_);
    visitListExp(p->u.eapp_.listexp_);
    break;
  case is_EPIncr:
    /* Code for EPIncr Goes Here */
    visitExp(p->u.epincr_.exp_);
    break;
  case is_EPDecr:
    /* Code for EPDecr Goes Here */
    visitExp(p->u.epdecr_.exp_);
    break;
  case is_EIncr:
    /* Code for EIncr Goes Here */
    visitExp(p->u.eincr_.exp_);
    break;
  case is_EDecr:
    /* Code for EDecr Goes Here */
    visitExp(p->u.edecr_.exp_);
    break;
  case is_ETimes:
    /* Code for ETimes Goes Here */
    visitExp(p->u.etimes_.exp_1);
    visitExp(p->u.etimes_.exp_2);
    break;
  case is_EDiv:
    /* Code for EDiv Goes Here */
    visitExp(p->u.ediv_.exp_1);
    visitExp(p->u.ediv_.exp_2);
    break;
  case is_EPlus:
    /* Code for EPlus Goes Here */
    visitExp(p->u.eplus_.exp_1);
    visitExp(p->u.eplus_.exp_2);
    break;
  case is_EMinus:
    /* Code for EMinus Goes Here */
    visitExp(p->u.eminus_.exp_1);
    visitExp(p->u.eminus_.exp_2);
    break;
  case is_ELt:
    /* Code for ELt Goes Here */
    visitExp(p->u.elt_.exp_1);
    visitExp(p->u.elt_.exp_2);
    break;
  case is_EGt:
    /* Code for EGt Goes Here */
    visitExp(p->u.egt_.exp_1);
    visitExp(p->u.egt_.exp_2);
    break;
  case is_ELtEq:
    /* Code for ELtEq Goes Here */
    visitExp(p->u.elteq_.exp_1);
    visitExp(p->u.elteq_.exp_2);
    break;
  case is_EGtWq:
    /* Code for EGtWq Goes Here */
    visitExp(p->u.egtwq_.exp_1);
    visitExp(p->u.egtwq_.exp_2);
    break;
  case is_EEq:
    /* Code for EEq Goes Here */
    visitExp(p->u.eeq_.exp_1);
    visitExp(p->u.eeq_.exp_2);
    break;
  case is_ENEq:
    /* Code for ENEq Goes Here */
    visitExp(p->u.eneq_.exp_1);
    visitExp(p->u.eneq_.exp_2);
    break;
  case is_EAnd:
    /* Code for EAnd Goes Here */
    visitExp(p->u.eand_.exp_1);
    visitExp(p->u.eand_.exp_2);
    break;
  case is_EOr:
    /* Code for EOr Goes Here */
    visitExp(p->u.eor_.exp_1);
    visitExp(p->u.eor_.exp_2);
    break;
  case is_EAss:
    /* Code for EAss Goes Here */
    visitExp(p->u.eass_.exp_1);
    visitExp(p->u.eass_.exp_2);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Exp!\n");
    exit(1);
  }
}

void visitListExp(ListExp listexp)
{
  while(listexp  != 0)
  {
    /* Code For ListExp Goes Here */
    visitExp(listexp->exp_);
    listexp = listexp->listexp_;
  }
}

void visitType(Type p)
{
  switch(p->kind)
  {
  case is_Tbool:
    /* Code for Tbool Goes Here */
    break;
  case is_Tdouble:
    /* Code for Tdouble Goes Here */
    break;
  case is_Tint:
    /* Code for Tint Goes Here */
    break;
  case is_Tvoid:
    /* Code for Tvoid Goes Here */
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Type!\n");
    exit(1);
  }
}

void visitIdent(Ident p)
{
  /* Code for Ident Goes Here */
}
void visitIdent(Ident i)
{
  /* Code for Ident Goes Here */
}
void visitInteger(Integer i)
{
  /* Code for Integer Goes Here */
}
void visitDouble(Double d)
{
  /* Code for Double Goes Here */
}
void visitChar(Char c)
{
  /* Code for Char Goes Here */
}
void visitString(String s)
{
  /* Code for String Goes Here */
}

