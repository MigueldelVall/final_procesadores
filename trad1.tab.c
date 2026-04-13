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
#line 6 "trad1.y"
                          // SECTION 1 Declarations for C-Bison
#include <stdio.h>
#include <ctype.h>            // tolower()
#include <string.h>           // strcmp() 
#include <stdlib.h>           // exit()

#define FF fflush(stdout);    // to force immediate printing 

int yylex () ;
void yyerror () ;
char *my_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;
void clear_local_vars();
void add_scoped_var(char *original, char *translated);
void add_local_var(char *name);
void add_param_var(char *name);
char *translated_name(char *name);

char temp [2048] ;

char current_function[256] = "";

typedef struct s_localvar {
    char *original;
    char *translated;
    struct s_localvar *next;
} t_localvar;

t_localvar *local_vars = NULL;

// Abstract Syntax Tree (AST) Node Structure

typedef struct ASTnode t_node ;

struct ASTnode {
    char *op ;
    int type ;		// leaf, unary or binary nodes
    t_node *left ;
    t_node *right ;
} ;


// Definitions for explicit attributes

typedef struct s_attr {
    int value ;    // - Numeric value of a NUMBER 
    char *code ;   // - to pass IDENTIFIER names, and other translations 
    t_node *node ; // - for possible future use of AST
} t_attr ;

#define YYSTYPE t_attr     // stack of PDA has type t_attr


#line 127 "trad1.tab.c"

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

#include "trad1.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIF = 4,                    /* IDENTIF  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_MAIN = 7,                       /* MAIN  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_INC = 12,                       /* INC  */
  YYSYMBOL_DEC = 13,                       /* DEC  */
  YYSYMBOL_SWITCH = 14,                    /* SWITCH  */
  YYSYMBOL_CASE = 15,                      /* CASE  */
  YYSYMBOL_DEFAULT = 16,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 17,                     /* BREAK  */
  YYSYMBOL_PUTS = 18,                      /* PUTS  */
  YYSYMBOL_PRINTF = 19,                    /* PRINTF  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_EQ = 23,                        /* EQ  */
  YYSYMBOL_NE = 24,                        /* NE  */
  YYSYMBOL_LE = 25,                        /* LE  */
  YYSYMBOL_GE = 26,                        /* GE  */
  YYSYMBOL_RETURN = 27,                    /* RETURN  */
  YYSYMBOL_28_ = 28,                       /* '='  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_30_ = 30,                       /* '>'  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '-'  */
  YYSYMBOL_33_ = 33,                       /* '*'  */
  YYSYMBOL_34_ = 34,                       /* '/'  */
  YYSYMBOL_35_ = 35,                       /* '%'  */
  YYSYMBOL_36_ = 36,                       /* '^'  */
  YYSYMBOL_UNARY_SIGN = 37,                /* UNARY_SIGN  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_axiom = 46,                     /* axiom  */
  YYSYMBOL_defs_before_main = 47,          /* defs_before_main  */
  YYSYMBOL_global_decls = 48,              /* global_decls  */
  YYSYMBOL_main_def = 49,                  /* main_def  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_function_def = 51,              /* function_def  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_param_defs = 53,                /* param_defs  */
  YYSYMBOL_param_list = 54,                /* param_list  */
  YYSYMBOL_call_args = 55,                 /* call_args  */
  YYSYMBOL_call_arg_list = 56,             /* call_arg_list  */
  YYSYMBOL_body = 57,                      /* body  */
  YYSYMBOL_body_element = 58,              /* body_element  */
  YYSYMBOL_statement = 59,                 /* statement  */
  YYSYMBOL_control_struct = 60,            /* control_struct  */
  YYSYMBOL_case_list = 61,                 /* case_list  */
  YYSYMBOL_case_block = 62,                /* case_block  */
  YYSYMBOL_for_init = 63,                  /* for_init  */
  YYSYMBOL_for_update = 64,                /* for_update  */
  YYSYMBOL_declaration = 65,               /* declaration  */
  YYSYMBOL_decl_list = 66,                 /* decl_list  */
  YYSYMBOL_decl_item = 67,                 /* decl_item  */
  YYSYMBOL_sentence = 68,                  /* sentence  */
  YYSYMBOL_arg_list = 69,                  /* arg_list  */
  YYSYMBOL_arg = 70,                       /* arg  */
  YYSYMBOL_expression = 71,                /* expression  */
  YYSYMBOL_term = 72,                      /* term  */
  YYSYMBOL_operand = 73                    /* operand  */
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
#define YYLAST   530

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
       2,     2,     2,     2,     2,     2,     2,    35,     2,     2,
      39,    40,    33,    31,    43,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    38,
      29,    28,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      25,    26,    27,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   100,   100,   107,   111,   118,   119,   125,   124,   140,
     139,   154,   157,   164,   169,   178,   181,   188,   192,   200,
     205,   213,   217,   223,   225,   229,   231,   233,   235,   237,
     241,   243,   246,   248,   253,   262,   268,   276,   279,   280,
     285,   298,   314,   320,   325,   329,   334,   340,   342,   346,
     347,   351,   352,   354,   356,   358,   360,   362,   364,   366,
     368,   370,   372,   374,   376,   378,   380,   384,   385,   386,
     391,   400,   406,   411
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIF",
  "INTEGER", "STRING", "MAIN", "WHILE", "IF", "ELSE", "FOR", "INC", "DEC",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "PUTS", "PRINTF", "AND", "OR",
  "NOT", "EQ", "NE", "LE", "GE", "RETURN", "'='", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'^'", "UNARY_SIGN", "';'", "'('", "')'",
  "'{'", "'}'", "','", "':'", "$accept", "axiom", "defs_before_main",
  "global_decls", "main_def", "$@1", "function_def", "$@2", "param_defs",
  "param_list", "call_args", "call_arg_list", "body", "body_element",
  "statement", "control_struct", "case_list", "case_block", "for_init",
  "for_update", "declaration", "decl_list", "decl_item", "sentence",
  "arg_list", "arg", "expression", "term", "operand", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -46,    18,    48,   -46,   -46,    19,    -8,   -46,   -46,     6,
      16,    21,    36,    22,   -46,    28,   -46,   -46,    65,    68,
      19,   -46,    69,    34,    32,   -46,   -46,    37,   -46,    40,
      79,   323,   323,    83,   -46,   -27,    49,    54,    55,    59,
      60,    62,   157,   157,    12,    12,   157,    58,   -46,   -46,
     -46,    71,    73,   451,   -46,   -46,    99,   -46,   157,   157,
     157,   157,   102,   157,   106,   108,    77,   -46,   451,   -46,
     -46,   360,   -46,   -46,   -46,   -46,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     -46,   451,    84,    80,   451,   378,   396,   100,    95,   414,
      97,   101,   -46,   482,   468,   494,   494,    -6,    -6,    -6,
      -6,     0,     0,   107,   107,   107,   107,   -46,   157,   105,
     110,   157,   157,   111,   -46,   343,   451,   323,   323,   451,
     432,    -7,   -46,   -26,   -46,   451,   131,   163,    44,   144,
     104,   -10,   -46,   -46,   343,   -46,   145,   115,   117,   119,
     113,   323,   -46,   -46,   -46,   123,   161,   165,   134,   323,
     259,   323,   136,   138,   323,   291,   142,   195,   -46,   -46,
     227,   146,   -46,   -46,   -46,   -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     9,     0,     0,     2,     3,     0,
       0,     0,    40,    37,    38,     0,     4,     6,    11,     0,
       0,     7,     0,     0,    12,    41,    39,     0,    13,     0,
       0,     0,     0,     0,    72,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    21,
      24,     0,     0,    46,    51,    67,     0,    14,     0,    15,
       0,     0,     0,     0,     0,     0,    71,    60,    43,    68,
      69,     0,     8,    20,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    42,     0,    16,    17,     0,     0,     0,     0,     0,
       0,     0,    73,    58,    59,    61,    62,    64,    66,    63,
      65,    52,    53,    54,    55,    56,    57,    70,     0,     0,
       0,     0,     0,     0,    45,     0,    18,     0,     0,    34,
       0,     0,    50,     0,    47,    49,     0,     0,     0,     0,
       0,     0,    31,    44,     0,    25,    26,     0,     0,     0,
       0,     0,    29,    30,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    35,    36,
       0,     0,    33,    27,    28,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   174,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -32,   -45,   -46,   -46,   -46,    45,   -46,   -46,
     185,   -46,   171,   -46,   -46,    53,   -39,   -46,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     7,     2,     8,    27,     9,    11,    23,    24,
      92,    93,    47,    48,    49,    50,   141,   142,    98,   149,
      51,    13,    14,    52,   133,   134,    53,    54,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    58,    73,    67,    68,   139,   140,    71,   139,   140,
       4,    73,    59,     6,   143,    34,    66,   144,     3,    91,
      94,    95,    96,    12,    99,    84,    85,    86,    87,    88,
      89,    15,   152,    86,    87,    88,    89,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    46,     4,     5,    17,     6,   147,   148,    69,    70,
      18,    34,    35,     5,    19,    20,    36,    37,    21,    38,
      22,    25,    39,    28,    29,    30,    40,    41,    31,   126,
      42,    32,   129,   130,    33,    43,   135,    57,    60,    44,
      45,    73,    73,    61,    62,   136,   137,    46,    63,    64,
      72,    65,    34,    35,     5,   135,    97,    36,    37,    74,
      38,    75,   100,    39,   101,    73,    59,    40,    41,   160,
      73,    42,    73,   118,   117,    73,    43,   165,   121,   167,
      44,    45,   170,   122,    34,    35,     5,   124,    46,    36,
      37,    90,    38,    89,   125,    39,   127,   150,   151,    40,
      41,   128,   131,    42,   156,   155,   157,   159,    43,   158,
      34,    66,    44,    45,   161,   162,    34,    35,     5,   163,
      46,    36,    37,   145,    38,   164,   168,    39,   169,    42,
     172,    40,    41,    16,   175,    42,   153,    10,    44,    45,
      43,    26,     0,     0,    44,    45,    46,   154,    34,    35,
       5,     0,    46,    36,    37,   146,    38,     0,     0,    39,
       0,     0,     0,    40,    41,     0,     0,    42,     0,     0,
       0,     0,    43,     0,     0,     0,    44,    45,     0,     0,
      34,    35,     5,     0,    46,    36,    37,   173,    38,     0,
       0,    39,     0,     0,     0,    40,    41,     0,     0,    42,
       0,     0,     0,     0,    43,     0,     0,     0,    44,    45,
       0,     0,    34,    35,     5,     0,    46,    36,    37,   174,
      38,     0,     0,    39,     0,     0,   166,    40,    41,     0,
       0,    42,     0,     0,     0,     0,    43,     0,     0,     0,
      44,    45,     0,     0,    34,    35,     5,     0,    46,    36,
      37,     0,    38,     0,     0,    39,     0,     0,   171,    40,
      41,     0,     0,    42,     0,     0,     0,     0,    43,     0,
       0,     0,    44,    45,     0,     0,    34,    35,     5,     0,
      46,    36,    37,     0,    38,     0,     0,    39,     0,     0,
       0,    40,    41,     0,     0,    42,    34,    66,     0,   132,
      43,     0,     0,     0,    44,    45,     0,     0,     0,     0,
       0,     0,    46,     0,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,     0,     0,
      76,    77,    46,    78,    79,    80,    81,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,     0,    76,    77,
     102,    78,    79,    80,    81,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,     0,    76,    77,   119,    78,
      79,    80,    81,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,     0,    76,    77,   120,    78,    79,    80,
      81,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,     0,    76,    77,   123,    78,    79,    80,    81,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,     0,
     138,    76,    77,     0,    78,    79,    80,    81,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    76,     0,
       0,    78,    79,    80,    81,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    78,    79,    80,    81,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    80,
      81,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89
};

static const yytype_int16 yycheck[] =
{
      32,    28,    47,    42,    43,    15,    16,    46,    15,    16,
       4,    56,    39,     7,    40,     3,     4,    43,     0,    58,
      59,    60,    61,     4,    63,    31,    32,    33,    34,    35,
      36,    39,    42,    33,    34,    35,    36,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    39,     4,     5,    38,     7,    12,    13,    44,    45,
      39,     3,     4,     5,    28,    43,     8,     9,    40,    11,
       5,     3,    14,     4,    40,    43,    18,    19,    41,   118,
      22,    41,   121,   122,     5,    27,   125,     4,    39,    31,
      32,   136,   137,    39,    39,   127,   128,    39,    39,    39,
      42,    39,     3,     4,     5,   144,     4,     8,     9,    38,
      11,    38,     6,    14,     6,   160,    39,    18,    19,   151,
     165,    22,   167,    43,    40,   170,    27,   159,    28,   161,
      31,    32,   164,    38,     3,     4,     5,    40,    39,     8,
       9,    42,    11,    36,    43,    14,    41,     3,    44,    18,
      19,    41,    41,    22,    39,    10,    39,    44,    27,    40,
       3,     4,    31,    32,    41,     4,     3,     4,     5,     4,
      39,     8,     9,    42,    11,    41,    40,    14,    40,    22,
      38,    18,    19,     9,    38,    22,   141,     2,    31,    32,
      27,    20,    -1,    -1,    31,    32,    39,   144,     3,     4,
       5,    -1,    39,     8,     9,    42,    11,    -1,    -1,    14,
      -1,    -1,    -1,    18,    19,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    -1,
       3,     4,     5,    -1,    39,     8,     9,    42,    11,    -1,
      -1,    14,    -1,    -1,    -1,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    -1,     3,     4,     5,    -1,    39,     8,     9,    42,
      11,    -1,    -1,    14,    -1,    -1,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    -1,     3,     4,     5,    -1,    39,     8,
       9,    -1,    11,    -1,    -1,    14,    -1,    -1,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    -1,     3,     4,     5,    -1,
      39,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    -1,
      -1,    18,    19,    -1,    -1,    22,     3,     4,    -1,     6,
      27,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      20,    21,    39,    23,    24,    25,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    20,    21,
      40,    23,    24,    25,    26,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    20,    21,    40,    23,
      24,    25,    26,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    20,    21,    40,    23,    24,    25,
      26,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    20,    21,    40,    23,    24,    25,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    20,    21,    -1,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    20,    -1,
      -1,    23,    24,    25,    26,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    23,    24,    25,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    25,
      26,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    46,    48,     0,     4,     5,     7,    47,    49,    51,
      65,    52,     4,    66,    67,    39,    47,    38,    39,    28,
      43,    40,     5,    53,    54,     3,    67,    50,     4,    40,
      43,    41,    41,     5,     3,     4,     8,     9,    11,    14,
      18,    19,    22,    27,    31,    32,    39,    57,    58,    59,
      60,    65,    68,    71,    72,    73,    57,     4,    28,    39,
      39,    39,    39,    39,    39,    39,     4,    71,    71,    73,
      73,    71,    42,    58,    38,    38,    20,    21,    23,    24,
      25,    26,    29,    30,    31,    32,    33,    34,    35,    36,
      42,    71,    55,    56,    71,    71,    71,     4,    63,    71,
       6,     6,    40,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    40,    43,    40,
      40,    28,    38,    40,    40,    43,    71,    41,    41,    71,
      71,    41,     6,    69,    70,    71,    57,    57,    38,    15,
      16,    61,    62,    40,    43,    42,    42,    12,    13,    64,
       3,    44,    42,    62,    70,    10,    39,    39,    40,    44,
      57,    41,     4,     4,    41,    57,    17,    57,    40,    40,
      57,    17,    38,    42,    42,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    50,    49,    52,
      51,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    60,    60,    60,
      61,    61,    62,    62,    63,    64,    64,    65,    66,    66,
      67,    67,    68,    68,    68,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    72,
      73,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     0,     3,     0,     7,     0,
       8,     0,     1,     2,     4,     0,     1,     1,     3,     1,
       2,     1,     2,     2,     1,     7,     7,    11,    11,     7,
       2,     1,     6,     5,     3,     4,     4,     2,     1,     3,
       1,     3,     3,     2,     6,     4,     1,     1,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     1,     2,     2,
       4,     1,     1,     3
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
  case 2: /* axiom: global_decls defs_before_main  */
#line 101 "trad1.y"
      {
          printf("%s%s(main)\n", yyvsp[-1].code, yyvsp[0].code);
      }
#line 1369 "trad1.tab.c"
    break;

  case 3: /* defs_before_main: main_def  */
#line 108 "trad1.y"
      {
          yyval = yyvsp[0];
      }
#line 1377 "trad1.tab.c"
    break;

  case 4: /* defs_before_main: function_def defs_before_main  */
#line 112 "trad1.y"
      {
          sprintf(temp, "%s%s", yyvsp[-1].code, yyvsp[0].code);
          yyval.code = gen_code(temp);
      }
#line 1386 "trad1.tab.c"
    break;

  case 5: /* global_decls: %empty  */
#line 118 "trad1.y"
                                             { yyval.code = gen_code(""); }
#line 1392 "trad1.tab.c"
    break;

  case 6: /* global_decls: global_decls declaration ';'  */
#line 119 "trad1.y"
                                             { sprintf(temp, "%s%s\n", yyvsp[-2].code, yyvsp[-1].code);
                                               yyval.code = gen_code(temp); }
#line 1399 "trad1.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 125 "trad1.y"
      {
          strcpy(current_function, "main");
          clear_local_vars();
      }
#line 1408 "trad1.tab.c"
    break;

  case 8: /* main_def: MAIN '(' ')' $@1 '{' body '}'  */
#line 130 "trad1.y"
      {
          sprintf(temp, "(defun main ()\n%s)\n", yyvsp[-1].code);
          yyval.code = gen_code(temp);
          clear_local_vars();
          strcpy(current_function, "");
      }
#line 1419 "trad1.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 140 "trad1.y"
      {
          strcpy(current_function, yyvsp[0].code);
          clear_local_vars();
      }
#line 1428 "trad1.tab.c"
    break;

  case 10: /* function_def: IDENTIF $@2 '(' param_defs ')' '{' body '}'  */
#line 145 "trad1.y"
      {
          sprintf(temp, "(defun %s (%s)\n%s)\n", yyvsp[-7].code, yyvsp[-4].code, yyvsp[-1].code);
          yyval.code = gen_code(temp);
          clear_local_vars();
          strcpy(current_function, "");
      }
#line 1439 "trad1.tab.c"
    break;

  case 11: /* param_defs: %empty  */
#line 154 "trad1.y"
      {
          yyval.code = gen_code("");
      }
#line 1447 "trad1.tab.c"
    break;

  case 12: /* param_defs: param_list  */
#line 158 "trad1.y"
      {
          yyval = yyvsp[0];
      }
#line 1455 "trad1.tab.c"
    break;

  case 13: /* param_list: INTEGER IDENTIF  */
#line 165 "trad1.y"
      {
          add_param_var(yyvsp[0].code);
          yyval.code = gen_code(yyvsp[0].code);
      }
#line 1464 "trad1.tab.c"
    break;

  case 14: /* param_list: param_list ',' INTEGER IDENTIF  */
#line 170 "trad1.y"
      {
          add_param_var(yyvsp[0].code);
          sprintf(temp, "%s %s", yyvsp[-3].code, yyvsp[0].code);
          yyval.code = gen_code(temp);
      }
#line 1474 "trad1.tab.c"
    break;

  case 15: /* call_args: %empty  */
#line 178 "trad1.y"
      {
          yyval.code = gen_code("");
      }
#line 1482 "trad1.tab.c"
    break;

  case 16: /* call_args: call_arg_list  */
#line 182 "trad1.y"
      {
          yyval = yyvsp[0];
      }
#line 1490 "trad1.tab.c"
    break;

  case 17: /* call_arg_list: expression  */
#line 189 "trad1.y"
      {
          yyval = yyvsp[0];
      }
#line 1498 "trad1.tab.c"
    break;

  case 18: /* call_arg_list: call_arg_list ',' expression  */
#line 193 "trad1.y"
      {
          sprintf(temp, "%s %s", yyvsp[-2].code, yyvsp[0].code);
          yyval.code = gen_code(temp);
      }
#line 1507 "trad1.tab.c"
    break;

  case 19: /* body: body_element  */
#line 201 "trad1.y"
      {
          sprintf(temp, " %s\n", yyvsp[0].code);
          yyval.code = gen_code(temp);
      }
#line 1516 "trad1.tab.c"
    break;

  case 20: /* body: body body_element  */
#line 206 "trad1.y"
      {
          sprintf(temp, "%s %s\n", yyvsp[-1].code, yyvsp[0].code);
          yyval.code = gen_code(temp);
      }
#line 1525 "trad1.tab.c"
    break;

  case 21: /* body_element: statement  */
#line 214 "trad1.y"
      {
          yyval.code = yyvsp[0].code;
      }
#line 1533 "trad1.tab.c"
    break;

  case 22: /* body_element: declaration ';'  */
#line 218 "trad1.y"
      {
          yyval.code = yyvsp[-1].code;
      }
#line 1541 "trad1.tab.c"
    break;

  case 23: /* statement: sentence ';'  */
#line 223 "trad1.y"
                                        { sprintf(temp, "%s", yyvsp[-1].code);
                                          yyval.code = gen_code(temp); }
#line 1548 "trad1.tab.c"
    break;

  case 24: /* statement: control_struct  */
#line 225 "trad1.y"
                                        { sprintf(temp, "%s", yyvsp[0].code);
                                          yyval.code = gen_code(temp); }
#line 1555 "trad1.tab.c"
    break;

  case 25: /* control_struct: WHILE '(' expression ')' '{' body '}'  */
#line 229 "trad1.y"
                                                                                  { sprintf (temp, "(loop while %s do %s)", yyvsp[-4].code, yyvsp[-1].code) ;  
                                                                                    yyval.code = gen_code (temp) ; }
#line 1562 "trad1.tab.c"
    break;

  case 26: /* control_struct: IF '(' expression ')' '{' body '}'  */
#line 231 "trad1.y"
                                                                                  { sprintf (temp, "(if %s (progn %s))", yyvsp[-4].code, yyvsp[-1].code) ;  //!ASK ABOUT PROGN!
                                                                                    yyval.code = gen_code (temp) ; }
#line 1569 "trad1.tab.c"
    break;

  case 27: /* control_struct: IF '(' expression ')' '{' body '}' ELSE '{' body '}'  */
#line 233 "trad1.y"
                                                                                  { sprintf (temp, "(if %s (progn %s) (progn %s))", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code) ;  //!ASK ABOUT PROGN!
                                                                                    yyval.code = gen_code (temp) ; }
#line 1576 "trad1.tab.c"
    break;

  case 28: /* control_struct: FOR '(' for_init ';' expression ';' for_update ')' '{' body '}'  */
#line 235 "trad1.y"
                                                                                  { sprintf (temp, "(progn %s (loop while %s do (progn %s %s)))", yyvsp[-8].code, yyvsp[-6].code, yyvsp[-1].code, yyvsp[-4].code) ;
                                                                                    yyval.code = gen_code (temp) ; }
#line 1583 "trad1.tab.c"
    break;

  case 29: /* control_struct: SWITCH '(' expression ')' '{' case_list '}'  */
#line 237 "trad1.y"
                                                                                  { sprintf (temp, "(case %s %s)", yyvsp[-4].code, yyvsp[-1].code) ;
                                                                                    yyval.code = gen_code (temp) ; }
#line 1590 "trad1.tab.c"
    break;

  case 30: /* case_list: case_list case_block  */
#line 241 "trad1.y"
                                            { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code);
                                              yyval.code = gen_code(temp) ; }
#line 1597 "trad1.tab.c"
    break;

  case 31: /* case_list: case_block  */
#line 243 "trad1.y"
                                            { yyval.code = yyvsp[0].code ; }
#line 1603 "trad1.tab.c"
    break;

  case 32: /* case_block: CASE NUMBER ':' body BREAK ';'  */
#line 246 "trad1.y"
                                                { sprintf(temp, "(%d (progn %s))", yyvsp[-4].value, yyvsp[-2].code);
                                                  yyval.code = gen_code(temp) ; }
#line 1610 "trad1.tab.c"
    break;

  case 33: /* case_block: DEFAULT ':' body BREAK ';'  */
#line 248 "trad1.y"
                                                { sprintf(temp, "(otherwise (progn %s))", yyvsp[-2].code);
                                                  yyval.code = gen_code(temp) ; }
#line 1617 "trad1.tab.c"
    break;

  case 34: /* for_init: IDENTIF '=' expression  */
#line 254 "trad1.y"
      {
          char *name = translated_name(yyvsp[-2].code);
          sprintf(temp, "(setf %s %s)", name, yyvsp[0].code);
          yyval.code = gen_code(temp);
      }
#line 1627 "trad1.tab.c"
    break;

  case 35: /* for_update: INC '(' IDENTIF ')'  */
#line 263 "trad1.y"
      {
          char *name = translated_name(yyvsp[-1].code);
          sprintf(temp, "(setf %s (+ %s 1))", name, name);
          yyval.code = gen_code(temp);
      }
#line 1637 "trad1.tab.c"
    break;

  case 36: /* for_update: DEC '(' IDENTIF ')'  */
#line 269 "trad1.y"
      {
          char *name = translated_name(yyvsp[-1].code);
          sprintf(temp, "(setf %s (- %s 1))", name, name);
          yyval.code = gen_code(temp);
      }
#line 1647 "trad1.tab.c"
    break;

  case 37: /* declaration: INTEGER decl_list  */
#line 276 "trad1.y"
                                             { yyval = yyvsp[0] ; }
#line 1653 "trad1.tab.c"
    break;

  case 38: /* decl_list: decl_item  */
#line 279 "trad1.y"
                                             { yyval = yyvsp[0] ; }
#line 1659 "trad1.tab.c"
    break;

  case 39: /* decl_list: decl_list ',' decl_item  */
#line 280 "trad1.y"
                                             { sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1666 "trad1.tab.c"
    break;

  case 40: /* decl_item: IDENTIF  */
#line 286 "trad1.y"
      {
          char *name;
          if (strlen(current_function) > 0) {
              add_local_var(yyvsp[0].code);
              name = translated_name(yyvsp[0].code);
          } else {
              name = gen_code(yyvsp[0].code);
          }

          sprintf(temp, "(setq %s 0)", name);
          yyval.code = gen_code(temp);
      }
#line 1683 "trad1.tab.c"
    break;

  case 41: /* decl_item: IDENTIF '=' NUMBER  */
#line 299 "trad1.y"
      {
          char *name;
          if (strlen(current_function) > 0) {
              add_local_var(yyvsp[-2].code);
              name = translated_name(yyvsp[-2].code);
          } else {
              name = gen_code(yyvsp[-2].code);
          }

          sprintf(temp, "(setq %s %d)", name, yyvsp[0].value);
          yyval.code = gen_code(temp);
      }
#line 1700 "trad1.tab.c"
    break;

  case 42: /* sentence: IDENTIF '=' expression  */
#line 315 "trad1.y"
      {
          char *name = translated_name(yyvsp[-2].code);
          sprintf(temp, "(setf %s %s)", name, yyvsp[0].code);
          yyval.code = gen_code(temp);
      }
#line 1710 "trad1.tab.c"
    break;

  case 43: /* sentence: RETURN expression  */
#line 321 "trad1.y"
      {
          sprintf(temp, "(return-from %s %s)", current_function, yyvsp[0].code);
          yyval.code = gen_code(temp);
      }
#line 1719 "trad1.tab.c"
    break;

  case 44: /* sentence: PRINTF '(' STRING ',' arg_list ')'  */
#line 326 "trad1.y"
      {
          yyval.code = yyvsp[-1].code;
      }
#line 1727 "trad1.tab.c"
    break;

  case 45: /* sentence: PUTS '(' STRING ')'  */
#line 330 "trad1.y"
      {
          sprintf(temp, "(print \"%s\")", yyvsp[-1].code);
          yyval.code = gen_code(temp);
      }
#line 1736 "trad1.tab.c"
    break;

  case 46: /* sentence: expression  */
#line 335 "trad1.y"
      {
          yyval = yyvsp[0];
      }
#line 1744 "trad1.tab.c"
    break;

  case 47: /* arg_list: arg  */
#line 340 "trad1.y"
                                            {sprintf (temp, "(princ %s)", yyvsp[0].code) ; 
                                               yyval.code = gen_code (temp) ;}
#line 1751 "trad1.tab.c"
    break;

  case 48: /* arg_list: arg_list ',' arg  */
#line 342 "trad1.y"
                                            {sprintf (temp, "%s\n(princ %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                               yyval.code = gen_code (temp) ;}
#line 1758 "trad1.tab.c"
    break;

  case 49: /* arg: expression  */
#line 346 "trad1.y"
                                            {yyval = yyvsp[0] ; }
#line 1764 "trad1.tab.c"
    break;

  case 50: /* arg: STRING  */
#line 347 "trad1.y"
                                            {sprintf (temp, "\"%s\"", yyvsp[0].code) ; 
                                               yyval.code = gen_code (temp) ;}
#line 1771 "trad1.tab.c"
    break;

  case 51: /* expression: term  */
#line 351 "trad1.y"
                                             { yyval = yyvsp[0] ; }
#line 1777 "trad1.tab.c"
    break;

  case 52: /* expression: expression '+' expression  */
#line 352 "trad1.y"
                                             { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1784 "trad1.tab.c"
    break;

  case 53: /* expression: expression '-' expression  */
#line 354 "trad1.y"
                                             { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1791 "trad1.tab.c"
    break;

  case 54: /* expression: expression '*' expression  */
#line 356 "trad1.y"
                                             { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1798 "trad1.tab.c"
    break;

  case 55: /* expression: expression '/' expression  */
#line 358 "trad1.y"
                                             { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1805 "trad1.tab.c"
    break;

  case 56: /* expression: expression '%' expression  */
#line 360 "trad1.y"
                                             { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1812 "trad1.tab.c"
    break;

  case 57: /* expression: expression '^' expression  */
#line 362 "trad1.y"
                                             { sprintf (temp, "(expt %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1819 "trad1.tab.c"
    break;

  case 58: /* expression: expression AND expression  */
#line 364 "trad1.y"
                                             { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1826 "trad1.tab.c"
    break;

  case 59: /* expression: expression OR expression  */
#line 366 "trad1.y"
                                             { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1833 "trad1.tab.c"
    break;

  case 60: /* expression: NOT expression  */
#line 368 "trad1.y"
                                             { sprintf (temp, "(not %s)", yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1840 "trad1.tab.c"
    break;

  case 61: /* expression: expression EQ expression  */
#line 370 "trad1.y"
                                             { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1847 "trad1.tab.c"
    break;

  case 62: /* expression: expression NE expression  */
#line 372 "trad1.y"
                                             { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1854 "trad1.tab.c"
    break;

  case 63: /* expression: expression '<' expression  */
#line 374 "trad1.y"
                                             { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1861 "trad1.tab.c"
    break;

  case 64: /* expression: expression LE expression  */
#line 376 "trad1.y"
                                             { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1868 "trad1.tab.c"
    break;

  case 65: /* expression: expression '>' expression  */
#line 378 "trad1.y"
                                             { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1875 "trad1.tab.c"
    break;

  case 66: /* expression: expression GE expression  */
#line 380 "trad1.y"
                                             { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1882 "trad1.tab.c"
    break;

  case 67: /* term: operand  */
#line 384 "trad1.y"
                                             { yyval = yyvsp[0] ; }
#line 1888 "trad1.tab.c"
    break;

  case 68: /* term: '+' operand  */
#line 385 "trad1.y"
                                             { yyval = yyvsp[0] ; }
#line 1894 "trad1.tab.c"
    break;

  case 69: /* term: '-' operand  */
#line 386 "trad1.y"
                                             { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1901 "trad1.tab.c"
    break;

  case 70: /* operand: IDENTIF '(' call_args ')'  */
#line 392 "trad1.y"
      {
          if (strlen(yyvsp[-1].code) == 0)
              sprintf(temp, "(%s)", yyvsp[-3].code);
          else
              sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code);

          yyval.code = gen_code(temp);
      }
#line 1914 "trad1.tab.c"
    break;

  case 71: /* operand: IDENTIF  */
#line 401 "trad1.y"
      {
          char *name = translated_name(yyvsp[0].code);
          sprintf(temp, "%s", name);
          yyval.code = gen_code(temp);
      }
#line 1924 "trad1.tab.c"
    break;

  case 72: /* operand: NUMBER  */
#line 407 "trad1.y"
      {
          sprintf(temp, "%d", yyvsp[0].value);
          yyval.code = gen_code(temp);
      }
#line 1933 "trad1.tab.c"
    break;

  case 73: /* operand: '(' expression ')'  */
#line 412 "trad1.y"
      {
          yyval = yyvsp[-1];
      }
#line 1941 "trad1.tab.c"
    break;


#line 1945 "trad1.tab.c"

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

#line 418 "trad1.y"
                           // SECTION 4    Code in C

int n_line = 1 ;

void yyerror (char *message)
{
    fprintf (stderr, "%s in line %d\n", message, n_line) ;
    printf ( "\n") ;
}

char *int_to_string (int n)
{
    sprintf (temp, "%d", n) ;
    return gen_code (temp) ;
}

char *char_to_string (char c)
{
    sprintf (temp, "%c", c) ;
    return gen_code (temp) ;
}

char *my_malloc (int nbytes)     // reserve n bytes of dynamic memory 
{
    char *p ;
    static long int nb = 0 ;     // used to count the memory  
    static int nv = 0 ;          // required in total 

    p = malloc (nbytes) ;
    if (p == NULL) {
      fprintf (stderr, "No memory left for additional %d bytes\n", nbytes) ;
      fprintf (stderr, "%ld bytes reserved in %d calls \n", nb, nv) ;  
      exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}



/***************************************************************************/
/***************************** Keyword Section *****************************/
/***************************************************************************/

typedef struct s_keyword { // for the reserved words of C  
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = {     // define the keywords 
    "main",        MAIN,      // and their associated token  
    "int",         INTEGER,
    "puts",        PUTS,
    "printf",      PRINTF,
    "while",       WHILE,
    "if",          IF,
    "else",        ELSE,
    "for",         FOR,
    "inc",         INC,
    "dec",         DEC,
    "switch",      SWITCH,
    "case",        CASE,
    "default",     DEFAULT,
    "break",       BREAK,
    "&&",          AND,
    "||",          OR,
    "!",          NOT,
    "==",          EQ,
    "!=",          NE,
    "<=",          LE,
    ">=",          GE,
    "return",      RETURN,
    NULL,          0          // 0 to mark the end of the table
} ;

t_keyword *search_keyword (char *symbol_name)
{                       // Search symbol names in the keyword table
                        // and return a pointer to token register
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
                                   // strcmp(a, b) returns == 0 if a==b  
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************** Section for the Lexical Analyzer  ********************/
/***************************************************************************/

char *gen_code (char *name)   // copy the argument to an  
{                             // string in dynamic memory  
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char expandable_ops [] =  "<=>|%&/+-*^" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do { 
        c = getchar () ; 
        if (c == '#') { // Ignore the lines starting with # (#define, #include) 
            do { // WARNING that it may malfunction if a line contains # 
                c = getchar () ; 
            } while (c != '\n') ; 
        } 
        if (c == '/') { // character / can be the beginning of a comment. 
            cc = getchar () ; 
            if (cc != '/') { // If the following char is / is a comment, but.... 
                ungetc (cc, stdin) ; 
            } else { 
                c = getchar () ; // ... 
                if (c == '@') { // Lines starting with //@ are transcribed
                    do { // This is inline code (embedded code in C).
                        c = getchar () ; 
                        putchar (c) ; 
                    } while (c != '\n') ; 
                } else { // ==> comment, ignore the line 
                    while (c != '\n') { 
                        c = getchar () ; 
                    } 
                } 
            } 
        } 
        if (c == '\n') 
            n_line++ ; 
    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("WARNING: string with more than 255 characters in line %d\n", n_line) ; 
        } // we should read until the next “, but, what if it is  missing? 
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;       
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
        temp_str [i++] = tolower (c) ; // ALL TO SMALL LETTERS
        c = getchar () ; 
    } 
    temp_str [i] = '\0' ; // End of string  
    ungetc (c, stdin) ; // return excess char  

    yylval.code = gen_code (temp_str) ; 
    symbol = search_keyword (yylval.code) ;
    if (symbol == NULL) { // is not reserved word -> iderntifrier  
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (c == '!') {
    cc = getchar();
    if (cc == '=') {
        yylval.code = gen_code("!=");
        return NE;
    }
    ungetc(cc, stdin);
    return NOT;
    }

    if (strchr (expandable_ops, c) != NULL) { // // look for c in expandable_ops
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // although it is not used   
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}


void clear_local_vars()
{
    local_vars = NULL;
}

void add_scoped_var(char *original, char *translated)
{
    t_localvar *p = (t_localvar *) my_malloc(sizeof(t_localvar));
    p->original = gen_code(original);
    p->translated = gen_code(translated);
    p->next = local_vars;
    local_vars = p;
}

void add_local_var(char *name)
{
    sprintf(temp, "%s_%s", current_function, name);
    add_scoped_var(name, temp);
}

void add_param_var(char *name)
{
    add_scoped_var(name, name);
}

char *translated_name(char *name)
{
    t_localvar *p = local_vars;

    while (p != NULL) {
        if (strcmp(p->original, name) == 0) {
            return gen_code(p->translated);
        }
        p = p->next;
    }

    return gen_code(name);
}

int main ()
{
    yyparse () ;
}
