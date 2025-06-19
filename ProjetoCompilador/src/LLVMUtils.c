#include "../include/LLVM/LLVMUtils.h"
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
LLVMValueRef currentFunc;
LLVMBasicBlockRef entry;
LLVMValueRef fmt_int, fmt_float, fmt_char, fmt_bool, fmt_str;
LLVMTypeRef printf_type, scanf_type;
LLVMTypeRef func_type;

LLVMValueRef aux;

LLVMValueRef allocaVars(const char* name, VarType type) {
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
    return alloc;
}

void allocaArrayVars(const char* name, VarType type, int size) {
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
    LLVMTypeRef array_type = LLVMArrayType(llvm_type, size);
    LLVMValueRef alloc = LLVMBuildAlloca(builder, array_type, name);
    var_names[var_count] = strdup(name);
    var_values[var_count++] = alloc;
}

void setVarLLVM(const char* name, LLVMValueRef var) {
    int exists = 0;
    // Se já existe, atualiza
    for (int i = 0; i < var_count; ++i) {
        if (strcmp(var_names[i], name) == 0) {
            var_values[i] = var;
            exists = 1;
        }
    }
    if(exists == 0) {
        // Se não existe, adiciona
        if (var_count >= MAX_VARS) {
            fprintf(stderr, "Error: too many variables.\n");
        }
        var_names[var_count] = strdup(name);
        var_values[var_count++] = var;
    }
}

LLVMValueRef getVarLLVM(const char* name) {
    for (int i = 0; i < var_count; ++i)
        if (strcmp(var_names[i], name) == 0)
            return var_values[i];
    return NULL;
}

LLVMValueRef getArrayVarLLVM(const char* name, int index) {
    for (int i = 0; i < var_count; ++i) {
        if (strcmp(var_names[i], name) == 0) {
            LLVMValueRef idx = LLVMConstInt(LLVMInt32TypeInContext(context), index, 0);
            LLVMValueRef indices[2] = { LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0), idx };
            LLVMValueRef array_ptr = LLVMBuildGEP2(builder, LLVMInt32TypeInContext(context), var_values[i], indices, 2, "");
            return array_ptr;
        }
    }
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