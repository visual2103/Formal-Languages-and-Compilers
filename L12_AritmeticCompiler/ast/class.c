#include "class.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ClassNode* ClassNode_create(const char* name, VariableNode* fields, FunctionNode* methods) {
    ClassNode* cls = calloc(1, sizeof(ClassNode));
    cls->name = strdup(name);
    cls->fields = fields;
    cls->methods = methods;
    return cls;
}

ClassNode* ClassNode_create_body(FunctionNode* method, DeclarationNode* fieldDecl, ClassNode* next, int lineno) {
    ClassNode* cls = calloc(1, sizeof(ClassNode));
    cls->lineno = lineno;
    cls->methods = method;

    if (fieldDecl) {
        VariableNode* var = VariableNode_create(fieldDecl->identifier, fieldDecl->type, fieldDecl->assigned_expression, lineno);
        if (next && next->fields) {
            var->next = next->fields;
        }
        cls->fields = var;
    } else if (next) {
        cls->fields = next->fields;
    }

    if (next && next->methods) {
        if (cls->methods) {
            FunctionNode* last = cls->methods;
            while (last->next) last = last->next;
            last->next = next->methods;
        } else {
            cls->methods = next->methods;
        }
    }

    return cls;
}

void ClassNode_free(ClassNode* self) {
    if (!self) return;
    printf("free class node\n");
    free(self->name);
   //ClassNode_free(self->next);
    free(self);
}