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

typedef struct SymbolTable {
    Symbol* table[HASH_SIZE];
    struct SymbolTable* prev;
} SymbolTable;

extern SymbolTable* currentScope;

unsigned int hash(const char* id);
Symbol* findSymbol(const char* id);
void insertSymbol(const char* id, double value, VarType type);
void pushScope();
void popScope();
void freeSymbolTable(SymbolTable* table);

#endif