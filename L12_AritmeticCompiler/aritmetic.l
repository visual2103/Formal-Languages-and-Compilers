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

[ \t\r\f\v]+            ;
\n                      { printf("TOKEN: S_NEWLINE \\n\n"); return S_NEWLINE; }

"class"                 { printf("TOKEN: S_CLASS (%s)\n", yytext); return S_CLASS; }
"func"                  { printf("TOKEN: S_FUNC (%s)\n", yytext); return S_FUNC; }
"var"                   { printf("TOKEN: S_VAR (%s)\n", yytext); return S_VAR; }
"new"                   { printf("TOKEN: S_NEW (%s)\n", yytext); return S_NEW; }
"return"                { printf("TOKEN: S_RETURN (%s)\n", yytext); return S_RETURN; }
"if"                    { printf("TOKEN: S_IF (%s)\n", yytext); return S_IF; }
"else"                  { printf("TOKEN: S_ELSE (%s)\n", yytext); return S_ELSE; }
"while"                 { printf("TOKEN: S_WHILE (%s)\n", yytext); return S_WHILE; }
"for"                   { printf("TOKEN: S_FOR (%s)\n", yytext); return S_FOR; }
"float"                 { printf("TOKEN: S_FLOAT_TYPE (%s)\n", yytext); return S_FLOAT_TYPE; }
"println"               { printf("TOKEN: S_PRINTLN (%s)\n", yytext); return S_PRINTLN; }
"sqrt"                  { printf("TOKEN: S_SQRT (%s)\n", yytext); return S_SQRT; }

"->"                    { printf("TOKEN: S_ARROW (%s)\n", yytext); return S_ARROW; }

{DIGIT}"."{DIGIT}*([eE][-+]?{DIGIT}+)? {
    printf("TOKEN: FLOAT (%s)\n", yytext);
    yylval.floatVal = atof(yytext);
    return FLOAT;
}
{DIGIT} {
    printf("TOKEN: NUMBER (%s)\n", yytext);
    yylval.integer = atoi(yytext);
    return NUMBER;
}

"+"                     { printf("TOKEN: S_PLUS (%s)\n", yytext); return S_PLUS; }
"-"                     { printf("TOKEN: S_MINUS (%s)\n", yytext); return S_MINUS; }
"/"                     { printf("TOKEN: S_DIV (%s)\n", yytext); return S_DIV; }
"%"                     { printf("TOKEN: S_MOD (%s)\n", yytext); return S_MOD; }
"*"                     { printf("TOKEN: S_MUL (%s)\n", yytext); return S_MUL; }
"^"                     { printf("TOKEN: S_POW (%s)\n", yytext); return S_POW; }
"("                     { printf("TOKEN: S_OBRACE (%s)\n", yytext); return S_OBRACE; }
")"                     { printf("TOKEN: S_CBRACE (%s)\n", yytext); return S_CBRACE; }

"="                     { printf("TOKEN: S_EQUALS (%s)\n", yytext); return S_EQUALS; }
":"                     { printf("TOKEN: S_COLON (%s)\n", yytext); return S_COLON; }
";"                     { printf("TOKEN: S_SEMICOLON (%s)\n", yytext); return S_SEMICOLON; }
","                     { printf("TOKEN: S_COMMA (%s)\n", yytext); return S_COMMA; }
"{"                     { printf("TOKEN: S_LBRACE (%s)\n", yytext); return S_LBRACE; }
"}"                     { printf("TOKEN: S_RBRACE (%s)\n", yytext); return S_RBRACE; }
"."                     { printf("TOKEN: S_DOT (%s)\n", yytext); return S_DOT; }

"=="                    { printf("TOKEN: S_EQ (%s)\n", yytext); return S_EQ; }
"!="                    { printf("TOKEN: S_NEQ (%s)\n", yytext); return S_NEQ; }
"<="                    { printf("TOKEN: S_LE (%s)\n", yytext); return S_LE; }
">="                    { printf("TOKEN: S_GE (%s)\n", yytext); return S_GE; }
"<"                     { printf("TOKEN: S_LT (%s)\n", yytext); return S_LT; }
">"                     { printf("TOKEN: S_GT (%s)\n", yytext); return S_GT; }

"&&"                    { printf("TOKEN: S_AND (%s)\n", yytext); return S_AND; }
"||"                    { printf("TOKEN: S_OR (%s)\n", yytext); return S_OR; }
"!"                     { printf("TOKEN: S_NOT (%s)\n", yytext); return S_NOT; }

"//".*                  { printf("TOKEN: COMMENT (single line)\n"); }
"/*"(.|[\r\n])*?"*/"    { printf("TOKEN: COMMENT (multi line)\n"); }

{ID}                    { printf("TOKEN: IDENTIFIER (%s)\n", yytext); yylval.strVal = strdup(yytext); return IDENTIFIER; }
\"([^\\"]|\\.)*\"       { printf("TOKEN: STRING (%s)\n", yytext); yylval.strVal = strdup(yytext); return STRING; }

.                       { printf("TOKEN: ERROR (%s)\n", yytext); yyerror(yytext); }

%%