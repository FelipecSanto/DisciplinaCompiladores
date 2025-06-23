#include "SymbolTable.h"
#include <stdlib.h>
#include <string.h>

SymbolTable* currentScope = NULL;
FunctionSymbol* functionList = NULL;

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

ArraySymbol* findArraySymbol(const char* id) {
    SymbolTable* scope = currentScope;
    while (scope != NULL) {
        ArraySymbol* arr = scope->arrayTable[hash(id)];
        while (arr != NULL) {
            if (strcmp(arr->id, id) == 0) return arr;
            arr = arr->next;
        }
        scope = scope->prev;
    }
    return NULL;
}

FunctionSymbol* findFunctionSymbol(const char* id) {
    FunctionSymbol* curr = functionList;
    while (curr) {
        if (strcmp(curr->id, id) == 0)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

void insertSymbol(const char* id, double value, VarType type) {
    if(currentScope) {
        Symbol* sym = findSymbol(id);
        ArraySymbol* arr = findArraySymbol(id);
        if (sym != NULL) {
            sym->value = value;
            sym->type = type;
        } else if (arr != NULL) {
            fprintf(stderr, "Symbol %s is an array, cannot assign value\n", id);
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

void createArraySymbol(const char* id, double* values, int size) {
    if (currentScope) {
        unsigned int index = hash(id);
        ArraySymbol* arr = findArraySymbol(id);
        Symbol* sym = findSymbol(id);
        if (arr != NULL) {
            fprintf(stderr, "Array %s already declared in this scope\n", id);
        } else if (sym != NULL) {
            fprintf(stderr, "Symbol %s is already declared as a variable, cannot create array with the same name\n", id);
        } else {
            arr = malloc(sizeof(ArraySymbol));
            arr->id = strdup(id);
            arr->values = malloc(size * sizeof(double));
            memcpy(arr->values, values, size * sizeof(double));
            arr->size = size;
            arr->type = TYPE_INT;
            arr->next = currentScope->arrayTable[index];
            currentScope->arrayTable[index] = arr;
        }
    }
}

void insertValueArraySymbol(const char* id, double value, int indice) {
    if (currentScope) {
        ArraySymbol* arr = findArraySymbol(id);
        if (arr == NULL) {
            fprintf(stderr, "Array %s not declared in this scope\n", id);
        }
        else if (indice < 0 || indice >= arr->size) {
            fprintf(stderr, "Index out of bounds for array %s\n", id);
        } else {
            arr->values[indice] = value;
        }
    }
}

void insertFunctionSymbol(const char* id, VarType returnType, int paramCount, VarType* paramTypes) {
    // Verifica se já existe
    FunctionSymbol* existing = findFunctionSymbol(id);
    if (existing) {
        fprintf(stderr, "Function '%s' already declared.\n", id);
        return;
    }
    FunctionSymbol* func = malloc(sizeof(FunctionSymbol));
    func->id = strdup(id);
    func->returnType = returnType;
    func->paramCount = paramCount;
    func->paramTypes = malloc(sizeof(VarType) * paramCount);
    for (int i = 0; i < paramCount; i++)
        func->paramTypes[i] = paramTypes[i];
    func->next = functionList;
    functionList = func;
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