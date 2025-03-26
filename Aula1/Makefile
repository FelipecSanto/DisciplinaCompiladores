# Variáveis
LEXER_FILE = lexer.l
OUTPUT_FILE = lexer

# Regras
all:
	flex -o $(OUTPUT_FILE).yy.c $(LEXER_FILE)
	gcc -o $(OUTPUT_FILE) $(OUTPUT_FILE).yy.c -lfl
	./$(OUTPUT_FILE) < ExemplosAula2.txt

# Se você quiser passar o nome do arquivo `.l` como parâmetro
# Exemplo: make LEXER_FILE=outro_arquivo.l