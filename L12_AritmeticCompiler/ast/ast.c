#include "ast.h"
#include "../engine/engine.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



AST* AST_create() {
    AST* ast = calloc(1, sizeof(AST));
    return ast;
}

void AST_add_class(AST* ast, ClassNode* c) {
    if (!ast || !c) return;
    c->next = ast->classes;
    ast->classes = c;
    ast->lastClass = c;
    ast->numDeclarations++;
}

void AST_add_function(AST* ast, FunctionNode* f) {
    if (!ast || !f) return;
    f->next = ast->functions;
    ast->functions = f;
    ast->lastFunction = f;
    ast->numDeclarations++;
}

void AST_add_statement(AST* ast, StatementNode* s) {
    if (!ast || !s) return;
    s->next = ast->statements;
    ast->statements = s;
    ast->lastStatement = s;
    ast->numDeclarations++;
}

void AST_add_variable(AST* ast, VariableNode* v) {
    if (!ast || !v) return;
    v->next = ast->variables;
    ast->variables = v;
    ast->lastVariable = v;
    ast->numDeclarations++;
}

void AST_add_declaration(AST* ast, DeclarationNode* d) {
    if (!ast || !d) return;
    d->next = ast->declarations;
    ast->declarations = d;
    ast->lastDeclaration = d;
    ast->numDeclarations++;
}

void AST_add_expression(AST* ast, ExpressionNode* e) {
    if (!ast || !e) return;
    e->next = ast->expressions;
    ast->expressions = e;
    ast->lastExpression = e;
    ast->numDeclarations++;
}

void AST_execute(AST* self, FILE* outputFile) {
    if (!self || !outputFile) return;
    execute(self, outputFile);
}

void AST_free(AST* ast) {
    if (!ast) return;
    printf("free ast \n");
    ClassNode* c = ast->classes;
    while (c) {
        ClassNode* next = c->next;
        ClassNode_free(c);
        c = next;
    }
    FunctionNode* f = ast->functions;
    while (f) {
        FunctionNode* next = f->next;
        FunctionNode_free(f);
        f = next;
    }
    StatementNode* s = ast->statements;
    while (s) {
        StatementNode* next = s->next;
        StatementNode_free(s);
        s = next;
    }
    VariableNode* v = ast->variables;
    while (v) {
        VariableNode* next = v->next;
        VariableNode_free(v);
        v = next;
    }
    DeclarationNode* d = ast->declarations;
    while (d) {
        DeclarationNode* next = d->next;
        DeclarationNode_free(d);
        d = next;
    }
    ExpressionNode* e = ast->expressions;
    while (e) {
        ExpressionNode* next = e->next;
        ExpressionNode_free(e);
        e = next;
    }
    free(ast);
}