#include "LLVMUtils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <llvm-c/Core.h>

char* var_names[MAX_VARS];
LLVMValueRef var_values[MAX_VARS];
int var_count = 0;

LLVMModuleRef module;
LLVMBuilderRef builder;
LLVMContextRef context;
LLVMValueRef mainFunc;
LLVMBasicBlockRef entry;

LLVMValueRef aux;

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