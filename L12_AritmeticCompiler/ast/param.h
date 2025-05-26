#pragma once
#include "var.h"

typedef struct ParamNode {
    char* name;
    char* type;
    struct ParamNode* next;
    int lineno;
} ParamNode;

ParamNode* ParamNode_create(const char* name, const char* type, ParamNode* next, int lineno);
void ParamNode_free(ParamNode* self);