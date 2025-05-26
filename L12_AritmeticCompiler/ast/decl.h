#pragma once
#include "expr.h"

typedef struct DeclarationNode {
    char* identifier;
    char* type ; 
    ExpressionNode* assigned_expression;
    int lineno;
    struct DeclarationNode* next;
} DeclarationNode;

/* ------------ */
/* Constructors */
/* ------------ */

DeclarationNode* DeclarationNode_create(
    char* identifier,
    char* type,
    ExpressionNode* assigned_expression,
    int lineno
);

/* ------- */
/* Methods */
/* ------- */

void DeclarationNode_free(DeclarationNode* self);