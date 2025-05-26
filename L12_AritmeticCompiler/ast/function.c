#include "function.h"
#include <stdlib.h>
#include <string.h>

FunctionNode* FunctionNode_create(const char* name, ParamNode* params, const char* returnType, StatementNode* body, int lineno) {
    FunctionNode* fn = calloc(1, sizeof(FunctionNode));
    fn->name = strdup(name);
    fn->params = params;
    fn->returnType = returnType ? strdup(returnType) : NULL;
    fn->body = body;
    fn->lineno = lineno;
    return fn;
}

FunctionNode* FunctionNode_create_call(const char* name, struct ArgNode* args, int lineno) {
    FunctionNode* fn = calloc(1, sizeof(FunctionNode));
    fn->name = strdup(name);
    fn->params = (ParamNode*)args; // Reutilizăm câmpul params pentru args
    fn->isCall = 1; // Adaugă câmp isCall în struct dacă e necesar
    fn->lineno = lineno;
    return fn;
}

FunctionNode* FunctionNode_create_method_call(ExpressionNode* object, const char* methodName, struct ArgNode* args, int lineno) {
    FunctionNode* fn = calloc(1, sizeof(FunctionNode));
    fn->name = strdup(methodName);
    fn->params = (ParamNode*)args; // Reutilizăm câmpul params pentru args
    fn->object = object; // Adaugă câmp object în struct dacă e necesar
    fn->isMethodCall = 1; // Adaugă câmp isMethodCall dacă e necesar
    fn->lineno = lineno;
    return fn;
}

void FunctionNode_free(FunctionNode* self) {
    if (!self) return;
    free(self->name);
    free(self->returnType);
    ParamNode_free(self->params);
    StatementNode_free(self->body);
    ExpressionNode_free(self->object);
    FunctionNode_free(self->next);
    free(self);
}