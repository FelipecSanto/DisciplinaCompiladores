%{
#include "LLVMUtils.h"
#include "SymbolTable.h"
#include "UtilsConditionals.h"
#include "stdbool.h"
#include "VarType.h"

#define MAX_PARAMS 10

typedef struct Param_call {
    double value;
    VarType type;
    LLVMValueRef llvm_value;
} Param_call;

int yylex();
int yywrap( );
void yyerror(const char* str);
extern int yylineno;

double* vals = NULL; // Array para armazenar valores de inicialização de vetor
int array_value_count = 0; // Contador de valores de vetor

char* param_names[MAX_PARAMS];
LLVMTypeRef param_typesLLVM[MAX_PARAMS];
VarType param_types[MAX_PARAMS];
int param_count = 0;

Param_call param_call[MAX_PARAMS];
int param_call_count = 0;

int haveRet = 0;
int haveRetAll = 1;

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
    struct {
        LLVMBasicBlockRef condBB, bodyBB, incBB, endFORBB;
    } for_blocks;

    struct {
        LLVMValueRef values[10];
        int count;
    } printf;
}


%token IF ELSE ELSEIF
%token INT CHAR FLOAT BOOL
%token PRINTF SCANF ADDRESS
%token WHILE FOR DO
%token VOID RETURN
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
%type <number> expression soma_sub mult_div term comparison log_exp cast term_const call_function call_function_notfull

%type program_global program_global_list program_globals declaration_global
%type program_local program_local_list program_locals declaration_local

%type function parameters parameter parameter_list call_parameters call_parameter_list
%type int_function float_function char_function bool_function void_function

%type printf scanf assignment assignment_notfull increment return comand
%type <printf> printf_args scanf_args

%type int_declaration_global float_declaration_global char_declaration_global bool_declaration_global 
%type int_declaration_global_list float_declaration_global_list char_declaration_global_list bool_declaration_global_list
%type int_declaration_globals float_declaration_globals char_declaration_globals bool_declaration_globals

%type array_global array_local array_values_global array_values_local

%type int_declaration_local float_declaration_local char_declaration_local bool_declaration_local
%type int_declaration_local_list float_declaration_local_list char_declaration_local_list bool_declaration_local_list
%type int_declaration_locals float_declaration_locals char_declaration_locals bool_declaration_locals

%type <if_else_blocks> if_statement
%type <while_blocks> while while_aux do_while do_while_aux
%type <for_blocks> for for_aux

/* give us more detailed errors */
%define parse.error verbose

%start program_globals

%%

program_globals
    : /* empty */ {}
    | program_global program_global_list {}
    ;

program_global_list
    : /* empty */ {}
    | program_global program_global_list {}
    ;

program_global
    : function {}
    | declaration_global {}
    | error { yyerrok; yyclearin; }
    ;


program_locals
    : /* empty */ {}
    | program_local program_local_list {}
    ;

program_local_list
    : /* empty */ {}
    | program_local program_local_list {}
    ;

program_local
    : comand {}
    | declaration_local {}
    ;


function
    : int_function {}
    | float_function {}
    | char_function {}
    | bool_function {}
    | void_function {}
    ;



int_function
    : INT ID LEFTPAR {
        pushScope();
    } parameters {
        
        LLVMTypeRef func_type = LLVMFunctionType(
            LLVMInt32TypeInContext(context), // tipo de retorno int
            param_typesLLVM, param_count, 0
        );
        LLVMValueRef func = LLVMAddFunction(module, $2, func_type);
        LLVMBasicBlockRef entryBB = LLVMAppendBasicBlockInContext(context, func, "entry");
        LLVMPositionBuilderAtEnd(builder, entryBB);
        currentFunc = func; // Atualize currentFunc para a função atual

        for (int i = 0; i < param_count; i++) {
            LLVMValueRef param = LLVMGetParam(func, i);
            LLVMValueRef var = allocaVars(param_names[i], param_types[i]);
            LLVMBuildStore(builder, param, var);
        }

        insertFunctionSymbol($2, TYPE_INT, param_count, param_types);

        // Limpa as variáveis de parâmetros para a próxima função
        for (int i = 0; i < MAX_PARAMS; i++) {
            param_names[i] = NULL;
            param_typesLLVM[i] = NULL;
            param_types[i] = 0;
        }
        param_count = 0;

        haveRet = 0;
    } RIGHTPAR LEFTKEYS program_locals RIGHTKEYS {
        if(haveRet == 0) {
            fprintf(stderr, "Warning: function '%s' does not have a return statement at line %d.\n", $2, yylineno);
            LLVMValueRef ret_value = LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0);
            LLVMBuildRet(builder, ret_value); // Retorna 0 por padrão
        }
        popScope();
    }
    ;

float_function
    : FLOAT ID LEFTPAR {
            pushScope();
        } parameters {

        LLVMTypeRef func_type = LLVMFunctionType(
            LLVMDoubleTypeInContext(context), // tipo de retorno float
            param_typesLLVM, param_count, 0
        );
        LLVMValueRef func = LLVMAddFunction(module, $2, func_type);
        LLVMBasicBlockRef entryBB = LLVMAppendBasicBlockInContext(context, func, "entry");
        LLVMPositionBuilderAtEnd(builder, entryBB);
        currentFunc = func; // Atualize currentFunc para a função atual

        for (int i = 0; i < param_count; i++) {
            LLVMValueRef param = LLVMGetParam(func, i);
            LLVMValueRef var = allocaVars(param_names[i], param_types[i]);
            LLVMBuildStore(builder, param, var);
        }

        insertFunctionSymbol($2, TYPE_FLOAT, param_count, param_types);

        // Limpa as variáveis de parâmetros para a próxima função
        for (int i = 0; i < MAX_PARAMS; i++) {
            param_names[i] = NULL;
            param_typesLLVM[i] = NULL;
            param_types[i] = 0;
        }
        param_count = 0;
        
        haveRet = 0;
    } RIGHTPAR LEFTKEYS program_locals RIGHTKEYS {
        if(haveRet == 0) {
            fprintf(stderr, "Warning: function '%s' does not have a return statement at line %d.\n", $2, yylineno);
            LLVMValueRef ret_value = LLVMConstReal(LLVMDoubleTypeInContext(context), 0.0);
            LLVMBuildRet(builder, ret_value); // Retorna 0.0 por padrão
        }
        popScope();
    }
    ;

char_function
    : CHAR ID LEFTPAR {
        pushScope();
    } parameters {

        LLVMTypeRef func_type = LLVMFunctionType(
            LLVMInt8TypeInContext(context), // tipo de retorno char
            param_typesLLVM, param_count, 0
        );
        LLVMValueRef func = LLVMAddFunction(module, $2, func_type);
        LLVMBasicBlockRef entryBB = LLVMAppendBasicBlockInContext(context, func, "entry");
        LLVMPositionBuilderAtEnd(builder, entryBB);
        currentFunc = func; // Atualize currentFunc para a função atual

        for (int i = 0; i < param_count; i++) {
            LLVMValueRef param = LLVMGetParam(func, i);
            LLVMValueRef var = allocaVars(param_names[i], param_types[i]);
            LLVMBuildStore(builder, param, var);
        }

        insertFunctionSymbol($2, TYPE_CHAR, param_count, param_types);

        // Limpa as variáveis de parâmetros para a próxima função
        for (int i = 0; i < MAX_PARAMS; i++) {
            param_names[i] = NULL;
            param_typesLLVM[i] = NULL;
            param_types[i] = 0;
        }
        param_count = 0;
        
        haveRet = 0;
    } RIGHTPAR LEFTKEYS program_locals RIGHTKEYS {
        if(haveRet == 0) {
            fprintf(stderr, "Warning: function '%s' does not have a return statement at line %d.\n", $2, yylineno);
            LLVMValueRef ret_value = LLVMConstInt(LLVMInt8TypeInContext(context), 0, 0);
            LLVMBuildRet(builder, ret_value); // Retorna 0 por padrão
        }
        popScope();
    }
    ;

bool_function
    : BOOL ID LEFTPAR {
        pushScope();
    } parameters {

        LLVMTypeRef func_type = LLVMFunctionType(
            LLVMInt1TypeInContext(context), // tipo de retorno bool
            param_typesLLVM, param_count, 0
        );
        LLVMValueRef func = LLVMAddFunction(module, $2, func_type);
        LLVMBasicBlockRef entryBB = LLVMAppendBasicBlockInContext(context, func, "entry");
        LLVMPositionBuilderAtEnd(builder, entryBB);
        currentFunc = func; // Atualize currentFunc para a função atual

        for (int i = 0; i < param_count; i++) {
            LLVMValueRef param = LLVMGetParam(func, i);
            LLVMValueRef var = allocaVars(param_names[i], param_types[i]);
            LLVMBuildStore(builder, param, var);
        }

        insertFunctionSymbol($2, TYPE_BOOL, param_count, param_types);

        // Limpa as variáveis de parâmetros para a próxima função
        for (int i = 0; i < MAX_PARAMS; i++) {
            param_names[i] = NULL;
            param_typesLLVM[i] = NULL;
            param_types[i] = 0;
        }
        param_count = 0;
        
        haveRet = 0;
    } RIGHTPAR LEFTKEYS program_locals RIGHTKEYS {
        if(haveRet == 0) {
            fprintf(stderr, "Warning: function '%s' does not have a return statement at line %d.\n", $2, yylineno);
            LLVMValueRef ret_value = LLVMConstInt(LLVMInt1TypeInContext(context), 0, 0);
            LLVMBuildRet(builder, ret_value); // Retorna 0 por padrão
        }
        popScope();
    }
    ;


void_function
    : VOID ID LEFTPAR {
            pushScope();
    } parameters {
        LLVMTypeRef func_type = LLVMFunctionType(
            LLVMVoidTypeInContext(context), // tipo de retorno void
            param_typesLLVM, param_count, 0
        );
        LLVMValueRef func = LLVMAddFunction(module, $2, func_type);
        LLVMBasicBlockRef entryBB = LLVMAppendBasicBlockInContext(context, func, "entry");
        LLVMPositionBuilderAtEnd(builder, entryBB);
        currentFunc = func; // Atualize currentFunc para a função atual

        for (int i = 0; i < param_count; i++) {
            LLVMValueRef param = LLVMGetParam(func, i);
            LLVMValueRef var = allocaVars(param_names[i], param_types[i]);
            LLVMBuildStore(builder, param, var);
        }

        insertFunctionSymbol($2, TYPE_VOID, param_count, param_types);

        for (int i = 0; i < MAX_PARAMS; i++) {
            param_names[i] = NULL;
            param_typesLLVM[i] = NULL;
            param_types[i] = 0;
        }
        param_count = 0;
    } RIGHTPAR LEFTKEYS program_locals RIGHTKEYS {
        LLVMBuildRetVoid(builder);
        popScope();
    }
    ;


parameters
    : /* empty */
    | parameter parameter_list {};

parameter_list
    : /* empty */
    | COMMA parameter parameter_list {};


parameter
    : INT ID {
        if (param_count >= MAX_PARAMS) {
            fprintf(stderr, "Error: too many parameters at line %d.\n", yylineno);
        } else {
            param_names[param_count] = $2;
            param_types[param_count] = TYPE_INT;
            param_typesLLVM[param_count++] = LLVMInt32TypeInContext(context);
            insertSymbol($2, 0.0, TYPE_INT);
        }
    }
    | FLOAT ID {
        if (param_count >= MAX_PARAMS) {
            fprintf(stderr, "Error: too many parameters at line %d.\n", yylineno);
        } else {
            param_names[param_count] = $2;
            param_types[param_count] = TYPE_FLOAT;
            param_typesLLVM[param_count++] = LLVMDoubleTypeInContext(context);
            insertSymbol($2, 0.0, TYPE_FLOAT);
        }
    }
    | CHAR ID {
        if (param_count >= MAX_PARAMS) {
            fprintf(stderr, "Error: too many parameters at line %d.\n", yylineno);
        } else {
            param_names[param_count] = $2;
            param_types[param_count] = TYPE_CHAR;
            param_typesLLVM[param_count++] = LLVMInt8TypeInContext(context);
            insertSymbol($2, 0.0, TYPE_CHAR);
        }
    }
    | BOOL ID {
        if (param_count >= MAX_PARAMS) {
            fprintf(stderr, "Error: too many parameters at line %d.\n", yylineno);
        } else {
            param_names[param_count] = $2;
            param_types[param_count] = TYPE_BOOL;
            param_typesLLVM[param_count++] = LLVMInt1TypeInContext(context);
            insertSymbol($2, 0.0, TYPE_BOOL);
        }
};



declaration_global
    : int_declaration_globals {}
    | float_declaration_globals {}
    | char_declaration_globals {}
    | bool_declaration_globals {};


int_declaration_globals
    : INT int_declaration_global int_declaration_global_list DONE {};

int_declaration_global_list
    : /* empty */
    | COMMA int_declaration_global int_declaration_global_list;

int_declaration_global
    : ID {
        insertSymbol($1, -DBL_MAX, TYPE_INT);
        LLVMTypeRef type = LLVMInt32TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, $1);
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM($1, global); // Função que associa o nome ao LLVMValueRef global
    }
    | ID RECEIVE term_const {
        insertSymbol($1, $3.value, TYPE_INT);
        LLVMTypeRef type = LLVMInt32TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, $1);
        LLVMSetInitializer(global, $3.llvm_value);
        setVarLLVM($1, global);
    }
    | array_global {};

array_global
    : ID LEFTBRACKET term_const RIGHTBRACKET {
        // Declaração de vetor
        int size = (int)$3.value;
        if (size <= 0) {
            fprintf(stderr, "Error: array size must be positive at line %d.\n", yylineno);
        } else {
            double valores[size];
            for (int i = 0; i < size; i++) {
                valores[i] = -DBL_MAX; // Inicializa com valor padrão
            }
            createArraySymbol($1, valores, size);
            allocaArrayVars($1, TYPE_INT, size);
        }
    }
    | ID LEFTBRACKET term_const RIGHTBRACKET RECEIVE LEFTKEYS array_values_global RIGHTKEYS {
        int size = (int)$3.value;
        if (size <= 0) {
            fprintf(stderr, "Error: array size must be positive at line %d.\n", yylineno);
        } else if (array_value_count != size) {
            fprintf(stderr, "Error: number of initializers (%d) does not match array size (%d) at line %d.\n", array_value_count, size, yylineno);
        } else {
            createArraySymbol($1, vals, size);
            allocaArrayVars($1, TYPE_INT, size);
            LLVMValueRef var = getVarLLVM($1);
            for (int i = 0; i < size; i++) {
                LLVMValueRef idx = LLVMConstInt(LLVMInt32TypeInContext(context), i, 0);
                LLVMValueRef indices[2] = { LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0), idx };
                LLVMValueRef array_ptr = LLVMBuildGEP2(
                    builder,
                    LLVMArrayType(LLVMInt32TypeInContext(context), size),
                    var,
                    indices,
                    2,
                    ""
                );
                LLVMValueRef val = LLVMConstInt(LLVMInt32TypeInContext(context), (int)vals[i], 0);
                LLVMBuildStore(builder, val, array_ptr);
            }
        }
        free(vals);
        vals = NULL; // Libera o array de valores
        array_value_count = 0;
    }
    ;



float_declaration_globals
    : FLOAT float_declaration_global float_declaration_global_list DONE {};

float_declaration_global_list
    : /* empty */
    | COMMA float_declaration_global float_declaration_global_list;

float_declaration_global
    : ID {
        insertSymbol($1, -DBL_MAX, TYPE_FLOAT);
        LLVMTypeRef type = LLVMDoubleTypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, $1);
        LLVMSetInitializer(global, LLVMConstReal(type, 0.0)); // valor padrão
        setVarLLVM($1, global); // Função que associa o nome ao LLVMValueRef global
    }
    | ID RECEIVE term_const {
        insertSymbol($1, $3.value, TYPE_FLOAT);
        LLVMTypeRef type = LLVMDoubleTypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, $1);
        LLVMSetInitializer(global, $3.llvm_value);
        setVarLLVM($1, global);
    }
    ;

char_declaration_globals
    : CHAR char_declaration_global char_declaration_global_list DONE {};

char_declaration_global_list
    : /* empty */ {}
    | COMMA char_declaration_global char_declaration_global_list {};

char_declaration_global
    : ID {
        insertSymbol($1, -DBL_MAX, TYPE_CHAR);
        LLVMTypeRef type = LLVMInt8TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, $1);
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM($1, global); // Função que associa o nome ao LLVMValueRef global
    }
    | ID RECEIVE term_const {
        insertSymbol($1, $3.value, TYPE_CHAR);
        LLVMTypeRef type = LLVMInt8TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, $1);
        LLVMSetInitializer(global, $3.llvm_value);
        setVarLLVM($1, global);
    }
    ;

bool_declaration_globals
    : BOOL bool_declaration_global bool_declaration_global_list DONE {};

bool_declaration_global_list
    : /* empty */ {}
    | COMMA bool_declaration_global bool_declaration_global_list {};

bool_declaration_global
    : ID {
        insertSymbol($1, -DBL_MAX, TYPE_BOOL);
        LLVMTypeRef type = LLVMInt1TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, $1);
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM($1, global); // Função que associa o nome ao LLVMValueRef global
    }
    | ID RECEIVE term_const {
        insertSymbol($1, $3.value, TYPE_BOOL);
        LLVMTypeRef type = LLVMInt1TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, $1);
        LLVMSetInitializer(global, $3.llvm_value);
        setVarLLVM($1, global);
    }
    ;


array_values_global
    : term_const {
        if(vals) {
            free(vals);
        }
        vals = malloc(sizeof(double));
        vals[0] = $1.value;
        array_value_count = 1;
    }
    | array_values_global COMMA term_const {
        vals = realloc(vals, sizeof(double) * (array_value_count + 1));
        vals[array_value_count] = $3.value;
        array_value_count++;
    }
    ;


term_const
    : NUMBER {
        $$.value = $1.value; 
        $$.type = $1.type; 
        switch ($1.type) {
            case TYPE_INT:   $$.llvm_value = LLVMConstInt(LLVMInt32TypeInContext(context), (int)$1.value, 0); break;
            case TYPE_FLOAT: $$.llvm_value = LLVMConstReal(LLVMDoubleTypeInContext(context), $1.value); break;
            case TYPE_BOOL:  $$.llvm_value = LLVMConstInt(LLVMInt1TypeInContext(context), (int)$1.value, 0); break;
            default:         $$.llvm_value = LLVMConstReal(LLVMDoubleTypeInContext(context), $1.value); break;
        }
    }
    | CARACTERE {
        $$.value = (double) $1;
        $$.type = TYPE_CHAR;
        $$.llvm_value = LLVMConstInt(LLVMInt8TypeInContext(context), $1, 0);
};


declaration_local
    : int_declaration_locals {}
    | float_declaration_locals {}
    | char_declaration_locals {}
    | bool_declaration_locals {};


int_declaration_locals
    : INT int_declaration_local int_declaration_local_list DONE {};

int_declaration_local_list
    : /* empty */ {}
    | COMMA int_declaration_local int_declaration_local_list {};

int_declaration_local
    : ID {
        insertSymbol($1, -DBL_MAX, TYPE_INT);
        allocaVars($1, TYPE_INT);
    }
    | ID RECEIVE expression {
        insertSymbol($1, $3.value, TYPE_INT);
        allocaVars($1, TYPE_INT);
        Symbol* symbol = findSymbol($1);
        LLVMValueRef var = getVarLLVM($1);
        LLVMTypeRef llvm_type = LLVMInt32TypeInContext(context);
        LLVMValueRef value = $3.llvm_value;
        if(symbol) {
            if ($3.type == TYPE_INT) {
                LLVMBuildStore(builder, value, var);
            }
            else if ($3.type == TYPE_FLOAT) {
                fprintf(stderr, "Warning: casting float to int for variable '%s' at line %d.\n", $1, yylineno);
                value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
    | array_local
    ;

array_local
    : ID LEFTBRACKET expression RIGHTBRACKET {
        // Declaração de vetor
        int size = (int)$3.value;
        if (size <= 0) {
            fprintf(stderr, "Error: array size must be positive at line %d.\n", yylineno);
        } else {
            double valores[size];
            for (int i = 0; i < size; i++) {
                valores[i] = -DBL_MAX; // Inicializa com valor padrão
            }
            createArraySymbol($1, valores, size);
            allocaArrayVars($1, TYPE_INT, size);
        }
    }
    | ID LEFTBRACKET expression RIGHTBRACKET RECEIVE LEFTKEYS array_values_local RIGHTKEYS {
        int size = (int)$3.value;
        if (size <= 0) {
            fprintf(stderr, "Error: array size must be positive at line %d.\n", yylineno);
        } else if (array_value_count != size) {
            fprintf(stderr, "Error: number of initializers (%d) does not match array size (%d) at line %d.\n", array_value_count, size, yylineno);
        } else {
            createArraySymbol($1, vals, size);
            allocaArrayVars($1, TYPE_INT, size);
            LLVMValueRef var = getVarLLVM($1);
            for (int i = 0; i < size; i++) {
                LLVMValueRef idx = LLVMConstInt(LLVMInt32TypeInContext(context), i, 0);
                LLVMValueRef indices[2] = { LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0), idx };
                LLVMValueRef array_ptr = LLVMBuildGEP2(
                    builder,
                    LLVMArrayType(LLVMInt32TypeInContext(context), size),
                    var,
                    indices,
                    2,
                    ""
                );
                LLVMValueRef val = LLVMConstInt(LLVMInt32TypeInContext(context), (int)vals[i], 0);
                LLVMBuildStore(builder, val, array_ptr);
            }
        }
        free(vals);
        vals = NULL; // Libera o array de valores
        array_value_count = 0;
    }
    ;

float_declaration_locals
    : FLOAT float_declaration_local float_declaration_local_list DONE {};

float_declaration_local_list
    : /* empty */ {}
    | COMMA float_declaration_local float_declaration_local_list {};

float_declaration_local
    : ID {
        insertSymbol($1, -DBL_MAX, TYPE_FLOAT);
        allocaVars($1, TYPE_FLOAT);
    }
    | ID RECEIVE expression {
        insertSymbol($1, $3.value, TYPE_FLOAT);
        allocaVars($1, TYPE_FLOAT);
        Symbol* symbol = findSymbol($1);
        LLVMValueRef var = getVarLLVM($1);
        LLVMTypeRef llvm_type = LLVMDoubleTypeInContext(context);
        LLVMValueRef value = $3.llvm_value;
        if(symbol) {
            if ($3.type == TYPE_FLOAT) {
                LLVMBuildStore(builder, value, var);
            }
            else if ($3.type == TYPE_INT) {
                value = LLVMBuildSIToFP(builder, value, llvm_type, "inttofloat");
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
    ;

char_declaration_locals
    : CHAR char_declaration_local char_declaration_local_list DONE {};

char_declaration_local_list
    : /* empty */ {}
    | COMMA char_declaration_local char_declaration_local_list {};

char_declaration_local
    : ID {
        insertSymbol($1, -DBL_MAX, TYPE_CHAR);
        allocaVars($1, TYPE_CHAR);
    }
    | ID RECEIVE expression {
        insertSymbol($1, $3.value, TYPE_CHAR);
        allocaVars($1, TYPE_CHAR);
        Symbol* symbol = findSymbol($1);
        LLVMValueRef var = getVarLLVM($1);
        LLVMValueRef value = $3.llvm_value;
        if(symbol) {
            if ($3.type == TYPE_CHAR) {
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
    ;

bool_declaration_locals
    : BOOL bool_declaration_local bool_declaration_local_list DONE {};

bool_declaration_local_list
    : /* empty */ {}
    | COMMA bool_declaration_local bool_declaration_local_list {};

bool_declaration_local
    : ID {
        insertSymbol($1, -DBL_MAX, TYPE_BOOL);
        allocaVars($1, TYPE_BOOL);
    }
    | ID RECEIVE expression {
        insertSymbol($1, $3.value, TYPE_BOOL);
        allocaVars($1, TYPE_BOOL);
        Symbol* symbol = findSymbol($1);
        LLVMValueRef var = getVarLLVM($1);
        LLVMValueRef value = $3.llvm_value;
        if(symbol) {
            if ($3.type == TYPE_BOOL) {
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
    ;

array_values_local
    : expression {
        if(vals) {
            free(vals);
        }
        vals = malloc(sizeof(double));
        vals[0] = $1.value;
        array_value_count = 1;
    }
    | array_values_local COMMA expression {
        vals = realloc(vals, sizeof(double) * (array_value_count + 1));
        vals[array_value_count] = $3.value;
        array_value_count++;
};


comand
    : assignment {}
    | increment {}
    | if_statement {}
    | while {}
    | for {}
    | do_while {}
    | printf {}
    | scanf {}
    | return {}
    | call_function {}
    ;


assignment
    : assignment_notfull DONE
    ;

assignment_notfull
    : ID RECEIVE expression {
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
                insertSymbol($1, $3.value, symbol->type);
            }
            // Cast se necessário
            else if (symbol->type == TYPE_FLOAT && $3.type == TYPE_INT) {
                value = LLVMBuildSIToFP(builder, value, llvm_type, "inttofloat");
                LLVMBuildStore(builder, value, var);
                insertSymbol($1, $3.value, symbol->type);
            }
            else if (symbol->type == TYPE_INT && $3.type == TYPE_FLOAT) {
                fprintf(stderr, "Warning: casting float to int for variable '%s' at line %d.\n", $1, yylineno);
                value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
                LLVMBuildStore(builder, value, var);
                insertSymbol($1, (int)$3.value, symbol->type);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        } else {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", $1, yylineno);
        }
    }
    | ID LEFTBRACKET expression RIGHTBRACKET RECEIVE expression {
        ArraySymbol* symbol = findArraySymbol($1);
        if (!symbol) {
            fprintf(stderr, "Error: variable '%s' is not an array or not exist at line %d.\n", $1, yylineno);
        }
        LLVMValueRef var = getVarLLVM($1);
        LLVMTypeRef llvm_type = LLVMInt32TypeInContext(context);
        LLVMValueRef index = $3.llvm_value;
        LLVMValueRef value = $6.llvm_value;

        // Gera o índice do array
        LLVMValueRef indices[2] = { LLVMConstInt(LLVMInt32TypeInContext(context), 0, false), index };
        LLVMValueRef array_ptr = LLVMBuildGEP2(
            builder,
            LLVMArrayType(LLVMInt32TypeInContext(context), symbol->size),
            var,
            indices,
            2,
            "arrayptr"
        );
        
        // Armazena o valor no array
        if ($6.type == TYPE_INT) {
            LLVMBuildStore(builder, value, array_ptr);
            insertValueArraySymbol($1, $6.value, (int)$3.value);
        } else if ($6.type == TYPE_FLOAT) {
            fprintf(stderr, "Warning: casting float to int for variable '%s' at line %d.\n", $1, yylineno);
            value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
            LLVMBuildStore(builder, value, array_ptr);
            insertValueArraySymbol($1, (int)$6.value, (int)$3.value);
        } else {
            fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
        }
    }
    | increment {}
    ;


increment
    : ID PLUS RECEIVE expression {
        Symbol* symbol = findSymbol($1);
        if (!symbol) {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", $1, yylineno);
        }
        else if(symbol->type == TYPE_INT || symbol->type == TYPE_FLOAT) {
            LLVMValueRef var = getVarLLVM($1);
            LLVMTypeRef llvm_type;
            switch (symbol->type) {
                case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                default:         llvm_type = LLVMInt32TypeInContext(context); break;
            }

            // Carrega o valor atual
            LLVMValueRef current_value = LLVMBuildLoad2(builder, llvm_type, var, "current_value");

            LLVMValueRef incremented_value;
            
            if(symbol->type == $4.type) {
                // Atualiza a tabela de símbolos
                insertSymbol($1, symbol->value + $4.value, symbol->type);
                // Incrementa o valor
                if (symbol->type == TYPE_INT) {
                    incremented_value = LLVMBuildAdd(builder, current_value, $4.llvm_value, "incremented_value");
                } else {
                    incremented_value = LLVMBuildFAdd(builder, current_value, $4.llvm_value, "incremented_value");
                }
            }
            else if(symbol->type == TYPE_INT && $4.type == TYPE_FLOAT) {
                fprintf(stderr, "Warning: casting float to int for variable '%s' at line %d.\n", $1, yylineno);
                LLVMValueRef float_to_int = LLVMBuildFPToSI(builder, $4.llvm_value, llvm_type, "floattoint");
                incremented_value = LLVMBuildAdd(builder, current_value, float_to_int, "incremented_value");
                // Atualiza a tabela de símbolos
                insertSymbol($1, symbol->value + (int)$4.value, symbol->type);
            } else if(symbol->type == TYPE_FLOAT && $4.type == TYPE_INT) {
                LLVMValueRef int_to_float = LLVMBuildSIToFP(builder, $4.llvm_value, llvm_type, "inttofloat");
                incremented_value = LLVMBuildFAdd(builder, current_value, int_to_float, "incremented_value");
                // Atualiza a tabela de símbolos
                insertSymbol($1, symbol->value + $4.value, symbol->type);
            }

            // Armazena o novo valor
            LLVMBuildStore(builder, incremented_value, var);
        } else {
            fprintf(stderr, "Error: cannot increment variable '%s' of type %d at line %d.\n", $1, symbol->type, yylineno);
        }
    }
    | ID MIN RECEIVE expression {
        Symbol* symbol = findSymbol($1);
        if (!symbol) {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", $1, yylineno);
        }
        else if(symbol->type == TYPE_INT || symbol->type == TYPE_FLOAT) {
            LLVMValueRef var = getVarLLVM($1);
            LLVMTypeRef llvm_type;
            switch (symbol->type) {
                case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                default:         llvm_type = LLVMInt32TypeInContext(context); break;
            }

            // Carrega o valor atual
            LLVMValueRef current_value = LLVMBuildLoad2(builder, llvm_type, var, "current_value");
            
            LLVMValueRef decremented_value;

            if(symbol->type == $4.type) {
                // Atualiza a tabela de símbolos
                insertSymbol($1, symbol->value - $4.value, symbol->type);
                // Decrementa o valor
                if (symbol->type == TYPE_INT) {
                    decremented_value = LLVMBuildSub(builder, current_value, $4.llvm_value, "decremented_value");
                } else {
                    decremented_value = LLVMBuildFSub(builder, current_value, $4.llvm_value, "decremented_value");
                }
            }
            else if(symbol->type == TYPE_INT && $4.type == TYPE_FLOAT) {
                fprintf(stderr, "Warning: casting float to int for variable '%s' at line %d.\n", $1, yylineno);
                LLVMValueRef float_to_int = LLVMBuildFPToSI(builder, $4.llvm_value, llvm_type, "floattoint");
                decremented_value = LLVMBuildSub(builder, current_value, float_to_int, "decremented_value");
                insertSymbol($1, symbol->value - (int)$4.value, symbol->type);
            } else if(symbol->type == TYPE_FLOAT && $4.type == TYPE_INT) {
                LLVMValueRef int_to_float = LLVMBuildSIToFP(builder, $4.llvm_value, llvm_type, "inttofloat");
                decremented_value = LLVMBuildFSub(builder, current_value, int_to_float, "decremented_value");
                insertSymbol($1, symbol->value - $4.value, symbol->type);
            }

            // Armazena o novo valor
            LLVMBuildStore(builder, decremented_value, var);
        } else {
            fprintf(stderr, "Error: cannot decrement variable '%s' of type %d at line %d.\n", $1, symbol->type, yylineno);
        }
    }
    | ID MULT RECEIVE expression {
        Symbol* symbol = findSymbol($1);
        if (!symbol) {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", $1, yylineno);
        }
        else if(symbol->type == TYPE_INT || symbol->type == TYPE_FLOAT) {
            LLVMValueRef var = getVarLLVM($1);
            LLVMTypeRef llvm_type;
            switch (symbol->type) {
                case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                default:         llvm_type = LLVMInt32TypeInContext(context); break;
            }

            // Carrega o valor atual
            LLVMValueRef current_value = LLVMBuildLoad2(builder, llvm_type, var, "current_value");

            LLVMValueRef multiplied_value;
            
            if(symbol->type == $4.type) {
                // Atualiza a tabela de símbolos
                insertSymbol($1, symbol->value * $4.value, symbol->type);
                // Multiplica o valor
                if (symbol->type == TYPE_INT) {
                    multiplied_value = LLVMBuildMul(builder, current_value, $4.llvm_value, "multiplied_value");
                } else {
                    multiplied_value = LLVMBuildFMul(builder, current_value, $4.llvm_value, "multiplied_value");
                }
            }
            else if(symbol->type == TYPE_INT && $4.type == TYPE_FLOAT) {
                fprintf(stderr, "Warning: casting float to int for variable '%s' at line %d.\n", $1, yylineno);
                LLVMValueRef float_to_int = LLVMBuildFPToSI(builder, $4.llvm_value, llvm_type, "floattoint");
                multiplied_value = LLVMBuildMul(builder, current_value, float_to_int, "multiplied_value");
                // Atualiza a tabela de símbolos
                insertSymbol($1, symbol->value * (int)$4.value, symbol->type);
            } else if(symbol->type == TYPE_FLOAT && $4.type == TYPE_INT) {
                LLVMValueRef int_to_float = LLVMBuildSIToFP(builder, $4.llvm_value, llvm_type, "inttofloat");
                multiplied_value = LLVMBuildFMul(builder, current_value, int_to_float, "multiplied_value");
                // Atualiza a tabela de símbolos
                insertSymbol($1, symbol->value * $4.value, symbol->type);
            }

            // Armazena o novo valor
            LLVMBuildStore(builder, multiplied_value, var);
        } else {
            fprintf(stderr, "Error: cannot multiply variable '%s' of type %d at line %d.\n", $1, symbol->type, yylineno);
        }
    }
    | ID DIV RECEIVE expression {
        Symbol* symbol = findSymbol($1);
        if (!symbol) {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", $1, yylineno);
        } else if ($4.value == 0.0) {
            fprintf(stderr, "Error: division by zero for variable '%s' at line %d.\n", $1, yylineno);
        } else if(symbol->type == TYPE_INT || symbol->type == TYPE_FLOAT) {
            LLVMValueRef var = getVarLLVM($1);
            LLVMTypeRef llvm_type;
            switch (symbol->type) {
                case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                default:         llvm_type = LLVMInt32TypeInContext(context); break;
            }

            // Carrega o valor atual
            LLVMValueRef current_value = LLVMBuildLoad2(builder, llvm_type, var, "current_value");

            LLVMValueRef divided_value;
            
            if(symbol->type == $4.type) {
                // Atualiza a tabela de símbolos
                insertSymbol($1, symbol->value / $4.value, symbol->type);
                // Divide o valor
                if (symbol->type == TYPE_INT) {
                    divided_value = LLVMBuildUDiv(builder, current_value, $4.llvm_value, "divided_value");
                } else {
                    divided_value = LLVMBuildFDiv(builder, current_value, $4.llvm_value, "divided_value");
                }
            }
            else if(symbol->type == TYPE_INT && $4.type == TYPE_FLOAT) {
                fprintf(stderr, "Warning: casting float to int for variable '%s' at line %d.\n", $1, yylineno);
                LLVMValueRef float_to_int = LLVMBuildFPToSI(builder, $4.llvm_value, llvm_type, "floattoint");
                divided_value = LLVMBuildUDiv(builder, current_value, float_to_int, "divided_value");
                // Atualiza a tabela de símbolos
                insertSymbol($1, symbol->value / (int)$4.value, symbol->type);
            } else if(symbol->type == TYPE_FLOAT && $4.type == TYPE_INT) {
                LLVMValueRef int_to_float = LLVMBuildSIToFP(builder, $4.llvm_value, llvm_type, "inttofloat");
                divided_value = LLVMBuildFDiv(builder, current_value, int_to_float, "divided_value");
                // Atualiza a tabela de símbolos
                insertSymbol($1, symbol->value / $4.value, symbol->type);
            }

            // Armazena o novo valor
            LLVMBuildStore(builder, divided_value, var);
        } else {
            fprintf(stderr, "Error: cannot divide variable '%s' of type %d at line %d.\n", $1, symbol->type, yylineno);
        }
    }
    | ID PLUS PLUS {
        Symbol* symbol = findSymbol($1);
        if (!symbol) {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", $1, yylineno);
        }
        
        if(symbol->type == TYPE_INT || symbol->type == TYPE_FLOAT) {
            LLVMValueRef var = getVarLLVM($1);
            LLVMTypeRef llvm_type;
            switch (symbol->type) {
                case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                default:         llvm_type = LLVMInt32TypeInContext(context); break;
            }

            // Carrega o valor atual
            LLVMValueRef current_value = LLVMBuildLoad2(builder, llvm_type, var, "current_value");

            LLVMValueRef incremented_value;

            if (symbol->type == TYPE_INT) {
                // Incrementa o valor
                incremented_value = LLVMBuildAdd(builder, current_value, LLVMConstInt(llvm_type, 1, false), "incremented_value");
            } else {
                // Incrementa o valor
                incremented_value = LLVMBuildFAdd(builder, current_value, LLVMConstReal(llvm_type, 1.0), "incremented_value");
            }
            // Armazena o novo valor
            LLVMBuildStore(builder, incremented_value, var);
            
            // Atualiza a tabela de símbolos
            insertSymbol($1, symbol->value + 1, symbol->type);
        } else {
            fprintf(stderr, "Error: cannot increment variable '%s' of type %d at line %d.\n", $1, symbol->type, yylineno);
        }
    }
    | ID MIN MIN {
        Symbol* symbol = findSymbol($1);
        if (!symbol) {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", $1, yylineno);
        }
        if(symbol->type == TYPE_INT || symbol->type == TYPE_FLOAT) {
            LLVMValueRef var = getVarLLVM($1);
            LLVMTypeRef llvm_type;
            switch (symbol->type) {
                case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                default:         llvm_type = LLVMInt32TypeInContext(context); break;
            }

            // Carrega o valor atual
            LLVMValueRef current_value = LLVMBuildLoad2(builder, llvm_type, var, "current_value");

            LLVMValueRef decremented_value;

            if (symbol->type == TYPE_INT) {
                // Decrementa o valor
                decremented_value = LLVMBuildSub(builder, current_value, LLVMConstInt(llvm_type, 1, false), "decremented_value");
            } else {
                // Decrementa o valor
                decremented_value = LLVMBuildFSub(builder, current_value, LLVMConstReal(llvm_type, 1.0), "decremented_value");
            }

            // Armazena o novo valor
            LLVMBuildStore(builder, decremented_value, var);
            
            // Atualiza a tabela de símbolos
            insertSymbol($1, symbol->value - 1, symbol->type);
        } else {
            fprintf(stderr, "Error: cannot decrement variable '%s' of type %d at line %d.\n", $1, symbol->type, yylineno);
        }
    }
    ;


if_statement
    : IF LEFTPAR expression RIGHTPAR {
        if ($3.type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }
        
        // Cria blocos básicos
        LLVMBasicBlockRef ifBB = LLVMAppendBasicBlockInContext(context, currentFunc, "if");
        LLVMBasicBlockRef nextCondBB = LLVMAppendBasicBlockInContext(context, currentFunc, "next_cond");
        LLVMBasicBlockRef intermediary = LLVMAppendBasicBlockInContext(context, currentFunc, "intermediary");
        
        // Empilha contexto
        push_cond_context(intermediary, nextCondBB);
        
        // Gera branch condicional
        LLVMBuildCondBr(builder, $3.llvm_value, ifBB, nextCondBB);
        
        // Entra no bloco if
        LLVMPositionBuilderAtEnd(builder, ifBB);

        pushScope();

        haveRetAll = 1;

        haveRet = 0;
    } LEFTKEYS program_locals RIGHTKEYS {

        popScope();

        if(haveRet == 0) {
            haveRetAll = 0;
        }

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);
    } else_if_chain {
        // Finaliza este contexto
        ConditionalContext current = pop_cond_context();
        LLVMPositionBuilderAtEnd(builder, current.endBB);
        
        LLVMBasicBlockRef endBB = LLVMAppendBasicBlockInContext(context, currentFunc, "endif");
        LLVMBuildBr(builder, endBB);

        LLVMPositionBuilderAtEnd(builder, endBB);

        if(haveRetAll == 1) {
            LLVMBuildUnreachable(builder);
        }
    }
    ;

else_if_chain
    : /* empty */ {
        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
    }
    | ELSE LEFTPAR expression RIGHTPAR {
        fprintf(stderr, "Error: else cannot have a condition at line %d.\n", yylineno);
    }
    | ELSE {

        pushScope();
        
        ConditionalContext* current = top_cond_context();
        // Transforma o nextCondBB em bloco else
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);

        haveRet = 0;
    } LEFTKEYS program_locals RIGHTKEYS {

        popScope();

        if(haveRet == 0) {
            haveRetAll = 0;
        }

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
    }
    | ELSEIF LEFTPAR expression RIGHTPAR {
        if ($3.type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }
        
        ConditionalContext* current = top_cond_context();
        
        // Cria blocos para este elseif
        LLVMBasicBlockRef elseifBB = LLVMAppendBasicBlockInContext(context, currentFunc, "elseif");
        LLVMBasicBlockRef newNextBB = LLVMAppendBasicBlockInContext(context, currentFunc, "next_cond");
        
        // Gera branch condicional
        LLVMBuildCondBr(builder, $3.llvm_value, elseifBB, newNextBB);
        
        // Atualiza contexto
        current->nextCondBB = newNextBB;
        
        // Entra no bloco elseif
        LLVMPositionBuilderAtEnd(builder, elseifBB);

        pushScope();

        haveRet = 0;
    } LEFTKEYS program_locals RIGHTKEYS {

        popScope();

        if(haveRet == 0) {
            haveRetAll = 0;
        }

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);
    } else_if_chain {}
    ;





while
    : WHILE while_aux LEFTPAR expression RIGHTPAR {
        pushScope();
        if ($4.type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }

        // Gera branch condicional
        LLVMBuildCondBr(builder, $4.llvm_value, $2.bodyBB, $2.endWHILEBB);

        // Corpo do while
        LLVMPositionBuilderAtEnd(builder, $2.bodyBB);
    } LEFTKEYS program_locals RIGHTKEYS {
        // Ao final do corpo, volta para o condicional
        LLVMBuildBr(builder, $2.condBB);

        // Posiciona o builder no bloco de saída do while
        LLVMPositionBuilderAtEnd(builder, $2.endWHILEBB);

        popScope();
    }
    ;

while_aux
    : {
        // Cria blocos para condicional, corpo e fim do while
        $$.condBB = LLVMAppendBasicBlockInContext(context, currentFunc, "while.cond");
        $$.bodyBB = LLVMAppendBasicBlockInContext(context, currentFunc, "while.body");
        $$.endWHILEBB = LLVMAppendBasicBlockInContext(context, currentFunc, "while.end");

        // Branch para o bloco condicional
        LLVMBuildBr(builder, $$.condBB);

        // Condicional
        LLVMPositionBuilderAtEnd(builder, $$.condBB);
    }
    ;


for
    : FOR for_aux LEFTPAR declaration_local {
        // Pula direto para o bloco de condição após a declaração
        LLVMBuildBr(builder, $2.condBB);

        // Posiciona no bloco condicional
        LLVMPositionBuilderAtEnd(builder, $2.condBB);
    } expression DONE {
        pushScope();
        if ($6.type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }

        // Condicional
        LLVMBuildCondBr(builder, $6.llvm_value, $2.bodyBB, $2.endFORBB);

        // Incremento do for
        LLVMPositionBuilderAtEnd(builder, $2.incBB);
    } assignment_notfull {
        // Posiciona o builder no bloco de corpo
        LLVMPositionBuilderAtEnd(builder, $2.bodyBB);
    }
    RIGHTPAR LEFTKEYS program_locals RIGHTKEYS {
        // Ao final do corpo, volta para o incremento
        LLVMBuildBr(builder, $2.incBB);

        LLVMPositionBuilderAtEnd(builder, $2.incBB);

        // Ao final do incremento, volta para a condição
        LLVMBuildBr(builder, $2.condBB);

        // Posiciona no final do for
        LLVMPositionBuilderAtEnd(builder, $2.endFORBB);

        popScope();
    }
    ;

for_aux
    : {
        // Cria os blocos condicional, corpo e final
        $$.condBB = LLVMAppendBasicBlockInContext(context, currentFunc, "for.cond");
        $$.bodyBB = LLVMAppendBasicBlockInContext(context, currentFunc, "for.body");
        $$.incBB = LLVMAppendBasicBlockInContext(context, currentFunc, "for.inc");
        $$.endFORBB = LLVMAppendBasicBlockInContext(context, currentFunc, "for.end");
    }
    ;

do_while
    : DO do_while_aux {
        pushScope();

        // Posiciona o builder no corpo do do-while
        LLVMPositionBuilderAtEnd(builder, $2.bodyBB);
    } LEFTKEYS program_locals RIGHTKEYS {
        // Ao final do corpo, volta para a condição
        LLVMBuildBr(builder, $2.condBB);

        // Posiciona o builder no bloco de condição
        LLVMPositionBuilderAtEnd(builder, $2.condBB);
    } WHILE LEFTPAR expression RIGHTPAR DONE {
        if ($10.type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }
        // Gera branch condicional
        LLVMBuildCondBr(builder, $10.llvm_value, $2.bodyBB, $2.endWHILEBB);

        // Posiciona o builder no final do do-while
        LLVMPositionBuilderAtEnd(builder, $2.endWHILEBB);

        popScope();
    }


do_while_aux
    : {
        // Cria blocos para o corpo e condicional do do-while
        $$.bodyBB = LLVMAppendBasicBlockInContext(context, currentFunc, "do.body");
        $$.condBB = LLVMAppendBasicBlockInContext(context, currentFunc, "do.cond");
        $$.endWHILEBB = LLVMAppendBasicBlockInContext(context, currentFunc, "do.end");

        // Gera branch para o corpo do do-while
        LLVMBuildBr(builder, $$.bodyBB);
    }
    ;


printf
    : PRINTF LEFTPAR STRING printf_args RIGHTPAR DONE {
        // Cria global para a string de formatação
        LLVMValueRef str_global = LLVMAddGlobal(module, LLVMArrayType(LLVMInt8TypeInContext(context), strlen($3) + 1), "str_literal");
        LLVMSetInitializer(str_global, LLVMConstStringInContext(context, $3, strlen($3), 0));
        LLVMValueRef zero = LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0);
        LLVMValueRef indices[2] = { zero, zero };
        LLVMValueRef str_ptr = LLVMBuildGEP2(builder, LLVMArrayType(LLVMInt8TypeInContext(context), strlen($3) + 1), str_global, indices, 2, "strptr");

        // Monta lista de argumentos: primeiro a string, depois os valores
        LLVMValueRef args[MAX_PARAMS + 1];
        args[0] = str_ptr;
        for (int i = 0; i < $4.count; i++)
            args[i+1] = $4.values[i];

        LLVMValueRef printf_func = LLVMGetNamedFunction(module, "printf");
        LLVMBuildCall2(builder, printf_type, printf_func, args, $4.count + 1, "");
        free($3);
    }
    ;

printf_args
    : /* vazio */ { $$.count = 0; }
    | COMMA expression printf_args {
        $$.values[0] = $2.llvm_value;
        for (int i = 0; i < $3.count; i++)
            $$.values[i+1] = $3.values[i];
        $$.count = $3.count + 1;
    }
    ;


scanf
    : SCANF LEFTPAR STRING scanf_args RIGHTPAR DONE {
        // Cria global para a string de formatação
        LLVMValueRef str_global = LLVMAddGlobal(module, LLVMArrayType(LLVMInt8TypeInContext(context), strlen($3) + 1), "str_literal_scanf");
        LLVMSetInitializer(str_global, LLVMConstStringInContext(context, $3, strlen($3), 0));
        LLVMValueRef zero = LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0);
        LLVMValueRef indices[2] = { zero, zero };
        LLVMValueRef str_ptr = LLVMBuildGEP2(builder, LLVMArrayType(LLVMInt8TypeInContext(context), strlen($3) + 1), str_global, indices, 2, "strptr_scanf");

        // Monta lista de argumentos: primeiro a string, depois os ponteiros das variáveis
        LLVMValueRef args[MAX_PARAMS + 1];
        args[0] = str_ptr;
        for (int i = 0; i < $4.count; i++)
            args[i+1] = $4.values[i];

        LLVMValueRef scanf_func = LLVMGetNamedFunction(module, "scanf");
        LLVMBuildCall2(builder, scanf_type, scanf_func, args, $4.count + 1, "");
        free($3);
    }
    ;

scanf_args
    : /* vazio */ { $$.count = 0; }
    | COMMA ADDRESS ID scanf_args {
        Symbol* sym = findSymbol($3);
        if (!sym) {
            fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", $3, yylineno);
            $$.count = $4.count;
        } else {
            $$.values[0] = getVarLLVM($3);
            for (int i = 0; i < $4.count; i++)
                $$.values[i+1] = $4.values[i];
            $$.count = $4.count + 1;
        }
    }
    ;

return
    : RETURN expression DONE {
        if(functionList->returnType != TYPE_VOID) {
            if($2.type != functionList->returnType) {
                fprintf(stderr, "Error: return type mismatch at line %d. Expected %s but got %s.\n", yylineno, typeToString(functionList->returnType), typeToString($2.type));
            } else {
                LLVMBuildRet(builder, $2.llvm_value);
            }
        } else {
            fprintf(stderr, "Error: cannot return a value in a void function at line %d.\n", yylineno);
        }
        haveRet = 1;
    }
    | RETURN DONE {
        if(functionList->returnType != TYPE_VOID) {
            fprintf(stderr, "Error: function '%s' must return a value at line %d.\n", functionList->id, yylineno);
        } else {
            LLVMBuildRetVoid(builder);
        }
        haveRet = 1;
};



expression
    : soma_sub { $$.value = $1.value; $$.type = $1.type; $$.llvm_value = $1.llvm_value; }
    | mult_div { $$.value = $1.value; $$.type = $1.type; $$.llvm_value = $1.llvm_value; }
    | LEFTPAR expression RIGHTPAR { $$.value = $2.value; $$.type = $2.type; $$.llvm_value = $2.llvm_value; }
    | comparison { $$.value = $1.value; $$.type = $1.type; $$.llvm_value = $1.llvm_value; }
    | log_exp { $$.value = $1.value; $$.type = $1.type; $$.llvm_value = $1.llvm_value; }
    | cast { $$.value = $1.value; $$.type = $1.type; $$.llvm_value = $1.llvm_value; }
    | call_function_notfull { $$.value = $1.value; $$.type = $1.type; $$.llvm_value = $1.llvm_value; }
    | term { $$.value = $1.value; $$.type = $1.type; $$.llvm_value = $1.llvm_value; }
    ;

soma_sub
    : expression PLUS expression { 
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

mult_div
    : expression MULT expression {
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

comparison
    : expression LESS expression {
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

log_exp
    : expression AND expression {
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

cast
    : LEFTPAR INT RIGHTPAR LEFTPAR expression RIGHTPAR {
        int temp = (int) $5.value;
        $$.value = (double) temp;
        $$.type = TYPE_INT;
        switch ($5.type) {
            case TYPE_INT:
                $$.llvm_value = $5.llvm_value; // Já é int
                break;
            case TYPE_FLOAT:
                $$.llvm_value = LLVMBuildFPToSI(builder, $5.llvm_value, LLVMInt32TypeInContext(context), "castint");
                break;
            case TYPE_CHAR:
                $$.llvm_value = LLVMBuildSExt(builder, $5.llvm_value, LLVMInt32TypeInContext(context), "castint");
                break;
            case TYPE_BOOL:
                $$.llvm_value = LLVMBuildZExt(builder, $5.llvm_value, LLVMInt32TypeInContext(context), "castint");
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to int at line %d.\n", typeToString($5.type), yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
                $$.llvm_value = NULL;
        }
    }
    | LEFTPAR INT RIGHTPAR term {
        int temp = (int) $4.value;
        $$.value = (double) temp;
        $$.type = TYPE_INT;
        switch ($4.type) {
            case TYPE_INT:
                $$.llvm_value = $4.llvm_value; // Já é int
                break;
            case TYPE_FLOAT:
                $$.llvm_value = LLVMBuildFPToSI(builder, $4.llvm_value, LLVMInt32TypeInContext(context), "castint");
                break;
            case TYPE_CHAR:
                $$.llvm_value = LLVMBuildSExt(builder, $4.llvm_value, LLVMInt32TypeInContext(context), "castint");
                break;
            case TYPE_BOOL:
                $$.llvm_value = LLVMBuildZExt(builder, $4.llvm_value, LLVMInt32TypeInContext(context), "castint");
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to int at line %d.\n", typeToString($4.type), yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
                $$.llvm_value = NULL;
        }
    }
    | LEFTPAR FLOAT RIGHTPAR LEFTPAR expression RIGHTPAR {
        $$.value = $5.value;
        $$.type = TYPE_FLOAT;
        switch ($5.type) {
            case TYPE_INT:
                $$.llvm_value = LLVMBuildSIToFP(builder, $5.llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
                break;
            case TYPE_FLOAT:
                $$.llvm_value = $5.llvm_value; // Já é float
                break;
            case TYPE_CHAR:
                $$.llvm_value = LLVMBuildSIToFP(builder, $5.llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
                break;
            case TYPE_BOOL:
                $$.llvm_value = LLVMBuildSIToFP(builder, $5.llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to float at line %d.\n", typeToString($5.type), yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
                $$.llvm_value = NULL;
        }
    }
    | LEFTPAR FLOAT RIGHTPAR term {
        $$.value = $4.value;
        $$.type = TYPE_FLOAT;
        switch ($4.type) {
            case TYPE_INT:
                $$.llvm_value = LLVMBuildSIToFP(builder, $4.llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
                break;
            case TYPE_FLOAT:
                $$.llvm_value = $4.llvm_value; // Já é float
                break;
            case TYPE_CHAR:
                $$.llvm_value = LLVMBuildSIToFP(builder, $4.llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
                break;
            case TYPE_BOOL:
                $$.llvm_value = LLVMBuildSIToFP(builder, $4.llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to float at line %d.\n", typeToString($4.type), yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
                $$.llvm_value = NULL;
        }
    }
    | LEFTPAR CHAR RIGHTPAR LEFTPAR expression RIGHTPAR {
        $$.value = (double) ((char) $5.value);
        $$.type = TYPE_CHAR;
        switch ($5.type) {
            case TYPE_INT:
                $$.llvm_value = LLVMBuildTrunc(builder, $5.llvm_value, LLVMInt8TypeInContext(context), "castchar");
                break;
            case TYPE_FLOAT:
                $$.llvm_value = LLVMBuildFPToSI(builder, $5.llvm_value, LLVMInt8TypeInContext(context), "castchar");
                break;
            case TYPE_CHAR:
                $$.llvm_value = $5.llvm_value; // Já é char
                break;
            case TYPE_BOOL:
                $$.llvm_value = LLVMBuildZExt(builder, $5.llvm_value, LLVMInt8TypeInContext(context), "castbool");
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to char at line %d.\n", typeToString($5.type), yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
                $$.llvm_value = NULL;
        }
    }
    | LEFTPAR CHAR RIGHTPAR term {
        $$.value = (double) ((char) $4.value);
        $$.type = TYPE_CHAR;
        switch ($4.type) {
            case TYPE_INT:
                $$.llvm_value = LLVMBuildTrunc(builder, $4.llvm_value, LLVMInt8TypeInContext(context), "castchar");
                break;
            case TYPE_FLOAT:
                $$.llvm_value = LLVMBuildFPToSI(builder, $4.llvm_value, LLVMInt8TypeInContext(context), "castchar");
                break;
            case TYPE_CHAR:
                $$.llvm_value = $4.llvm_value; // Já é char
                break;
            case TYPE_BOOL:
                $$.llvm_value = LLVMBuildZExt(builder, $4.llvm_value, LLVMInt8TypeInContext(context), "castbool");
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to char at line %d.\n", typeToString($4.type), yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
                $$.llvm_value = NULL;
        }
    }
    | LEFTPAR BOOL RIGHTPAR LEFTPAR expression RIGHTPAR {
        $$.value = ($5.value != 0.0) ? 1.0 : 0.0;
        $$.type = TYPE_BOOL;
        LLVMValueRef zero;
        switch ($5.type) {
            case TYPE_INT:
                zero = LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0);
                $$.llvm_value = LLVMBuildICmp(builder, LLVMIntNE, $5.llvm_value, zero, "castbool");
                break;
            case TYPE_FLOAT:
                zero = LLVMConstReal(LLVMDoubleTypeInContext(context), 0.0);
                $$.llvm_value = LLVMBuildFCmp(builder, LLVMRealUNE, $5.llvm_value, zero, "castbool");
                break;
            case TYPE_CHAR:
                zero = LLVMConstInt(LLVMInt8TypeInContext(context), 0, 0);
                $$.llvm_value = LLVMBuildICmp(builder, LLVMIntNE, $5.llvm_value, zero, "castbool");
                break;
            case TYPE_BOOL:
                $$.llvm_value = $5.llvm_value; // Já é bool
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to bool at line %d.\n", typeToString($5.type), yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
                $$.llvm_value = NULL;
        }
    }
    | LEFTPAR BOOL RIGHTPAR term {
        $$.value = ($4.value != 0.0) ? 1.0 : 0.0;
        $$.type = TYPE_BOOL;
        LLVMValueRef zero;
        switch ($4.type) {
            case TYPE_INT:
                zero = LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0);
                $$.llvm_value = LLVMBuildICmp(builder, LLVMIntNE, $4.llvm_value, zero, "castbool");
                break;
            case TYPE_FLOAT:
                zero = LLVMConstReal(LLVMDoubleTypeInContext(context), 0.0);
                $$.llvm_value = LLVMBuildFCmp(builder, LLVMRealUNE, $4.llvm_value, zero, "castbool");
                break;
            case TYPE_CHAR:
                zero = LLVMConstInt(LLVMInt8TypeInContext(context), 0, 0);
                $$.llvm_value = LLVMBuildICmp(builder, LLVMIntNE, $4.llvm_value, zero, "castbool");
                break;
            case TYPE_BOOL:
                $$.llvm_value = $4.llvm_value; // Já é bool
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to bool at line %d.\n", typeToString($4.type), yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
                $$.llvm_value = NULL;
        }
    }
    ;

call_function
    : call_function_notfull DONE {}


call_function_notfull
    : ID LEFTPAR call_parameters RIGHTPAR {
        FunctionSymbol* func = findFunctionSymbol($1);
        if (func == NULL) {
            fprintf(stderr, "Error: function '%s' not declared at line %d.\n", $1, yylineno);
            $$.value = -1;
            $$.type = TYPE_UNKNOWN;
            $$.llvm_value = NULL;
        } else {
            if (func->paramCount != param_call_count) {
                fprintf(stderr, "Error: function '%s' expects %d parameters but got %d at line %d.\n", $1, func->paramCount, param_call_count, yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
                $$.llvm_value = NULL;
            } else {
                LLVMValueRef args[param_call_count];
                int j = 0;
                for (int i = param_call_count - 1; i >= 0; i--) {
                    args[j++] = param_call[i].llvm_value;
                }
                switch (func->returnType) {
                    case TYPE_INT:   func_type = LLVMFunctionType(LLVMInt32TypeInContext(context), NULL, 0, 0); break;
                    case TYPE_FLOAT: func_type = LLVMFunctionType(LLVMDoubleTypeInContext(context), NULL, 0, 0); break;
                    case TYPE_CHAR:  func_type = LLVMFunctionType(LLVMInt8TypeInContext(context), NULL, 0, 0); break;
                    case TYPE_BOOL:  func_type = LLVMFunctionType(LLVMInt1TypeInContext(context), NULL, 0, 0); break;
                    default:         func_type = LLVMFunctionType(LLVMVoidTypeInContext(context), NULL, 0, 0); break;
                }
                LLVMValueRef func_ref = LLVMGetNamedFunction(module, $1);
                if (func_ref == NULL) {
                    fprintf(stderr, "Error: function '%s' not found in module at line %d.\n", $1, yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                    $$.llvm_value = NULL;
                } else {
                    // Chama a função e armazena o valor de retorno
                    $$.llvm_value = LLVMBuildCall2(builder, func_type, func_ref, args, param_call_count, "");
                    $$.type = func->returnType;
                    $$.value = 0; // Opcional: você pode tentar calcular o valor se quiser
                }
            }
        }
        param_call_count = 0; // Limpa para próxima chamada
    }
    ;

call_parameters
    : /* empty */ {}
    | term call_parameter_list {
        param_call[param_call_count].value = $1.value;
        param_call[param_call_count].type = $1.type;
        param_call[param_call_count++].llvm_value = $1.llvm_value;
    }
    ;

call_parameter_list
    : /* empty */ {}
    | COMMA term call_parameter_list {
        param_call[param_call_count].value = $2.value;
        param_call[param_call_count].type = $2.type;
        param_call[param_call_count++].llvm_value = $2.llvm_value;
    }
    ;

term
    : NUMBER { 
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
        ArraySymbol* array_sym = findArraySymbol($1);
        if (!sym) {
            if (!array_sym) {
                fprintf(stderr, "Undeclared variable '%s' at line %d\n", $1, yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
            } else {
                // É um vetor, retorna ponteiro para o array
                $$.value = -1;
                $$.type = TYPE_POINTER;
                $$.llvm_value = getVarLLVM($1); // Ponteiro para o array
            }
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
    | ID LEFTBRACKET expression RIGHTBRACKET {
        ArraySymbol* array_sym = findArraySymbol($1);
        if (!array_sym) {
            fprintf(stderr, "Undeclared array '%s' at line %d\n", $1, yylineno);
            $$.value = -1;
            $$.type = TYPE_UNKNOWN;
        } else {
            if((int)$3.value < 0 || (int)$3.value >= array_sym->size) {
                fprintf(stderr, "Array index out of bounds for '%s' at line %d\n", $1, yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
            } else {
                if (array_sym->values[(int)$3.value] == -DBL_MAX) {
                    fprintf(stderr, "Array in position %d is uninitialized at line %d\n", (int)$3.value, yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                } else {
                    if ($3.type != TYPE_INT) {
                        fprintf(stderr, "Array index must be an integer at line %d\n", yylineno);
                        $$.value = -1;
                        $$.type = TYPE_UNKNOWN;
                    } else {
                        $$.value = array_sym->values[(int)$3.value];
                        $$.type = TYPE_INT;
                        LLVMValueRef var = getVarLLVM($1); // ponteiro para o array
                        LLVMValueRef idxs[2] = {
                            LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0),
                            $3.llvm_value // índice dinâmico
                        };
                        LLVMValueRef elem_ptr = LLVMBuildGEP2(
                            builder,
                            LLVMArrayType(LLVMInt32TypeInContext(context), array_sym->size),
                            var,
                            idxs,
                            2,
                            "arrayelem"
                        );
                        LLVMTypeRef llvm_type = LLVMInt32TypeInContext(context);
                        $$.llvm_value = LLVMBuildLoad2(builder, llvm_type, elem_ptr, "loadtmp");
                    }
                }
            }
        }
    }
    | CARACTERE {
        $$.value = (double) $1;
        $$.type = TYPE_CHAR;
        $$.llvm_value = LLVMConstInt(LLVMInt8TypeInContext(context), $1, 0);
};


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

int main() {
    signal(SIGSEGV, handleSegfault); // Handle segmentation faults
    pushScope(); // Initialize the first scope

    // Inicialização LLVM
    context = LLVMContextCreate();
    module = LLVMModuleCreateWithNameInContext("parser", context);
    builder = LLVMCreateBuilderInContext(context);

    // Declarações de funções padrão (assinaturas iguais às da linguagem C)
    LLVMTypeRef printf_arg_types[] = { LLVMPointerType(LLVMInt8TypeInContext(context), 0) };
    printf_type = LLVMFunctionType(
        LLVMInt32TypeInContext(context),
        printf_arg_types,
        1, 1 // 1 argumento fixo, variádico (igual ao C)
    );
    LLVMAddFunction(module, "printf", printf_type);

    LLVMTypeRef scanf_arg_types[] = { LLVMPointerType(LLVMInt8TypeInContext(context), 0) };
    scanf_type = LLVMFunctionType(
        LLVMInt32TypeInContext(context),
        scanf_arg_types,
        1, 1 // 1 argumento fixo, variádico (igual ao C)
    );
    LLVMAddFunction(module, "scanf", scanf_type);

    currentFunc = NULL; // Inicializa o ponteiro da função atual

    yyparse( );

    // Adiciona declare void @exit(i32)
    LLVMTypeRef exit_arg_types[] = { LLVMInt32TypeInContext(context) };
    LLVMTypeRef exit_type = LLVMFunctionType(LLVMVoidTypeInContext(context), exit_arg_types, 1, 0);
    LLVMAddFunction(module, "exit", exit_type);

    // Cria a função _start
    LLVMTypeRef start_type = LLVMFunctionType(LLVMVoidTypeInContext(context), NULL, 0, 0);
    LLVMValueRef start_func = LLVMAddFunction(module, "_start", start_type);
    LLVMBasicBlockRef entry = LLVMAppendBasicBlockInContext(context, start_func, "entry");
    LLVMPositionBuilderAtEnd(builder, entry);

    // Chama main()
    LLVMValueRef main_func = LLVMGetNamedFunction(module, "main");
    LLVMTypeRef main_type = LLVMFunctionType(LLVMInt32TypeInContext(context), NULL, 0, 0);
    if (main_func) {
        LLVMValueRef *args = NULL; // Ponteiro nulo para argumentos
        LLVMBuildCall2(builder, main_type, main_func, args, 0, "");
    }

    // Chama exit(0)
    LLVMValueRef zero = LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0);
    LLVMValueRef exit_func = LLVMGetNamedFunction(module, "exit");
    LLVMValueRef exit_args[] = { zero };
    LLVMBuildCall2(builder, exit_type, exit_func, exit_args, 1, "");

    LLVMBuildUnreachable(builder);

    // Imprime IR
    char *irstr = LLVMPrintModuleToString(module);
    printf("%s", irstr);
    LLVMDisposeMessage(irstr);

    LLVMDisposeBuilder(builder);
    LLVMDisposeModule(module);
    LLVMContextDispose(context);
    
    /* printSymbolTable(currentScope); // Print the symbol table */
    freeSymbolTable(currentScope); // Free the symbol table
    return 0;
}