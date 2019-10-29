/*** BNFC-Generated Pretty Printer and Abstract Syntax Viewer ***/

#include "Printer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INDENT_WIDTH 2

int _n_;
char *buf_;
int cur_;
int buf_size;

/* You may wish to change the renderC functions */
void renderC(Char c)
{
  if (c == '{')
  {
     bufAppendC('\n');
     indent();
     bufAppendC(c);
     _n_ = _n_ + INDENT_WIDTH;
     bufAppendC('\n');
     indent();
  }
  else if (c == '(' || c == '[')
     bufAppendC(c);
  else if (c == ')' || c == ']')
  {
     backup();
     bufAppendC(c);
  }
  else if (c == '}')
  {
     int t;
     _n_ = _n_ - INDENT_WIDTH;
     for(t=0; t<INDENT_WIDTH; t++) {
       backup();
     }
     bufAppendC(c);
     bufAppendC('\n');
     indent();
  }
  else if (c == ',')
  {
     backup();
     bufAppendC(c);
     bufAppendC(' ');
  }
  else if (c == ';')
  {
     backup();
     bufAppendC(c);
     bufAppendC('\n');
     indent();
  }
  else if (c == 0) return;
  else
  {
     bufAppendC(' ');
     bufAppendC(c);
     bufAppendC(' ');
  }
}
void renderS(String s)
{
  if(strlen(s) > 0)
  {
    bufAppendS(s);
    bufAppendC(' ');
  }
}
void indent(void)
{
  int n = _n_;
  while (n > 0)
  {
    bufAppendC(' ');
    n--;
  }
}
void backup(void)
{
  if (buf_[cur_ - 1] == ' ')
  {
    buf_[cur_ - 1] = 0;
    cur_--;
  }
}
char *printProgram(Program p)
{
  _n_ = 0;
  bufReset();
  ppProgram(p, 0);
  return buf_;
}
char *printListExternal_declaration(ListExternal_declaration p)
{
  _n_ = 0;
  bufReset();
  ppListExternal_declaration(p, 0);
  return buf_;
}
char *printExternal_declaration(External_declaration p)
{
  _n_ = 0;
  bufReset();
  ppExternal_declaration(p, 0);
  return buf_;
}
char *printFunction(Function p)
{
  _n_ = 0;
  bufReset();
  ppFunction(p, 0);
  return buf_;
}
char *printArg(Arg p)
{
  _n_ = 0;
  bufReset();
  ppArg(p, 0);
  return buf_;
}
char *printDecl(Decl p)
{
  _n_ = 0;
  bufReset();
  ppDecl(p, 0);
  return buf_;
}
char *printListFunction(ListFunction p)
{
  _n_ = 0;
  bufReset();
  ppListFunction(p, 0);
  return buf_;
}
char *printListStm(ListStm p)
{
  _n_ = 0;
  bufReset();
  ppListStm(p, 0);
  return buf_;
}
char *printListDecl(ListDecl p)
{
  _n_ = 0;
  bufReset();
  ppListDecl(p, 0);
  return buf_;
}
char *printListArg(ListArg p)
{
  _n_ = 0;
  bufReset();
  ppListArg(p, 0);
  return buf_;
}
char *printListIdent(ListIdent p)
{
  _n_ = 0;
  bufReset();
  ppListIdent(p, 0);
  return buf_;
}
char *printStm(Stm p)
{
  _n_ = 0;
  bufReset();
  ppStm(p, 0);
  return buf_;
}
char *printExp(Exp p)
{
  _n_ = 0;
  bufReset();
  ppExp(p, 0);
  return buf_;
}
char *printListExp(ListExp p)
{
  _n_ = 0;
  bufReset();
  ppListExp(p, 0);
  return buf_;
}
char *printType(Type p)
{
  _n_ = 0;
  bufReset();
  ppType(p, 0);
  return buf_;
}
char *showProgram(Program p)
{
  _n_ = 0;
  bufReset();
  shProgram(p);
  return buf_;
}
char *showListExternal_declaration(ListExternal_declaration p)
{
  _n_ = 0;
  bufReset();
  shListExternal_declaration(p);
  return buf_;
}
char *showExternal_declaration(External_declaration p)
{
  _n_ = 0;
  bufReset();
  shExternal_declaration(p);
  return buf_;
}
char *showFunction(Function p)
{
  _n_ = 0;
  bufReset();
  shFunction(p);
  return buf_;
}
char *showArg(Arg p)
{
  _n_ = 0;
  bufReset();
  shArg(p);
  return buf_;
}
char *showDecl(Decl p)
{
  _n_ = 0;
  bufReset();
  shDecl(p);
  return buf_;
}
char *showListFunction(ListFunction p)
{
  _n_ = 0;
  bufReset();
  shListFunction(p);
  return buf_;
}
char *showListStm(ListStm p)
{
  _n_ = 0;
  bufReset();
  shListStm(p);
  return buf_;
}
char *showListDecl(ListDecl p)
{
  _n_ = 0;
  bufReset();
  shListDecl(p);
  return buf_;
}
char *showListArg(ListArg p)
{
  _n_ = 0;
  bufReset();
  shListArg(p);
  return buf_;
}
char *showListIdent(ListIdent p)
{
  _n_ = 0;
  bufReset();
  shListIdent(p);
  return buf_;
}
char *showStm(Stm p)
{
  _n_ = 0;
  bufReset();
  shStm(p);
  return buf_;
}
char *showExp(Exp p)
{
  _n_ = 0;
  bufReset();
  shExp(p);
  return buf_;
}
char *showListExp(ListExp p)
{
  _n_ = 0;
  bufReset();
  shListExp(p);
  return buf_;
}
char *showType(Type p)
{
  _n_ = 0;
  bufReset();
  shType(p);
  return buf_;
}
void ppProgram(Program p, int _i_)
{
  switch(p->kind)
  {
  case is_Prog:
    if (_i_ > 0) renderC(_L_PAREN);
    ppListExternal_declaration(p->u.prog_.listexternal_declaration_, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing Program!\n");
    exit(1);
  }
}

void ppListExternal_declaration(ListExternal_declaration listexternal_declaration, int i)
{
  while(listexternal_declaration != 0)
  {
    if (listexternal_declaration->listexternal_declaration_ == 0)
    {
      ppExternal_declaration(listexternal_declaration->external_declaration_, i);
      renderS("");
      listexternal_declaration = 0;
    }
    else
    {
      ppExternal_declaration(listexternal_declaration->external_declaration_, i);
      renderS("");
      listexternal_declaration = listexternal_declaration->listexternal_declaration_;
    }
  }
}

void ppExternal_declaration(External_declaration p, int _i_)
{
  switch(p->kind)
  {
  case is_Afunc:
    if (_i_ > 0) renderC(_L_PAREN);
    ppFunction(p->u.afunc_.function_, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_Global:
    if (_i_ > 0) renderC(_L_PAREN);
    ppStm(p->u.global_.stm_, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing External_declaration!\n");
    exit(1);
  }
}

void ppFunction(Function p, int _i_)
{
  switch(p->kind)
  {
  case is_Fun:
    if (_i_ > 0) renderC(_L_PAREN);
    ppType(p->u.fun_.type_, 0);
    ppIdent(p->u.fun_.ident_, 0);
    renderC('(');
    ppListArg(p->u.fun_.listarg_, 0);
    renderC(')');
    renderC('{');
    ppListStm(p->u.fun_.liststm_, 0);
    renderC('}');

    if (_i_ > 0) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing Function!\n");
    exit(1);
  }
}

void ppArg(Arg p, int _i_)
{
  switch(p->kind)
  {
  case is_ADecl:
    if (_i_ > 0) renderC(_L_PAREN);
    ppType(p->u.adecl_.type_, 0);
    ppIdent(p->u.adecl_.ident_, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_APred:
    if (_i_ > 0) renderC(_L_PAREN);
    ppType(p->u.apred_.type_, 0);
    ppIdent(p->u.apred_.ident_, 0);
    renderC('=');
    ppExp(p->u.apred_.exp_, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing Arg!\n");
    exit(1);
  }
}

void ppDecl(Decl p, int _i_)
{
  switch(p->kind)
  {
  case is_Dec:
    if (_i_ > 0) renderC(_L_PAREN);
    ppType(p->u.dec_.type_, 0);
    ppListIdent(p->u.dec_.listident_, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing Decl!\n");
    exit(1);
  }
}

void ppListFunction(ListFunction listfunction, int i)
{
  while(listfunction != 0)
  {
    if (listfunction->listfunction_ == 0)
    {
      ppFunction(listfunction->function_, i);
      renderS("");
      listfunction = 0;
    }
    else
    {
      ppFunction(listfunction->function_, i);
      renderS("");
      listfunction = listfunction->listfunction_;
    }
  }
}

void ppListStm(ListStm liststm, int i)
{
  while(liststm != 0)
  {
    if (liststm->liststm_ == 0)
    {
      ppStm(liststm->stm_, i);
      renderS("");
      liststm = 0;
    }
    else
    {
      ppStm(liststm->stm_, i);
      renderS("");
      liststm = liststm->liststm_;
    }
  }
}

void ppListDecl(ListDecl listdecl, int i)
{
  while(listdecl != 0)
  {
    if (listdecl->listdecl_ == 0)
    {
      ppDecl(listdecl->decl_, i);

      listdecl = 0;
    }
    else
    {
      ppDecl(listdecl->decl_, i);
      renderC(',');
      listdecl = listdecl->listdecl_;
    }
  }
}

void ppListArg(ListArg listarg, int i)
{
  while(listarg != 0)
  {
    if (listarg->listarg_ == 0)
    {
      ppArg(listarg->arg_, i);

      listarg = 0;
    }
    else
    {
      ppArg(listarg->arg_, i);
      renderC(',');
      listarg = listarg->listarg_;
    }
  }
}

void ppListIdent(ListIdent listident, int i)
{
  while(listident != 0)
  {
    if (listident->listident_ == 0)
    {
      ppIdent(listident->ident_, i);

      listident = 0;
    }
    else
    {
      ppIdent(listident->ident_, i);
      renderC(',');
      listident = listident->listident_;
    }
  }
}

void ppStm(Stm p, int _i_)
{
  switch(p->kind)
  {
  case is_SDecl:
    if (_i_ > 0) renderC(_L_PAREN);
    ppDecl(p->u.sdecl_.decl_, 0);
    renderC(';');

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_SDecls:
    if (_i_ > 0) renderC(_L_PAREN);
    ppDecl(p->u.sdecls_.decl_, 0);
    renderC(',');
    ppListIdent(p->u.sdecls_.listident_, 0);
    renderC(';');

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_SInit:
    if (_i_ > 0) renderC(_L_PAREN);
    ppDecl(p->u.sinit_.decl_, 0);
    renderC('=');
    ppExp(p->u.sinit_.exp_, 0);
    renderC(';');

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_SExp:
    if (_i_ > 0) renderC(_L_PAREN);
    ppExp(p->u.sexp_.exp_, 0);
    renderC(';');

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_SBlock:
    if (_i_ > 0) renderC(_L_PAREN);
    renderC('{');
    ppListStm(p->u.sblock_.liststm_, 0);
    renderC('}');

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_SWhile:
    if (_i_ > 0) renderC(_L_PAREN);
    renderS("while");
    renderC('(');
    ppExp(p->u.swhile_.exp_, 0);
    renderC(')');
    ppStm(p->u.swhile_.stm_, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_SReturn:
    if (_i_ > 0) renderC(_L_PAREN);
    renderS("return");
    ppExp(p->u.sreturn_.exp_, 0);
    renderC(';');

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_SIfElse:
    if (_i_ > 0) renderC(_L_PAREN);
    renderS("if");
    renderC('(');
    ppExp(p->u.sifelse_.exp_, 0);
    renderC(')');
    ppStm(p->u.sifelse_.stm_1, 0);
    renderS("else");
    ppStm(p->u.sifelse_.stm_2, 0);

    if (_i_ > 0) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing Stm!\n");
    exit(1);
  }
}

void ppExp(Exp p, int _i_)
{
  switch(p->kind)
  {
  case is_EInt:
    if (_i_ > 15) renderC(_L_PAREN);
    ppInteger(p->u.eint_.integer_, 0);

    if (_i_ > 15) renderC(_R_PAREN);
    break;

  case is_EDouble:
    if (_i_ > 15) renderC(_L_PAREN);
    ppDouble(p->u.edouble_.double_, 0);

    if (_i_ > 15) renderC(_R_PAREN);
    break;

  case is_ETrue:
    if (_i_ > 15) renderC(_L_PAREN);
    renderS("true");

    if (_i_ > 15) renderC(_R_PAREN);
    break;

  case is_EFalse:
    if (_i_ > 15) renderC(_L_PAREN);
    renderS("false");

    if (_i_ > 15) renderC(_R_PAREN);
    break;

  case is_EIdent:
    if (_i_ > 15) renderC(_L_PAREN);
    ppIdent(p->u.eident_.ident_, 0);

    if (_i_ > 15) renderC(_R_PAREN);
    break;

  case is_EApp:
    if (_i_ > 15) renderC(_L_PAREN);
    ppIdent(p->u.eapp_.ident_, 0);
    renderC('(');
    ppListExp(p->u.eapp_.listexp_, 0);
    renderC(')');

    if (_i_ > 15) renderC(_R_PAREN);
    break;

  case is_EPIncr:
    if (_i_ > 14) renderC(_L_PAREN);
    ppExp(p->u.epincr_.exp_, 15);
    renderS("++");

    if (_i_ > 14) renderC(_R_PAREN);
    break;

  case is_EPDecr:
    if (_i_ > 14) renderC(_L_PAREN);
    ppExp(p->u.epdecr_.exp_, 15);
    renderS("--");

    if (_i_ > 14) renderC(_R_PAREN);
    break;

  case is_EIncr:
    if (_i_ > 13) renderC(_L_PAREN);
    renderS("++");
    ppExp(p->u.eincr_.exp_, 14);

    if (_i_ > 13) renderC(_R_PAREN);
    break;

  case is_EDecr:
    if (_i_ > 13) renderC(_L_PAREN);
    renderS("--");
    ppExp(p->u.edecr_.exp_, 14);

    if (_i_ > 13) renderC(_R_PAREN);
    break;

  case is_ETimes:
    if (_i_ > 12) renderC(_L_PAREN);
    ppExp(p->u.etimes_.exp_1, 12);
    renderC('*');
    ppExp(p->u.etimes_.exp_2, 13);

    if (_i_ > 12) renderC(_R_PAREN);
    break;

  case is_EDiv:
    if (_i_ > 12) renderC(_L_PAREN);
    ppExp(p->u.ediv_.exp_1, 12);
    renderC('/');
    ppExp(p->u.ediv_.exp_2, 13);

    if (_i_ > 12) renderC(_R_PAREN);
    break;

  case is_EPlus:
    if (_i_ > 11) renderC(_L_PAREN);
    ppExp(p->u.eplus_.exp_1, 11);
    renderC('+');
    ppExp(p->u.eplus_.exp_2, 12);

    if (_i_ > 11) renderC(_R_PAREN);
    break;

  case is_EMinus:
    if (_i_ > 11) renderC(_L_PAREN);
    ppExp(p->u.eminus_.exp_1, 11);
    renderC('-');
    ppExp(p->u.eminus_.exp_2, 12);

    if (_i_ > 11) renderC(_R_PAREN);
    break;

  case is_ELt:
    if (_i_ > 9) renderC(_L_PAREN);
    ppExp(p->u.elt_.exp_1, 9);
    renderC('<');
    ppExp(p->u.elt_.exp_2, 10);

    if (_i_ > 9) renderC(_R_PAREN);
    break;

  case is_EGt:
    if (_i_ > 9) renderC(_L_PAREN);
    ppExp(p->u.egt_.exp_1, 9);
    renderC('>');
    ppExp(p->u.egt_.exp_2, 10);

    if (_i_ > 9) renderC(_R_PAREN);
    break;

  case is_ELtEq:
    if (_i_ > 9) renderC(_L_PAREN);
    ppExp(p->u.elteq_.exp_1, 9);
    renderS("<=");
    ppExp(p->u.elteq_.exp_2, 10);

    if (_i_ > 9) renderC(_R_PAREN);
    break;

  case is_EGtWq:
    if (_i_ > 9) renderC(_L_PAREN);
    ppExp(p->u.egtwq_.exp_1, 9);
    renderS(">=");
    ppExp(p->u.egtwq_.exp_2, 10);

    if (_i_ > 9) renderC(_R_PAREN);
    break;

  case is_EEq:
    if (_i_ > 8) renderC(_L_PAREN);
    ppExp(p->u.eeq_.exp_1, 8);
    renderS("==");
    ppExp(p->u.eeq_.exp_2, 9);

    if (_i_ > 8) renderC(_R_PAREN);
    break;

  case is_ENEq:
    if (_i_ > 8) renderC(_L_PAREN);
    ppExp(p->u.eneq_.exp_1, 8);
    renderS("!=");
    ppExp(p->u.eneq_.exp_2, 9);

    if (_i_ > 8) renderC(_R_PAREN);
    break;

  case is_EAnd:
    if (_i_ > 4) renderC(_L_PAREN);
    ppExp(p->u.eand_.exp_1, 4);
    renderS("&&");
    ppExp(p->u.eand_.exp_2, 5);

    if (_i_ > 4) renderC(_R_PAREN);
    break;

  case is_EOr:
    if (_i_ > 3) renderC(_L_PAREN);
    ppExp(p->u.eor_.exp_1, 3);
    renderS("||");
    ppExp(p->u.eor_.exp_2, 4);

    if (_i_ > 3) renderC(_R_PAREN);
    break;

  case is_EAss:
    if (_i_ > 2) renderC(_L_PAREN);
    ppExp(p->u.eass_.exp_1, 3);
    renderC('=');
    ppExp(p->u.eass_.exp_2, 2);

    if (_i_ > 2) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing Exp!\n");
    exit(1);
  }
}

void ppListExp(ListExp listexp, int i)
{
  while(listexp != 0)
  {
    if (listexp->listexp_ == 0)
    {
      ppExp(listexp->exp_, i);

      listexp = 0;
    }
    else
    {
      ppExp(listexp->exp_, i);
      renderC(',');
      listexp = listexp->listexp_;
    }
  }
}

void ppType(Type p, int _i_)
{
  switch(p->kind)
  {
  case is_Tbool:
    if (_i_ > 0) renderC(_L_PAREN);
    renderS("bool");

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_Tdouble:
    if (_i_ > 0) renderC(_L_PAREN);
    renderS("double");

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_Tint:
    if (_i_ > 0) renderC(_L_PAREN);
    renderS("int");

    if (_i_ > 0) renderC(_R_PAREN);
    break;

  case is_Tvoid:
    if (_i_ > 0) renderC(_L_PAREN);
    renderS("void");

    if (_i_ > 0) renderC(_R_PAREN);
    break;


  default:
    fprintf(stderr, "Error: bad kind field when printing Type!\n");
    exit(1);
  }
}

void ppInteger(Integer n, int i)
{
  char tmp[16];
  sprintf(tmp, "%d", n);
  bufAppendS(tmp);
}
void ppDouble(Double d, int i)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppendS(tmp);
}
void ppChar(Char c, int i)
{
  bufAppendC('\'');
  bufAppendC(c);
  bufAppendC('\'');
}
void ppString(String s, int i)
{
  bufAppendC('\"');
  bufAppendS(s);
  bufAppendC('\"');
}
void ppIdent(String s, int i)
{
  renderS(s);
}


void shProgram(Program p)
{
  switch(p->kind)
  {
  case is_Prog:
    bufAppendC('(');

    bufAppendS("Prog");

    bufAppendC(' ');

    shListExternal_declaration(p->u.prog_.listexternal_declaration_);

    bufAppendC(')');

    break;

  default:
    fprintf(stderr, "Error: bad kind field when showing Program!\n");
    exit(1);
  }
}

void shListExternal_declaration(ListExternal_declaration listexternal_declaration)
{
  bufAppendC('[');
  while(listexternal_declaration != 0)
  {
    if (listexternal_declaration->listexternal_declaration_)
    {
      shExternal_declaration(listexternal_declaration->external_declaration_);
      bufAppendS(", ");
      listexternal_declaration = listexternal_declaration->listexternal_declaration_;
    }
    else
    {
      shExternal_declaration(listexternal_declaration->external_declaration_);
      listexternal_declaration = 0;
    }
  }
  bufAppendC(']');
}

void shExternal_declaration(External_declaration p)
{
  switch(p->kind)
  {
  case is_Afunc:
    bufAppendC('(');

    bufAppendS("Afunc");

    bufAppendC(' ');

    shFunction(p->u.afunc_.function_);

    bufAppendC(')');

    break;
  case is_Global:
    bufAppendC('(');

    bufAppendS("Global");

    bufAppendC(' ');

    shStm(p->u.global_.stm_);

    bufAppendC(')');

    break;

  default:
    fprintf(stderr, "Error: bad kind field when showing External_declaration!\n");
    exit(1);
  }
}

void shFunction(Function p)
{
  switch(p->kind)
  {
  case is_Fun:
    bufAppendC('(');

    bufAppendS("Fun");

    bufAppendC(' ');

    shType(p->u.fun_.type_);
  bufAppendC(' ');
    shIdent(p->u.fun_.ident_);
  bufAppendC(' ');
    shListArg(p->u.fun_.listarg_);
  bufAppendC(' ');
    shListStm(p->u.fun_.liststm_);

    bufAppendC(')');

    break;

  default:
    fprintf(stderr, "Error: bad kind field when showing Function!\n");
    exit(1);
  }
}

void shArg(Arg p)
{
  switch(p->kind)
  {
  case is_ADecl:
    bufAppendC('(');

    bufAppendS("ADecl");

    bufAppendC(' ');

    shType(p->u.adecl_.type_);
  bufAppendC(' ');
    shIdent(p->u.adecl_.ident_);

    bufAppendC(')');

    break;
  case is_APred:
    bufAppendC('(');

    bufAppendS("APred");

    bufAppendC(' ');

    shType(p->u.apred_.type_);
  bufAppendC(' ');
    shIdent(p->u.apred_.ident_);
  bufAppendC(' ');
    shExp(p->u.apred_.exp_);

    bufAppendC(')');

    break;

  default:
    fprintf(stderr, "Error: bad kind field when showing Arg!\n");
    exit(1);
  }
}

void shDecl(Decl p)
{
  switch(p->kind)
  {
  case is_Dec:
    bufAppendC('(');

    bufAppendS("Dec");

    bufAppendC(' ');

    shType(p->u.dec_.type_);
  bufAppendC(' ');
    shListIdent(p->u.dec_.listident_);

    bufAppendC(')');

    break;

  default:
    fprintf(stderr, "Error: bad kind field when showing Decl!\n");
    exit(1);
  }
}

void shListFunction(ListFunction listfunction)
{
  bufAppendC('[');
  while(listfunction != 0)
  {
    if (listfunction->listfunction_)
    {
      shFunction(listfunction->function_);
      bufAppendS(", ");
      listfunction = listfunction->listfunction_;
    }
    else
    {
      shFunction(listfunction->function_);
      listfunction = 0;
    }
  }
  bufAppendC(']');
}

void shListStm(ListStm liststm)
{
  bufAppendC('[');
  while(liststm != 0)
  {
    if (liststm->liststm_)
    {
      shStm(liststm->stm_);
      bufAppendS(", ");
      liststm = liststm->liststm_;
    }
    else
    {
      shStm(liststm->stm_);
      liststm = 0;
    }
  }
  bufAppendC(']');
}

void shListDecl(ListDecl listdecl)
{
  bufAppendC('[');
  while(listdecl != 0)
  {
    if (listdecl->listdecl_)
    {
      shDecl(listdecl->decl_);
      bufAppendS(", ");
      listdecl = listdecl->listdecl_;
    }
    else
    {
      shDecl(listdecl->decl_);
      listdecl = 0;
    }
  }
  bufAppendC(']');
}

void shListArg(ListArg listarg)
{
  bufAppendC('[');
  while(listarg != 0)
  {
    if (listarg->listarg_)
    {
      shArg(listarg->arg_);
      bufAppendS(", ");
      listarg = listarg->listarg_;
    }
    else
    {
      shArg(listarg->arg_);
      listarg = 0;
    }
  }
  bufAppendC(']');
}

void shListIdent(ListIdent listident)
{
  bufAppendC('[');
  while(listident != 0)
  {
    if (listident->listident_)
    {
      shIdent(listident->ident_);
      bufAppendS(", ");
      listident = listident->listident_;
    }
    else
    {
      shIdent(listident->ident_);
      listident = 0;
    }
  }
  bufAppendC(']');
}

void shStm(Stm p)
{
  switch(p->kind)
  {
  case is_SDecl:
    bufAppendC('(');

    bufAppendS("SDecl");

    bufAppendC(' ');

    shDecl(p->u.sdecl_.decl_);

    bufAppendC(')');

    break;
  case is_SDecls:
    bufAppendC('(');

    bufAppendS("SDecls");

    bufAppendC(' ');

    shDecl(p->u.sdecls_.decl_);
  bufAppendC(' ');
    shListIdent(p->u.sdecls_.listident_);

    bufAppendC(')');

    break;
  case is_SInit:
    bufAppendC('(');

    bufAppendS("SInit");

    bufAppendC(' ');

    shDecl(p->u.sinit_.decl_);
  bufAppendC(' ');
    shExp(p->u.sinit_.exp_);

    bufAppendC(')');

    break;
  case is_SExp:
    bufAppendC('(');

    bufAppendS("SExp");

    bufAppendC(' ');

    shExp(p->u.sexp_.exp_);

    bufAppendC(')');

    break;
  case is_SBlock:
    bufAppendC('(');

    bufAppendS("SBlock");

    bufAppendC(' ');

    shListStm(p->u.sblock_.liststm_);

    bufAppendC(')');

    break;
  case is_SWhile:
    bufAppendC('(');

    bufAppendS("SWhile");

    bufAppendC(' ');

    shExp(p->u.swhile_.exp_);
  bufAppendC(' ');
    shStm(p->u.swhile_.stm_);

    bufAppendC(')');

    break;
  case is_SReturn:
    bufAppendC('(');

    bufAppendS("SReturn");

    bufAppendC(' ');

    shExp(p->u.sreturn_.exp_);

    bufAppendC(')');

    break;
  case is_SIfElse:
    bufAppendC('(');

    bufAppendS("SIfElse");

    bufAppendC(' ');

    shExp(p->u.sifelse_.exp_);
  bufAppendC(' ');
    shStm(p->u.sifelse_.stm_1);
  bufAppendC(' ');
    shStm(p->u.sifelse_.stm_2);

    bufAppendC(')');

    break;

  default:
    fprintf(stderr, "Error: bad kind field when showing Stm!\n");
    exit(1);
  }
}

void shExp(Exp p)
{
  switch(p->kind)
  {
  case is_EInt:
    bufAppendC('(');

    bufAppendS("EInt");

    bufAppendC(' ');

    shInteger(p->u.eint_.integer_);

    bufAppendC(')');

    break;
  case is_EDouble:
    bufAppendC('(');

    bufAppendS("EDouble");

    bufAppendC(' ');

    shDouble(p->u.edouble_.double_);

    bufAppendC(')');

    break;
  case is_ETrue:

    bufAppendS("ETrue");




    break;
  case is_EFalse:

    bufAppendS("EFalse");




    break;
  case is_EIdent:
    bufAppendC('(');

    bufAppendS("EIdent");

    bufAppendC(' ');

    shIdent(p->u.eident_.ident_);

    bufAppendC(')');

    break;
  case is_EApp:
    bufAppendC('(');

    bufAppendS("EApp");

    bufAppendC(' ');

    shIdent(p->u.eapp_.ident_);
  bufAppendC(' ');
    shListExp(p->u.eapp_.listexp_);

    bufAppendC(')');

    break;
  case is_EPIncr:
    bufAppendC('(');

    bufAppendS("EPIncr");

    bufAppendC(' ');

    shExp(p->u.epincr_.exp_);

    bufAppendC(')');

    break;
  case is_EPDecr:
    bufAppendC('(');

    bufAppendS("EPDecr");

    bufAppendC(' ');

    shExp(p->u.epdecr_.exp_);

    bufAppendC(')');

    break;
  case is_EIncr:
    bufAppendC('(');

    bufAppendS("EIncr");

    bufAppendC(' ');

    shExp(p->u.eincr_.exp_);

    bufAppendC(')');

    break;
  case is_EDecr:
    bufAppendC('(');

    bufAppendS("EDecr");

    bufAppendC(' ');

    shExp(p->u.edecr_.exp_);

    bufAppendC(')');

    break;
  case is_ETimes:
    bufAppendC('(');

    bufAppendS("ETimes");

    bufAppendC(' ');

    shExp(p->u.etimes_.exp_1);
  bufAppendC(' ');
    shExp(p->u.etimes_.exp_2);

    bufAppendC(')');

    break;
  case is_EDiv:
    bufAppendC('(');

    bufAppendS("EDiv");

    bufAppendC(' ');

    shExp(p->u.ediv_.exp_1);
  bufAppendC(' ');
    shExp(p->u.ediv_.exp_2);

    bufAppendC(')');

    break;
  case is_EPlus:
    bufAppendC('(');

    bufAppendS("EPlus");

    bufAppendC(' ');

    shExp(p->u.eplus_.exp_1);
  bufAppendC(' ');
    shExp(p->u.eplus_.exp_2);

    bufAppendC(')');

    break;
  case is_EMinus:
    bufAppendC('(');

    bufAppendS("EMinus");

    bufAppendC(' ');

    shExp(p->u.eminus_.exp_1);
  bufAppendC(' ');
    shExp(p->u.eminus_.exp_2);

    bufAppendC(')');

    break;
  case is_ELt:
    bufAppendC('(');

    bufAppendS("ELt");

    bufAppendC(' ');

    shExp(p->u.elt_.exp_1);
  bufAppendC(' ');
    shExp(p->u.elt_.exp_2);

    bufAppendC(')');

    break;
  case is_EGt:
    bufAppendC('(');

    bufAppendS("EGt");

    bufAppendC(' ');

    shExp(p->u.egt_.exp_1);
  bufAppendC(' ');
    shExp(p->u.egt_.exp_2);

    bufAppendC(')');

    break;
  case is_ELtEq:
    bufAppendC('(');

    bufAppendS("ELtEq");

    bufAppendC(' ');

    shExp(p->u.elteq_.exp_1);
  bufAppendC(' ');
    shExp(p->u.elteq_.exp_2);

    bufAppendC(')');

    break;
  case is_EGtWq:
    bufAppendC('(');

    bufAppendS("EGtWq");

    bufAppendC(' ');

    shExp(p->u.egtwq_.exp_1);
  bufAppendC(' ');
    shExp(p->u.egtwq_.exp_2);

    bufAppendC(')');

    break;
  case is_EEq:
    bufAppendC('(');

    bufAppendS("EEq");

    bufAppendC(' ');

    shExp(p->u.eeq_.exp_1);
  bufAppendC(' ');
    shExp(p->u.eeq_.exp_2);

    bufAppendC(')');

    break;
  case is_ENEq:
    bufAppendC('(');

    bufAppendS("ENEq");

    bufAppendC(' ');

    shExp(p->u.eneq_.exp_1);
  bufAppendC(' ');
    shExp(p->u.eneq_.exp_2);

    bufAppendC(')');

    break;
  case is_EAnd:
    bufAppendC('(');

    bufAppendS("EAnd");

    bufAppendC(' ');

    shExp(p->u.eand_.exp_1);
  bufAppendC(' ');
    shExp(p->u.eand_.exp_2);

    bufAppendC(')');

    break;
  case is_EOr:
    bufAppendC('(');

    bufAppendS("EOr");

    bufAppendC(' ');

    shExp(p->u.eor_.exp_1);
  bufAppendC(' ');
    shExp(p->u.eor_.exp_2);

    bufAppendC(')');

    break;
  case is_EAss:
    bufAppendC('(');

    bufAppendS("EAss");

    bufAppendC(' ');

    shExp(p->u.eass_.exp_1);
  bufAppendC(' ');
    shExp(p->u.eass_.exp_2);

    bufAppendC(')');

    break;

  default:
    fprintf(stderr, "Error: bad kind field when showing Exp!\n");
    exit(1);
  }
}

void shListExp(ListExp listexp)
{
  bufAppendC('[');
  while(listexp != 0)
  {
    if (listexp->listexp_)
    {
      shExp(listexp->exp_);
      bufAppendS(", ");
      listexp = listexp->listexp_;
    }
    else
    {
      shExp(listexp->exp_);
      listexp = 0;
    }
  }
  bufAppendC(']');
}

void shType(Type p)
{
  switch(p->kind)
  {
  case is_Tbool:

    bufAppendS("Tbool");




    break;
  case is_Tdouble:

    bufAppendS("Tdouble");




    break;
  case is_Tint:

    bufAppendS("Tint");




    break;
  case is_Tvoid:

    bufAppendS("Tvoid");




    break;

  default:
    fprintf(stderr, "Error: bad kind field when showing Type!\n");
    exit(1);
  }
}

void shInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppendS(tmp);
}
void shDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppendS(tmp);
}
void shChar(Char c)
{
  bufAppendC('\'');
  bufAppendC(c);
  bufAppendC('\'');
}
void shString(String s)
{
  bufAppendC('\"');
  bufAppendS(s);
  bufAppendC('\"');
}
void shIdent(String s)
{
  bufAppendC('\"');
  bufAppendS(s);
  bufAppendC('\"');
}

void bufAppendS(const char *s)
{
  int len = strlen(s);
  int n;
  while (cur_ + len > buf_size)
  {
    buf_size *= 2; /* Double the buffer size */
    resizeBuffer();
  }
  for(n = 0; n < len; n++)
  {
    buf_[cur_ + n] = s[n];
  }
  cur_ += len;
  buf_[cur_] = 0;
}
void bufAppendC(const char c)
{
  if (cur_ == buf_size)
  {
    buf_size *= 2; /* Double the buffer size */
    resizeBuffer();
  }
  buf_[cur_] = c;
  cur_++;
  buf_[cur_] = 0;
}
void bufReset(void)
{
  cur_ = 0;
  buf_size = BUFFER_INITIAL;
  resizeBuffer();
  memset(buf_, 0, buf_size);
}
void resizeBuffer(void)
{
  char *temp = (char *) malloc(buf_size);
  if (!temp)
  {
    fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
    exit(1);
  }
  if (buf_)
  {
    strncpy(temp, buf_, buf_size); /* peteg: strlcpy is safer, but not POSIX/ISO C. */
    free(buf_);
  }
  buf_ = temp;
}
char *buf_;
int cur_, buf_size;

