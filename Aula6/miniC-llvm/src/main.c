#include <stdio.h>
#include <stdlib.h>
#include <llvm-c/Core.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Transforms/PassManager.h>
#include "parser/miniC.tab.h"
#include "llvm/codegen.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize LLVM
    LLVMInitializeNativeTarget();
    LLVMInitializeNativeAsmPrinter();
    LLVMInitializeNativeAsmParser();

    // Parse the input miniC code
    if (yyparse() != 0) {
        fprintf(stderr, "Error parsing the input file.\n");
        return EXIT_FAILURE;
    }

    // Generate LLVM IR
    LLVMModuleRef module = LLVMModuleCreateWithName("miniC_module");
    if (generateCode(module) != 0) {
        fprintf(stderr, "Error generating LLVM IR.\n");
        return EXIT_FAILURE;
    }

    // Create execution engine
    LLVMExecutionEngineRef engine;
    if (LLVMCreateExecutionEngineForModule(&engine, module, NULL) != 0) {
        fprintf(stderr, "Error creating execution engine.\n");
        return EXIT_FAILURE;
    }

    // Execute the generated code (if applicable)
    // ...

    // Clean up
    LLVMDisposeExecutionEngine(engine);
    LLVMDisposeModule(module);

    return EXIT_SUCCESS;
}