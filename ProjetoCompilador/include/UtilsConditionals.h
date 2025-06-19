#ifndef UTILS_CONDITIONALS_H
#define UTILS_CONDITIONALS_H
#include <stdio.h>
#include <stdlib.h>
#include <llvm-c/Core.h>

extern int yylineno;

#define MAX_SCOPE_DEPTH 20  // Profundidade máxima de aninhamento

typedef struct {
    LLVMBasicBlockRef endBB;      // Bloco de fim do contexto atual
    LLVMBasicBlockRef nextCondBB; // Próxima condição na cadeia
} ConditionalContext;

typedef struct {
    ConditionalContext contexts[MAX_SCOPE_DEPTH];
    int top;
} CondContextStack;

extern CondContextStack condStack;

// Função para empilhar contexto
void push_cond_context(LLVMBasicBlockRef endBB, LLVMBasicBlockRef nextCondBB);

// Função para desempilhar contexto
ConditionalContext pop_cond_context();

// Função para acessar o topo sem desempilhar
ConditionalContext* top_cond_context();

#endif // UTILS_CONDITIONALS_H