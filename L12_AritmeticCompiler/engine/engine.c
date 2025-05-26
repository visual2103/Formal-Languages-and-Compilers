#include "engine.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../ast/decl.h"
#include "../ast/expr.h"
#include "../ast/var.h"
#include "../ast/statement.h"
#include "../ast/function.h"
#include "../ast/class.h"

static char wasDeclared[52] = {0}; // track pentru identificatori A–Z, a–z

// Forward declarations
static void gen_declaration(DeclarationNode* d, FILE* out);
static void gen_expression(ExpressionNode* e, FILE* out);
static void gen_variable(VariableNode* v, FILE* out);
static void gen_statement(StatementNode* s, FILE* out);
static void gen_function(FunctionNode* f, FILE* out);
static void gen_class(ClassNode* c, FILE* out);

void execute(AST* ast, FILE* out) {
    if (!ast) return;

    // 1) Include-uri
    fprintf(out,
        "#include <stdio.h>\n"
        "#include <stdlib.h>\n"
        "#include <math.h>\n\n"
    );

    // 2) Clase
    for (ClassNode* c = ast->classes; c; c = c->next) {
        gen_class(c, out);
    }

    // 3) Funcții
    for (FunctionNode* f = ast->functions; f; f = f->next) {
        gen_function(f, out);
    }

    // 4) Main implicit (dacă nu e în AST)
    int hasMain = 0;
    for (FunctionNode* f = ast->functions; f; f = f->next) { // Corectăm: f->next → f = f->next
        if (strcmp(f->name, "main") == 0) { hasMain = 1; break; }
    }

    if (!hasMain) {
        fprintf(out, "int main() {\n");
        // variabile globale / inițiale
        for (VariableNode* v = ast->variables; v; v = v->next) {
            gen_variable(v, out);
        }
        // statement-uri
        for (StatementNode* s = ast->statements; s; s = s->next) {
            gen_statement(s, out);
        }
        // declarații/expresii legacy
        DeclarationNode* decl = ast->declarations;
        ExpressionNode* expr = ast->expressions;
        while (decl || expr) {
            if (decl && (!expr || decl->lineno < expr->lineno)) {
                gen_declaration(decl, out);
                decl = decl->next;
            } else {
                fprintf(out, "\tprintf(\"%%d\\n\", ");
                gen_expression(expr, out);
                fprintf(out, ");\n");
                expr = expr->next;
            }
        }
        fprintf(out, "\treturn 0;\n}\n");
    }
}

// -----------------------------------------------------------------------------
// DeclarationNode -> C
static void gen_declaration(DeclarationNode* d, FILE* out) {
    if (!d || !d->identifier) return;
    char* id = d->identifier; // identifier este char*
    int idx = (id[0] >= 'a' ? id[0] - 'a' + 26 : id[0] - 'A');
    if (wasDeclared[idx]) {
        fprintf(out, "\t%s = ", id);
    } else {
        fprintf(out, "\tint %s = ", id);
        wasDeclared[idx] = 1;
    }
    gen_expression(d->assigned_expression, out);
    fprintf(out, ";\n");
}

// -----------------------------------------------------------------------------
// ExpressionNode -> C
static void gen_expression(ExpressionNode* e, FILE* out) {
    if (!e) return;
    switch (e->type) {
        case IMMEDIATE_IDENTIFIER: {
            char* id = e->data.identifier; // identifier este char*
            int idx = (id[0] >= 'a' ? id[0] - 'a' + 26 : id[0] - 'A');
            fprintf(out, "%s", wasDeclared[idx] ? id : "0");
            break;
        }
        case IMMEDIATE_NUMBER:
            fprintf(out, "%d", e->data.immediate_number);
            break;
        case IMMEDIATE_FLOAT:
            fprintf(out, "%f", e->data.immediate_float);
            break;
        case IMMEDIATE_STRING:
            fprintf(out, "\"%s\"", e->data.string);
            break;
         case MEMBER_ACCESS:
            gen_expression(e->data.member_access.object, out);
            fprintf(out, ".%s", e->data.member_access.member);
            break;
        case OPERATION_PLUS:
        case OPERATION_MINUS:
        case OPERATION_MUL:
        case OPERATION_DIV:
        case OPERATION_MOD:
        case OPERATION_EQ:
        case OPERATION_NEQ:
        case OPERATION_LE:
        case OPERATION_GE:
        case OPERATION_LT:
        case OPERATION_GT:
        case OPERATION_AND:
        case OPERATION_OR: {
            const char* op = e->type == OPERATION_PLUS  ? " + " :
                             e->type == OPERATION_MINUS ? " - " :
                             e->type == OPERATION_MUL   ? " * " :
                             e->type == OPERATION_DIV   ? " / " :
                             e->type == OPERATION_MOD   ? " % " :
                             e->type == OPERATION_EQ    ? " == " :
                             e->type == OPERATION_NEQ   ? " != " :
                             e->type == OPERATION_LE    ? " <= " :
                             e->type == OPERATION_GE    ? " >= " :
                             e->type == OPERATION_LT    ? " < " :
                             e->type == OPERATION_GT    ? " > " :
                             e->type == OPERATION_AND   ? " && " :
                                                          " || ";
            fprintf(out, "(");
            gen_expression(e->data.operation.left, out);
            fprintf(out, "%s", op);
            gen_expression(e->data.operation.right, out);
            fprintf(out, ")");
            break;
        }
        case OPERATION_POW:
            fprintf(out, "pow(");
            gen_expression(e->data.operation.left, out);
            fprintf(out, ", ");
            gen_expression(e->data.operation.right, out);
            fprintf(out, ")");
            break;
        case OPERATION_UNARY_MINUS:
            fprintf(out, "(-");
            gen_expression(e->data.operation.left, out);
            fprintf(out, ")");
            break;
        case OPERATION_NOT:
            fprintf(out, "(!");
            gen_expression(e->data.operation.left, out);
            fprintf(out, ")");
            break;
        case FUNCTION_CALL:
            if (e->data.functionCall->isMethodCall) {
                fprintf(out, "%s_%s(", e->data.functionCall->object ? e->data.functionCall->object->data.identifier : "this", e->data.functionCall->name);
                gen_expression(e->data.functionCall->object, out); // Obiectul (this)
                for (ArgNode* a = (ArgNode*)e->data.functionCall->params; a; a = a->next) { // Cast params la ArgNode*
                    fprintf(out, ", ");
                    gen_expression(a->expr, out);
                }
            } else {
                fprintf(out, "%s(", e->data.functionCall->name);
                for (ArgNode* a = (ArgNode*)e->data.functionCall->params; a; a = a->next) { // Cast params la ArgNode*
                    gen_expression(a->expr, out);
                    if (a->next) fprintf(out, ", ");
                }
            }
            fprintf(out, ")");
            break;
        case NEW_OBJECT:
            fprintf(out, "new_%s(", e->data.newObject.className);
            for (ArgNode* a = e->data.newObject.args; a; a = a->next) {
                gen_expression(a->expr, out);
                if (a->next) fprintf(out, ", ");
            }
            fprintf(out, ")");
            break;
        case ASSIGNMENT:
            fprintf(out, "%s = ", e->data.assignment.target);
            gen_expression(e->data.assignment.value, out);
            break;
    }
}

// -----------------------------------------------------------------------------
// VariableNode -> C
static void gen_variable(VariableNode* v, FILE* out) {
    if (!v) return;
    fprintf(out, "    %s %s", v->type ? v->type : "int", v->identifier);
    if (v->assigned_expression) {
        fprintf(out, " = ");
        gen_expression(v->assigned_expression, out);
    }
    fprintf(out, ";\n");
    if (strlen(v->identifier) == 1) {
        char id = v->identifier[0];
        int idx = (id >= 'a' ? id - 'a' + 26 : id - 'A');
        wasDeclared[idx] = 1;
    }
}

// -----------------------------------------------------------------------------
// StatementNode -> C
static void gen_statement(StatementNode* s, FILE* out) {
    if (!s) return;
    switch (s->type) {
        case STMT_VAR_DECL:
            gen_variable(s->as.varDecl, out);
            break;
        case STMT_ASSIGN:
            fprintf(out, "    ");
            gen_expression(s->as.assignStmt.target, out);
            fprintf(out, " = ");
            gen_expression(s->as.assignStmt.value, out);
            fprintf(out, ";\n");
            break;
        case STMT_EXPR:
            fprintf(out, "    ");
            gen_expression(s->as.expr, out);
            fprintf(out, ";\n");
            break;
        case STMT_RETURN:
            fprintf(out, "    return");
            if (s->as.returnExpr) {
                fprintf(out, " ");
                gen_expression(s->as.returnExpr, out);
            }
            fprintf(out, ";\n");
            break;
        case STMT_IF: {
            fprintf(out, "    if (");
            gen_expression(s->as.ifStmt.cond, out);
            fprintf(out, ") {\n");
            for (StatementNode* t = s->as.ifStmt.thenBranch; t; t = t->next)
                gen_statement(t, out);
            fprintf(out, "    }");
            if (s->as.ifStmt.elseBranch) {
                fprintf(out, " else {\n");
                for (StatementNode* e = s->as.ifStmt.elseBranch; e; e = e->next)
                    gen_statement(e, out);
                fprintf(out, "    }");
            }
            fprintf(out, "\n");
            break;
        }
        case STMT_WHILE:
            fprintf(out, "    while (");
            gen_expression(s->as.whileStmt.cond, out);
            fprintf(out, ") {\n");
            for (StatementNode* b = s->as.whileStmt.body; b; b = b->next)
                gen_statement(b, out);
            fprintf(out, "    }\n");
            break;
        case STMT_FOR:
            fprintf(out, "    for (");
            if (s->as.forStmt.init) gen_statement(s->as.forStmt.init, out);
            else fprintf(out, "; ");
            gen_expression(s->as.forStmt.cond, out);
            fprintf(out, "; ");
            if (s->as.forStmt.update) gen_statement(s->as.forStmt.update, out);
            else fprintf(out, "; ");
            fprintf(out, ") {\n");
            for (StatementNode* b = s->as.forStmt.body; b; b = b->next)
                gen_statement(b, out);
            fprintf(out, "    }\n");
            break;
        case STMT_LIST:
            for (StatementNode* stmt = s->as.listStmt; stmt; stmt = stmt->next)
                gen_statement(stmt, out);
            break;
    }
}

// -----------------------------------------------------------------------------
// FunctionNode -> C
static void gen_function(FunctionNode* f, FILE* out) {
    if (!f) return;
    fprintf(out, "%s %s(", f->returnType ? f->returnType : "void", f->name);
    for (ParamNode* p = f->params; p; p = p->next) {
        fprintf(out, "%s %s", p->type ? p->type : "int", p->name);
        if (p->next) fprintf(out, ", ");
    }
    fprintf(out, ") {\n");
    for (StatementNode* s = f->body; s; s = s->next)
        gen_statement(s, out);
    fprintf(out, "}\n\n");
}

// -----------------------------------------------------------------------------
// ClassNode -> C
static void gen_class(ClassNode* c, FILE* out) {
    if (!c) return;
    // struct
    fprintf(out, "typedef struct %s {\n", c->name);
    for (VariableNode* f = c->fields; f; f = f->next)
        fprintf(out, "    %s %s;\n", f->type ? f->type : "int", f->identifier);
    fprintf(out, "} %s;\n\n", c->name);

    // constructor „new_<Class>”
    fprintf(out, "%s* new_%s(", c->name, c->name);
    FunctionNode* init = NULL;
    for (FunctionNode* m = c->methods; m; m = m->next)
        if (strcmp(m->name, "init") == 0) { init = m; break; }
    if (init) {
        for (ParamNode* p = init->params; p; p = p->next) {
            fprintf(out, "%s %s", p->type ? p->type : "int", p->name);
            if (p->next) fprintf(out, ", ");
        }
    }
    fprintf(out, ") {\n"
                 "    %s* this = malloc(sizeof(%s));\n",
            c->name, c->name);
    if (init) {
        fprintf(out, "    %s_init(this", c->name);
        for (ParamNode* p = init->params; p; p = p->next)
            fprintf(out, ", %s", p->name);
        fprintf(out, ");\n");
    }
    fprintf(out, "    return this;\n}\n\n");

    // metode
    for (FunctionNode* m = c->methods; m; m = m->next) {
        fprintf(out, "void %s_%s(%s* this", c->name, m->name, c->name);
        for (ParamNode* p = m->params; p; p = p->next)
            fprintf(out, ", %s %s", p->type ? p->type : "int", p->name);
        fprintf(out, ") {\n");
        for (StatementNode* s = m->body; s; s = s->next)
            gen_statement(s, out);
        fprintf(out, "}\n\n");
    }
}