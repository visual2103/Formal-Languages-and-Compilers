#pragma once
#include <stdio.h>
#include "expr.h"
#include "var.h"

typedef enum {
    STMT_VAR_DECL,   // var x: T = expr;
    STMT_EXPR,       // expr;
    STMT_IF,         // if (cond) { … } else { … }
    STMT_WHILE,      // while (cond) { … }
    STMT_FOR,        // for (init; cond; update) { … }
    STMT_RETURN,     // return expr ;
    STMT_ASSIGN      // x = expr;
    // FARA STMT_LIST!
} StatementType;

typedef struct StatementNode {
    StatementType         type;
    struct StatementNode* next;

    union {
        VariableNode*  varDecl;  
        ExpressionNode* expr;     

        // if 
        struct {
            ExpressionNode* cond;
            struct StatementNode* thenBranch;
            struct StatementNode* elseBranch;  // NULL dacă nu exista
        } ifStmt;

        // while 
        struct {
            ExpressionNode* cond;
            struct StatementNode* body;
        } whileStmt;

        // for 
        struct {                                // STMT_FOR
            struct StatementNode* init;        // varDecl sau assign/expr
            ExpressionNode* cond;
            struct StatementNode* update;      // assign sau expr
            struct StatementNode* body;
        } forStmt;

        // return expr ; 
        ExpressionNode* returnExpr;  // NULL daca nu am expresie

        // x = expr;
        struct {
            ExpressionNode* target;       // IdentExpr sau MemberExpr
            ExpressionNode* value;        // expresia din dreapta
        } assignStmt;
    } as;
    int lineno;
} StatementNode;

// constructori
StatementNode* StatementNode_create_var    (VariableNode* var);
StatementNode* StatementNode_create_expr   (ExpressionNode* expr);
StatementNode* StatementNode_create_if     (ExpressionNode* cond, StatementNode* thenB, StatementNode* elseB);
StatementNode* StatementNode_create_while  (ExpressionNode* cond, StatementNode* body);
StatementNode* StatementNode_create_for    (StatementNode* init, ExpressionNode* cond, StatementNode* update,  StatementNode* body);
StatementNode* StatementNode_create_return (ExpressionNode* expr);
StatementNode* StatementNode_create_assign (ExpressionNode* target, ExpressionNode* value);
// FARA StatementNode_create_list!

void  StatementNode_free  (StatementNode* self);