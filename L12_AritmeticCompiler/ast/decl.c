#include "decl.h"
#include <stdlib.h>
#include <string.h>

DeclarationNode* DeclarationNode_create(
    char* identifier,
    char* type,
    ExpressionNode* assigned_expression,
    int lineno
) {
    DeclarationNode* self = calloc(1, sizeof(DeclarationNode));
    self->identifier = strdup(identifier);
    self->type = type ? strdup(type) : NULL;
    self->assigned_expression = assigned_expression;
    self->lineno = lineno;
    return self;
}

void DeclarationNode_free(DeclarationNode* self) {
    if (self == NULL) return;
    free(self->identifier);
    free(self->type);
    ExpressionNode_free(self->assigned_expression);
    free(self);
}