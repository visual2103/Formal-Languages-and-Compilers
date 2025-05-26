%{
#include <stdio.h>
#include "../ast/ast.h"
#include "aritmetic.y.h"

void yyerror(const char* s);
%}

%option yylineno


ID    [A-Za-z_][A-Za-z0-9_]*
DIGIT [0-9]+

%%

[ \t]                   ;
\n                      return S_NEWLINE;

"class"                 return S_CLASS;
"func"                  return S_FUNC;
"var"                   return S_VAR;
"new"                   return S_NEW;
"return"                return S_RETURN;
"if"                    return S_IF;
"else"                  return S_ELSE;
"while"                 return S_WHILE;
"for"                   return S_FOR;
"float"                 return S_FLOAT_TYPE;
"println"               return S_PRINTLN;
"sqrt"                  return S_SQRT;

{DIGIT}+"."{DIGIT}+      { yylval.floatVal = atof(yytext); return FLOAT; }

0|[1-9][0-9]*           { yylval.integer = atoi(yytext); return NUMBER; }

"+"                     return S_PLUS;
"-"                     return S_MINUS;
"/"                     return S_DIV;
"%"                     return S_MOD;
"*"                     return S_MUL;
"^"                     return S_POW;
"("                     return S_OBRACE;
")"                     return S_CBRACE;

"="                     return S_EQUALS; //atribuire

"->"                    return S_ARROW;
":"                     return S_COLON;
";"                     return S_SEMICOLON;
","                     return S_COMMA;
"{"                     return S_LBRACE;
"}"                     return S_RBRACE;
"."                     return S_DOT;


"=="                    return S_EQ;      
"!="                    return S_NEQ;     
"<="                    return S_LE;      
">="                    return S_GE;      
"<"                     return S_LT;      
">"                     return S_GT;      

"&&"                    return S_AND;  
"||"                    return S_OR;    
"!"                     return S_NOT;   


"//".*                  ;
"/*"(.|[\r\n])*?"*/"    ;

{ID}                    { yylval.strVal = strdup(yytext); return IDENTIFIER; }
\"([^\\"]|\\.)*\"       { yylval.strVal   = strdup(yytext); return STRING; }


.                       yyerror(yytext);

%%

int yywrap() {
    return 1;
}

void yyerror(const char* s) {
    fprintf(stderr, "Unrecognized character on line %d: %s\n", yylineno, s);
    exit(1);
}