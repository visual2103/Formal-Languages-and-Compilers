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

ClassNode* ClassNode_create_body(FunctionNode* method, struct DeclarationNode* fieldDecl, ClassNode* next, int lineno) {
    ClassNode* cls = calloc(1, sizeof(ClassNode));
    if (fieldDecl) {
        cls->fields = VariableNode_create(fieldDecl->identifier, fieldDecl->type, fieldDecl->assigned_expression, lineno);
    }
    cls->methods = method;
    cls->next = next;
    cls->lineno = lineno;
    return cls;
}

void ClassNode_free(ClassNode* self) {
    if (!self) return;
    printf("free class node\n");
    free(self->name);
   //ClassNode_free(self->next);
    free(self);
}