
#include "param.h"
#include <stdlib.h>
#include <string.h>

ParamNode* ParamNode_create(const char* name, const char* type, ParamNode* next, int lineno) {
    ParamNode* node = calloc(1, sizeof(ParamNode));
    node->name = strdup(name);
    node->type = type ? strdup(type) : NULL;    node->next = next;
    node->lineno = lineno;
    return node;
}

void ParamNode_free(ParamNode* self) {
    if (!self) return;
    free(self->name);
    free(self->type);
    ParamNode_free(self->next);
    free(self);
}