#ifndef LLVM_UTILS_H
#define LLVM_UTILS_H

#include "VarType.h"
#include <llvm-c/Core.h>

#define MAX_VARS 1000

extern char* var_names[MAX_VARS];
extern LLVMValueRef var_values[MAX_VARS];
extern int var_count;

extern LLVMModuleRef module;
extern LLVMBuilderRef builder;
extern LLVMContextRef context;
extern LLVMValueRef mainFunc;
extern LLVMBasicBlockRef entry;
extern LLVMValueRef fmt_int, fmt_float, fmt_char, fmt_bool, fmt_str;
extern LLVMTypeRef printf_type, scanf_type;

void allocaVars(const char* name, VarType type);
LLVMValueRef getVarLLVM(const char* name);
LLVMValueRef createGlobalString(const char* str, const char* name);

extern LLVMValueRef aux;

#endif