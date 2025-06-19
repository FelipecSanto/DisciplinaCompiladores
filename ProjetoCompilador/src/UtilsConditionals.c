#include "../include/UtilsConditionals.h"

CondContextStack condStack = { .top = -1 };

// Função para empilhar contexto
void push_cond_context(LLVMBasicBlockRef endBB, LLVMBasicBlockRef nextCondBB) {
    if (condStack.top >= MAX_SCOPE_DEPTH - 1) {
        fprintf(stderr, "Error: Maximum nesting depth exceeded at line %d\n", yylineno);
        exit(1);
    }
    
    condStack.top++;
    condStack.contexts[condStack.top].endBB = endBB;
    condStack.contexts[condStack.top].nextCondBB = nextCondBB;
}

// Função para desempilhar contexto
ConditionalContext pop_cond_context() {
    if (condStack.top < 0) {
        fprintf(stderr, "Error: Condition stack underflow at line %d\n", yylineno);
        exit(1);
    }
    
    return condStack.contexts[condStack.top--];
}

// Função para acessar o topo sem desempilhar
ConditionalContext* top_cond_context() {
    if (condStack.top < 0) {
        return NULL;
    }
    return &condStack.contexts[condStack.top];
}