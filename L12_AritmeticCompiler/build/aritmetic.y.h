/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_ARITMETIC_Y_H_INCLUDED
# define YY_YY_BUILD_ARITMETIC_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    S_NEWLINE = 258,               /* S_NEWLINE  */
    NUMBER = 259,                  /* NUMBER  */
    FLOAT = 260,                   /* FLOAT  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    STRING = 262,                  /* STRING  */
    S_CLASS = 263,                 /* S_CLASS  */
    S_FUNC = 264,                  /* S_FUNC  */
    S_VAR = 265,                   /* S_VAR  */
    S_NEW = 266,                   /* S_NEW  */
    S_RETURN = 267,                /* S_RETURN  */
    S_IF = 268,                    /* S_IF  */
    S_ELSE = 269,                  /* S_ELSE  */
    S_WHILE = 270,                 /* S_WHILE  */
    S_FOR = 271,                   /* S_FOR  */
    S_ARROW = 272,                 /* S_ARROW  */
    S_COLON = 273,                 /* S_COLON  */
    S_SEMICOLON = 274,             /* S_SEMICOLON  */
    S_COMMA = 275,                 /* S_COMMA  */
    S_LBRACE = 276,                /* S_LBRACE  */
    S_RBRACE = 277,                /* S_RBRACE  */
    S_DOT = 278,                   /* S_DOT  */
    S_EQUALS = 279,                /* S_EQUALS  */
    S_PLUS = 280,                  /* S_PLUS  */
    S_MINUS = 281,                 /* S_MINUS  */
    S_DIV = 282,                   /* S_DIV  */
    S_MOD = 283,                   /* S_MOD  */
    S_MUL = 284,                   /* S_MUL  */
    S_POW = 285,                   /* S_POW  */
    S_EQ = 286,                    /* S_EQ  */
    S_NEQ = 287,                   /* S_NEQ  */
    S_LE = 288,                    /* S_LE  */
    S_GE = 289,                    /* S_GE  */
    S_LT = 290,                    /* S_LT  */
    S_GT = 291,                    /* S_GT  */
    S_AND = 292,                   /* S_AND  */
    S_OR = 293,                    /* S_OR  */
    S_NOT = 294,                   /* S_NOT  */
    S_OBRACE = 295,                /* S_OBRACE  */
    S_CBRACE = 296,                /* S_CBRACE  */
    S_FLOAT_TYPE = 297,            /* S_FLOAT_TYPE  */
    S_PRINTLN = 298,               /* S_PRINTLN  */
    S_SQRT = 299,                  /* S_SQRT  */
    UMINUS = 300                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define S_NEWLINE 258
#define NUMBER 259
#define FLOAT 260
#define IDENTIFIER 261
#define STRING 262
#define S_CLASS 263
#define S_FUNC 264
#define S_VAR 265
#define S_NEW 266
#define S_RETURN 267
#define S_IF 268
#define S_ELSE 269
#define S_WHILE 270
#define S_FOR 271
#define S_ARROW 272
#define S_COLON 273
#define S_SEMICOLON 274
#define S_COMMA 275
#define S_LBRACE 276
#define S_RBRACE 277
#define S_DOT 278
#define S_EQUALS 279
#define S_PLUS 280
#define S_MINUS 281
#define S_DIV 282
#define S_MOD 283
#define S_MUL 284
#define S_POW 285
#define S_EQ 286
#define S_NEQ 287
#define S_LE 288
#define S_GE 289
#define S_LT 290
#define S_GT 291
#define S_AND 292
#define S_OR 293
#define S_NOT 294
#define S_OBRACE 295
#define S_CBRACE 296
#define S_FLOAT_TYPE 297
#define S_PRINTLN 298
#define S_SQRT 299
#define UMINUS 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "aritmetic.y"

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

#line 171 "build/aritmetic.y.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_ARITMETIC_Y_H_INCLUDED  */
