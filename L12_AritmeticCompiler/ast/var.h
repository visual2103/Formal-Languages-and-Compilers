#pragma once
#include "expr.h"

// globala, locala sau camp de clasa 
#pragma once
#include "expr.h"

typedef struct VariableNode {
    char* identifier;
    char* type;
    ExpressionNode* assigned_expression;
    struct VariableNode* next;
    int lineno;
} VariableNode;

VariableNode* VariableNode_create(const char* identifier, const char* type, ExpressionNode* assigned_expression , int lineno);
void VariableNode_free(VariableNode* self);