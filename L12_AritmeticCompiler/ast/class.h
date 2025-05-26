#pragma once
#include "var.h"
#include "function.h"
#include "decl.h"

typedef struct ClassNode {
    char* name;
    VariableNode* fields;
    FunctionNode* methods;
    struct ClassNode* next;
    int lineno;
} ClassNode;

ClassNode* ClassNode_create(const char* name, VariableNode* fields, FunctionNode* methods);
ClassNode* ClassNode_create_body(FunctionNode* method, struct DeclarationNode* fieldDecl, ClassNode* next, int lineno);
void ClassNode_free(ClassNode* self);