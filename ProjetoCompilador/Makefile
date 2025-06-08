# ===========================
# C Simplificado LLVM Compiler
# ===========================

# Variáveis
CC = gcc
CFLAGS = -g -Wall -Wno-unused-function -Iinclude -Iinclude/LLVM -Iinclude/SymbolTable
LDFLAGS = `llvm-config --cflags --ldflags --libs core` -rdynamic

SRC = src/LLVMUtils.c src/SymbolTable.c
PARSER = compiler/parser.y
LEXER = compiler/lexer.l
OBJDIR = objects
PARSER_C = $(OBJDIR)/parser.tab.c
PARSER_H = $(OBJDIR)/parser.tab.h
LEXER_C = $(OBJDIR)/lexer.yy.c

TARGET = $(OBJDIR)/ccompiler
EXEMPLO = Exemplos/ExemplosPrintfScanf.txt

# Regras principais
all: $(OBJDIR) $(TARGET)
	@echo "=================================="
	@echo " Compilando e executando exemplo "
	@echo "=================================="
	@./$(TARGET) < $(EXEMPLO)

$(TARGET): $(PARSER_C) $(LEXER_C) $(SRC)
	@echo "=================================="
	@echo "Linkando arquivos objeto..."
	@echo "=================================="
	$(CC) $(CFLAGS) $(PARSER_C) $(LEXER_C) $(SRC) -o $(TARGET) $(LDFLAGS)
	@echo "=================================="
	@echo "Compilação concluída!"
	@echo "Executando o compilador..."

$(PARSER_C) $(PARSER_H): $(PARSER) | $(OBJDIR)
	@echo "=================================="
	@echo "Gerando parser com Bison..."
	@echo "=================================="
	bison -d -o $(PARSER_C) $(PARSER) -Wcounterexamples

$(LEXER_C): $(LEXER) | $(OBJDIR)
	@echo "=================================="
	@echo "Gerando lexer com Flex..."
	@echo "=================================="
	flex -l -o $(LEXER_C) $(LEXER)

clean:
	@echo "=================================="
	@echo "Limpando arquivos gerados..."
	@echo "=================================="
	rm -f $(PARSER_C) $(PARSER_H) $(LEXER_C) $(TARGET)
	@echo "=================================="
	@echo "Limpeza concluída!"
	@echo "=================================="

.PHONY: all clean