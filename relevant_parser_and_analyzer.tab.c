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
#line 2 "relevant_parser_and_analyzer.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include "ast/ast.h"
    #include <vector> 
    #include <unordered_set>
    #include <string>
    #include <assert.h>

    astNode* root; // root note of AST
    std::vector<std::unordered_set<std::string>> scopes; // contains the symbol tables for scope

    int traverse(astNode* r);
    int yylex(void);
    void yyerror(const char *s);
    int semantic_analysis(astNode* root);
    int traverse(astNode* node);
    void get_into_scope();
    void get_out_of_scope();
    int declare(const char* name);
    int declared_in_any_scope(const char* name);
    int has_declaration_in_scope(const char* name);
    int semantic_error_notifier(const char* message, const char* name_of_associated_var);
    int traverse_stmt_list(std::vector<astNode*>* stmt_list);

#line 97 "relevant_parser_and_analyzer.tab.c"

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

#include "relevant_parser_and_analyzer.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_ADD = 5,                        /* ADD  */
  YYSYMBOL_MINUS = 6,                      /* MINUS  */
  YYSYMBOL_DIVIDE = 7,                     /* DIVIDE  */
  YYSYMBOL_MUL = 8,                        /* MUL  */
  YYSYMBOL_LE = 9,                         /* LE  */
  YYSYMBOL_GE = 10,                        /* GE  */
  YYSYMBOL_EQ = 11,                        /* EQ  */
  YYSYMBOL_NEQ = 12,                       /* NEQ  */
  YYSYMBOL_LT = 13,                        /* LT  */
  YYSYMBOL_GT = 14,                        /* GT  */
  YYSYMBOL_ASSIGN = 15,                    /* ASSIGN  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_LEFT_PARENTHESIS = 17,          /* LEFT_PARENTHESIS  */
  YYSYMBOL_RIGHT_PARENTHESIS = 18,         /* RIGHT_PARENTHESIS  */
  YYSYMBOL_LEFT_CURLY = 19,                /* LEFT_CURLY  */
  YYSYMBOL_RIGHT_CURLY = 20,               /* RIGHT_CURLY  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_RETURN = 23,                    /* RETURN  */
  YYSYMBOL_END_OF_STATEMENT = 24,          /* END_OF_STATEMENT  */
  YYSYMBOL_PRINT = 25,                     /* PRINT  */
  YYSYMBOL_READ = 26,                      /* READ  */
  YYSYMBOL_EXTERN = 27,                    /* EXTERN  */
  YYSYMBOL_INT_DECLARATION = 28,           /* INT_DECLARATION  */
  YYSYMBOL_VOID_DECLARATION = 29,          /* VOID_DECLARATION  */
  YYSYMBOL_UMINUS = 30,                    /* UMINUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 31,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_expression = 34,                /* expression  */
  YYSYMBOL_stmt = 35,                      /* stmt  */
  YYSYMBOL_call = 36,                      /* call  */
  YYSYMBOL_extern_print = 37,              /* extern_print  */
  YYSYMBOL_extern_read = 38,               /* extern_read  */
  YYSYMBOL_func = 39,                      /* func  */
  YYSYMBOL_param_func_possibilities = 40,  /* param_func_possibilities  */
  YYSYMBOL_stmt_list = 41,                 /* stmt_list  */
  YYSYMBOL_block = 42                      /* block  */
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
typedef yytype_int8 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   243

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    64,    64,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    84,    85,
      86,    87,    88,    89,    90,    91,    94,    95,    96,    97,
     100,   101,   104,   107,   108,   113,   114,   117,   118,   121
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "IDENTIFIER",
  "ADD", "MINUS", "DIVIDE", "MUL", "LE", "GE", "EQ", "NEQ", "LT", "GT",
  "ASSIGN", "WHILE", "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "LEFT_CURLY",
  "RIGHT_CURLY", "IF", "ELSE", "RETURN", "END_OF_STATEMENT", "PRINT",
  "READ", "EXTERN", "INT_DECLARATION", "VOID_DECLARATION", "UMINUS",
  "LOWER_THAN_ELSE", "$accept", "program", "expression", "stmt", "call",
  "extern_print", "extern_read", "func", "param_func_possibilities",
  "stmt_list", "block", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-95)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,    11,    36,    14,    17,   -95,    16,   -22,    26,    19,
      42,    45,   -95,    25,    38,    41,    47,    -3,    44,    37,
      37,    48,    43,    46,    64,    51,    53,    55,   -95,   -95,
     -95,    56,    56,   -95,   -95,   -95,   -95,    31,   -95,     1,
      87,    60,    87,   -95,    67,    87,    71,    75,    68,   109,
     -95,   -95,   -95,    87,    83,    77,   -95,    87,   169,    87,
     129,    87,    63,    72,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,   -95,   149,   -95,   183,   197,   -95,
     211,   -95,   225,   -95,   -95,    15,    15,   -95,   -95,     4,
       4,     4,     4,     4,     4,   -95,   -95,    57,    57,   -95,
     -95,    73,    57,   -95
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     0,     0,    35,
      35,     0,     0,     0,     0,     0,     0,     0,    30,    32,
      36,     0,     0,    31,    38,    33,    34,     0,    14,    15,
       0,     0,     0,    39,     0,     0,     0,     0,     0,     0,
      37,    17,    24,     0,     0,    15,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     0,    27,     0,     0,    16,
       0,    22,     0,    29,    21,     5,     6,     3,     4,     7,
       8,     9,    10,    11,    12,    23,    26,     0,     0,    28,
      18,    20,     0,    19
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -95,   -95,   -40,   -94,   -95,   -95,   -95,   -95,    78,   -95,
       7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    49,    50,    51,     3,     7,    12,    25,    37,
      52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      56,    21,    58,   100,   101,    60,    10,    11,   103,    64,
      65,    66,    67,    75,    77,    22,    53,    78,    54,    80,
       1,    82,    66,    67,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    38,    39,     5,    40,    35,    36,
       4,     6,     8,    13,     9,    14,    15,    41,    42,    16,
      34,    43,    44,    17,    45,    18,    46,    47,    19,    48,
      38,    39,    23,    40,    20,    24,    27,    28,    30,    31,
      29,    32,    63,    41,    42,    34,    34,    57,    44,    33,
      45,    83,    46,    47,    59,    48,    38,    55,    61,    40,
      38,    55,    62,    40,    54,   102,    84,     0,    26,     0,
      42,    76,     0,     0,    42,     0,     0,     0,    46,    47,
       0,     0,    46,    47,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,     0,    79,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
       0,    96,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,     0,    97,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,     0,    98,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,     0,    99
};

static const yytype_int8 yycheck[] =
{
      40,     4,    42,    97,    98,    45,    28,    29,   102,     5,
       6,     7,     8,    53,    54,    18,    15,    57,    17,    59,
      27,    61,     7,     8,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     3,     4,     0,     6,    31,    32,
      29,    27,    25,    17,    28,    26,     4,    16,    17,     4,
      19,    20,    21,    28,    23,    17,    25,    26,    17,    28,
       3,     4,    18,     6,    17,    28,    18,    24,     4,    18,
      24,    18,     4,    16,    17,    19,    19,    17,    21,    24,
      23,    18,    25,    26,    17,    28,     3,     4,    17,     6,
       3,     4,    17,     6,    17,    22,    24,    -1,    20,    -1,
      17,    18,    -1,    -1,    17,    -1,    -1,    -1,    25,    26,
      -1,    -1,    25,    26,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    18,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    18,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    18,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    18,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    18
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    33,    37,    29,     0,    27,    38,    25,    28,
      28,    29,    39,    17,    26,     4,     4,    28,    17,    17,
      17,     4,    18,    18,    28,    40,    40,    18,    24,    24,
       4,    18,    18,    24,    19,    42,    42,    41,     3,     4,
       6,    16,    17,    20,    21,    23,    25,    26,    28,    34,
      35,    36,    42,    15,    17,     4,    34,    17,    34,    17,
      34,    17,    17,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    24,    34,    18,    34,    34,    18,
      34,    24,    34,    18,    24,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    24,    18,    18,    18,    18,
      35,    35,    22,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    35,    35,
      35,    35,    35,    35,    35,    35,    36,    36,    36,    36,
      37,    37,    38,    39,    39,    40,    40,    41,    41,    42
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     3,     1,     5,     7,
       5,     3,     3,     4,     1,     2,     4,     3,     4,     3,
       7,     8,     6,     6,     6,     0,     2,     2,     0,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: extern_print extern_read func  */
#line 64 "relevant_parser_and_analyzer.y"
                                                                          {(yyval.node) = createProg((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); root = (yyval.node);}
#line 1480 "relevant_parser_and_analyzer.tab.c"
    break;

  case 3: /* expression: expression DIVIDE expression  */
#line 67 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = createBExpr((yyvsp[-2].node), (yyvsp[0].node), divide);}
#line 1486 "relevant_parser_and_analyzer.tab.c"
    break;

  case 4: /* expression: expression MUL expression  */
#line 68 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = createBExpr((yyvsp[-2].node), (yyvsp[0].node), mul);}
#line 1492 "relevant_parser_and_analyzer.tab.c"
    break;

  case 5: /* expression: expression ADD expression  */
#line 69 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = createBExpr((yyvsp[-2].node), (yyvsp[0].node), add);}
#line 1498 "relevant_parser_and_analyzer.tab.c"
    break;

  case 6: /* expression: expression MINUS expression  */
#line 70 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = createBExpr((yyvsp[-2].node), (yyvsp[0].node), sub);}
#line 1504 "relevant_parser_and_analyzer.tab.c"
    break;

  case 7: /* expression: expression LE expression  */
#line 71 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = createRExpr((yyvsp[-2].node), (yyvsp[0].node), le);}
#line 1510 "relevant_parser_and_analyzer.tab.c"
    break;

  case 8: /* expression: expression GE expression  */
#line 72 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = createRExpr((yyvsp[-2].node), (yyvsp[0].node), ge);}
#line 1516 "relevant_parser_and_analyzer.tab.c"
    break;

  case 9: /* expression: expression EQ expression  */
#line 73 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = createRExpr((yyvsp[-2].node), (yyvsp[0].node), eq);}
#line 1522 "relevant_parser_and_analyzer.tab.c"
    break;

  case 10: /* expression: expression NEQ expression  */
#line 74 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = createRExpr((yyvsp[-2].node), (yyvsp[0].node), neq);}
#line 1528 "relevant_parser_and_analyzer.tab.c"
    break;

  case 11: /* expression: expression LT expression  */
#line 75 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = createRExpr((yyvsp[-2].node), (yyvsp[0].node), lt);}
#line 1534 "relevant_parser_and_analyzer.tab.c"
    break;

  case 12: /* expression: expression GT expression  */
#line 76 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = createRExpr((yyvsp[-2].node), (yyvsp[0].node), gt);}
#line 1540 "relevant_parser_and_analyzer.tab.c"
    break;

  case 13: /* expression: MINUS expression  */
#line 77 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = createUExpr((yyvsp[0].node), uminus);}
#line 1546 "relevant_parser_and_analyzer.tab.c"
    break;

  case 14: /* expression: NUM  */
#line 78 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = createCnst((yyvsp[0].ival));}
#line 1552 "relevant_parser_and_analyzer.tab.c"
    break;

  case 15: /* expression: IDENTIFIER  */
#line 79 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = createVar((yyvsp[0].sval));}
#line 1558 "relevant_parser_and_analyzer.tab.c"
    break;

  case 16: /* expression: LEFT_PARENTHESIS expression RIGHT_PARENTHESIS  */
#line 80 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = (yyvsp[-1].node);}
#line 1564 "relevant_parser_and_analyzer.tab.c"
    break;

  case 17: /* expression: call  */
#line 81 "relevant_parser_and_analyzer.y"
                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1570 "relevant_parser_and_analyzer.tab.c"
    break;

  case 18: /* stmt: WHILE LEFT_PARENTHESIS expression RIGHT_PARENTHESIS stmt  */
#line 84 "relevant_parser_and_analyzer.y"
                                                                                                    {(yyval.node) = createWhile((yyvsp[-2].node), (yyvsp[0].node));}
#line 1576 "relevant_parser_and_analyzer.tab.c"
    break;

  case 19: /* stmt: IF LEFT_PARENTHESIS expression RIGHT_PARENTHESIS stmt ELSE stmt  */
#line 85 "relevant_parser_and_analyzer.y"
                                                                                                    {(yyval.node) = createIf((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1582 "relevant_parser_and_analyzer.tab.c"
    break;

  case 20: /* stmt: IF LEFT_PARENTHESIS expression RIGHT_PARENTHESIS stmt  */
#line 86 "relevant_parser_and_analyzer.y"
                                                                                                    {(yyval.node) = createIf((yyvsp[-2].node), (yyvsp[0].node));}
#line 1588 "relevant_parser_and_analyzer.tab.c"
    break;

  case 21: /* stmt: INT_DECLARATION IDENTIFIER END_OF_STATEMENT  */
#line 87 "relevant_parser_and_analyzer.y"
                                                                                                    {(yyval.node) = createDecl((yyvsp[-1].sval));}
#line 1594 "relevant_parser_and_analyzer.tab.c"
    break;

  case 22: /* stmt: RETURN expression END_OF_STATEMENT  */
#line 88 "relevant_parser_and_analyzer.y"
                                                                                                    {(yyval.node) = createRet((yyvsp[-1].node));}
#line 1600 "relevant_parser_and_analyzer.tab.c"
    break;

  case 23: /* stmt: IDENTIFIER ASSIGN expression END_OF_STATEMENT  */
#line 89 "relevant_parser_and_analyzer.y"
                                                                                                    {(yyval.node) = createAsgn(createVar((yyvsp[-3].sval)), (yyvsp[-1].node));}
#line 1606 "relevant_parser_and_analyzer.tab.c"
    break;

  case 24: /* stmt: block  */
#line 90 "relevant_parser_and_analyzer.y"
                                                                                                    {(yyval.node) = (yyvsp[0].node);}
#line 1612 "relevant_parser_and_analyzer.tab.c"
    break;

  case 25: /* stmt: expression END_OF_STATEMENT  */
#line 91 "relevant_parser_and_analyzer.y"
                                                                                                    {(yyval.node) = (yyvsp[-1].node);}
#line 1618 "relevant_parser_and_analyzer.tab.c"
    break;

  case 26: /* call: IDENTIFIER LEFT_PARENTHESIS expression RIGHT_PARENTHESIS  */
#line 94 "relevant_parser_and_analyzer.y"
                                                                       {(yyval.node) = createCall((yyvsp[-3].sval), (yyvsp[-1].node));}
#line 1624 "relevant_parser_and_analyzer.tab.c"
    break;

  case 27: /* call: IDENTIFIER LEFT_PARENTHESIS RIGHT_PARENTHESIS  */
#line 95 "relevant_parser_and_analyzer.y"
                                                                       {(yyval.node) = createCall((yyvsp[-2].sval));}
#line 1630 "relevant_parser_and_analyzer.tab.c"
    break;

  case 28: /* call: PRINT LEFT_PARENTHESIS expression RIGHT_PARENTHESIS  */
#line 96 "relevant_parser_and_analyzer.y"
                                                                       {(yyval.node) = createCall("print", (yyvsp[-1].node));}
#line 1636 "relevant_parser_and_analyzer.tab.c"
    break;

  case 29: /* call: READ LEFT_PARENTHESIS RIGHT_PARENTHESIS  */
#line 97 "relevant_parser_and_analyzer.y"
                                                                       {(yyval.node) = createCall("read");}
#line 1642 "relevant_parser_and_analyzer.tab.c"
    break;

  case 30: /* extern_print: EXTERN VOID_DECLARATION PRINT LEFT_PARENTHESIS INT_DECLARATION RIGHT_PARENTHESIS END_OF_STATEMENT  */
#line 100 "relevant_parser_and_analyzer.y"
                                                                                                                {(yyval.node) = createExtern("print");}
#line 1648 "relevant_parser_and_analyzer.tab.c"
    break;

  case 31: /* extern_print: EXTERN VOID_DECLARATION PRINT LEFT_PARENTHESIS INT_DECLARATION IDENTIFIER RIGHT_PARENTHESIS END_OF_STATEMENT  */
#line 101 "relevant_parser_and_analyzer.y"
                                                                                                                           {(yyval.node) = createExtern("print");}
#line 1654 "relevant_parser_and_analyzer.tab.c"
    break;

  case 32: /* extern_read: EXTERN INT_DECLARATION READ LEFT_PARENTHESIS RIGHT_PARENTHESIS END_OF_STATEMENT  */
#line 104 "relevant_parser_and_analyzer.y"
                                                                                              {(yyval.node) = createExtern("read");}
#line 1660 "relevant_parser_and_analyzer.tab.c"
    break;

  case 33: /* func: INT_DECLARATION IDENTIFIER LEFT_PARENTHESIS param_func_possibilities RIGHT_PARENTHESIS block  */
#line 107 "relevant_parser_and_analyzer.y"
                                                                                                             {(yyval.node) = createFunc((yyvsp[-4].sval), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1666 "relevant_parser_and_analyzer.tab.c"
    break;

  case 34: /* func: VOID_DECLARATION IDENTIFIER LEFT_PARENTHESIS param_func_possibilities RIGHT_PARENTHESIS block  */
#line 108 "relevant_parser_and_analyzer.y"
                                                                                                             {(yyval.node) = createFunc((yyvsp[-4].sval), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1672 "relevant_parser_and_analyzer.tab.c"
    break;

  case 35: /* param_func_possibilities: %empty  */
#line 113 "relevant_parser_and_analyzer.y"
                                                              {(yyval.node) = NULL;}
#line 1678 "relevant_parser_and_analyzer.tab.c"
    break;

  case 36: /* param_func_possibilities: INT_DECLARATION IDENTIFIER  */
#line 114 "relevant_parser_and_analyzer.y"
                                                              {(yyval.node) = createVar((yyvsp[0].sval));}
#line 1684 "relevant_parser_and_analyzer.tab.c"
    break;

  case 37: /* stmt_list: stmt_list stmt  */
#line 117 "relevant_parser_and_analyzer.y"
                                    {(yyvsp[-1].vec)->push_back((yyvsp[0].node)); (yyval.vec) = (yyvsp[-1].vec);}
#line 1690 "relevant_parser_and_analyzer.tab.c"
    break;

  case 38: /* stmt_list: %empty  */
#line 118 "relevant_parser_and_analyzer.y"
                                    {(yyval.vec) = new std::vector<astNode*>();}
#line 1696 "relevant_parser_and_analyzer.tab.c"
    break;

  case 39: /* block: LEFT_CURLY stmt_list RIGHT_CURLY  */
#line 121 "relevant_parser_and_analyzer.y"
                                                    {(yyval.node) = createBlock((yyvsp[-1].vec));}
#line 1702 "relevant_parser_and_analyzer.tab.c"
    break;


#line 1706 "relevant_parser_and_analyzer.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 124 "relevant_parser_and_analyzer.y"


int semantic_analysis(astNode* root){
    scopes.clear();
    get_into_scope();
    int err = traverse(root); // returns 1 if error and 0 if matches the semantic rules
    get_out_of_scope();
    return err;
}
// Depth First Search to traverse the AST
int traverse(astNode* node){
    if (node == NULL) return 0;

    switch (node->type){
        case (ast_prog) :
            return traverse(node->prog.func);
        
        case (ast_func) : {
            get_into_scope();
            if (node -> func.param != NULL) {
                if (declare(node->func.param->var.name)) {
                    get_out_of_scope();
                    return 1;
                }
            }

            astNode* body = node->func.body;

            // This is with the purpose of inspecting the list of the
            // block of the function while being in the same scope. 
            // So that when a variable is
            // declared as parameter, and in the body of the function it is also declared
            // that generates a semantic error by being in the same scope

            
            if (body && body->type == ast_stmt && body->stmt.type == ast_block){
                int err = traverse_stmt_list(body->stmt.block.stmt_list);
                get_out_of_scope();
                return err;
            }
            
            int err = traverse(body);
            get_out_of_scope();
            return err;
        }

        case (ast_extern) :
            return 0; // externs, as defined, cannot break the rules

        case (ast_var) :
            // detect case for when a variable is being used without
            // being declared
            if (!declared_in_any_scope(node->var.name)) {
                semantic_error_notifier("You tried using a var that was not been declared, namely", node->var.name);
                return 1;
            };
            return 0;

        case (ast_cnst) :
            return 0; // constants cannot break the rules

        case (ast_stmt) :
            switch (node->stmt.type) {
                case (ast_call) :
                    if (node->stmt.call.param != NULL) {
                        // to check if the potential variables follow the rules
                        return traverse(node->stmt.call.param); 
                    }
                    return 0;
                
                case (ast_ret) :
                    if (node -> stmt.ret.expr != NULL) {
                        return traverse(node->stmt.ret.expr);
                    }
                    return 0; // no rule has been broken
                                
                case (ast_block) : {
                    get_into_scope();
                    std::vector<astNode*>* stmts = node -> stmt.block.stmt_list;
                    // the function serves to iterate over each stmt and if semantic 
                    // error found 1 is returned otherwise 0 is
                    int err = traverse_stmt_list(stmts);
                    get_out_of_scope();
                    return err;
                }
                                
                case (ast_while) :
                    if (node -> stmt.whilen.cond != NULL) {
                        if (traverse(node->stmt.whilen.cond)) return 1;
                    }
                    if (node -> stmt.whilen.body != NULL) {
                        if (traverse(node->stmt.whilen.body)) return 1;
                    }
                    return 0;
                                
                case (ast_if) :
                    if (node -> stmt.ifn.cond != NULL) {
                        if (traverse(node->stmt.ifn.cond)) return 1;
                    }
                    if (node -> stmt.ifn.if_body != NULL) {
                        if (traverse(node->stmt.ifn.if_body)) return 1;
                    } 
                    if (node -> stmt.ifn.else_body != NULL) {
                        if (traverse(node->stmt.ifn.else_body)) return 1;
                    } 
                    return 0;
                                
                case (ast_decl) :
                    // check b/c we can only have one declaration per variable in the scope 
                    return (declare(node->stmt.decl.name));
                                
                case (ast_asgn) :
                    if (node -> stmt.asgn.lhs != NULL){
                        // because the identifier associated with an assignment is
                        // declared as a var using createVar in the parsing stage
                        // and we handle that case in this function
                        if(traverse(node->stmt.asgn.lhs)) return 1;
                    }
                    if (node -> stmt.asgn.rhs != NULL){
                        // it is an expression thus traversing is also reasonable
                        if(traverse(node->stmt.asgn.rhs)) return 1;
                    }
                    return 0;

                default:
                    fprintf(stderr, "Unknown AST statement type\n"); // since other cases are not considered
                    return 1; 
            }

        case (ast_rexpr) :
            if (node->rexpr.lhs != NULL){
                if (traverse(node->rexpr.lhs)) return 1;
            }

            if (node->rexpr.rhs != NULL){
                if (traverse(node->rexpr.rhs)) return 1;
            }
            
            return 0;

        case (ast_bexpr) :
            if (node->bexpr.lhs != NULL) {
                if (traverse(node->bexpr.lhs)) return 1;
            } 

            if (node->bexpr.rhs != NULL) {
                if (traverse(node->bexpr.rhs)) return 1;
            }
            
            return 0;

        case (ast_uexpr) :
            if (node->uexpr.expr != NULL) return traverse(node->uexpr.expr);
            fprintf(stderr, "Unary expression does not have an operand. Error.\n");
            return 1;

        default:
            fprintf(stderr, "Unknown AST node type\n");
            return 1; // since other cases are not considered
    }
}

void get_into_scope(){
    scopes.push_back({}); // initializes an empty unordered set to read from the current scope
}

void get_out_of_scope(){
    if (!scopes.empty()) scopes.pop_back(); // the innermost symbol table was inspected as now we go to the outer one
}

int declare(const char* name){
    // include only if there is no current declaration
    // to enforce semantic rule only one declaration per variable in scope
    if (has_declaration_in_scope(name)) { 
        semantic_error_notifier("In a scope there cannot be double declaration of the same variable", name);
       return 1; 
    }

    scopes.back().insert(std::string(name));
    
    return 0;
}

// to emphasize two rules better
int semantic_error_notifier(const char* message, const char* name_of_associated_var) {
    fprintf(stderr, "Semantic error: %s '%s'\n", message, name_of_associated_var);
    return 1;
}

int traverse_stmt_list(std::vector<astNode*>* stmt_list){
    if (!stmt_list) return 0;
    for (astNode* stmt : *stmt_list){
        if (traverse(stmt)) return 1;
    }
    return 0;
}

int declared_in_any_scope(const char* name){
    // cast to integer so that 'i' does not behave like an unsigned integer and lead to indexing problems.
    for (int i = ((int) scopes.size())-1; i >= 0; i--){
        if (scopes[i].count(std::string(name))  > 0) return 1;
    }
    return 0;
}

int has_declaration_in_scope(const char* name){
    assert(!scopes.empty()); // just to guarantee the following operation is valid
    return scopes.back().count(std::string(name)) > 0;
}

void yyerror (const char *s) {fprintf(stderr, "%s\n", s);}
