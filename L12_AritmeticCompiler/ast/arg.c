#include "arg.h"
#include <stdlib.h>
#include <stdio.h>

ArgNode* ArgNode_create(ExpressionNode* expr, ArgNode* next, int lineno) {
    ArgNode* node = calloc(1, sizeof(ArgNode));
    node->expr = expr;
    node->next = next;
    node->lineno = lineno;
    return node;
}

void ArgNode_free(ArgNode* self) {
    if (!self) return;
    printf("free arg node\n ");

    ExpressionNode_free(self->expr);
    ArgNode_free(self->next);
    free(self);
}