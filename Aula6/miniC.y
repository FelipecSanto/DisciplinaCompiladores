%{
#include "VarType.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <signal.h>
#include <unistd.h>
#include <stdint.h>
#include <execinfo.h>
#include <llvm-c/Core.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/Target.h>
#include <llvm-c/ExecutionEngine.h>

#define HASH_SIZE 100

typedef struct Symbol {
    char* id;
    double value;
    VarType type;
    struct Symbol* next;
} Symbol;

typedef struct SymbolTable {
    Symbol* table[HASH_SIZE];
    struct SymbolTable* prev; // points to the previous scope
} SymbolTable;

SymbolTable* currentScope = NULL;

unsigned int hash(const char* id) {
    unsigned int h = 0;
    for (; *id; id++) {
        h = (h << 4) + *id;
    }
    return h % HASH_SIZE;
}

Symbol* findSymbol(const char* id) {
    SymbolTable* scope = currentScope;
    while (scope != NULL) {
        Symbol* sym = scope->table[hash(id)];
        while (sym != NULL) {
            if (strcmp(sym->id, id) == 0) return sym;
            sym = sym->next;
        }
        scope = scope->prev;
    }
    return NULL;
}

void insertSymbol(const char* id, double value, VarType type) {
    if(currentScope) {
        Symbol* sym = findSymbol(id);
        if (sym != NULL) {
            sym->value = value;
            sym->type = type;
        } else {
            unsigned int index = hash(id);
            sym = malloc(sizeof(Symbol));
            sym->id = strdup(id);
            sym->value = value;
            sym->type = type;
            sym->next = currentScope->table[index];
            currentScope->table[index] = sym;
        }
    }
}

void pushScope() {
    SymbolTable* newScope = malloc(sizeof(SymbolTable));
    for (int i = 0; i < HASH_SIZE; i++) {
        newScope->table[i] = NULL;
    }
    newScope->prev = currentScope;
    currentScope = newScope;
}

void popScope() {
    if (currentScope == NULL) exit(1);
    for (int i = 0; i < HASH_SIZE; i++) {
        Symbol* sym = currentScope->table[i];
        while (sym != NULL) {
            Symbol* temp = sym;
            sym = sym->next;
            free(temp->id);
            free(temp);
        }
    }
    SymbolTable* tempScope = currentScope;
    currentScope = currentScope->prev;
    free(tempScope);
}

void freeSymbolTable(SymbolTable* table) {
    while (table != NULL) {
        for (int i = 0; i < HASH_SIZE; i++) {
            Symbol* sym = table->table[i];
            while (sym != NULL) {
                Symbol* temp = sym;
                sym = sym->next;
                free(temp->id);
                free(temp);
            }
        }
        SymbolTable* temp = table;
        table = table->prev;
        free(temp);
    }
}

#define MAX_VARS 1000

char* var_names[MAX_VARS];
LLVMValueRef var_values[MAX_VARS];
int var_count = 0;

LLVMModuleRef module;
LLVMBuilderRef builder;
LLVMContextRef context;
LLVMValueRef mainFunc;
LLVMBasicBlockRef entry;

void allocaVars(const char* name, VarType type) {
    if (var_count >= MAX_VARS) {
        fprintf(stderr, "Error: too many variables.\n");
        exit(1);
    }

    LLVMTypeRef llvm_type;
    switch (type) {
        case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
        case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
        case TYPE_CHAR:  llvm_type = LLVMInt8TypeInContext(context); break;
        case TYPE_BOOL:  llvm_type = LLVMInt1TypeInContext(context); break;
        default:         llvm_type = LLVMDoubleTypeInContext(context); break;
    }
    LLVMValueRef alloc = LLVMBuildAlloca(builder, llvm_type, name);
    var_names[var_count] = strdup(name);
    var_values[var_count++] = alloc;
}

LLVMValueRef getVarLLVM(const char* name) {
    for (int i = 0; i < var_count; ++i)
        if (strcmp(var_names[i], name) == 0)
            return var_values[i];
    
    return NULL;
}

LLVMValueRef createGlobalString(const char* str, const char* name) {
    LLVMValueRef str_const = LLVMConstStringInContext(context, str, strlen(str), 1);
    LLVMValueRef global = LLVMAddGlobal(module, LLVMTypeOf(str_const), name);
    LLVMSetInitializer(global, str_const);
    LLVMSetGlobalConstant(global, 1);
    LLVMSetLinkage(global, LLVMPrivateLinkage);
    return global;
}

LLVMValueRef aux;

int yylex();
int yywrap( );
void yyerror(const char* str);
extern int yylineno;

int if_condition = 1;
int if_else_condition = 0;

%}

%union {
    struct {
        double value;
        VarType type;
        LLVMValueRef llvm_value;
    } number;
    struct {
        LLVMBasicBlockRef ifBB, elseBB, endIFBB;
    } if_else_blocks;
    struct {
        LLVMBasicBlockRef condBB, bodyBB, endWHILEBB;
    } while_blocks;
    char* id;
}


%token IF 
%token ELSE
%token INT CHAR FLOAT BOOL
%token READ
%token WRITE
%token WHILE
%token <id> ID 
%token <number> NUMBER
%token <id> STRING
%token RECEIVE
%token EQUAL
%token NEQUAL
%token LESS
%token GREAT
%token LEQUAL
%token GEQUAL
%token AND
%token OR
%token NOT
%token PLUS 
%token MIN
%token MULT
%token DIV
%token LEFTPAR 
%token RIGHTPAR
%token DONE
%token LEFTKEYS
%token RIGHTKEYS

/* declare precedence and associativity of operators */
%left OR
%left AND
%nonassoc LESS GREAT LEQUAL GEQUAL EQUAL NEQUAL
%left PLUS MIN
%left MULT DIV
%right NOT

/* declare non-terminals */
%type <number> expression soma_sub mult_div term comparison log_exp cast
%type program declaration comand assignment write 
%type <if_else_blocks> if_then else if_then_aux if_then_aux2
%type <while_blocks> while while_aux

/* give us more detailed errors */
%define parse.error verbose


%%

program: /* empty */ {}
       | comand program {}
       | declaration program {}
       | error program { yyerrok; yyclearin; }
       ;



declaration: INT ID DONE {
                if(if_condition == 1) {
                    insertSymbol($2, -DBL_MAX, TYPE_INT);
                    allocaVars($2, TYPE_INT);
                }
           }
           | FLOAT ID DONE {
                if(if_condition == 1) {
                    insertSymbol($2, -DBL_MAX, TYPE_FLOAT);
                    allocaVars($2, TYPE_FLOAT);
                }
           }
           | CHAR ID DONE {
                if(if_condition == 1) {
                    insertSymbol($2, -DBL_MAX, TYPE_CHAR);
                    allocaVars($2, TYPE_CHAR);
                }
           }
           | BOOL ID DONE {
                if(if_condition == 1) {
                    insertSymbol($2, -DBL_MAX, TYPE_BOOL);
                    allocaVars($2, TYPE_BOOL);
                }
           }
           ;




comand: assignment {}
      | if_then {}
      | while {}
      | write {}
      | read {}
      ;



assignment: ID RECEIVE expression DONE {
                Symbol* symbol = findSymbol($1);
                LLVMValueRef var = getVarLLVM($1);
                LLVMTypeRef llvm_type;
                if (symbol) {
                    switch (symbol->type) {
                        case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                        case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                        case TYPE_CHAR:  llvm_type = LLVMInt8TypeInContext(context); break;
                        case TYPE_BOOL:  llvm_type = LLVMInt1TypeInContext(context); break;
                        default:         llvm_type = LLVMInt32TypeInContext(context); break;
                    }
                }
                LLVMValueRef value = $3.llvm_value;
                if(symbol) {
                    if (symbol->type == $3.type) {
                        LLVMBuildStore(builder, value, var);
                    }
                    // Cast se necessário
                    else if (symbol->type == TYPE_FLOAT && $3.type == TYPE_INT) {
                        value = LLVMBuildSIToFP(builder, value, llvm_type, "inttofloat");
                        LLVMBuildStore(builder, value, var);
                    }
                    else if (symbol->type == TYPE_INT && $3.type == TYPE_FLOAT) {
                        printf("Warning: casting float to int for variable '%s' at line %d.\n", $1, yylineno);
                        value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
                        LLVMBuildStore(builder, value, var);
                    }
                }

                // Atualiza a tabela de símbolos
                if(if_condition == 1) {
                    if (symbol) {
                        if (symbol->type == $3.type) {
                            insertSymbol($1, $3.value, symbol->type);
                        } else if (symbol->type == TYPE_FLOAT && $3.type == TYPE_INT) {
                            insertSymbol($1, $3.value, symbol->type);
                        } else if (symbol->type == TYPE_INT && $3.type == TYPE_FLOAT) {
                            insertSymbol($1, (int)$3.value, symbol->type);
                        } else {
                            fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
                        }
                    } else {
                        fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", $1, yylineno);
                    }
                }
		  }
	      ;




if_then: IF LEFTPAR expression RIGHTPAR {
            pushScope();
            if ($3.type == TYPE_BOOL) {
                if_condition = $3.value;
                if_else_condition = $3.value;
            } else {
                fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
                if_condition = 0;
            }
            aux = $3.llvm_value;
        } if_then_aux LEFTKEYS program RIGHTKEYS if_then_aux2 {
            if (if_condition == 0) {
                popScope();
                if_condition = 1;
            }

            // Ao final do bloco if, faz branch para o fim do if
            LLVMBuildBr(builder, $10.endIFBB);

            // Entra no bloco else para continuar parsing
            LLVMPositionBuilderAtEnd(builder, $6.elseBB);
        } else {
            // Ao final do else, faz branch para o fim do if
            LLVMBuildBr(builder, $10.endIFBB);

            // Posiciona o builder no bloco de saída do if
            LLVMPositionBuilderAtEnd(builder, $10.endIFBB);
        }
        ;

if_then_aux: {
    // Cria blocos para if, else e fim
    $$.ifBB = LLVMAppendBasicBlockInContext(context, mainFunc, "if");
    $$.elseBB = LLVMAppendBasicBlockInContext(context, mainFunc, "else");

    // Gera branch condicional
    LLVMBuildCondBr(builder, aux, $$.ifBB, $$.elseBB);

    // Entra no bloco do if
    LLVMPositionBuilderAtEnd(builder, $$.ifBB);
};

if_then_aux2: {
    $$.endIFBB = LLVMAppendBasicBlockInContext(context, mainFunc, "endif");
};

else: /* empty */ {}
    | ELSE {
        pushScope();
        if (if_else_condition == 1) {
            if_condition = 0;
        }
    } LEFTKEYS program RIGHTKEYS {
        if (if_condition == 0) {
            if_condition = 1;
        }

        if(if_else_condition == 1) {
            popScope();
        }
    }
    ;



while: WHILE while_aux LEFTPAR expression RIGHTPAR {
        LLVMBuildCondBr(builder, $4.llvm_value, $2.bodyBB, $2.endWHILEBB);

        // Corpo do while
        LLVMPositionBuilderAtEnd(builder, $2.bodyBB);
    } LEFTKEYS program RIGHTKEYS {
        // Ao final do corpo, volta para o condicional
        LLVMBuildBr(builder, $2.condBB);

        // Posiciona o builder no bloco de saída do while
        LLVMPositionBuilderAtEnd(builder, $2.endWHILEBB);
    }
    ;

while_aux: {
    // Cria blocos para condicional, corpo e fim do while
        $$.condBB = LLVMAppendBasicBlockInContext(context, mainFunc, "while.cond");
        $$.bodyBB = LLVMAppendBasicBlockInContext(context, mainFunc, "while.body");
        $$.endWHILEBB = LLVMAppendBasicBlockInContext(context, mainFunc, "while.end");

        // Branch para o bloco condicional
        LLVMBuildBr(builder, $$.condBB);

        // Condicional
        LLVMPositionBuilderAtEnd(builder, $$.condBB);
};

write: WRITE LEFTPAR ID RIGHTPAR DONE {
        Symbol* sym = findSymbol($3);
        if (sym == NULL) {
            fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", $3, yylineno);
        }
        else if(sym->value == -DBL_MAX) {
            fprintf(stderr, "Error: variable '%s' is uninitialized at line %d.\n", $3, yylineno);
        }
        else {
            LLVMValueRef var = getVarLLVM($3);
            LLVMValueRef loaded[1];
            LLVMValueRef write_func;
            switch (sym->type) {
                case TYPE_INT:
                    write_func = LLVMGetNamedFunction(module, "write_int");
                    loaded[0] = LLVMBuildLoad2(builder, LLVMInt32TypeInContext(context), var, "loadtmp");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, loaded, 1, "");
                    break;
                case TYPE_FLOAT:
                    write_func = LLVMGetNamedFunction(module, "write_float");
                    loaded[0] = LLVMBuildLoad2(builder, LLVMDoubleTypeInContext(context), var, "loadtmp");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, loaded, 1, "");
                    break;
                case TYPE_BOOL:
                    write_func = LLVMGetNamedFunction(module, "write_bool");
                    loaded[0] = LLVMBuildLoad2(builder, LLVMInt1TypeInContext(context), var, "loadtmp");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, loaded, 1, "");
                    break;
                case TYPE_CHAR:
                    write_func = LLVMGetNamedFunction(module, "write_char");
                    loaded[0] = LLVMBuildLoad2(builder, LLVMInt8TypeInContext(context), var, "loadtmp");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, loaded, 1, "");
                    break;
                default:
                    fprintf(stderr, "Error: unsupported type for variable '%s' at line %d.\n", $3, yylineno);
            }
        }
     }
    | WRITE LEFTPAR NUMBER RIGHTPAR DONE {
        LLVMValueRef write_func;
        LLVMValueRef arg[1];
        switch ($3.type) {
            case TYPE_INT:
                write_func = LLVMGetNamedFunction(module, "write_int");
                arg[0] = LLVMConstInt(LLVMInt32TypeInContext(context), (int)$3.value, 0);
                LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, arg, 1, "");
                break;
            case TYPE_FLOAT:
                write_func = LLVMGetNamedFunction(module, "write_float");
                arg[0] = LLVMConstReal(LLVMDoubleTypeInContext(context), $3.value);
                LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, arg, 1, "");
                break;
            case TYPE_CHAR:
                write_func = LLVMGetNamedFunction(module, "write_char");
                arg[0] = LLVMConstInt(LLVMInt8TypeInContext(context), (char)$3.value, 0);
                LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, arg, 1, "");
                break;
            case TYPE_BOOL:
                write_func = LLVMGetNamedFunction(module, "write_bool");
                arg[0] = LLVMConstInt(LLVMInt1TypeInContext(context), (int)$3.value, 0);
                LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, arg, 1, "");
                break;
            default:
                fprintf(stderr, "Error: unsupported type for number at line %d.\n", yylineno);
        }
    }
    | WRITE LEFTPAR STRING RIGHTPAR DONE {
        LLVMValueRef write_func = LLVMGetNamedFunction(module, "write_string");
        LLVMValueRef str = LLVMBuildPointerCast(builder, createGlobalString($3, "str_literal"), LLVMPointerType(LLVMInt8TypeInContext(context), 0), "");
        LLVMValueRef arg[1];
        arg[0] = str;
        LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, arg, 1, "");
        free($3);
    }
    ;


read: READ LEFTPAR ID RIGHTPAR DONE {
        Symbol* sym = findSymbol($3);
        if (sym == NULL) {
            fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", $3, yylineno);
        }
        else {
            LLVMValueRef var = getVarLLVM($3);
            LLVMValueRef arg[1];
            arg[0] = var;
            LLVMValueRef read_func;
            switch (sym->type) {
                case TYPE_INT:
                    read_func = LLVMGetNamedFunction(module, "read_int");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(read_func)), read_func, arg, 1, "");
                    break;
                case TYPE_FLOAT:
                    read_func = LLVMGetNamedFunction(module, "read_float");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(read_func)), read_func, arg, 1, "");
                    break;
                case TYPE_BOOL:
                    read_func = LLVMGetNamedFunction(module, "read_bool");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(read_func)), read_func, arg, 1, "");
                    break;
                case TYPE_CHAR:
                    read_func = LLVMGetNamedFunction(module, "read_char");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(read_func)), read_func, arg, 1, "");
                    break;
                default:
                    fprintf(stderr, "Error: unsupported type for variable '%s' at line %d.\n", $3, yylineno);
            }
        }
    }
    ;



expression: soma_sub { $$.value = $1.value; $$.type = $1.type; $$.llvm_value = $1.llvm_value; }
		  | mult_div { $$.value = $1.value; $$.type = $1.type; $$.llvm_value = $1.llvm_value; }
          | LEFTPAR expression RIGHTPAR { $$.value = $2.value; $$.type = $2.type; $$.llvm_value = $2.llvm_value; }
          | comparison { $$.value = $1.value; $$.type = $1.type; $$.llvm_value = $1.llvm_value; }
          | log_exp { $$.value = $1.value; $$.type = $1.type; $$.llvm_value = $1.llvm_value; }
          | cast { $$.value = $1.value; $$.type = $1.type; $$.llvm_value = $1.llvm_value; }
		  | term { $$.value = $1.value; $$.type = $1.type; $$.llvm_value = $1.llvm_value; }
		  ;

soma_sub: expression PLUS expression { 
                if ($1.type == TYPE_INT && $3.type == TYPE_INT) {
                    $$.value = $1.value + $3.value;
                    $$.type = TYPE_INT;
                    $$.llvm_value = LLVMBuildAdd(builder, $1.llvm_value, $3.llvm_value, "addtmp");
                } else if ((($1.type == TYPE_FLOAT || $1.type == TYPE_INT) && ($3.type == TYPE_INT || $3.type == TYPE_FLOAT))) {
                    // Promove para float se necessário
                    LLVMValueRef left = $1.llvm_value;
                    LLVMValueRef right = $3.llvm_value;
                    if ($1.type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ($3.type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    $$.value = $1.value + $3.value;
                    $$.type = TYPE_FLOAT;
                    $$.llvm_value = LLVMBuildFAdd(builder, left, right, "faddtmp");
                } else {
                    fprintf(stderr, "Error: incompatible types for addition at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
        }
    	| expression MIN  expression {
                if ($1.type == TYPE_INT && $3.type == TYPE_INT) {
                    $$.value = $1.value - $3.value;
                    $$.type = TYPE_INT;
                    $$.llvm_value = LLVMBuildSub(builder, $1.llvm_value, $3.llvm_value, "subtmp");
                } else if ((($1.type == TYPE_FLOAT || $1.type == TYPE_INT) && ($3.type == TYPE_INT || $3.type == TYPE_FLOAT))) {
                    // Promove para float se necessário
                    LLVMValueRef left = $1.llvm_value;
                    LLVMValueRef right = $3.llvm_value;
                    if ($1.type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ($3.type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    $$.value = $1.value - $3.value;
                    $$.type = TYPE_FLOAT;
                    $$.llvm_value = LLVMBuildFSub(builder, left, right, "fsubtmp");
                } else {
                    fprintf(stderr, "Error: incompatible types for subtraction at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
        }
		;

mult_div: expression MULT expression {
                if ($1.type == TYPE_INT && $3.type == TYPE_INT) {
                    $$.value = $1.value * $3.value;
                    $$.type = TYPE_INT;
                    $$.llvm_value = LLVMBuildMul(builder, $1.llvm_value, $3.llvm_value, "multtmp");
                } else if ((($1.type == TYPE_FLOAT || $1.type == TYPE_INT) && ($3.type == TYPE_INT || $3.type == TYPE_FLOAT))) {
                    // Promove para float se necessário
                    LLVMValueRef left = $1.llvm_value;
                    LLVMValueRef right = $3.llvm_value;
                    if ($1.type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ($3.type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    $$.value = $1.value * $3.value;
                    $$.type = TYPE_FLOAT;
                    $$.llvm_value = LLVMBuildFMul(builder, left, right, "fmulttmp");
                } else {
                    fprintf(stderr, "Error: incompatible types for multiplication at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
        }
		| expression DIV  expression { 
                if ($3.value == 0.0) {
                        fprintf(stderr, "Error: division by zero at line %d.\n", yylineno);
                        $$.value = -1;
                        $$.type = TYPE_UNKNOWN;
                } else {
                    if ($1.type == TYPE_INT && $3.type == TYPE_INT) {
                        $$.value = $1.value / $3.value;
                        $$.type = TYPE_INT;
                        $$.llvm_value = LLVMBuildSDiv(builder, $1.llvm_value, $3.llvm_value, "divtmp");
                    } else if ((($1.type == TYPE_FLOAT || $1.type == TYPE_INT) && ($3.type == TYPE_INT || $3.type == TYPE_FLOAT))) {
                        // Promove para float se necessário
                        LLVMValueRef left = $1.llvm_value;
                        LLVMValueRef right = $3.llvm_value;
                        if ($1.type == TYPE_INT)
                            left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                        if ($3.type == TYPE_INT)
                            right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                        $$.value = $1.value / $3.value;
                        $$.type = TYPE_FLOAT;
                        $$.llvm_value = LLVMBuildFDiv(builder, left, right, "fdivtmp");
                    } else {
                        fprintf(stderr, "Error: incompatible types for division at line %d.\n", yylineno);
                        $$.value = -1;
                        $$.type = TYPE_UNKNOWN;
                    }
                }
		}
		;

comparison: expression LESS expression {
                if ($1.type == TYPE_INT && $3.type == TYPE_INT) {
                    $$.value = $1.value < $3.value;
                    $$.type = TYPE_BOOL;
                    $$.llvm_value = LLVMBuildICmp(builder, LLVMIntSLT, $1.llvm_value, $3.llvm_value, "cmptmp");
                } else if (($1.type == TYPE_FLOAT || $1.type == TYPE_INT) && ($3.type == TYPE_FLOAT || $3.type == TYPE_INT)) {
                    // Promove para float se necessário
                    LLVMValueRef left = $1.llvm_value;
                    LLVMValueRef right = $3.llvm_value;
                    if ($1.type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ($3.type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    $$.value = $1.value < $3.value;
                    $$.type = TYPE_BOOL;
                    $$.llvm_value = LLVMBuildFCmp(builder, LLVMRealULT, left, right, "cmptmp");
                } else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
            }
            | expression GREAT expression {
                if ($1.type == TYPE_INT && $3.type == TYPE_INT) {
                    $$.value = $1.value > $3.value;
                    $$.type = TYPE_BOOL;
                    $$.llvm_value = LLVMBuildICmp(builder, LLVMIntSGT, $1.llvm_value, $3.llvm_value, "cmptmp");
                } else if (($1.type == TYPE_FLOAT || $1.type == TYPE_INT) && ($3.type == TYPE_FLOAT || $3.type == TYPE_INT)) {
                    // Promove para float se necessário
                    LLVMValueRef left = $1.llvm_value;
                    LLVMValueRef right = $3.llvm_value;
                    if ($1.type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ($3.type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    $$.value = $1.value > $3.value;
                    $$.type = TYPE_BOOL;
                    $$.llvm_value = LLVMBuildFCmp(builder, LLVMRealUGT, left, right, "fcmptmp");
                } else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
            }
            | expression LEQUAL expression {
                if ($1.type == TYPE_INT && $3.type == TYPE_INT) {
                    $$.value = $1.value <= $3.value;
                    $$.type = TYPE_BOOL;
                    $$.llvm_value = LLVMBuildICmp(builder, LLVMIntSLE, $1.llvm_value, $3.llvm_value, "cmptmp");
                } else if (($1.type == TYPE_FLOAT || $1.type == TYPE_INT) && ($3.type == TYPE_FLOAT || $3.type == TYPE_INT)) {
                    // Promove para float se necessário
                    LLVMValueRef left = $1.llvm_value;
                    LLVMValueRef right = $3.llvm_value;
                    if ($1.type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ($3.type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    $$.value = $1.value <= $3.value;
                    $$.type = TYPE_BOOL;
                    $$.llvm_value = LLVMBuildFCmp(builder, LLVMRealULE, left, right, "fcmptmp");
                } else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
            }
            | expression GEQUAL expression {
                if ($1.type == TYPE_INT && $3.type == TYPE_INT) {
                    $$.value = $1.value >= $3.value;
                    $$.type = TYPE_BOOL;
                    $$.llvm_value = LLVMBuildICmp(builder, LLVMIntSGE, $1.llvm_value, $3.llvm_value, "cmptmp");
                } else if (($1.type == TYPE_FLOAT || $1.type == TYPE_INT) && ($3.type == TYPE_FLOAT || $3.type == TYPE_INT)) {
                    // Promove para float se necessário
                    LLVMValueRef left = $1.llvm_value;
                    LLVMValueRef right = $3.llvm_value;
                    if ($1.type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ($3.type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    $$.value = $1.value >= $3.value;
                    $$.type = TYPE_BOOL;
                    $$.llvm_value = LLVMBuildFCmp(builder, LLVMRealUGE, left, right, "fcmptmp");
                } else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
            }
            | expression EQUAL  expression { 
                if ($1.type == TYPE_INT && $3.type == TYPE_INT) {
                    $$.value = $1.value == $3.value;
                    $$.type = TYPE_BOOL;
                    $$.llvm_value = LLVMBuildICmp(builder, LLVMIntEQ, $1.llvm_value, $3.llvm_value, "cmptmp");
                } else if (($1.type == TYPE_FLOAT || $1.type == TYPE_INT) && ($3.type == TYPE_FLOAT || $3.type == TYPE_INT)) {
                    // Promove para float se necessário
                    LLVMValueRef left = $1.llvm_value;
                    LLVMValueRef right = $3.llvm_value;
                    if ($1.type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    else if ($3.type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    $$.value = $1.value == $3.value;
                    $$.type = TYPE_BOOL;
                    $$.llvm_value = LLVMBuildFCmp(builder, LLVMRealUEQ, left, right, "fcmptmp");
                } else if ($1.type == TYPE_CHAR && $3.type == TYPE_CHAR) {
                    $$.value = $1.value == $3.value;
                    $$.type = TYPE_BOOL;
                    $$.llvm_value = LLVMBuildICmp(builder, LLVMIntEQ, $1.llvm_value, $3.llvm_value, "cmptmp");
                } else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
            }
            | expression NEQUAL expression {
                if ($1.type == TYPE_INT && $3.type == TYPE_INT) {
                    $$.value = $1.value != $3.value;
                    $$.type = TYPE_BOOL;
                    $$.llvm_value = LLVMBuildICmp(builder, LLVMIntNE, $1.llvm_value, $3.llvm_value, "cmptmp");
                } else if (($1.type == TYPE_FLOAT || $1.type == TYPE_INT) && ($3.type == TYPE_FLOAT || $3.type == TYPE_INT)) {
                    LLVMValueRef left = $1.llvm_value;
                    LLVMValueRef right = $3.llvm_value;
                    if ($1.type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ($3.type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    $$.value = $1.value != $3.value;
                    $$.type = TYPE_BOOL;
                    $$.llvm_value = LLVMBuildFCmp(builder, LLVMRealUNE, left, right, "fcmptmp");
                } else if ($1.type == TYPE_CHAR && $3.type == TYPE_CHAR) {
                    $$.value = $1.value != $3.value;
                    $$.type = TYPE_BOOL;
                    $$.llvm_value = LLVMBuildICmp(builder, LLVMIntNE, $1.llvm_value, $3.llvm_value, "cmptmp");
                } else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
            }
            ;

log_exp: expression AND expression {
            if ($1.type == TYPE_BOOL && $3.type == TYPE_BOOL) {
                $$.value = $1.value && $3.value;
                $$.type = TYPE_BOOL;
                $$.llvm_value = LLVMBuildAnd(builder, $1.llvm_value, $3.llvm_value, "andtmp");
            } else {
                fprintf(stderr, "Error: logical AND between incompatible types at line %d.\n", yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
            }
       }
       | expression OR  expression {
            if ($1.type == TYPE_BOOL && $3.type == TYPE_BOOL) {
                $$.value = $1.value || $3.value;
                $$.type = TYPE_BOOL;
                $$.llvm_value = LLVMBuildOr(builder, $1.llvm_value, $3.llvm_value, "ortmp");
            } else {
                fprintf(stderr, "Error: logical OR between incompatible types at line %d.\n", yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
            }
       }
       | NOT expression {
            if ($2.type == TYPE_BOOL) {
                $$.value = !$2.value;
                $$.type = TYPE_BOOL;
                $$.llvm_value = LLVMBuildNot(builder, $2.llvm_value, "nottmp");
            } else {
                fprintf(stderr, "Error: logical NOT on incompatible type at line %d.\n", yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
            }
        }
       ;

cast: LEFTPAR INT RIGHTPAR LEFTPAR expression RIGHTPAR {
        int temp = (int) $5.value;
        $$.value = (double) temp;
        $$.type = TYPE_INT;
        $$.llvm_value = LLVMBuildFPToSI(builder, $5.llvm_value, LLVMInt32TypeInContext(context), "castint");
    }
    | LEFTPAR INT RIGHTPAR term {
        int temp = (int) $4.value;
        $$.value = (double) temp;
        $$.type = TYPE_INT;
        $$.llvm_value = LLVMBuildFPToSI(builder, $4.llvm_value, LLVMInt32TypeInContext(context), "castint");
    }
    | LEFTPAR FLOAT RIGHTPAR LEFTPAR expression RIGHTPAR {
        $$.value = $5.value;
        $$.type = TYPE_FLOAT;
        $$.llvm_value = LLVMBuildSIToFP(builder, $5.llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
    }
    | LEFTPAR FLOAT RIGHTPAR term {
        $$.value = $4.value;
        $$.type = TYPE_FLOAT;
        $$.llvm_value = LLVMBuildSIToFP(builder, $4.llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
    }
    | LEFTPAR CHAR RIGHTPAR LEFTPAR expression RIGHTPAR {
        $$.value = (double) ((char) $5.value);
        $$.type = TYPE_CHAR;
        $$.llvm_value = LLVMBuildTrunc(builder, $5.llvm_value, LLVMInt8TypeInContext(context), "castchar");
    }
    | LEFTPAR CHAR RIGHTPAR term {
        $$.value = (double) ((char) $4.value);
        $$.type = TYPE_CHAR;
        $$.llvm_value = LLVMBuildTrunc(builder, $4.llvm_value, LLVMInt8TypeInContext(context), "castchar");
    }
    | LEFTPAR BOOL RIGHTPAR LEFTPAR expression RIGHTPAR {
        $$.value = ($5.value != 0.0) ? 1.0 : 0.0;
        $$.type = TYPE_BOOL;
        // Compara com zero para gerar i1
        LLVMValueRef zero = LLVMConstInt(LLVMTypeOf($5.llvm_value), 0, 0);
        $$.llvm_value = LLVMBuildICmp(builder, LLVMIntNE, $5.llvm_value, zero, "castbool");
    }
    | LEFTPAR BOOL RIGHTPAR term {
        $$.value = ($4.value != 0.0) ? 1.0 : 0.0;
        $$.type = TYPE_BOOL;
        // Compara com zero para gerar i1
        LLVMValueRef zero = LLVMConstInt(LLVMTypeOf($4.llvm_value), 0, 0);
        $$.llvm_value = LLVMBuildICmp(builder, LLVMIntNE, $4.llvm_value, zero, "castbool");
    }
    ;

term: NUMBER { 
        $$.value = $1.value; 
        $$.type = $1.type; 
        switch ($1.type) {
            case TYPE_INT:   $$.llvm_value = LLVMConstInt(LLVMInt32TypeInContext(context), (int)$1.value, 0); break;
            case TYPE_FLOAT: $$.llvm_value = LLVMConstReal(LLVMDoubleTypeInContext(context), $1.value); break;
            case TYPE_CHAR:  $$.llvm_value = LLVMConstInt(LLVMInt8TypeInContext(context), (int)$1.value, 0); break;
            case TYPE_BOOL:  $$.llvm_value = LLVMConstInt(LLVMInt1TypeInContext(context), (int)$1.value, 0); break;
            default:         $$.llvm_value = LLVMConstReal(LLVMDoubleTypeInContext(context), $1.value); break;
        }
    }
    | ID {
        Symbol* sym = findSymbol($1);
        if (!sym) {
            fprintf(stderr, "Undeclared variable '%s' at line %d\n", $1, yylineno);
            $$.value = -1;
            $$.type = TYPE_UNKNOWN;
        } else {
            if (sym->value == -DBL_MAX) {
                fprintf(stderr, "Uninitialized variable '%s' at line %d\n", $1, yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
            } else {
                $$.value = sym->value;
                $$.type = sym->type;
                LLVMValueRef var = getVarLLVM($1);
                LLVMTypeRef llvm_type;
                switch (sym->type) {
                    case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                    case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                    case TYPE_CHAR:  llvm_type = LLVMInt8TypeInContext(context); break;
                    case TYPE_BOOL:  llvm_type = LLVMInt1TypeInContext(context); break;
                    default:         llvm_type = LLVMDoubleTypeInContext(context); break;
                }
                $$.llvm_value = LLVMBuildLoad2(builder, llvm_type, var, "loadtmp");
            }
        }
    }
	;


%%

int yywrap( ) {
  return 1;
}

void yyerror(const char* str) {
    fprintf(stderr, "Compilation error at line %d: '%s'.\n", yylineno, str);
}

void handleSegfault(int sig) {
    void *array[10];
    size_t size;

    fprintf(stderr, "Segmentation fault (signal %d). Exiting gracefully.\n", sig);

    // Captura o backtrace
    size = backtrace(array, 10);
    backtrace_symbols_fd(array, size, STDERR_FILENO);

    exit(1);
}

void printSymbolTable(SymbolTable* table) {
    printf("\nSymbol Table:\n");
    printf("-------------------------------------------------\n");
    printf("| %-10s | %-10s | %-10s |\n", "Identifier", "Value", "Type");
    printf("-------------------------------------------------\n");
    while (table != NULL) {
        for (int i = 0; i < HASH_SIZE; i++) {
            Symbol* sym = table->table[i];
            while (sym != NULL) {
                if(sym->value >= INT_MAX - 10 || sym->value <= INT_MIN + 10) {
                    switch (sym->type) {
                        case TYPE_INT: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "INT"); break;
                        case TYPE_BOOL: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "BOOL"); break;
                        case TYPE_FLOAT: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "FLOAT"); break;
                        case TYPE_CHAR: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "CHAR"); break;
                        default: break;
                    }
                }
                else {
                    switch (sym->type) {
                        case TYPE_INT: printf("| %-10s | %-10d | %-10s |\n", sym->id, (int)sym->value, "INT"); break;
                        case TYPE_BOOL: printf("| %-10s | %-10d | %-10s |\n", sym->id, (int)sym->value, "BOOL"); break;
                        case TYPE_FLOAT: printf("| %-10s | %-10.2lf | %-10s |\n", sym->id, sym->value, "FLOAT"); break;
                        case TYPE_CHAR: printf("| %-10s | %-10c | %-10s |\n", sym->id, (char)sym->value, "CHAR"); break;
                        case TYPE_UNKNOWN: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "UNKNOWN"); break;
                        default: break;
                    }
                }
                sym = sym->next;
            }
        }
        table = table->prev;
    }
    printf("-------------------------------------------------\n\n");
}

int main( ) {
    signal(SIGSEGV, handleSegfault); // Handle segmentation faults
    pushScope(); // Initialize the first scope

    // Inicialização LLVM
    context = LLVMContextCreate();
    module = LLVMModuleCreateWithNameInContext("miniC", context);
    builder = LLVMCreateBuilderInContext(context);

    // Cria função write: void write(param)
    LLVMTypeRef write_int_args[] = { LLVMInt32TypeInContext(context) };
    LLVMTypeRef write_int_type = LLVMFunctionType(LLVMVoidTypeInContext(context), write_int_args, 1, 0);
    LLVMAddFunction(module, "write_int", write_int_type);

    LLVMTypeRef write_float_args[] = { LLVMDoubleTypeInContext(context) };
    LLVMTypeRef write_float_type = LLVMFunctionType(LLVMVoidTypeInContext(context), write_float_args, 1, 0);
    LLVMAddFunction(module, "write_float", write_float_type);

    LLVMTypeRef write_char_args[] = { LLVMInt8TypeInContext(context) };
    LLVMTypeRef write_char_type = LLVMFunctionType(LLVMVoidTypeInContext(context), write_char_args, 1, 0);
    LLVMAddFunction(module, "write_char", write_char_type);

    LLVMTypeRef write_bool_args[] = { LLVMInt1TypeInContext(context) };
    LLVMTypeRef write_bool_type = LLVMFunctionType(LLVMVoidTypeInContext(context), write_bool_args, 1, 0);
    LLVMAddFunction(module, "write_bool", write_bool_type);

    LLVMTypeRef write_string_args[] = { LLVMPointerType(LLVMInt8TypeInContext(context), 0) };
    LLVMTypeRef write_string_type = LLVMFunctionType(LLVMVoidTypeInContext(context), write_string_args, 1, 0);
    LLVMAddFunction(module, "write_string", write_string_type);

    // Cria função read: void read(param)
    LLVMTypeRef read_int_args[] = { LLVMInt32TypeInContext(context) };
    LLVMTypeRef read_int_type = LLVMFunctionType(LLVMVoidTypeInContext(context), read_int_args, 1, 0);
    LLVMAddFunction(module, "read_int", read_int_type);

    LLVMTypeRef read_float_args[] = { LLVMDoubleTypeInContext(context) };
    LLVMTypeRef read_float_type = LLVMFunctionType(LLVMVoidTypeInContext(context), read_float_args, 1, 0);
    LLVMAddFunction(module, "read_float", read_float_type);

    LLVMTypeRef read_char_args[] = { LLVMInt8TypeInContext(context) };
    LLVMTypeRef read_char_type = LLVMFunctionType(LLVMVoidTypeInContext(context), read_char_args, 1, 0);
    LLVMAddFunction(module, "read_char", read_char_type);

    LLVMTypeRef read_bool_args[] = { LLVMInt1TypeInContext(context) };
    LLVMTypeRef read_bool_type = LLVMFunctionType(LLVMVoidTypeInContext(context), read_bool_args, 1, 0);
    LLVMAddFunction(module, "read_bool", read_bool_type);

    // Cria função main: int main()
    LLVMTypeRef mainType = LLVMFunctionType(LLVMInt32TypeInContext(context), NULL, 0, 0);
    mainFunc = LLVMAddFunction(module, "main", mainType);
    entry = LLVMAppendBasicBlockInContext(context, mainFunc, "entry");
    LLVMPositionBuilderAtEnd(builder, entry);

    yyparse( );

    // Retorno main
    LLVMBuildRet(builder, LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0));

    // Imprime IR
    char *irstr = LLVMPrintModuleToString(module);
    printf("\nLLVM IR:\n%s\n", irstr);
    LLVMDisposeMessage(irstr);

    LLVMDisposeBuilder(builder);
    LLVMDisposeModule(module);
    LLVMContextDispose(context);
    
    /* printSymbolTable(currentScope); // Print the symbol table */
    freeSymbolTable(currentScope); // Free the symbol table
    return 0;
}