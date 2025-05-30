/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "aritmetic.y"

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

#line 87 "build/aritmetic.y.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "aritmetic.y.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_S_NEWLINE = 3,                  /* S_NEWLINE  */
  YYSYMBOL_NUMBER = 4,                     /* NUMBER  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_S_CLASS = 8,                    /* S_CLASS  */
  YYSYMBOL_S_FUNC = 9,                     /* S_FUNC  */
  YYSYMBOL_S_VAR = 10,                     /* S_VAR  */
  YYSYMBOL_S_NEW = 11,                     /* S_NEW  */
  YYSYMBOL_S_RETURN = 12,                  /* S_RETURN  */
  YYSYMBOL_S_IF = 13,                      /* S_IF  */
  YYSYMBOL_S_ELSE = 14,                    /* S_ELSE  */
  YYSYMBOL_S_WHILE = 15,                   /* S_WHILE  */
  YYSYMBOL_S_FOR = 16,                     /* S_FOR  */
  YYSYMBOL_S_ARROW = 17,                   /* S_ARROW  */
  YYSYMBOL_S_COLON = 18,                   /* S_COLON  */
  YYSYMBOL_S_SEMICOLON = 19,               /* S_SEMICOLON  */
  YYSYMBOL_S_COMMA = 20,                   /* S_COMMA  */
  YYSYMBOL_S_LBRACE = 21,                  /* S_LBRACE  */
  YYSYMBOL_S_RBRACE = 22,                  /* S_RBRACE  */
  YYSYMBOL_S_DOT = 23,                     /* S_DOT  */
  YYSYMBOL_S_EQUALS = 24,                  /* S_EQUALS  */
  YYSYMBOL_S_PLUS = 25,                    /* S_PLUS  */
  YYSYMBOL_S_MINUS = 26,                   /* S_MINUS  */
  YYSYMBOL_S_DIV = 27,                     /* S_DIV  */
  YYSYMBOL_S_MOD = 28,                     /* S_MOD  */
  YYSYMBOL_S_MUL = 29,                     /* S_MUL  */
  YYSYMBOL_S_POW = 30,                     /* S_POW  */
  YYSYMBOL_S_EQ = 31,                      /* S_EQ  */
  YYSYMBOL_S_NEQ = 32,                     /* S_NEQ  */
  YYSYMBOL_S_LE = 33,                      /* S_LE  */
  YYSYMBOL_S_GE = 34,                      /* S_GE  */
  YYSYMBOL_S_LT = 35,                      /* S_LT  */
  YYSYMBOL_S_GT = 36,                      /* S_GT  */
  YYSYMBOL_S_AND = 37,                     /* S_AND  */
  YYSYMBOL_S_OR = 38,                      /* S_OR  */
  YYSYMBOL_S_NOT = 39,                     /* S_NOT  */
  YYSYMBOL_S_OBRACE = 40,                  /* S_OBRACE  */
  YYSYMBOL_S_CBRACE = 41,                  /* S_CBRACE  */
  YYSYMBOL_S_FLOAT_TYPE = 42,              /* S_FLOAT_TYPE  */
  YYSYMBOL_S_PRINTLN = 43,                 /* S_PRINTLN  */
  YYSYMBOL_S_SQRT = 44,                    /* S_SQRT  */
  YYSYMBOL_UMINUS = 45,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_file_content = 47,              /* file_content  */
  YYSYMBOL_top_items = 48,                 /* top_items  */
  YYSYMBOL_top_item = 49,                  /* top_item  */
  YYSYMBOL_statements = 50,                /* statements  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_declaration = 52,               /* declaration  */
  YYSYMBOL_type = 53,                      /* type  */
  YYSYMBOL_class = 54,                     /* class  */
  YYSYMBOL_class_body = 55,                /* class_body  */
  YYSYMBOL_class_member_list = 56,         /* class_member_list  */
  YYSYMBOL_class_member = 57,              /* class_member  */
  YYSYMBOL_function = 58,                  /* function  */
  YYSYMBOL_params = 59,                    /* params  */
  YYSYMBOL_args = 60,                      /* args  */
  YYSYMBOL_expr = 61                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    70,    72,    73,    77,    78,    79,    84,
      85,    86,    90,    95,    96,    97,    98,    99,   100,   104,
     106,   108,   113,   114,   118,   123,   124,   128,   129,   130,
     131,   132,   133,   137,   141,   142,   147,   148,   150,   155,
     156,   157,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "S_NEWLINE", "NUMBER",
  "FLOAT", "IDENTIFIER", "STRING", "S_CLASS", "S_FUNC", "S_VAR", "S_NEW",
  "S_RETURN", "S_IF", "S_ELSE", "S_WHILE", "S_FOR", "S_ARROW", "S_COLON",
  "S_SEMICOLON", "S_COMMA", "S_LBRACE", "S_RBRACE", "S_DOT", "S_EQUALS",
  "S_PLUS", "S_MINUS", "S_DIV", "S_MOD", "S_MUL", "S_POW", "S_EQ", "S_NEQ",
  "S_LE", "S_GE", "S_LT", "S_GT", "S_AND", "S_OR", "S_NOT", "S_OBRACE",
  "S_CBRACE", "S_FLOAT_TYPE", "S_PRINTLN", "S_SQRT", "UMINUS", "$accept",
  "file_content", "top_items", "top_item", "statements", "statement",
  "declaration", "type", "class", "class_body", "class_member_list",
  "class_member", "function", "params", "args", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-114)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -114,     8,    53,  -114,  -114,  -114,  -114,   -23,  -114,    20,
      25,    69,    70,    43,    38,    41,    43,    43,    43,    49,
      50,  -114,  -114,    72,  -114,  -114,   117,    43,    43,    73,
      63,     0,    71,    75,   137,    43,    43,    86,    86,   173,
      43,    43,  -114,  -114,   106,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,   157,
      76,   192,     3,   107,    13,    43,    43,  -114,   208,   225,
    -114,    78,    83,    91,    44,    44,   -14,   -14,   -14,   -14,
     287,   287,   100,   100,   100,   100,   273,   258,  -114,  -114,
      43,     3,    97,   110,  -114,     3,     3,   123,   116,  -114,
    -114,   134,   242,   118,   140,   156,  -114,  -114,    43,  -114,
    -114,  -114,  -114,  -114,  -114,    13,   -10,    43,  -114,    95,
      95,   138,   158,    13,    95,   242,    95,   159,    95,   175,
    -114,   107,   195,   191,  -114,   218,  -114,  -114,  -114,    95,
    -114,   226,   260,    95,  -114,   275,  -114
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     4,    42,    43,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     8,     0,     7,     6,     0,     0,    39,     0,
       0,     0,     0,    44,     0,     0,     0,    57,    66,     0,
      39,    39,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    40,    25,    36,     0,     0,    39,    18,     0,     0,
      67,     0,     0,    50,    51,    52,    53,    55,    54,    56,
      58,    59,    60,    61,    62,    63,    64,    65,    14,    48,
      39,    30,     0,     0,    26,    31,    32,     0,     0,    22,
      23,    21,    20,     0,     0,     0,    47,    46,    39,    41,
      27,    33,    24,    28,    29,     0,     0,     0,    68,     9,
       9,     0,    37,     0,     9,    19,     9,     0,     9,     0,
      49,    36,     0,     0,    11,    15,    10,    17,    38,     9,
      35,     0,     0,     9,    34,     0,    16
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,  -114,    -6,   262,   -11,  -113,  -114,  -114,
     -66,  -114,   309,   187,   -20,   -13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    21,   127,   128,    23,   101,    24,    93,
      94,    95,    96,    98,    60,    26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    27,   122,    37,    38,    39,    91,   123,     3,    44,
     132,   124,    10,    11,    59,    61,    50,    28,    64,    99,
      71,    72,    68,    69,    65,   110,    29,    61,    61,   113,
     114,    30,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,   103,     5,     6,    33,
       8,    92,   102,    61,    12,   100,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    44,    15,    16,
     109,    47,    48,    49,    50,    31,    32,    61,    35,    16,
      92,    36,    17,    18,    92,    92,    19,    20,   121,    40,
      41,    42,    17,    18,    62,    61,    19,    20,   126,     5,
       6,     7,     8,    63,   125,    11,    12,    13,    14,    44,
      15,    66,    73,    97,   129,    28,   111,    89,   133,   106,
     134,    16,   136,    44,   107,    45,    46,    47,    48,    49,
      50,   108,   112,   142,    17,    18,    43,   145,    19,    20,
      44,   115,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    67,   116,   117,   118,
      44,   119,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    88,   120,   131,   130,
      44,   135,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    44,   137,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    90,   140,    70,    44,   139,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    44,   141,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   143,    44,   104,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    22,    44,   105,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    44,   144,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    44,   146,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      44,    25,    45,    46,    47,    48,    49,    50,   138,     0,
      53,    54,    55,    56
};

static const yytype_int16 yycheck[] =
{
      13,    24,   115,    16,    17,    18,     3,    17,     0,    23,
     123,    21,     9,    10,    27,    28,    30,    40,    18,     6,
      40,    41,    35,    36,    24,    91,     6,    40,    41,    95,
      96,     6,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    66,     4,     5,     6,
       7,    62,    65,    66,    11,    42,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    23,    15,    26,
      90,    27,    28,    29,    30,     6,     6,    90,    40,    26,
      91,    40,    39,    40,    95,    96,    43,    44,   108,    40,
      40,    19,    39,    40,    21,   108,    43,    44,     3,     4,
       5,     6,     7,    40,   117,    10,    11,    12,    13,    23,
      15,    40,     6,     6,   120,    40,    19,    41,   124,    41,
     126,    26,   128,    23,    41,    25,    26,    27,    28,    29,
      30,    40,    22,   139,    39,    40,    19,   143,    43,    44,
      23,    18,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    19,    41,    24,    41,
      23,    21,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    19,    21,    20,    41,
      23,    22,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    23,    22,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    20,    22,    41,    23,    21,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    23,    14,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    21,    23,    41,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,     2,    23,    41,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    23,    22,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    23,    22,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      23,     2,    25,    26,    27,    28,    29,    30,   131,    -1,
      33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    48,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    15,    26,    39,    40,    43,
      44,    49,    51,    52,    54,    58,    61,    24,    40,     6,
       6,     6,     6,     6,    61,    40,    40,    61,    61,    61,
      40,    40,    19,    19,    23,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    61,
      60,    61,    21,    40,    18,    24,    40,    19,    61,    61,
      41,    60,    60,     6,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    19,    41,
      20,     3,    52,    55,    56,    57,    58,     6,    59,     6,
      42,    53,    61,    60,    41,    41,    41,    41,    40,    60,
      56,    19,    22,    56,    56,    18,    41,    24,    41,    21,
      21,    60,    53,    17,    21,    61,     3,    50,    51,    50,
      41,    20,    53,    50,    50,    22,    50,    22,    59,    21,
      22,    14,    50,    21,    22,    50,    22
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    49,    49,    49,    50,
      50,    50,    51,    51,    51,    51,    51,    51,    51,    52,
      52,    52,    53,    53,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    57,    58,    58,    59,    59,    59,    60,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     1,     1,     1,     0,
       2,     2,     2,     2,     4,     7,    11,     7,     3,     6,
       4,     4,     1,     1,     5,     0,     1,     2,     2,     2,
       1,     1,     1,     2,    10,     8,     0,     3,     5,     0,
       1,     3,     1,     1,     1,     1,     4,     4,     4,     6,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6: /* top_item: function  */
#line 77 "aritmetic.y"
                 { AST_add_function(ast, (yyvsp[0].functionNode)); }
#line 1260 "build/aritmetic.y.c"
    break;

  case 7: /* top_item: class  */
#line 78 "aritmetic.y"
                 { AST_add_class(ast, (yyvsp[0].classNode)); }
#line 1266 "build/aritmetic.y.c"
    break;

  case 9: /* statements: %empty  */
#line 84 "aritmetic.y"
                 { (yyval.statementNode) = NULL; }
#line 1272 "build/aritmetic.y.c"
    break;

  case 10: /* statements: statement statements  */
#line 85 "aritmetic.y"
                           { (yyvsp[-1].statementNode)->next = (yyvsp[0].statementNode); (yyval.statementNode) = (yyvsp[-1].statementNode); }
#line 1278 "build/aritmetic.y.c"
    break;

  case 11: /* statements: S_NEWLINE statements  */
#line 86 "aritmetic.y"
                           { (yyval.statementNode) = (yyvsp[0].statementNode); }
#line 1284 "build/aritmetic.y.c"
    break;

  case 12: /* statement: declaration S_SEMICOLON  */
#line 90 "aritmetic.y"
                            { 
        VariableNode* var = VariableNode_create((yyvsp[-1].declarationNode)->identifier, (yyvsp[-1].declarationNode)->type, (yyvsp[-1].declarationNode)->assigned_expression, yylineno); 
        (yyval.statementNode) = StatementNode_create_var(var); 
        AST_add_variable(ast, var); 
    }
#line 1294 "build/aritmetic.y.c"
    break;

  case 13: /* statement: expr S_SEMICOLON  */
#line 95 "aritmetic.y"
                                       { (yyval.statementNode) = StatementNode_create_expr((yyvsp[-1].expressionNode)); }
#line 1300 "build/aritmetic.y.c"
    break;

  case 14: /* statement: IDENTIFIER S_EQUALS expr S_SEMICOLON  */
#line 96 "aritmetic.y"
                                             { (yyval.statementNode) = StatementNode_create_assign(ExpressionNode_create_identifier((yyvsp[-3].strVal), yylineno), (yyvsp[-1].expressionNode)); }
#line 1306 "build/aritmetic.y.c"
    break;

  case 15: /* statement: S_IF S_OBRACE expr S_CBRACE S_LBRACE statements S_RBRACE  */
#line 97 "aritmetic.y"
                                                               { (yyval.statementNode) = StatementNode_create_if((yyvsp[-4].expressionNode), (yyvsp[-1].statementNode), NULL); }
#line 1312 "build/aritmetic.y.c"
    break;

  case 16: /* statement: S_IF S_OBRACE expr S_CBRACE S_LBRACE statements S_RBRACE S_ELSE S_LBRACE statements S_RBRACE  */
#line 98 "aritmetic.y"
                                                                                                   { (yyval.statementNode) = StatementNode_create_if((yyvsp[-8].expressionNode), (yyvsp[-5].statementNode), (yyvsp[-1].statementNode)); }
#line 1318 "build/aritmetic.y.c"
    break;

  case 17: /* statement: S_WHILE S_OBRACE expr S_CBRACE S_LBRACE statements S_RBRACE  */
#line 99 "aritmetic.y"
                                                                  { (yyval.statementNode) = StatementNode_create_while((yyvsp[-4].expressionNode), (yyvsp[-1].statementNode)); }
#line 1324 "build/aritmetic.y.c"
    break;

  case 18: /* statement: S_RETURN expr S_SEMICOLON  */
#line 100 "aritmetic.y"
                                       { (yyval.statementNode) = StatementNode_create_return((yyvsp[-1].expressionNode)); }
#line 1330 "build/aritmetic.y.c"
    break;

  case 19: /* declaration: S_VAR IDENTIFIER S_COLON type S_EQUALS expr  */
#line 105 "aritmetic.y"
        { (yyval.declarationNode) = DeclarationNode_create((yyvsp[-4].strVal), (yyvsp[-2].strVal), (yyvsp[0].expressionNode), yylineno); }
#line 1336 "build/aritmetic.y.c"
    break;

  case 20: /* declaration: S_VAR IDENTIFIER S_EQUALS expr  */
#line 107 "aritmetic.y"
        { (yyval.declarationNode) = DeclarationNode_create((yyvsp[-2].strVal), NULL, (yyvsp[0].expressionNode), yylineno); }
#line 1342 "build/aritmetic.y.c"
    break;

  case 21: /* declaration: S_VAR IDENTIFIER S_COLON type  */
#line 109 "aritmetic.y"
        { (yyval.declarationNode) = DeclarationNode_create((yyvsp[-2].strVal), (yyvsp[0].strVal), NULL, yylineno); }
#line 1348 "build/aritmetic.y.c"
    break;

  case 22: /* type: IDENTIFIER  */
#line 113 "aritmetic.y"
                        { (yyval.strVal) = (yyvsp[0].strVal); }
#line 1354 "build/aritmetic.y.c"
    break;

  case 23: /* type: S_FLOAT_TYPE  */
#line 114 "aritmetic.y"
                        { (yyval.strVal) = strdup("float"); }
#line 1360 "build/aritmetic.y.c"
    break;

  case 24: /* class: S_CLASS IDENTIFIER S_LBRACE class_body S_RBRACE  */
#line 119 "aritmetic.y"
        { (yyval.classNode) = ClassNode_create((yyvsp[-3].strVal), (yyvsp[-1].classNode) ? (yyvsp[-1].classNode)->fields : NULL, (yyvsp[-1].classNode) ? (yyvsp[-1].classNode)->methods : NULL); }
#line 1366 "build/aritmetic.y.c"
    break;

  case 25: /* class_body: %empty  */
#line 123 "aritmetic.y"
                                      { (yyval.classNode) = NULL; }
#line 1372 "build/aritmetic.y.c"
    break;

  case 26: /* class_body: class_member_list  */
#line 124 "aritmetic.y"
                                      { (yyval.classNode) = (yyvsp[0].classNode); }
#line 1378 "build/aritmetic.y.c"
    break;

  case 27: /* class_member_list: S_NEWLINE class_member_list  */
#line 128 "aritmetic.y"
                                      { (yyval.classNode) = (yyvsp[0].classNode); }
#line 1384 "build/aritmetic.y.c"
    break;

  case 28: /* class_member_list: class_member class_member_list  */
#line 129 "aritmetic.y"
                                      { (yyval.classNode) = ClassNode_create_body(NULL, (yyvsp[-1].declarationNode), (yyvsp[0].classNode), yylineno); }
#line 1390 "build/aritmetic.y.c"
    break;

  case 29: /* class_member_list: function class_member_list  */
#line 130 "aritmetic.y"
                                      { (yyval.classNode) = ClassNode_create_body((yyvsp[-1].functionNode), NULL, (yyvsp[0].classNode), yylineno); }
#line 1396 "build/aritmetic.y.c"
    break;

  case 30: /* class_member_list: S_NEWLINE  */
#line 131 "aritmetic.y"
                                      { (yyval.classNode) = NULL; }
#line 1402 "build/aritmetic.y.c"
    break;

  case 31: /* class_member_list: class_member  */
#line 132 "aritmetic.y"
                                      { (yyval.classNode) = ClassNode_create_body(NULL, (yyvsp[0].declarationNode), NULL, yylineno); }
#line 1408 "build/aritmetic.y.c"
    break;

  case 32: /* class_member_list: function  */
#line 133 "aritmetic.y"
                                      { (yyval.classNode) = ClassNode_create_body((yyvsp[0].functionNode), NULL, NULL, yylineno); }
#line 1414 "build/aritmetic.y.c"
    break;

  case 33: /* class_member: declaration S_SEMICOLON  */
#line 137 "aritmetic.y"
                                      { (yyval.declarationNode) = (yyvsp[-1].declarationNode); }
#line 1420 "build/aritmetic.y.c"
    break;

  case 34: /* function: S_FUNC IDENTIFIER S_OBRACE params S_CBRACE S_ARROW type S_LBRACE statements S_RBRACE  */
#line 141 "aritmetic.y"
                                                                                          { (yyval.functionNode) = FunctionNode_create((yyvsp[-8].strVal), (yyvsp[-6].paramNode), (yyvsp[-3].strVal), (yyvsp[-1].statementNode), yylineno); }
#line 1426 "build/aritmetic.y.c"
    break;

  case 35: /* function: S_FUNC IDENTIFIER S_OBRACE params S_CBRACE S_LBRACE statements S_RBRACE  */
#line 142 "aritmetic.y"
                                                                               { (yyval.functionNode) = FunctionNode_create((yyvsp[-6].strVal), (yyvsp[-4].paramNode), NULL, (yyvsp[-1].statementNode), yylineno); }
#line 1432 "build/aritmetic.y.c"
    break;

  case 36: /* params: %empty  */
#line 147 "aritmetic.y"
        { (yyval.paramNode) = NULL; }
#line 1438 "build/aritmetic.y.c"
    break;

  case 37: /* params: IDENTIFIER S_COLON type  */
#line 149 "aritmetic.y"
        { (yyval.paramNode) = ParamNode_create((yyvsp[-2].strVal), (yyvsp[0].strVal), NULL, yylineno); }
#line 1444 "build/aritmetic.y.c"
    break;

  case 38: /* params: IDENTIFIER S_COLON type S_COMMA params  */
#line 151 "aritmetic.y"
        { (yyval.paramNode) = ParamNode_create((yyvsp[-4].strVal), (yyvsp[-2].strVal), (yyvsp[0].paramNode), yylineno); }
#line 1450 "build/aritmetic.y.c"
    break;

  case 39: /* args: %empty  */
#line 155 "aritmetic.y"
                                       { (yyval.argNode) = NULL; }
#line 1456 "build/aritmetic.y.c"
    break;

  case 40: /* args: expr  */
#line 156 "aritmetic.y"
                                       { (yyval.argNode) = ArgNode_create((yyvsp[0].expressionNode), NULL, yylineno); }
#line 1462 "build/aritmetic.y.c"
    break;

  case 41: /* args: expr S_COMMA args  */
#line 157 "aritmetic.y"
                                       { (yyval.argNode) = ArgNode_create((yyvsp[-2].expressionNode), (yyvsp[0].argNode), yylineno); }
#line 1468 "build/aritmetic.y.c"
    break;

  case 42: /* expr: NUMBER  */
#line 161 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_number((yyvsp[0].integer), yylineno); }
#line 1474 "build/aritmetic.y.c"
    break;

  case 43: /* expr: FLOAT  */
#line 162 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_float((yyvsp[0].floatVal), yylineno); }
#line 1480 "build/aritmetic.y.c"
    break;

  case 44: /* expr: IDENTIFIER  */
#line 163 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_identifier((yyvsp[0].strVal), yylineno); }
#line 1486 "build/aritmetic.y.c"
    break;

  case 45: /* expr: STRING  */
#line 164 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_string((yyvsp[0].strVal), yylineno); }
#line 1492 "build/aritmetic.y.c"
    break;

  case 46: /* expr: S_SQRT S_OBRACE args S_CBRACE  */
#line 165 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_function_call(FunctionNode_create_call("sqrt", (yyvsp[-1].argNode), yylineno), yylineno); }
#line 1498 "build/aritmetic.y.c"
    break;

  case 47: /* expr: S_PRINTLN S_OBRACE args S_CBRACE  */
#line 166 "aritmetic.y"
                                          { (yyval.expressionNode) = ExpressionNode_create_function_call(FunctionNode_create_call("println", (yyvsp[-1].argNode), yylineno), yylineno); }
#line 1504 "build/aritmetic.y.c"
    break;

  case 48: /* expr: IDENTIFIER S_OBRACE args S_CBRACE  */
#line 167 "aritmetic.y"
                                        { (yyval.expressionNode) = ExpressionNode_create_function_call(FunctionNode_create_call((yyvsp[-3].strVal), (yyvsp[-1].argNode), yylineno), yylineno); }
#line 1510 "build/aritmetic.y.c"
    break;

  case 49: /* expr: expr S_DOT IDENTIFIER S_OBRACE args S_CBRACE  */
#line 168 "aritmetic.y"
                                                   { (yyval.expressionNode) = ExpressionNode_create_function_call(FunctionNode_create_method_call((yyvsp[-5].expressionNode), (yyvsp[-3].strVal), (yyvsp[-1].argNode), yylineno), yylineno); }
#line 1516 "build/aritmetic.y.c"
    break;

  case 50: /* expr: expr S_DOT IDENTIFIER  */
#line 169 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_member_access((yyvsp[-2].expressionNode), (yyvsp[0].strVal), yylineno); }
#line 1522 "build/aritmetic.y.c"
    break;

  case 51: /* expr: expr S_PLUS expr  */
#line 170 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_PLUS, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1528 "build/aritmetic.y.c"
    break;

  case 52: /* expr: expr S_MINUS expr  */
#line 171 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_MINUS, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1534 "build/aritmetic.y.c"
    break;

  case 53: /* expr: expr S_DIV expr  */
#line 172 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_DIV, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1540 "build/aritmetic.y.c"
    break;

  case 54: /* expr: expr S_MUL expr  */
#line 173 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_MUL, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1546 "build/aritmetic.y.c"
    break;

  case 55: /* expr: expr S_MOD expr  */
#line 174 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_MOD, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1552 "build/aritmetic.y.c"
    break;

  case 56: /* expr: expr S_POW expr  */
#line 175 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_POW, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1558 "build/aritmetic.y.c"
    break;

  case 57: /* expr: S_MINUS expr  */
#line 176 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_UNARY_MINUS, (yyvsp[0].expressionNode), NULL, yylineno); }
#line 1564 "build/aritmetic.y.c"
    break;

  case 58: /* expr: expr S_EQ expr  */
#line 177 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_EQ, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1570 "build/aritmetic.y.c"
    break;

  case 59: /* expr: expr S_NEQ expr  */
#line 178 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_NEQ, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1576 "build/aritmetic.y.c"
    break;

  case 60: /* expr: expr S_LE expr  */
#line 179 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_LE, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1582 "build/aritmetic.y.c"
    break;

  case 61: /* expr: expr S_GE expr  */
#line 180 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_GE, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1588 "build/aritmetic.y.c"
    break;

  case 62: /* expr: expr S_LT expr  */
#line 181 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_LT, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1594 "build/aritmetic.y.c"
    break;

  case 63: /* expr: expr S_GT expr  */
#line 182 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_GT, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1600 "build/aritmetic.y.c"
    break;

  case 64: /* expr: expr S_AND expr  */
#line 183 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_AND, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1606 "build/aritmetic.y.c"
    break;

  case 65: /* expr: expr S_OR expr  */
#line 184 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_OR, (yyvsp[-2].expressionNode), (yyvsp[0].expressionNode), yylineno); }
#line 1612 "build/aritmetic.y.c"
    break;

  case 66: /* expr: S_NOT expr  */
#line 185 "aritmetic.y"
                                      { (yyval.expressionNode) = ExpressionNode_create_operation(OPERATION_NOT, (yyvsp[0].expressionNode), NULL, yylineno); }
#line 1618 "build/aritmetic.y.c"
    break;

  case 67: /* expr: S_OBRACE expr S_CBRACE  */
#line 186 "aritmetic.y"
                                      { (yyval.expressionNode) = (yyvsp[-1].expressionNode); }
#line 1624 "build/aritmetic.y.c"
    break;

  case 68: /* expr: S_NEW IDENTIFIER S_OBRACE args S_CBRACE  */
#line 187 "aritmetic.y"
                                              { (yyval.expressionNode) = ExpressionNode_create_new((yyvsp[-3].strVal), (yyvsp[-1].argNode), yylineno); }
#line 1630 "build/aritmetic.y.c"
    break;


#line 1634 "build/aritmetic.y.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 189 "aritmetic.y"


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
