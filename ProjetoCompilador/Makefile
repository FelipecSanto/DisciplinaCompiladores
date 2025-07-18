# ===========================
# C Simplificado LLVM Compiler
# ===========================

# Variáveis
CC = gcc
CFLAGS = -g -Wall -Wno-unused-function -Iinclude -Iinclude/LLVM -Iinclude/SymbolTable
LDFLAGS = `llvm-config --cflags --ldflags --libs core` -rdynamic

SRC = src/LLVMUtils.c src/SymbolTable.c src/UtilsConditionals.c src/VarType.c
PARSER = compiler/parser.y
LEXER = compiler/lexer.l

OBJDIR = objects
CODEIR = $(OBJDIR)/codeIR
FINALCODE = $(OBJDIR)/FinalCode

PARSER_C = $(CODEIR)/parser.tab.c
PARSER_H = $(CODEIR)/parser.tab.h
LEXER_C = $(CODEIR)/lexer.yy.c

TARGET = $(CODEIR)/ccompiler
OUTPUT_LLVM = $(CODEIR)/output.ll
OUTPUT_ASM = $(FINALCODE)/output.s
OUTPUT_OBJ = $(FINALCODE)/output.o
OUTPUT_ELF = $(FINALCODE)/output.elf

EXEMPLO = Exemplos/Simples.c

# Regras principais
all: clean_always $(OUTPUT_ELF)

clean_always:
	@if [ -d "$(OBJDIR)" ]; then \
	echo "Removendo diretório $(OBJDIR) antes do build..."; \
	rm -rf $(OBJDIR); \
	fi

$(OUTPUT_ELF): $(OUTPUT_OBJ)
	@echo "=================================="
	@echo " Linkando arquivo ELF para RISC-V"
	@echo "=================================="
	riscv64-unknown-elf-ld -m elf32lriscv -Ttext=0x80000000 -o $(OUTPUT_ELF) $(OUTPUT_OBJ)

$(OUTPUT_OBJ): $(OUTPUT_ASM)
	@echo "=================================="
	@echo " Montando arquivo objeto (.o)"
	@echo "=================================="
	riscv64-unknown-elf-as -march=rv32im -mabi=ilp32 -o $(OUTPUT_OBJ) $(OUTPUT_ASM)

$(OUTPUT_ASM): $(OUTPUT_LLVM)
	@echo "=================================="
	@echo " Criando arquivo assembly com LLC "
	@echo "=================================="
	@mkdir -p $(FINALCODE)
	llc -O0 -march=riscv32 -mattr=+m,+a,+f,+d $(OUTPUT_LLVM) -o $(OUTPUT_ASM)

$(OUTPUT_LLVM): | $(CODEIR) $(FINALCODE) $(TARGET)
	@echo "=================================="
	@echo " Criando arquivo LLVM "
	@echo "=================================="
	@./$(TARGET) < $(EXEMPLO) > $(OUTPUT_LLVM)

$(TARGET): $(PARSER_C) $(LEXER_C) $(SRC)
	@echo "=================================="
	@echo "Linkando arquivos objeto..."
	@echo "=================================="
	$(CC) $(CFLAGS) $(PARSER_C) $(LEXER_C) $(SRC) -o $(TARGET) $(LDFLAGS)
	@echo "=================================="
	@echo "Compilação concluída!"
	@echo "Executando o compilador..."

$(PARSER_C) $(PARSER_H): $(PARSER) | $(CODEIR)
	@echo "=================================="
	@echo "Gerando parser com Bison..."
	@echo "=================================="
	bison -d -o $(PARSER_C) $(PARSER) -Wcounterexamples

$(LEXER_C): $(LEXER) | $(CODEIR)
	@echo "=================================="
	@echo "Gerando lexer com Flex..."
	@echo "=================================="
	flex -l -o $(LEXER_C) $(LEXER)

$(CODEIR):
	mkdir -p $(CODEIR)

$(FINALCODE):
	mkdir -p $(FINALCODE)

clean:
	@echo "=================================="
	@echo "Limpando arquivos gerados..."
	@echo "=================================="
	rm -rf $(OBJDIR)
	@echo "=================================="
	@echo "Limpeza concluída!"
	@echo "=================================="

condicional: EXEMPLO = Exemplos/Condicionais.c
condicional: all

printscan: EXEMPLO = Exemplos/PrintfScanf.c
printscan: all

declaracao: EXEMPLO = Exemplos/DeclaracaoInicializavel.c
declaracao: all

vetor: EXEMPLO = Exemplos/Vetor.c
vetor: all

escopo: EXEMPLO = Exemplos/Escopo.c
escopo: all

cast: EXEMPLO = Exemplos/Casts.c
cast: all

funcoes: EXEMPLO = Exemplos/Funcoes.c
funcoes: all

simples: EXEMPLO = Exemplos/Simples.c
simples: all

repeticao: EXEMPLO = Exemplos/WhileForDoWhile.c
repeticao: all

incremento: EXEMPLO = Exemplos/Incremento.c
incremento: all

semantica: EXEMPLO = Exemplos/Semantica.c
semantica: all

crivo: EXEMPLO = Exemplos/Crivo.c
crivo: all

.PHONY: all clean condicional printscan declaracao vetor escopo cast funcoes simples repeticao incremento semantica
