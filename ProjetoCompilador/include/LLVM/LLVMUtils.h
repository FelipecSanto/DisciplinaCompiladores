#ifndef LLVM_UTILS_H
#define LLVM_UTILS_H

#include "VarType.h"
#include <llvm-c/Core.h>

#define MAX_VARS 100

extern char* var_names[MAX_VARS];
extern LLVMValueRef var_values[MAX_VARS];
extern int var_count;

extern LLVMModuleRef module;
extern LLVMBuilderRef builder;
extern LLVMContextRef context;
extern LLVMValueRef currentFunc;
extern LLVMBasicBlockRef entry;
extern LLVMValueRef fmt_int, fmt_float, fmt_char, fmt_bool, fmt_str;
extern LLVMTypeRef printf_type, scanf_type;
extern LLVMTypeRef func_type;

LLVMValueRef allocaVars(const char* name, VarType type);
void allocaArrayVars(const char* name, VarType type, int size);
void setVarLLVM(const char* name, LLVMValueRef var);
LLVMValueRef getVarLLVM(const char* name);
LLVMValueRef getArrayVarLLVM(const char* name, int index);
LLVMValueRef createGlobalString(const char* str, const char* name);

extern LLVMValueRef aux;

#endif