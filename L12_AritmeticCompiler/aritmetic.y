%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast/ast.h"

void yyerror(const char *s);
int yylex();
int yyparse();

extern FILE* yyin;
extern int yylineno;

AST* ast;
%}

%union {
    int integer;
    float floatVal ; 
    char* strVal ; 
    ExpressionNode* expressionNode;
    DeclarationNode* declarationNode;
    StatementNode* statementNode;
    FunctionNode* functionNode;
    ClassNode* classNode;
    VariableNode* variableNode; 
    ParamNode* paramNode;
    ArgNode* argNode;          
}

%token S_NEWLINE
%token <integer> NUMBER
%token <floatVal> FLOAT
%token <strVal> IDENTIFIER STRING
%token S_CLASS S_FUNC S_VAR S_NEW S_RETURN S_IF S_ELSE S_WHILE S_FOR
%token S_ARROW S_COLON S_SEMICOLON S_COMMA S_LBRACE S_RBRACE S_DOT
%token S_EQUALS S_PLUS S_MINUS S_DIV S_MOD S_MUL S_POW
%token S_EQ S_NEQ S_LE S_GE S_LT S_GT S_AND S_OR S_NOT
%token S_OBRACE S_CBRACE
%token S_FLOAT_TYPE S_PRINTLN S_SQRT

%right S_EQUALS           
%left S_OR
%left S_AND
%left S_EQ S_NEQ
%left S_LE S_GE S_LT S_GT
%left S_PLUS S_MINUS
%left S_DIV S_MUL S_MOD
%right S_POW
%right S_NOT
%nonassoc UMINUS
%left S_DOT              

%type <expressionNode> expr
%type <statementNode> statement statements
%type <declarationNode> declaration class_member
%type <functionNode> function
%type <classNode> class class_body class_member_list
%type <paramNode> params
%type <argNode> args
%type <strVal> type

%start file_content
%%

file_content:
    top_items
    ;

top_items:
      /* empty */
    | top_items S_NEWLINE
    | top_items top_item
    ;

top_item:
      function   { AST_add_function(ast, $1); }
    | class      { AST_add_class(ast, $1); }
    | statement
    ;


statements:
    /* empty */  { $$ = NULL; }
    | statement statements { $1->next = $2; $$ = $1; }
    | S_NEWLINE statements { $$ = $2; }
    ;

statement:
    declaration S_SEMICOLON { 
        VariableNode* var = VariableNode_create($1->identifier, $1->type, $1->assigned_expression, yylineno); 
        $$ = StatementNode_create_var(var); 
        AST_add_variable(ast, var); 
    }
    | expr S_SEMICOLON                 { $$ = StatementNode_create_expr($1); }
    | IDENTIFIER S_EQUALS expr S_SEMICOLON   { $$ = StatementNode_create_assign(ExpressionNode_create_identifier($1, yylineno), $3); }
    | S_IF S_OBRACE expr S_CBRACE S_LBRACE statements S_RBRACE { $$ = StatementNode_create_if($3, $6, NULL); }
    | S_IF S_OBRACE expr S_CBRACE S_LBRACE statements S_RBRACE S_ELSE S_LBRACE statements S_RBRACE { $$ = StatementNode_create_if($3, $6, $10); }
    | S_WHILE S_OBRACE expr S_CBRACE S_LBRACE statements S_RBRACE { $$ = StatementNode_create_while($3, $6); }
    | S_RETURN expr S_SEMICOLON        { $$ = StatementNode_create_return($2); }
    ;

declaration:
    S_VAR IDENTIFIER S_COLON type S_EQUALS expr
        { $$ = DeclarationNode_create($2, $4, $6, yylineno); }
    | S_VAR IDENTIFIER S_EQUALS expr
        { $$ = DeclarationNode_create($2, NULL, $4, yylineno); }
    | S_VAR IDENTIFIER S_COLON type
        { $$ = DeclarationNode_create($2, $4, NULL, yylineno); }
    ;

type:
    IDENTIFIER          { $$ = $1; }
    | S_FLOAT_TYPE      { $$ = strdup("float"); }
    ;
    
class:
    S_CLASS IDENTIFIER S_LBRACE class_body S_RBRACE  
        { $$ = ClassNode_create($2, $4 ? $4->fields : NULL, $4 ? $4->methods : NULL); }
    ;

class_body:
      /* empty */                     { $$ = NULL; }
    | class_member_list               { $$ = $1; }
    ;

class_member_list:
      S_NEWLINE class_member_list     { $$ = $2; }
    | class_member class_member_list  { $$ = ClassNode_create_body(NULL, $1, $2, yylineno); }
    | function class_member_list      { $$ = ClassNode_create_body($1, NULL, $2, yylineno); }
    | S_NEWLINE                       { $$ = NULL; }   // <-- ADĂUGAT pentru newline-uri la final
    | class_member                    { $$ = ClassNode_create_body(NULL, $1, NULL, yylineno); }
    | function                        { $$ = ClassNode_create_body($1, NULL, NULL, yylineno); }
    ;

class_member:
    declaration S_SEMICOLON           { $$ = $1; }
    ;

function:
    S_FUNC IDENTIFIER S_OBRACE params S_CBRACE S_ARROW type S_LBRACE statements S_RBRACE  { $$ = FunctionNode_create($2, $4, $7, $9, yylineno); }
    | S_FUNC IDENTIFIER S_OBRACE params S_CBRACE S_LBRACE statements S_RBRACE  { $$ = FunctionNode_create($2, $4, NULL, $7, yylineno); }
    ;
    
params:
    /* empty */                        
        { $$ = NULL; }
    | IDENTIFIER S_COLON type
        { $$ = ParamNode_create($1, $3, NULL, yylineno); }
    | IDENTIFIER S_COLON type S_COMMA params
        { $$ = ParamNode_create($1, $3, $5, yylineno); }
    ;

args:
    /* empty */                        { $$ = NULL; }
    | expr                             { $$ = ArgNode_create($1, NULL, yylineno); }
    | expr S_COMMA args                { $$ = ArgNode_create($1, $3, yylineno); }
    ;

expr:
    NUMBER                            { $$ = ExpressionNode_create_number($1, yylineno); }
    | FLOAT                           { $$ = ExpressionNode_create_float($1, yylineno); }
    | IDENTIFIER                      { $$ = ExpressionNode_create_identifier($1, yylineno); }
    | STRING                          { $$ = ExpressionNode_create_string($1, yylineno); }
    | S_SQRT S_OBRACE args S_CBRACE   { $$ = ExpressionNode_create_function_call(FunctionNode_create_call("sqrt", $3, yylineno), yylineno); }
    | S_PRINTLN S_OBRACE args S_CBRACE    { $$ = ExpressionNode_create_function_call(FunctionNode_create_call("println", $3, yylineno), yylineno); }
    | IDENTIFIER S_OBRACE args S_CBRACE { $$ = ExpressionNode_create_function_call(FunctionNode_create_call($1, $3, yylineno), yylineno); }
    | expr S_DOT IDENTIFIER S_OBRACE args S_CBRACE { $$ = ExpressionNode_create_function_call(FunctionNode_create_method_call($1, $3, $5, yylineno), yylineno); }
    | expr S_DOT IDENTIFIER           { $$ = ExpressionNode_create_member_access($1, $3, yylineno); }
    | expr S_PLUS expr                { $$ = ExpressionNode_create_operation(OPERATION_PLUS, $1, $3, yylineno); }
    | expr S_MINUS expr               { $$ = ExpressionNode_create_operation(OPERATION_MINUS, $1, $3, yylineno); }
    | expr S_DIV expr                 { $$ = ExpressionNode_create_operation(OPERATION_DIV, $1, $3, yylineno); }
    | expr S_MUL expr                 { $$ = ExpressionNode_create_operation(OPERATION_MUL, $1, $3, yylineno); }
    | expr S_MOD expr                 { $$ = ExpressionNode_create_operation(OPERATION_MOD, $1, $3, yylineno); }
    | expr S_POW expr                 { $$ = ExpressionNode_create_operation(OPERATION_POW, $1, $3, yylineno); }
    | S_MINUS expr %prec UMINUS       { $$ = ExpressionNode_create_operation(OPERATION_UNARY_MINUS, $2, NULL, yylineno); }
    | expr S_EQ expr                  { $$ = ExpressionNode_create_operation(OPERATION_EQ, $1, $3, yylineno); }
    | expr S_NEQ expr                 { $$ = ExpressionNode_create_operation(OPERATION_NEQ, $1, $3, yylineno); }
    | expr S_LE expr                  { $$ = ExpressionNode_create_operation(OPERATION_LE, $1, $3, yylineno); }
    | expr S_GE expr                  { $$ = ExpressionNode_create_operation(OPERATION_GE, $1, $3, yylineno); }
    | expr S_LT expr                  { $$ = ExpressionNode_create_operation(OPERATION_LT, $1, $3, yylineno); }
    | expr S_GT expr                  { $$ = ExpressionNode_create_operation(OPERATION_GT, $1, $3, yylineno); }
    | expr S_AND expr                 { $$ = ExpressionNode_create_operation(OPERATION_AND, $1, $3, yylineno); }
    | expr S_OR expr                  { $$ = ExpressionNode_create_operation(OPERATION_OR, $1, $3, yylineno); }
    | S_NOT expr                      { $$ = ExpressionNode_create_operation(OPERATION_NOT, $2, NULL, yylineno); }
    | S_OBRACE expr S_CBRACE          { $$ = $2; }
    | S_NEW IDENTIFIER S_OBRACE args S_CBRACE { $$ = ExpressionNode_create_new($2, $4, yylineno); }
    ;
%%

void yyerror(const char* s) {
    fprintf(stderr, "Unrecognized characters on line %d: %s\n", yylineno, s);
    fprintf(stderr, "Ultimul token: %d\n", yylex());
    exit(1);
}
 
int main(int argc, char** argv) {
    char* inputFileName = NULL;
    if (argc > 1) {
        inputFileName = argv[1];
        FILE *fp = fopen(inputFileName, "r");
        if (!fp) {
            perror("Failed to open file");
            exit(2);
        }
        yyin = fp;
    } else {
        fprintf(stderr, "File argument not provided\n");
        exit(3);
    }

    ast = AST_create();
    yyparse();

    // create output file name from input file name
    // append ".c" at the end of input file name
    int inputFileNameSize = strlen(inputFileName);
    int outputFileNameSize = inputFileNameSize + 3;
    char* outputFileName = malloc(outputFileNameSize);
    memcpy(outputFileName, inputFileName, inputFileNameSize);
    outputFileName[outputFileNameSize - 3] = '.';
    outputFileName[outputFileNameSize - 2] = 'c';
    outputFileName[outputFileNameSize - 1] = '\0';

    FILE* outputFile = fopen(outputFileName, "w");
    AST_execute(ast, outputFile);

    //clean
    AST_free(ast);
    fclose(yyin);
    fclose(outputFile);
    free(outputFileName);
    
    return 0;
}