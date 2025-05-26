#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <llvm-c/Core.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Transforms/Scalar.h>
#include "codegen.h"
#include "VarType.h"

// Function prototypes
static LLVMValueRef codegen_expression(expression_t *expr);
static LLVMValueRef codegen_statement(statement_t *stmt);
static LLVMModuleRef module;

// Initialize LLVM and create a new module
void init_codegen() {
    LLVMInitializeNativeTarget();
    LLVMInitializeNativeAsmPrinter();
    module = LLVMModuleCreateWithName("miniC_module");
}

// Generate LLVM IR for the given program
void codegen_program(program_t *program) {
    for (int i = 0; i < program->num_statements; i++) {
        codegen_statement(&program->statements[i]);
    }
}

// Generate LLVM IR for an expression
static LLVMValueRef codegen_expression(expression_t *expr) {
    switch (expr->type) {
        case EXPR_INT:
            return LLVMConstInt(LLVMInt32Type(), expr->value.int_val, 0);
        case EXPR_FLOAT:
            return LLVMConstReal(LLVMFloatType(), expr->value.float_val);
        // Add more cases for other expression types
        default:
            fprintf(stderr, "Error: Unsupported expression type\n");
            return NULL;
    }
}

// Generate LLVM IR for a statement
static LLVMValueRef codegen_statement(statement_t *stmt) {
    switch (stmt->type) {
        case STMT_ASSIGN:
            // Handle assignment
            break;
        case STMT_IF:
            // Handle if statement
            break;
        case STMT_WHILE:
            // Handle while statement
            break;
        // Add more cases for other statement types
        default:
            fprintf(stderr, "Error: Unsupported statement type\n");
            return NULL;
    }
    return NULL;
}

// Finalize the code generation and print the LLVM IR
void finalize_codegen() {
    char *ir = LLVMPrintModuleToString(module);
    printf("%s\n", ir);
    LLVMDisposeMessage(ir);
    LLVMDisposeModule(module);
}