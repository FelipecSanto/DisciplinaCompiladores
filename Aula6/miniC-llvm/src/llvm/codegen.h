#ifndef CODEGEN_H
#define CODEGEN_H

#include "VarType.h"

// Function to initialize the LLVM environment
void initializeLLVM();

// Function to generate LLVM IR for the given program
void generateCodeForProgram(Node* program);

// Function to generate LLVM IR for a declaration
void generateCodeForDeclaration(Node* declaration);

// Function to generate LLVM IR for an assignment
void generateCodeForAssignment(Node* assignment);

// Function to generate LLVM IR for an expression
Value* generateCodeForExpression(Node* expression);

// Function to generate LLVM IR for a while loop
void generateCodeForWhile(Node* whileNode);

// Function to generate LLVM IR for an if statement
void generateCodeForIf(Node* ifNode);

// Function to finalize the LLVM module and output the IR
void finalizeLLVM();

#endif // CODEGEN_H