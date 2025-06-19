#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

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

#define HASH_SIZE 100

typedef struct Symbol {
    char* id;
    double value;
    VarType type;
    struct Symbol* next;
} Symbol;

typedef struct ArraySymbol {
    char* id;
    double* values;
    int size;
    VarType type;
    struct ArraySymbol* next;
} ArraySymbol;

typedef struct FunctionSymbol {
    char* id;
    VarType returnType;
    int paramCount;
    VarType* paramTypes;
    struct FunctionSymbol* next;
} FunctionSymbol;

typedef struct SymbolTable {
    Symbol* table[HASH_SIZE];
    ArraySymbol* arrayTable[HASH_SIZE];
    struct SymbolTable* prev;
} SymbolTable;

extern SymbolTable* currentScope;
extern FunctionSymbol* functionList;

unsigned int hash(const char* id);
Symbol* findSymbol(const char* id);
ArraySymbol* findArraySymbol(const char* id);
FunctionSymbol* findFunctionSymbol(const char* id);
void insertSymbol(const char* id, double value, VarType type);
void createArraySymbol(const char* id, double* values, int size);
void insertValueArraySymbol(const char* id, double value, int indice);
void insertFunctionSymbol(const char* id, VarType returnType, int paramCount, VarType* paramTypes);
void pushScope();
void popScope();
void freeSymbolTable(SymbolTable* table);

#endif