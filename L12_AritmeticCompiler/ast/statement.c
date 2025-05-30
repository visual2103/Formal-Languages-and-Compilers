#include "statement.h"
#include <stdlib.h>
#include <stdio.h>

// var x: T = expr;
StatementNode* StatementNode_create_var(VariableNode* var) {
    StatementNode* s = calloc(1, sizeof(StatementNode));
    s->type         = STMT_VAR_DECL;
    s->as.varDecl   = var;
    s->next         = NULL;
    return s;
}
// expr;
StatementNode* StatementNode_create_expr(ExpressionNode* expr) {
    StatementNode* s = calloc(1, sizeof(StatementNode));
    s->type        = STMT_EXPR;
    s->as.expr     = expr;
    s->next        = NULL;
    return s;
}

/*
if (cond) { 
  blocul -> thenB
} else {
  blocul -> elseB 
}
*/
StatementNode* StatementNode_create_if(ExpressionNode* cond, StatementNode* thenB, StatementNode* elseB) {
    StatementNode* s = calloc(1, sizeof(StatementNode));
    s->type = STMT_IF;
    s->as.ifStmt.cond = cond;
    s->as.ifStmt.thenBranch = thenB;
    s->as.ifStmt.elseBranch = elseB;
    s->next = NULL;
    return s;
}

// while (cond) { body }
StatementNode* StatementNode_create_while(ExpressionNode* cond, StatementNode* body) {
    StatementNode* s = calloc(1, sizeof(StatementNode));
    s->type = STMT_WHILE;
    s->as.whileStmt.cond = cond;
    s->as.whileStmt.body = body;
    s->next = NULL;
    return s;
}

// for (init; cond; update) { body }
StatementNode* StatementNode_create_for(StatementNode* init, ExpressionNode* cond, StatementNode* update, StatementNode* body) {
    StatementNode* s     = calloc(1, sizeof(StatementNode));
    s->type              = STMT_FOR;
    s->as.forStmt.init   = init;
    s->as.forStmt.cond   = cond;
    s->as.forStmt.update = update;
    s->as.forStmt.body   = body;
    s->next = NULL;
    return s;
}

// return expr;
StatementNode* StatementNode_create_return(ExpressionNode* expr) {
    StatementNode* s             = calloc(1, sizeof(StatementNode));
    s->type                      = STMT_RETURN;
    s->as.returnExpr             = expr;
    s->next = NULL;
    return s;
}

// x = expr;
StatementNode* StatementNode_create_assign(ExpressionNode* target, ExpressionNode* value) {
    StatementNode* s               = calloc(1, sizeof(StatementNode));
    s->type                        = STMT_ASSIGN;
    s->as.assignStmt.target       = target;
    s->as.assignStmt.value        = value;
    s->next = NULL;
    return s;
}

// NU MAI EXISTĂ StatementNode_create_list!

void StatementNode_free(StatementNode* self) {
    if (!self) return;
    printf("free StatementNode\n ");
    switch (self->type) {
        case STMT_VAR_DECL:
            break;
        case STMT_EXPR:
            ExpressionNode_free(self->as.expr);
            break;
        case STMT_IF:
            ExpressionNode_free(self->as.ifStmt.cond);
            StatementNode_free(self->as.ifStmt.thenBranch);
            StatementNode_free(self->as.ifStmt.elseBranch);
            break;
        case STMT_WHILE:
            ExpressionNode_free(self->as.whileStmt.cond);
            StatementNode_free(self->as.whileStmt.body);
            break;
        case STMT_FOR:
            StatementNode_free(self->as.forStmt.init);
            ExpressionNode_free(self->as.forStmt.cond);
            StatementNode_free(self->as.forStmt.update);
            StatementNode_free(self->as.forStmt.body);
            break;
        case STMT_RETURN:
            ExpressionNode_free(self->as.returnExpr);
            break;
        case STMT_ASSIGN:
            ExpressionNode_free(self->as.assignStmt.target);
            ExpressionNode_free(self->as.assignStmt.value);
            break;
        // NU mai există STMT_LIST!
    }
    StatementNode_free(self->next);
    free(self);
}