#include "function.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

FunctionNode* FunctionNode_create(const char* name, ParamNode* params, const char* returnType, StatementNode* body, int lineno) {
    FunctionNode* fn = calloc(1, sizeof(FunctionNode));
    fn->name = strdup(name);
    fn->params = params;
    fn->args = NULL; // Explicitly set to NULL
    fn->returnType = returnType ? strdup(returnType) : NULL;
    fn->body = body;
    fn->lineno = lineno;
    return fn;
}

FunctionNode* FunctionNode_create_call(const char* name, ArgNode* args, int lineno) {
    FunctionNode* fn = calloc(1, sizeof(FunctionNode));
    fn->name = strdup(name);
    fn->params = NULL; // Explicitly set to NULL
    fn->args = args;
    fn->isCall = 1;
    fn->lineno = lineno;
    return fn;
}

FunctionNode* FunctionNode_create_method_call(ExpressionNode* object, const char* methodName, ArgNode* args, int lineno) {
    FunctionNode* fn = calloc(1, sizeof(FunctionNode));
    fn->name = strdup(methodName);
    fn->params = NULL; // Explicitly set to NULL
    fn->args = args;
    fn->object = object;
    fn->isMethodCall = 1;
    fn->lineno = lineno;
    return fn;
}

void FunctionNode_free(FunctionNode* self) {
    if (!self) return;
    printf("free function node %p (isCall=%d, isMethodCall=%d)\n", (void*)self, self->isCall, self->isMethodCall);
    free(self->name);
    free(self->returnType);
    if (self->isCall || self->isMethodCall) {
        printf("freeing args %p\n", (void*)self->args);
        ArgNode_free(self->args);
    } else {
        printf("freeing params %p\n", (void*)self->params);
        ParamNode_free(self->params);
        StatementNode_free(self->body);
    }
    //FunctionNode_free(self->next);
    free(self);
}