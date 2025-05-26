#pragma once
#include <stdio.h>
#include "expr.h"
#include "decl.h"
#include "var.h"
#include "class.h"
#include "param.h"
#include "arg.h"
#include "statement.h"


typedef struct AST {
    DeclarationNode* declarations;
    ExpressionNode* expressions;
    ClassNode* classes;
    FunctionNode* functions;
    VariableNode* variables;
    StatementNode* statements;
    int numDeclarations;
    DeclarationNode* lastDeclaration;
    ExpressionNode* lastExpression;
    ClassNode* lastClass;
    FunctionNode* lastFunction;
    VariableNode* lastVariable;
    StatementNode* lastStatement;

} AST;

/* ---------------- */
/* Constructors */
/* ---------------- */

AST* AST_create();

/* ----------- */
/* Methods */
/* ----------- */

void AST_add_declaration(AST* self, DeclarationNode* declaration);
void AST_add_expression(AST* self, ExpressionNode* expression);
void AST_add_class(AST* self, ClassNode* class);
void AST_add_function(AST* self, FunctionNode* function);
void  AST_add_statement  (AST* self, StatementNode* stmt);
void AST_add_variable(AST* self, VariableNode* variable);


void AST_execute(AST* self, FILE* outputFile);
void AST_free(AST* self);