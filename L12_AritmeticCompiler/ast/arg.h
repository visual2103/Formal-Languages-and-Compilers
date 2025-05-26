#pragma once
#include "expr.h"


typedef struct ArgNode {
    ExpressionNode* expr;
    struct ArgNode* next;
    int lineno;
} ArgNode;

ArgNode* ArgNode_create(ExpressionNode* expr, ArgNode* next, int lineno);
void ArgNode_free(ArgNode* self);