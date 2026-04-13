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
char *add_local_var(char *name);
int is_local_var(char *name);
char *translated_name(char *name);
void clear_local_vars();

char temp [2048] ;

char current_function[256] = "";

typedef struct s_localvar {
    char *name;      // original name in C
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


#line 125 "trad1.tab.c"

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
  YYSYMBOL_27_ = 27,                       /* '='  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_35_ = 35,                       /* '^'  */
  YYSYMBOL_UNARY_SIGN = 36,                /* UNARY_SIGN  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* ':'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_axiom = 45,                     /* axiom  */
  YYSYMBOL_global_decls = 46,              /* global_decls  */
  YYSYMBOL_main_def = 47,                  /* main_def  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_body = 49,                      /* body  */
  YYSYMBOL_body_element = 50,              /* body_element  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_control_struct = 52,            /* control_struct  */
  YYSYMBOL_case_list = 53,                 /* case_list  */
  YYSYMBOL_case_block = 54,                /* case_block  */
  YYSYMBOL_for_init = 55,                  /* for_init  */
  YYSYMBOL_for_update = 56,                /* for_update  */
  YYSYMBOL_declaration = 57,               /* declaration  */
  YYSYMBOL_decl_list = 58,                 /* decl_list  */
  YYSYMBOL_decl_item = 59,                 /* decl_item  */
  YYSYMBOL_sentence = 60,                  /* sentence  */
  YYSYMBOL_arg_list = 61,                  /* arg_list  */
  YYSYMBOL_arg = 62,                       /* arg  */
  YYSYMBOL_expression = 63,                /* expression  */
  YYSYMBOL_term = 64,                      /* term  */
  YYSYMBOL_operand = 65                    /* operand  */
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
#define YYLAST   342

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,     2,     2,     2,     2,    34,     2,     2,
      38,    39,    32,    30,    43,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    37,
      28,    27,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      25,    26,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    96,    96,    99,   100,   106,   105,   120,   125,   133,
     137,   143,   145,   149,   151,   153,   155,   157,   161,   163,
     166,   168,   173,   182,   188,   196,   199,   200,   205,   218,
     234,   240,   241,   245,   247,   251,   252,   256,   257,   259,
     261,   263,   265,   267,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   289,   290,   291,   296,   302,   307
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
  "NOT", "EQ", "NE", "LE", "GE", "'='", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'^'", "UNARY_SIGN", "';'", "'('", "')'", "'{'", "'}'",
  "':'", "','", "$accept", "axiom", "global_decls", "main_def", "$@1",
  "body", "body_element", "statement", "control_struct", "case_list",
  "case_block", "for_init", "for_update", "declaration", "decl_list",
  "decl_item", "sentence", "arg_list", "arg", "expression", "term",
  "operand", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-36)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -36,     6,     2,   -36,     9,   -28,   -36,   -19,    -6,   -17,
     -36,    -8,   -36,    44,     9,   -36,   -36,   -36,    16,   289,
      34,    30,    32,    33,    37,    40,    41,    11,   -36,   -36,
     -36,    47,    53,   123,   123,   123,    76,   123,    75,    85,
     -36,   -36,   -36,   -36,   -36,   -36,   123,     8,     8,   123,
     225,   -36,   -36,   139,   156,    67,    59,   173,    69,    54,
     -36,   -36,   -36,   190,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,    72,    78,
     123,   123,    90,   -36,   117,   -36,   286,   241,   297,   297,
     303,   303,   303,   303,   307,   307,    89,    89,    89,    89,
     289,   289,   225,   207,    43,   -36,   -35,   -36,   225,    46,
      58,    61,   128,    92,    12,   -36,   -36,   117,   -36,   126,
     102,   106,   107,   108,   289,   -36,   -36,   -36,   109,   147,
     148,   116,   289,   124,   289,   118,   119,   289,   273,   129,
      84,   -36,   -36,    96,   138,   -36,   -36,   -36,   -36
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     2,     0,    28,    25,
      26,     0,     4,     0,     0,     5,    29,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     9,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     8,    10,    11,    57,    56,     0,     0,     0,     0,
      30,    37,    53,     0,     0,     0,     0,     0,     0,     0,
      46,    54,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,    58,    44,    45,    47,    48,
      50,    52,    49,    51,    38,    39,    40,    41,    42,    43,
       0,     0,    22,     0,     0,    36,     0,    33,    35,     0,
       0,     0,     0,     0,     0,    19,    31,     0,    13,    14,
       0,     0,     0,     0,     0,    17,    18,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,     0,     0,    21,    15,    16,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -36,   -36,   -36,   -36,   -36,   -15,   -27,   -36,   -36,   -36,
      86,   -36,   -36,   181,   -36,   178,   -36,   -36,   100,   -32,
     -36,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,    18,    27,    28,    29,    30,   114,
     115,    56,   122,    31,     9,    10,    32,   106,   107,   108,
      51,    52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,    50,    53,    54,   116,    57,     3,     4,   117,     5,
      11,    44,    45,     8,    60,    20,     4,    63,    12,    21,
      22,    13,    23,    61,    62,    24,    14,   112,   113,    25,
      26,    15,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,    49,    16,   102,   103,
      20,     4,    40,   125,    21,    22,    19,    23,   112,   113,
      24,    33,    20,     4,    25,    26,    21,    22,    34,    23,
      35,    36,    24,   120,   121,    37,    25,    26,    38,    39,
      55,    58,    41,    41,    42,   109,   110,   118,    20,     4,
      43,    59,    21,    22,    80,    23,    81,    84,    24,   119,
      20,     4,    25,    26,    21,    22,    41,    23,    83,   133,
      24,    41,   100,    41,    25,    26,    41,   138,   101,   140,
      44,    45,   143,   105,    77,   146,    44,    45,    20,     4,
     104,   123,    21,    22,   124,    23,   128,   147,    24,    46,
     129,   139,    25,    26,   130,    46,   131,    47,    48,   134,
     132,   135,   136,    47,    48,    49,   137,   141,   142,    64,
      65,    49,    66,    67,    68,    69,   145,    70,    71,    72,
      73,    74,    75,    76,    77,   148,    64,    65,    78,    66,
      67,    68,    69,     7,    70,    71,    72,    73,    74,    75,
      76,    77,    17,    64,    65,    79,    66,    67,    68,    69,
     126,    70,    71,    72,    73,    74,    75,    76,    77,     0,
      64,    65,    82,    66,    67,    68,    69,   127,    70,    71,
      72,    73,    74,    75,    76,    77,     0,    64,    65,    85,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
      75,    76,    77,     0,   111,    64,    65,     0,    66,    67,
      68,    69,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    64,     0,     0,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    20,     4,     0,
       0,    21,    22,     0,    23,     0,     0,    24,     0,     0,
     144,    25,    26,    20,     4,     0,     0,    21,    22,     0,
      23,     0,     0,    24,     0,     0,     0,    25,    26,    66,
      67,    68,    69,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    68,    69,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    72,    73,    74,    75,    76,    77,    74,
      75,    76,    77
};

static const yytype_int16 yycheck[] =
{
      27,    33,    34,    35,    39,    37,     0,     5,    43,     7,
      38,     3,     4,     4,    46,     4,     5,    49,    37,     8,
       9,    27,    11,    47,    48,    14,    43,    15,    16,    18,
      19,    39,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    38,     3,    80,    81,
       4,     5,    41,    41,     8,     9,    40,    11,    15,    16,
      14,    27,     4,     5,    18,    19,     8,     9,    38,    11,
      38,    38,    14,    12,    13,    38,    18,    19,    38,    38,
       4,     6,   109,   110,    37,   100,   101,    41,     4,     5,
      37,     6,     8,     9,    27,    11,    37,    43,    14,    41,
       4,     5,    18,    19,     8,     9,   133,    11,    39,   124,
      14,   138,    40,   140,    18,    19,   143,   132,    40,   134,
       3,     4,   137,     6,    35,    41,     3,     4,     4,     5,
      40,     3,     8,     9,    42,    11,    10,    41,    14,    22,
      38,    17,    18,    19,    38,    22,    39,    30,    31,    40,
      42,     4,     4,    30,    31,    38,    40,    39,    39,    20,
      21,    38,    23,    24,    25,    26,    37,    28,    29,    30,
      31,    32,    33,    34,    35,    37,    20,    21,    39,    23,
      24,    25,    26,     2,    28,    29,    30,    31,    32,    33,
      34,    35,    14,    20,    21,    39,    23,    24,    25,    26,
     114,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      20,    21,    39,    23,    24,    25,    26,   117,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    20,    21,    39,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    37,    20,    21,    -1,    23,    24,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    20,    -1,    -1,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,     4,     5,    -1,
      -1,     8,     9,    -1,    11,    -1,    -1,    14,    -1,    -1,
      17,    18,    19,     4,     5,    -1,    -1,     8,     9,    -1,
      11,    -1,    -1,    14,    -1,    -1,    -1,    18,    19,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    30,    31,    32,    33,    34,    35,    32,
      33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    46,     0,     5,     7,    47,    57,     4,    58,
      59,    38,    37,    27,    43,    39,     3,    59,    48,    40,
       4,     8,     9,    11,    14,    18,    19,    49,    50,    51,
      52,    57,    60,    27,    38,    38,    38,    38,    38,    38,
      41,    50,    37,    37,     3,     4,    22,    30,    31,    38,
      63,    64,    65,    63,    63,     4,    55,    63,     6,     6,
      63,    65,    65,    63,    20,    21,    23,    24,    25,    26,
      28,    29,    30,    31,    32,    33,    34,    35,    39,    39,
      27,    37,    39,    39,    43,    39,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      40,    40,    63,    63,    40,     6,    61,    62,    63,    49,
      49,    37,    15,    16,    53,    54,    39,    43,    41,    41,
      12,    13,    56,     3,    42,    41,    54,    62,    10,    38,
      38,    39,    42,    49,    40,     4,     4,    40,    49,    17,
      49,    39,    39,    49,    17,    37,    41,    41,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    48,    47,    49,    49,    50,
      50,    51,    51,    52,    52,    52,    52,    52,    53,    53,
      54,    54,    55,    56,    56,    57,    58,    58,    59,    59,
      60,    60,    60,    61,    61,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    64,    64,    64,    65,    65,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     3,     0,     7,     1,     2,     1,
       2,     2,     1,     7,     7,    11,    11,     7,     2,     1,
       6,     5,     3,     4,     4,     2,     1,     3,     1,     3,
       3,     6,     4,     1,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     1,     2,     2,     1,     1,     3
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
  case 2: /* axiom: global_decls main_def  */
#line 96 "trad1.y"
                                             { printf("%s%s(main)\n", yyvsp[-1].code, yyvsp[0].code); }
#line 1303 "trad1.tab.c"
    break;

  case 3: /* global_decls: %empty  */
#line 99 "trad1.y"
                                             { yyval.code = gen_code(""); }
#line 1309 "trad1.tab.c"
    break;

  case 4: /* global_decls: global_decls declaration ';'  */
#line 100 "trad1.y"
                                             { sprintf(temp, "%s%s\n", yyvsp[-2].code, yyvsp[-1].code);
                                               yyval.code = gen_code(temp); }
#line 1316 "trad1.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 106 "trad1.y"
      {
          strcpy(current_function, "main");
          clear_local_vars();
      }
#line 1325 "trad1.tab.c"
    break;

  case 6: /* main_def: MAIN '(' ')' $@1 '{' body '}'  */
#line 111 "trad1.y"
      {
          sprintf(temp, "(defun main ()\n%s)\n", yyvsp[-1].code);
          yyval.code = gen_code(temp);
          clear_local_vars();
          strcpy(current_function, "");
      }
#line 1336 "trad1.tab.c"
    break;

  case 7: /* body: body_element  */
#line 121 "trad1.y"
      {
          sprintf(temp, " %s\n", yyvsp[0].code);
          yyval.code = gen_code(temp);
      }
#line 1345 "trad1.tab.c"
    break;

  case 8: /* body: body body_element  */
#line 126 "trad1.y"
      {
          sprintf(temp, "%s %s\n", yyvsp[-1].code, yyvsp[0].code);
          yyval.code = gen_code(temp);
      }
#line 1354 "trad1.tab.c"
    break;

  case 9: /* body_element: statement  */
#line 134 "trad1.y"
      {
          yyval.code = yyvsp[0].code;
      }
#line 1362 "trad1.tab.c"
    break;

  case 10: /* body_element: declaration ';'  */
#line 138 "trad1.y"
      {
          yyval.code = yyvsp[-1].code;
      }
#line 1370 "trad1.tab.c"
    break;

  case 11: /* statement: sentence ';'  */
#line 143 "trad1.y"
                                        { sprintf(temp, "%s", yyvsp[-1].code);
                                          yyval.code = gen_code(temp); }
#line 1377 "trad1.tab.c"
    break;

  case 12: /* statement: control_struct  */
#line 145 "trad1.y"
                                        { sprintf(temp, "%s", yyvsp[0].code);
                                          yyval.code = gen_code(temp); }
#line 1384 "trad1.tab.c"
    break;

  case 13: /* control_struct: WHILE '(' expression ')' '{' body '}'  */
#line 149 "trad1.y"
                                                                                  { sprintf (temp, "(loop while %s do %s)", yyvsp[-4].code, yyvsp[-1].code) ;  
                                                                                    yyval.code = gen_code (temp) ; }
#line 1391 "trad1.tab.c"
    break;

  case 14: /* control_struct: IF '(' expression ')' '{' body '}'  */
#line 151 "trad1.y"
                                                                                  { sprintf (temp, "(if %s (progn %s))", yyvsp[-4].code, yyvsp[-1].code) ;  //!ASK ABOUT PROGN!
                                                                                    yyval.code = gen_code (temp) ; }
#line 1398 "trad1.tab.c"
    break;

  case 15: /* control_struct: IF '(' expression ')' '{' body '}' ELSE '{' body '}'  */
#line 153 "trad1.y"
                                                                                  { sprintf (temp, "(if %s (progn %s) (progn %s))", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code) ;  //!ASK ABOUT PROGN!
                                                                                    yyval.code = gen_code (temp) ; }
#line 1405 "trad1.tab.c"
    break;

  case 16: /* control_struct: FOR '(' for_init ';' expression ';' for_update ')' '{' body '}'  */
#line 155 "trad1.y"
                                                                                  { sprintf (temp, "(progn %s (loop while %s do (progn %s %s)))", yyvsp[-8].code, yyvsp[-6].code, yyvsp[-1].code, yyvsp[-4].code) ;
                                                                                    yyval.code = gen_code (temp) ; }
#line 1412 "trad1.tab.c"
    break;

  case 17: /* control_struct: SWITCH '(' expression ')' '{' case_list '}'  */
#line 157 "trad1.y"
                                                                                  { sprintf (temp, "(case %s %s)", yyvsp[-4].code, yyvsp[-1].code) ;
                                                                                    yyval.code = gen_code (temp) ; }
#line 1419 "trad1.tab.c"
    break;

  case 18: /* case_list: case_list case_block  */
#line 161 "trad1.y"
                                            { sprintf(temp, "%s %s", yyvsp[-1].code, yyvsp[0].code);
                                              yyval.code = gen_code(temp) ; }
#line 1426 "trad1.tab.c"
    break;

  case 19: /* case_list: case_block  */
#line 163 "trad1.y"
                                            { yyval.code = yyvsp[0].code ; }
#line 1432 "trad1.tab.c"
    break;

  case 20: /* case_block: CASE NUMBER ':' body BREAK ';'  */
#line 166 "trad1.y"
                                                { sprintf(temp, "(%d (progn %s))", yyvsp[-4].value, yyvsp[-2].code);
                                                  yyval.code = gen_code(temp) ; }
#line 1439 "trad1.tab.c"
    break;

  case 21: /* case_block: DEFAULT ':' body BREAK ';'  */
#line 168 "trad1.y"
                                                { sprintf(temp, "(otherwise (progn %s))", yyvsp[-2].code);
                                                  yyval.code = gen_code(temp) ; }
#line 1446 "trad1.tab.c"
    break;

  case 22: /* for_init: IDENTIF '=' expression  */
#line 174 "trad1.y"
      {
          char *name = translated_name(yyvsp[-2].code);
          sprintf(temp, "(setf %s %s)", name, yyvsp[0].code);
          yyval.code = gen_code(temp);
      }
#line 1456 "trad1.tab.c"
    break;

  case 23: /* for_update: INC '(' IDENTIF ')'  */
#line 183 "trad1.y"
      {
          char *name = translated_name(yyvsp[-1].code);
          sprintf(temp, "(setf %s (+ %s 1))", name, name);
          yyval.code = gen_code(temp);
      }
#line 1466 "trad1.tab.c"
    break;

  case 24: /* for_update: DEC '(' IDENTIF ')'  */
#line 189 "trad1.y"
      {
          char *name = translated_name(yyvsp[-1].code);
          sprintf(temp, "(setf %s (- %s 1))", name, name);
          yyval.code = gen_code(temp);
      }
#line 1476 "trad1.tab.c"
    break;

  case 25: /* declaration: INTEGER decl_list  */
#line 196 "trad1.y"
                                             { yyval = yyvsp[0] ; }
#line 1482 "trad1.tab.c"
    break;

  case 26: /* decl_list: decl_item  */
#line 199 "trad1.y"
                                             { yyval = yyvsp[0] ; }
#line 1488 "trad1.tab.c"
    break;

  case 27: /* decl_list: decl_list ',' decl_item  */
#line 200 "trad1.y"
                                             { sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1495 "trad1.tab.c"
    break;

  case 28: /* decl_item: IDENTIF  */
#line 206 "trad1.y"
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
#line 1512 "trad1.tab.c"
    break;

  case 29: /* decl_item: IDENTIF '=' NUMBER  */
#line 219 "trad1.y"
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
#line 1529 "trad1.tab.c"
    break;

  case 30: /* sentence: IDENTIF '=' expression  */
#line 235 "trad1.y"
      {
          char *name = translated_name(yyvsp[-2].code);
          sprintf(temp, "(setf %s %s)", name, yyvsp[0].code);
          yyval.code = gen_code(temp);
      }
#line 1539 "trad1.tab.c"
    break;

  case 31: /* sentence: PRINTF '(' STRING ',' arg_list ')'  */
#line 240 "trad1.y"
                                            { yyval.code = yyvsp[-1].code ; }
#line 1545 "trad1.tab.c"
    break;

  case 32: /* sentence: PUTS '(' STRING ')'  */
#line 241 "trad1.y"
                                            { sprintf (temp, "(print \"%s\")", yyvsp[-1].code) ;  
                                              yyval.code = gen_code (temp) ; }
#line 1552 "trad1.tab.c"
    break;

  case 33: /* arg_list: arg  */
#line 245 "trad1.y"
                                            {sprintf (temp, "(princ %s)", yyvsp[0].code) ; 
                                               yyval.code = gen_code (temp) ;}
#line 1559 "trad1.tab.c"
    break;

  case 34: /* arg_list: arg_list ',' arg  */
#line 247 "trad1.y"
                                            {sprintf (temp, "%s\n(princ %s)", yyvsp[-2].code, yyvsp[0].code) ; 
                                               yyval.code = gen_code (temp) ;}
#line 1566 "trad1.tab.c"
    break;

  case 35: /* arg: expression  */
#line 251 "trad1.y"
                                            {yyval = yyvsp[0] ; }
#line 1572 "trad1.tab.c"
    break;

  case 36: /* arg: STRING  */
#line 252 "trad1.y"
                                            {sprintf (temp, "\"%s\"", yyvsp[0].code) ; 
                                               yyval.code = gen_code (temp) ;}
#line 1579 "trad1.tab.c"
    break;

  case 37: /* expression: term  */
#line 256 "trad1.y"
                                             { yyval = yyvsp[0] ; }
#line 1585 "trad1.tab.c"
    break;

  case 38: /* expression: expression '+' expression  */
#line 257 "trad1.y"
                                             { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1592 "trad1.tab.c"
    break;

  case 39: /* expression: expression '-' expression  */
#line 259 "trad1.y"
                                             { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1599 "trad1.tab.c"
    break;

  case 40: /* expression: expression '*' expression  */
#line 261 "trad1.y"
                                             { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1606 "trad1.tab.c"
    break;

  case 41: /* expression: expression '/' expression  */
#line 263 "trad1.y"
                                             { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1613 "trad1.tab.c"
    break;

  case 42: /* expression: expression '%' expression  */
#line 265 "trad1.y"
                                             { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1620 "trad1.tab.c"
    break;

  case 43: /* expression: expression '^' expression  */
#line 267 "trad1.y"
                                             { sprintf (temp, "(expt %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1627 "trad1.tab.c"
    break;

  case 44: /* expression: expression AND expression  */
#line 269 "trad1.y"
                                             { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1634 "trad1.tab.c"
    break;

  case 45: /* expression: expression OR expression  */
#line 271 "trad1.y"
                                             { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1641 "trad1.tab.c"
    break;

  case 46: /* expression: NOT expression  */
#line 273 "trad1.y"
                                             { sprintf (temp, "(! %s)", yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1648 "trad1.tab.c"
    break;

  case 47: /* expression: expression EQ expression  */
#line 275 "trad1.y"
                                             { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1655 "trad1.tab.c"
    break;

  case 48: /* expression: expression NE expression  */
#line 277 "trad1.y"
                                             { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1662 "trad1.tab.c"
    break;

  case 49: /* expression: expression '<' expression  */
#line 279 "trad1.y"
                                             { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1669 "trad1.tab.c"
    break;

  case 50: /* expression: expression LE expression  */
#line 281 "trad1.y"
                                             { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1676 "trad1.tab.c"
    break;

  case 51: /* expression: expression '>' expression  */
#line 283 "trad1.y"
                                             { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1683 "trad1.tab.c"
    break;

  case 52: /* expression: expression GE expression  */
#line 285 "trad1.y"
                                             { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1690 "trad1.tab.c"
    break;

  case 53: /* term: operand  */
#line 289 "trad1.y"
                                             { yyval = yyvsp[0] ; }
#line 1696 "trad1.tab.c"
    break;

  case 54: /* term: '+' operand  */
#line 290 "trad1.y"
                                             { yyval = yyvsp[-1] ; }
#line 1702 "trad1.tab.c"
    break;

  case 55: /* term: '-' operand  */
#line 291 "trad1.y"
                                             { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                               yyval.code = gen_code (temp) ; }
#line 1709 "trad1.tab.c"
    break;

  case 56: /* operand: IDENTIF  */
#line 297 "trad1.y"
      {
          char *name = translated_name(yyvsp[0].code);
          sprintf(temp, "%s", name);
          yyval.code = gen_code(temp);
      }
#line 1719 "trad1.tab.c"
    break;

  case 57: /* operand: NUMBER  */
#line 303 "trad1.y"
      {
          sprintf(temp, "%d", yyvsp[0].value);
          yyval.code = gen_code(temp);
      }
#line 1728 "trad1.tab.c"
    break;

  case 58: /* operand: '(' expression ')'  */
#line 308 "trad1.y"
      {
          yyval = yyvsp[-1];
      }
#line 1736 "trad1.tab.c"
    break;


#line 1740 "trad1.tab.c"

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

#line 314 "trad1.y"
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
    "!=",          NOT,
    "==",          EQ,
    "!=",          NE,
    "<=",          LE,
    ">=",          GE,
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
    char expandable_ops [] =  "!<=>|%&/+-*^" ;
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

char *add_local_var(char *name)
{
    t_localvar *p = (t_localvar *) my_malloc(sizeof(t_localvar));
    p->name = gen_code(name);
    p->next = local_vars;
    local_vars = p;
    return p->name;
}

int is_local_var(char *name)
{
    t_localvar *p = local_vars;
    while (p != NULL) {
        if (strcmp(p->name, name) == 0) return 1;
        p = p->next;
    }
    return 0;
}

char *translated_name(char *name)
{
    if (is_local_var(name)) {
        sprintf(temp, "%s_%s", current_function, name);
        return gen_code(temp);
    }
    return gen_code(name);
}

int main ()
{
    yyparse () ;
}
