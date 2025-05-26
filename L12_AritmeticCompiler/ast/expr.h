#pragma once

typedef enum ExpressionType {
    /* operations */
    OPERATION_PLUS,
    OPERATION_MINUS,
    OPERATION_UNARY_MINUS,
    OPERATION_MUL,
    OPERATION_DIV,
    OPERATION_MOD,
    OPERATION_POW,
    OPERATION_EQ,     
    OPERATION_NEQ,   
    OPERATION_LE,   
    OPERATION_GE,    
    OPERATION_LT,    
    OPERATION_GT,    
    OPERATION_AND,   
    OPERATION_OR,    
    OPERATION_NOT,   
    IMMEDIATE_NUMBER,
    IMMEDIATE_FLOAT, 
    IMMEDIATE_IDENTIFIER,
    IMMEDIATE_STRING, 
    FUNCTION_CALL,    
    NEW_OBJECT,       
    ASSIGNMENT        
} ExpressionType;

typedef struct ExpressionNode {
    ExpressionType type;
    union {
        int immediate_number;
        float immediate_float; 
        char* identifier;      
        char* string;        
        struct FunctionNode* functionCall;
        struct {
            char* className;
            struct ArgNode* args;
        } newObject;
        struct {
            char* target;
            struct ExpressionNode* value;
        } assignment;
        struct {
            ExpressionType op;
            struct ExpressionNode* left;
            struct ExpressionNode* right;
        } operation;
    } data;
    int lineno;
    struct ExpressionNode* next;
} ExpressionNode;

/* ------------ */
/* Constructors */
/* ------------ */

ExpressionNode* ExpressionNode_create_operation(ExpressionType type, ExpressionNode* left, ExpressionNode* right, int lineno);
ExpressionNode* ExpressionNode_create_number(int evaluated_value, int lineno);
ExpressionNode* ExpressionNode_create_float(float evaluated_value, int lineno);
ExpressionNode* ExpressionNode_create_identifier(char* identifier, int lineno);
ExpressionNode* ExpressionNode_create_string(char* string, int lineno);
ExpressionNode* ExpressionNode_create_function_call(struct FunctionNode* function, int lineno);
ExpressionNode* ExpressionNode_create_new(char* className, struct ArgNode* args, int lineno);
ExpressionNode* ExpressionNode_create_assignment(char* target, ExpressionNode* value, int lineno);
void ExpressionNode_free(ExpressionNode* self);