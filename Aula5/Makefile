# Regras
all:
	bison -d miniC.y -o miniC.tab.c
	flex -l -o lexer.yy.c lexer.l
	gcc miniC.tab.c lexer.yy.c -Wall -Wno-unused-function -o tinycompiler
	./tinycompiler < ExemplosAula5.txt

clear:
	rm -f miniC.tab.c miniC.tab.h lexer.yy.c tinycompiler