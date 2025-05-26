#pragma once
#include "param.h"
#include "statement.h"

typedef struct FunctionNode {
    char* name;
    ParamNode* params;
    char* returnType;
    StatementNode* body;
    ExpressionNode* object; // apel de metode
    int isCall;             // 1 = apel de func
    int isMethodCall;       // 1 = apel de metoda
    int lineno;
    struct FunctionNode* next;
} FunctionNode;

FunctionNode* FunctionNode_create(const char* name, ParamNode* params, const char* returnType, StatementNode* body, int lineno);
FunctionNode* FunctionNode_create_call(const char* name, struct ArgNode* args, int lineno);
FunctionNode* FunctionNode_create_method_call(ExpressionNode* object, const char* methodName, struct ArgNode* args, int lineno);
void FunctionNode_free(FunctionNode* self);