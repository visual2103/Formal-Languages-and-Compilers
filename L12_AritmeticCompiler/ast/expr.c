#include <stdlib.h>
#include <string.h>
#include "expr.h"
#include "function.h"

ExpressionNode* ExpressionNode_create_operation(ExpressionType type, ExpressionNode* left, ExpressionNode* right, int lineno) {
    ExpressionNode* self = calloc(1, sizeof(ExpressionNode));
    self->type = type;
    self->data.operation.op = type;
    self->data.operation.left = left;
    self->data.operation.right = right;
    self->lineno = lineno;
    return self;
}

ExpressionNode* ExpressionNode_create_number(int evaluated_value, int lineno) {
    ExpressionNode* self = calloc(1, sizeof(ExpressionNode));
    self->type = IMMEDIATE_NUMBER;
    self->data.immediate_number = evaluated_value;
    self->lineno = lineno;
    return self;
}

ExpressionNode* ExpressionNode_create_float(float evaluated_value, int lineno) {
    ExpressionNode* self = calloc(1, sizeof(ExpressionNode));
    self->type = IMMEDIATE_FLOAT;
    self->data.immediate_float = evaluated_value;
    self->lineno = lineno;
    return self;
}

ExpressionNode* ExpressionNode_create_identifier(char* identifier, int lineno) {
    ExpressionNode* self = calloc(1, sizeof(ExpressionNode));
    self->type = IMMEDIATE_IDENTIFIER;
    self->data.identifier = strdup(identifier);
    self->lineno = lineno;
    return self;
}

ExpressionNode* ExpressionNode_create_string(char* string, int lineno) {
    ExpressionNode* self = calloc(1, sizeof(ExpressionNode));
    self->type = IMMEDIATE_STRING;
    self->data.string = strdup(string);
    self->lineno = lineno;
    return self;
}

ExpressionNode* ExpressionNode_create_function_call(struct FunctionNode* function, int lineno) {
    ExpressionNode* self = calloc(1, sizeof(ExpressionNode));
    self->type = FUNCTION_CALL;
    self->data.functionCall = function;
    self->lineno = lineno;
    return self;
}

ExpressionNode* ExpressionNode_create_new(char* className, struct ArgNode* args, int lineno) {
    ExpressionNode* self = calloc(1, sizeof(ExpressionNode));
    self->type = NEW_OBJECT;
    self->data.newObject.className = strdup(className);
    self->data.newObject.args = args;
    self->lineno = lineno;
    return self;
}

ExpressionNode* ExpressionNode_create_assignment(char* target, ExpressionNode* value, int lineno) {
    ExpressionNode* self = calloc(1, sizeof(ExpressionNode));
    self->type = ASSIGNMENT;
    self->data.assignment.target = strdup(target);
    self->data.assignment.value = value;
    self->lineno = lineno;
    return self;
}

void ExpressionNode_free(ExpressionNode* self) {
    if (self == NULL) return;
    switch (self->type) {
        case IMMEDIATE_IDENTIFIER:
            free(self->data.identifier);
            break;
        case IMMEDIATE_STRING:
            free(self->data.string);
            break;
        case NEW_OBJECT:
            free(self->data.newObject.className);
            break;
        case ASSIGNMENT:
            free(self->data.assignment.target);
            ExpressionNode_free(self->data.assignment.value);
            break;
        case OPERATION_PLUS:
        case OPERATION_MINUS:
        case OPERATION_UNARY_MINUS:
        case OPERATION_MUL:
        case OPERATION_DIV:
        case OPERATION_MOD:
        case OPERATION_POW:
        case OPERATION_EQ:
        case OPERATION_NEQ:
        case OPERATION_LE:
        case OPERATION_GE:
        case OPERATION_LT:
        case OPERATION_GT:
        case OPERATION_AND:
        case OPERATION_OR:
        case OPERATION_NOT:
            ExpressionNode_free(self->data.operation.left);
            ExpressionNode_free(self->data.operation.right);
            break;
        case FUNCTION_CALL:
            FunctionNode_free(self->data.functionCall);
            break;
        default:
            break;
    }
    ExpressionNode_free(self->next);
    free(self);
}