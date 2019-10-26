CC = gcc
CCFLAGS = -g -W -Wall

FLEX = flex
FLEX_OPTS = -Pdfng

BISON = bison
BISON_OPTS = -t -pdfng

OBJS = Absyn.o Lexer.o Parser.o Printer.o

.PHONY : clean distclean

all : Testdfng

clean :
	rm -f *.o Testdfng dfng.aux dfng.log dfng.pdf dfng.dvi dfng.ps dfng

distclean : clean
	rm -f Absyn.h Absyn.c Test.c Parser.c Parser.h Lexer.c Skeleton.c Skeleton.h Printer.c Printer.h Makefile dfng.l dfng.y dfng.tex

Testdfng : ${OBJS} Test.o
	@echo "Linking Testdfng..."
	${CC} ${CCFLAGS} ${OBJS} Test.o -o Testdfng

Absyn.o : Absyn.c Absyn.h
	${CC} ${CCFLAGS} -c Absyn.c

Lexer.c : dfng.l
	${FLEX} ${FLEX_OPTS} -oLexer.c dfng.l

Parser.c : dfng.y
	${BISON} ${BISON_OPTS} dfng.y -o Parser.c

Lexer.o : Lexer.c Parser.h
	${CC} ${CCFLAGS} -c Lexer.c

Parser.o : Parser.c Absyn.h
	${CC} ${CCFLAGS} -c Parser.c

Printer.o : Printer.c Printer.h Absyn.h
	${CC} ${CCFLAGS} -c Printer.c

Test.o : Test.c Parser.h Printer.h Absyn.h
	${CC} ${CCFLAGS} -c Test.c
