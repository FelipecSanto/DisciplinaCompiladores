%{
#include "LLVMUtils.h"
#include "SymbolTable.h"

int yylex();
int yywrap( );
void yyerror(const char* str);
extern int yylineno;

%}

%union {
    struct {
        double value;
        VarType type;
        LLVMValueRef llvm_value;
    } number;

    char* id;
    char caractere;

    struct {
        LLVMBasicBlockRef ifBB, elseBB, endIFBB;
    } if_else_blocks;
    struct {
        LLVMBasicBlockRef condBB, bodyBB, endWHILEBB;
    } while_blocks;
}


%token IF ELSE
%token INT CHAR FLOAT BOOL
%token PRINTF SCANF
%token WHILE
%token <number> NUMBER
%token <id> ID STRING
%token <caractere> CARACTERE
%token RECEIVE
%token EQUAL NEQUAL LESS GREAT LEQUAL GEQUAL 
%token AND OR NOT
%token PLUS MIN MULT DIV
%token LEFTPAR RIGHTPAR LEFTKEYS RIGHTKEYS LEFTBRACKET RIGHTBRACKET
%token COMMA DONE

/* declare precedence and associativity of operators */
%left OR
%left AND
%nonassoc LESS GREAT LEQUAL GEQUAL EQUAL NEQUAL
%left PLUS MIN
%left MULT DIV
%right NOT

/* declare non-terminals */
%type <number> expression soma_sub mult_div term comparison log_exp cast
%type program declaration comand assignment printf scanf int_declaration float_declaration char_declaration bool_declaration
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



declaration: INT ID int_declaration DONE {
                insertSymbol($2, -DBL_MAX, TYPE_INT);
                allocaVars($2, TYPE_INT);
            }
            | INT ID RECEIVE expression int_declaration DONE {
                insertSymbol($2, $4.value, TYPE_INT);
                allocaVars($2, TYPE_INT);
                Symbol* symbol = findSymbol($2);
                LLVMValueRef var = getVarLLVM($2);
                LLVMTypeRef llvm_type = LLVMInt32TypeInContext(context);
                LLVMValueRef value = $4.llvm_value;
                if(symbol) {
                    if ($4.type == TYPE_INT) {
                        LLVMBuildStore(builder, value, var);
                    }
                    else if ($4.type == TYPE_FLOAT) {
                        printf("Warning: casting float to int for variable '%s' at line %d.\n", $2, yylineno);
                        value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
                        LLVMBuildStore(builder, value, var);
                    } else {
                        fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
                    }
                }
            }
            | FLOAT ID float_declaration DONE {
                insertSymbol($2, -DBL_MAX, TYPE_FLOAT);
                allocaVars($2, TYPE_FLOAT);
            }
            | FLOAT ID RECEIVE expression float_declaration DONE {
                insertSymbol($2, $4.value, TYPE_FLOAT);
                allocaVars($2, TYPE_FLOAT);
                Symbol* symbol = findSymbol($2);
                LLVMValueRef var = getVarLLVM($2);
                LLVMTypeRef llvm_type = LLVMDoubleTypeInContext(context);
                LLVMValueRef value = $4.llvm_value;
                if(symbol) {
                    if ($4.type == TYPE_FLOAT) {
                        LLVMBuildStore(builder, value, var);
                    }
                    else if ($4.type == TYPE_INT) {
                        value = LLVMBuildSIToFP(builder, value, llvm_type, "inttofloat");
                        LLVMBuildStore(builder, value, var);
                    } else {
                        fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
                    }
                }
            }
            | CHAR ID char_declaration DONE {
                insertSymbol($2, -DBL_MAX, TYPE_CHAR);
                allocaVars($2, TYPE_CHAR);
            }
            | CHAR ID RECEIVE expression char_declaration DONE {
                insertSymbol($2, $4.value, TYPE_CHAR);
                allocaVars($2, TYPE_CHAR);
                Symbol* symbol = findSymbol($2);
                LLVMValueRef var = getVarLLVM($2);
                LLVMValueRef value = $4.llvm_value;
                if(symbol) {
                    if ($4.type == TYPE_CHAR) {
                        LLVMBuildStore(builder, value, var);
                    } else {
                        fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
                    }
                }
            }
            | BOOL ID bool_declaration DONE {
                insertSymbol($2, -DBL_MAX, TYPE_BOOL);
                allocaVars($2, TYPE_BOOL);
            }
            | BOOL ID RECEIVE expression bool_declaration DONE {
                insertSymbol($2, $4.value, TYPE_BOOL);
                allocaVars($2, TYPE_BOOL);
                Symbol* symbol = findSymbol($2);
                LLVMValueRef var = getVarLLVM($2);
                LLVMValueRef value = $4.llvm_value;
                if(symbol) {
                    if ($4.type == TYPE_BOOL) {
                        LLVMBuildStore(builder, value, var);
                    } else {
                        fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
                    }
                }
            }
            ;


int_declaration: /* empty */ {}
                | COMMA ID int_declaration {
                    insertSymbol($2, -DBL_MAX, TYPE_INT);
                    allocaVars($2, TYPE_INT);
                }
                | COMMA ID RECEIVE expression int_declaration {
                    insertSymbol($2, $4.value, TYPE_INT);
                    allocaVars($2, TYPE_INT);
                    Symbol* symbol = findSymbol($2);
                    LLVMValueRef var = getVarLLVM($2);
                    LLVMTypeRef llvm_type = LLVMInt32TypeInContext(context);
                    LLVMValueRef value = $4.llvm_value;
                    if(symbol) {
                        if ($4.type == TYPE_INT) {
                            LLVMBuildStore(builder, value, var);
                        }
                        else if ($4.type == TYPE_FLOAT) {
                            printf("Warning: casting float to int for variable '%s' at line %d.\n", $2, yylineno);
                            value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
                            LLVMBuildStore(builder, value, var);
                        } else {
                            fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
                        }
                    }
                }

float_declaration: /* empty */ {}
                 | COMMA ID float_declaration {
                    insertSymbol($2, -DBL_MAX, TYPE_FLOAT);
                    allocaVars($2, TYPE_FLOAT);
                 }
                 | COMMA ID RECEIVE expression float_declaration {
                    insertSymbol($2, $4.value, TYPE_FLOAT);
                    allocaVars($2, TYPE_FLOAT);
                    Symbol* symbol = findSymbol($2);
                    LLVMValueRef var = getVarLLVM($2);
                    LLVMTypeRef llvm_type = LLVMDoubleTypeInContext(context);
                    LLVMValueRef value = $4.llvm_value;
                    if(symbol) {
                        if ($4.type == TYPE_FLOAT) {
                            LLVMBuildStore(builder, value, var);
                        }
                        else if ($4.type == TYPE_INT) {
                            value = LLVMBuildSIToFP(builder, value, llvm_type, "inttofloat");
                            LLVMBuildStore(builder, value, var);
                        } else {
                            fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
                        }
                    }
                 }

char_declaration: /* empty */ {}
                | COMMA ID char_declaration {
                    insertSymbol($2, -DBL_MAX, TYPE_CHAR);
                    allocaVars($2, TYPE_CHAR);
                }
                | COMMA ID RECEIVE expression char_declaration {
                    insertSymbol($2, $4.value, TYPE_CHAR);
                    allocaVars($2, TYPE_CHAR);
                    Symbol* symbol = findSymbol($2);
                    LLVMValueRef var = getVarLLVM($2);
                    LLVMValueRef value = $4.llvm_value;
                    if(symbol) {
                        if ($4.type == TYPE_CHAR) {
                            LLVMBuildStore(builder, value, var);
                        } else {
                            fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
                        }
                    }
                }

bool_declaration: /* empty */ {}
                | COMMA ID bool_declaration {
                    insertSymbol($2, -DBL_MAX, TYPE_BOOL);
                    allocaVars($2, TYPE_BOOL);
                }
                | COMMA ID RECEIVE expression bool_declaration {
                    insertSymbol($2, $4.value, TYPE_BOOL);
                    allocaVars($2, TYPE_BOOL);
                    Symbol* symbol = findSymbol($2);
                    LLVMValueRef var = getVarLLVM($2);
                    LLVMValueRef value = $4.llvm_value;
                    if(symbol) {
                        if ($4.type == TYPE_BOOL) {
                            LLVMBuildStore(builder, value, var);
                        } else {
                            fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
                        }
                    }
                }
                ;



comand: assignment {}
      | if_then {}
      | while {}
      | printf {}
      | scanf {}
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
	      ;




if_then: IF LEFTPAR expression RIGHTPAR {
            pushScope();
            if ($3.type != TYPE_BOOL) {
                fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
            }
            aux = $3.llvm_value;
        } if_then_aux LEFTKEYS program RIGHTKEYS if_then_aux2 {
            popScope();

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
    } LEFTKEYS program RIGHTKEYS {
        popScope();
    }
    ;



while: WHILE while_aux LEFTPAR expression RIGHTPAR {
        pushScope();
        if ($4.type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }

        LLVMBuildCondBr(builder, $4.llvm_value, $2.bodyBB, $2.endWHILEBB);

        // Corpo do while
        LLVMPositionBuilderAtEnd(builder, $2.bodyBB);
    } LEFTKEYS program RIGHTKEYS {
        // Ao final do corpo, volta para o condicional
        LLVMBuildBr(builder, $2.condBB);

        // Posiciona o builder no bloco de saída do while
        LLVMPositionBuilderAtEnd(builder, $2.endWHILEBB);

        popScope();
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

printf: PRINTF LEFTPAR ID RIGHTPAR DONE {
            Symbol* sym = findSymbol($3);
            if (sym == NULL) {
                fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", $3, yylineno);
            } else if(sym->value == -DBL_MAX) {
                fprintf(stderr, "Error: variable '%s' is uninitialized at line %d.\n", $3, yylineno);
            } else {
                LLVMValueRef fmt = NULL;
                switch (sym->type) {
                    case TYPE_INT:
                        fmt = fmt_int;
                        break;
                    case TYPE_FLOAT:
                        fmt = fmt_float;
                        break;
                    case TYPE_CHAR:
                        fmt = fmt_char;
                        break;
                    case TYPE_BOOL:
                        fmt = fmt_bool;
                        break;
                    default:
                        fprintf(stderr, "Error: unsupported type for variable '%s' at line %d.\n", $3, yylineno);
                }
                if (fmt) {
                    LLVMValueRef var = getVarLLVM($3);
                    LLVMTypeRef llvm_type;
                    switch (sym->type) {
                        case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                        case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                        case TYPE_CHAR:  llvm_type = LLVMInt8TypeInContext(context); break;
                        case TYPE_BOOL:  llvm_type = LLVMInt1TypeInContext(context); break;
                        default:         llvm_type = LLVMDoubleTypeInContext(context); break;
                    }
                    LLVMValueRef loaded = LLVMBuildLoad2(builder, llvm_type, var, "loadtmp");
                    LLVMValueRef args[2] = { fmt, loaded };
                    LLVMValueRef printf_func = LLVMGetNamedFunction(module, "printf");
                    LLVMBuildCall2(builder, printf_type, printf_func, args, 2, "");
                }
            }
        }
        | PRINTF LEFTPAR NUMBER RIGHTPAR DONE {
            LLVMValueRef fmt = NULL;
            switch ($3.type) {
                case TYPE_INT:
                    fmt = fmt_int;
                    break;
                case TYPE_FLOAT:
                    fmt = fmt_float;
                    break;
                case TYPE_CHAR:
                    fmt = fmt_char;
                    break;
                case TYPE_BOOL:
                    fmt = fmt_bool;
                    break;
                default:
                    fprintf(stderr, "Error: unsupported type for number at line %d.\n", yylineno);
            }
            if (fmt) {
                LLVMValueRef args[2] = { fmt, $3.llvm_value };
                LLVMValueRef printf_func = LLVMGetNamedFunction(module, "printf");
                LLVMBuildCall2(builder, printf_type, printf_func, args, 2, "");
            }
        }
        | PRINTF LEFTPAR STRING RIGHTPAR DONE {
            LLVMValueRef fmt = fmt_str;
            LLVMValueRef args[1] = { fmt };
            LLVMValueRef printf_func = LLVMGetNamedFunction(module, "printf");
            LLVMBuildCall2(builder, printf_type, printf_func, args, 1, "");
            free($3);
        }
        ;


scanf:  SCANF LEFTPAR ID RIGHTPAR DONE {
            Symbol* sym = findSymbol($3);
            sym->value = 0.0;
            if (sym == NULL) {
                fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", $3, yylineno);
            } else {
                LLVMValueRef fmt = NULL;
                switch (sym->type) {
                    case TYPE_INT:
                        fmt = fmt_int;
                        break;
                    case TYPE_FLOAT:
                        fmt = fmt_float;
                        break;
                    case TYPE_CHAR:
                        fmt = fmt_char;
                        break;
                    case TYPE_BOOL:
                        fmt = fmt_bool;
                        break;
                    default:
                        fprintf(stderr, "Error: unsupported type for variable '%s' at line %d.\n", $3, yylineno);
                }
                if (fmt) {
                    LLVMValueRef var = getVarLLVM($3);
                    LLVMValueRef args[2] = { fmt, var };
                    LLVMValueRef scanf_func = LLVMGetNamedFunction(module, "scanf");
                    LLVMBuildCall2(builder, scanf_type, scanf_func, args, 2, "");
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
    | CARACTERE {
        $$.value = (double) $1;
        $$.type = TYPE_CHAR;
        $$.llvm_value = LLVMConstInt(LLVMInt8TypeInContext(context), $1, 0);
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
    module = LLVMModuleCreateWithNameInContext("parser", context);
    builder = LLVMCreateBuilderInContext(context);

    // Declarações de funções padrão
    printf_type = LLVMFunctionType(
        LLVMInt32TypeInContext(context),
        (LLVMTypeRef[]){ LLVMPointerType(LLVMInt8TypeInContext(context), 0) },
        1, 1 // 1 argumento fixo, variádico
    );
    LLVMAddFunction(module, "printf", printf_type);

    scanf_type = LLVMFunctionType(
        LLVMInt32TypeInContext(context),
        (LLVMTypeRef[]){ LLVMPointerType(LLVMInt8TypeInContext(context), 0) },
        1, 1 // 1 argumento fixo, variádico
    );
    LLVMAddFunction(module, "scanf", scanf_type);

    // Cria função main: int main()
    LLVMTypeRef mainType = LLVMFunctionType(LLVMInt32TypeInContext(context), NULL, 0, 0);
    mainFunc = LLVMAddFunction(module, "main", mainType);
    entry = LLVMAppendBasicBlockInContext(context, mainFunc, "entry");
    LLVMPositionBuilderAtEnd(builder, entry);

    // Variáveis globais para formatação de strings
    fmt_int   = LLVMBuildGlobalStringPtr(builder, "%d\n", "fmt_int");
    fmt_float = LLVMBuildGlobalStringPtr(builder, "%f\n", "fmt_float");
    fmt_char  = LLVMBuildGlobalStringPtr(builder, "%c\n", "fmt_char");
    fmt_bool  = LLVMBuildGlobalStringPtr(builder, "%d\n", "fmt_bool");
    fmt_str   = LLVMBuildGlobalStringPtr(builder, "%s\n", "fmt_str");

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