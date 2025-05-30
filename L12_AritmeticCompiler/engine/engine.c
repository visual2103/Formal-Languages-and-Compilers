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
#include "stdbool.h"

static char wasDeclared[52] = {0}; // track pentru identificatori A–Z, a–z

// Forward declarations
static void gen_declaration(DeclarationNode* d, FILE* out);
static void gen_expression(ExpressionNode* e, FILE* out, bool in_class_method, VariableNode* class_fields, ParamNode* params);
static void gen_variable(VariableNode* v, FILE* out);
static void gen_statement(StatementNode* s, FILE* out, bool in_class_method, VariableNode* class_fields, ParamNode* params);
static void gen_function(FunctionNode* f, FILE* out);
static void gen_class(ClassNode* c, FILE* out);

// Helper: verifică dacă id este field al clasei curente
static bool is_class_field(const char* id, VariableNode* fields) {
    for (VariableNode* f = fields; f; f = f->next) {
        if (strcmp(id, f->identifier) == 0)
            return true;
    }
    return false;
}

// Helper: verifică dacă id este parametru al funcției curente
static bool is_param(const char* id , ParamNode* params) {
    for (ParamNode* p = params; p; p = p->next) {
        if (strcmp(p->name ,id ) == 0) return true;
    }
    return false;
}

// Helper: pentru printf cu concatenare
static void build_printf_format_and_args(ExpressionNode* e, char* format, ExpressionNode** args, int* arg_count) {
    if (!e) return;
    if (e->type == OPERATION_PLUS) {
        build_printf_format_and_args(e->data.operation.left, format, args, arg_count);
        build_printf_format_and_args(e->data.operation.right, format, args, arg_count);
    } else if (e->type == IMMEDIATE_STRING) {
        // REMOVE possible leading/trailing quotes if present
        const char* s = e->data.string;
        size_t len = strlen(s);
        // Strip leading and trailing quotes if they exist (e.g., "\"Point at (\"" -> "Point at (")
        if (len >= 2 && s[0] == '"' && s[len-1] == '"') {
            char temp[256];
            strncpy(temp, s+1, len-2);
            temp[len-2] = '\0';
            strcat(format, temp);
        } else {
            strcat(format, s);
        }
    } else if (e->type == IMMEDIATE_FLOAT || e->type == IMMEDIATE_NUMBER ||
               e->type == IMMEDIATE_IDENTIFIER || e->type == MEMBER_ACCESS) {
        strcat(format, "%f"); // dacă știi tipul, folosește %d pentru int, %f pentru float
        args[(*arg_count)++] = e;
    } else {
        strcat(format, "%f");
        args[(*arg_count)++] = e;
    }
}

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
    for (FunctionNode* f = ast->functions; f; f = f->next) {
        if (strcmp(f->name, "main") == 0) { hasMain = 1; break; }
    }

    if (!hasMain) {
        fprintf(out, "int main() {\n");
        for (VariableNode* v = ast->variables; v; v = v->next) {
            gen_variable(v, out);
        }
        for (StatementNode* s = ast->statements; s; s = s->next) {
            gen_statement(s, out, false, NULL, NULL);
        }
        DeclarationNode* decl = ast->declarations;
        ExpressionNode* expr = ast->expressions;
        while (decl || expr) {
            if (decl && (!expr || decl->lineno < expr->lineno)) {
                gen_declaration(decl, out);
                decl = decl->next;
            } else {
                fprintf(out, "\tprintf(\"%%d\\n\", ");
                gen_expression(expr, out, false, NULL, NULL);
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
    char* id = d->identifier;
    int idx = (id[0] >= 'a' ? id[0] - 'a' + 26 : id[0] - 'A');
    if (wasDeclared[idx]) {
        fprintf(out, "\t%s = ", id);
    } else {
        fprintf(out, "\tint %s = ", id);
        wasDeclared[idx] = 1;
    }
    gen_expression(d->assigned_expression, out, false, NULL, NULL);
    fprintf(out, ";\n");
}

// -----------------------------------------------------------------------------
// ExpressionNode -> C
static void gen_expression(ExpressionNode* e, FILE* out, bool in_class_method, VariableNode* class_fields, ParamNode* params) {
    if (!e) return;
    switch (e->type) {
        case IMMEDIATE_IDENTIFIER: {
            char* id = e->data.identifier;
            if (in_class_method && is_class_field(id, class_fields))
                fprintf(out, "this->%s", id);
            else if (params && is_param(id, params))
                fprintf(out, "%s", id);
            else
                fprintf(out, "%s", id); // fallback, poți adăuga și detecție de variabile locale aici
            break;
        }
        case IMMEDIATE_NUMBER:
            fprintf(out, "%d", e->data.immediate_number);
            break;
        case IMMEDIATE_FLOAT:
            fprintf(out, "%f", e->data.immediate_float);
            break;
        case IMMEDIATE_STRING:
            // Do NOT emit extra quotes for printf format!
            fprintf(out, "%s", e->data.string);
            break;
        case MEMBER_ACCESS:
            gen_expression(e->data.member_access.object, out, in_class_method, class_fields, params);
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
            gen_expression(e->data.operation.left, out, in_class_method, class_fields, params);
            fprintf(out, "%s", op);
            gen_expression(e->data.operation.right, out, in_class_method, class_fields, params);
            fprintf(out, ")");
            break;
        }
        case OPERATION_POW:
            fprintf(out, "pow(");
            gen_expression(e->data.operation.left, out, in_class_method, class_fields, params);
            fprintf(out, ", ");
            gen_expression(e->data.operation.right, out, in_class_method, class_fields, params);
            fprintf(out, ")");
            break;
        case OPERATION_UNARY_MINUS:
            fprintf(out, "(-");
            gen_expression(e->data.operation.left, out, in_class_method, class_fields, params);
            fprintf(out, ")");
            break;
        case OPERATION_NOT:
            fprintf(out, "(!");
            gen_expression(e->data.operation.left, out, in_class_method, class_fields, params);
            fprintf(out, ")");
            break;
        case FUNCTION_CALL: {
            // Special logic: println -> printf
            if (strcmp(e->data.functionCall->name, "println") == 0) {
                ArgNode* arg = (ArgNode*)e->data.functionCall->args;
                if (arg && arg->next == NULL && arg->expr->type == IMMEDIATE_STRING) {
                    // println("text")
                    fprintf(out, "printf(\"%s\\n\")", arg->expr->data.string);
                } else {
                    // Build format and args for printf with concatenation
                    char format[256] = "";
                    ExpressionNode* args[10] = {0};
                    int arg_count = 0;
                    if (arg) {
                        build_printf_format_and_args(arg->expr, format, args, &arg_count);
                    }
                    strcat(format, "\\n");
                    fprintf(out, "printf(\"%s\"", format);
                    for (int i = 0; i < arg_count; ++i) {
                        fprintf(out, ", ");
                        gen_expression(args[i], out, in_class_method, class_fields, params);
                    }
                    fprintf(out, ")");
                }
            } else {
                fprintf(out, "%s(", e->data.functionCall->name);
                for (ArgNode* a = (ArgNode*)e->data.functionCall->args; a; a = a->next) {
                    gen_expression(a->expr, out, in_class_method, class_fields, params);
                    if (a->next) fprintf(out, ", ");
                }
                fprintf(out, ")");
            }
            break;
        }
        case NEW_OBJECT:
            fprintf(out, "new_%s(", e->data.newObject.className);
            for (ArgNode* a = e->data.newObject.args; a; a = a->next) {
                gen_expression(a->expr, out, in_class_method, class_fields, params);
                if (a->next) fprintf(out, ", ");
            }
            fprintf(out, ")");
            break;
        case ASSIGNMENT: {
            if (e->data.assignment.target) {
                char* id = e->data.assignment.target;
                if (in_class_method && is_class_field(id, class_fields))
                    fprintf(out, "this->%s = ", id);
                else
                    fprintf(out, "%s = ", id);
            }
            gen_expression(e->data.assignment.value, out, in_class_method, class_fields, params);
            break;
        }
    }
}

// -----------------------------------------------------------------------------
// VariableNode -> C
static void gen_variable(VariableNode* v, FILE* out) {
    if (!v) return;

    bool isObject = v->assigned_expression
                 && v->assigned_expression->type == NEW_OBJECT;

    fprintf(out,
        "    %s%s %s",
        v->type ? v->type : "int",
        isObject ? "*" : "",
        v->identifier
    );

    if (v->assigned_expression) {
        fprintf(out, " = ");
        gen_expression(v->assigned_expression, out, false, NULL, NULL);
    }
    fprintf(out, ";\n");

    {
      char id  = v->identifier[0];
      int  idx = (id >= 'a' ? id - 'a' + 26 : id - 'A');
      wasDeclared[idx] = 1;
    }
}

// -----------------------------------------------------------------------------
// StatementNode -> C
static void gen_statement(StatementNode* s, FILE* out, bool in_class_method, VariableNode* class_fields, ParamNode* params) {
    if (!s) return;
    switch (s->type) {
        case STMT_VAR_DECL:
            gen_variable(s->as.varDecl, out);
            break;
        case STMT_ASSIGN:
            fprintf(out, "    ");
            if (s->as.assignStmt.target->type == IMMEDIATE_IDENTIFIER) {
                char* id = s->as.assignStmt.target->data.identifier;
                if (in_class_method && is_class_field(id, class_fields))
                    fprintf(out, "this->%s = ", id);
                else
                    fprintf(out, "%s = ", id);
            } else {
                gen_expression(s->as.assignStmt.target, out, in_class_method, class_fields, params);
                fprintf(out, " = ");
            }
            gen_expression(s->as.assignStmt.value, out, in_class_method, class_fields, params);
            fprintf(out, ";\n");
            break;
        case STMT_EXPR:
            fprintf(out, "    ");
            gen_expression(s->as.expr, out, in_class_method, class_fields, params);
            fprintf(out, ";\n");
            break;
        case STMT_RETURN:
            fprintf(out, "    return");
            if (s->as.returnExpr) {
                fprintf(out, " ");
                gen_expression(s->as.returnExpr, out, in_class_method, class_fields, params);
            }
            fprintf(out, ";\n");
            break;
        case STMT_IF: {
            fprintf(out, "    if (");
            gen_expression(s->as.ifStmt.cond, out, in_class_method, class_fields, params);
            fprintf(out, ") {\n");
            for (StatementNode* t = s->as.ifStmt.thenBranch; t; t = t->next)
                gen_statement(t, out, in_class_method, class_fields, params);
            fprintf(out, "    }");
            if (s->as.ifStmt.elseBranch) {
                fprintf(out, " else {\n");
                for (StatementNode* e = s->as.ifStmt.elseBranch; e; e = e->next)
                    gen_statement(e, out, in_class_method, class_fields, params);
                fprintf(out, "    }");
            }
            fprintf(out, "\n");
            break;
        }
        case STMT_WHILE:
            fprintf(out, "    while (");
            gen_expression(s->as.whileStmt.cond, out, in_class_method, class_fields, params);
            fprintf(out, ") {\n");
            for (StatementNode* b = s->as.whileStmt.body; b; b = b->next)
                gen_statement(b, out, in_class_method, class_fields, params);
            fprintf(out, "    }\n");
            break;
        case STMT_FOR:
            fprintf(out, "    for (");
            if (s->as.forStmt.init) gen_statement(s->as.forStmt.init, out, in_class_method, class_fields, params);
            else fprintf(out, "; ");
            gen_expression(s->as.forStmt.cond, out, in_class_method, class_fields, params);
            fprintf(out, "; ");
            if (s->as.forStmt.update) gen_statement(s->as.forStmt.update, out, in_class_method, class_fields, params);
            else fprintf(out, "; ");
            fprintf(out, ") {\n");
            for (StatementNode* b = s->as.forStmt.body; b; b = b->next)
                gen_statement(b, out, in_class_method, class_fields, params);
            fprintf(out, "    }\n");
            break;
       
    }
}

// -----------------------------------------------------------------------------
// FunctionNode -> C
static void gen_function(FunctionNode* f, FILE* out) {
    if (!f) return;

    fprintf(out, "%s %s(",
        f->returnType ? f->returnType : "void",
        f->name
    );
    for (ParamNode* p = f->params; p; p = p->next) {
        fprintf(out, "%s %s",
            p->type ? p->type : "int", // declara implicit la int 
            p->name
        );
        if (p->next) fprintf(out, ", ");
    }
    fprintf(out, ") {\n");

    for (ParamNode* p = f->params; p; p = p->next) {
        char id  = p->name[0];
        int  idx = (id >= 'a' ? id - 'a' + 26 : id - 'A');
        wasDeclared[idx] = 1;
    }

    for (StatementNode* s = f->body; s; s = s->next) {
        gen_statement(s, out, false, NULL, f->params);
    }
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
            gen_statement(s, out, true, c->fields, m->params);
        fprintf(out, "}\n\n");
    }
}