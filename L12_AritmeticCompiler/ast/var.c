#include "var.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

VariableNode* VariableNode_create(const char* identifier, const char* type, ExpressionNode* assigned_expression , int lineno) {
    VariableNode* node = calloc(1, sizeof(VariableNode));
    node->identifier = strdup(identifier);
    node->type = type ? strdup(type) : NULL;
    node->assigned_expression = assigned_expression;
    node->lineno = lineno;
    return node;
}

void VariableNode_free(VariableNode* self) {
    if (!self) return;
    printf("free VariableNode\n");

    free(self->identifier);
    free(self->type);
    ExpressionNode_free(self->assigned_expression);
    VariableNode_free(self->next);
    free(self);
}