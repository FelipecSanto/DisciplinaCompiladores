# Regras
all:
	bison -d parser.y -o parser.tab.c
	lex -l -o lexer.yy.c lexer.l
	gcc parser.tab.c lexer.yy.c -Wall -Wno-unused-function -o tinycompiler
	./tinycompiler < ExemplosAula3.txt

clear:
	rm -f parser.tab.c parser.tab.h lexer.yy.c tinycompiler