
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include "symbol_table.h"  // Include the symbol table header
    #include "quadruple.h"
    #include "utils/label_stack.h"

    void yyerror(const char *s);
    int yylex(void);
    extern FILE *yyin;
    LabelStack *labelStack;
    char *currentSwitchVar;
    char* nextLabel;
    char* endLabel;


/* Line 189 of yacc.c  */
#line 92 "Parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     POW = 258,
     NOT = 259,
     OR = 260,
     AND = 261,
     EQ = 262,
     NE = 263,
     LT = 264,
     LE = 265,
     GT = 266,
     GE = 267,
     ASSIGN = 268,
     LPAREN = 269,
     RPAREN = 270,
     LBRACE = 271,
     RBRACE = 272,
     SEMICOLON = 273,
     COLON = 274,
     FOR = 275,
     WHILE = 276,
     REPEAT = 277,
     UNTIL = 278,
     IF = 279,
     ELSE = 280,
     SWITCH = 281,
     CASE = 282,
     BREAK = 283,
     DEFAULT = 284,
     SUB = 285,
     ADD = 286,
     DIV = 287,
     MUL = 288,
     INT_TYPE = 289,
     FLOAT_TYPE = 290,
     CHAR_TYPE = 291,
     VOID_TYPE = 292,
     CONST = 293,
     RETURN = 294,
     COMMA = 295,
     ERROR = 296,
     INTEGER = 297,
     FLOAT = 298,
     CHAR = 299,
     ID = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 19 "Parser.y"

    int i;
    char c;
    float f;
    char *s;  
    char *Dtype;
    SymbolTableEntry *symbolTableEntry;



/* Line 214 of yacc.c  */
#line 184 "Parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 196 "Parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   358

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    11,    12,    18,    20,
      22,    24,    26,    28,    30,    32,    34,    36,    39,    43,
      48,    50,    52,    54,    55,    64,    66,    69,    71,    73,
      76,    77,    78,    87,    88,    95,    96,   109,   110,   119,
     120,   121,   133,   134,   143,   148,   152,   156,   160,   162,
     166,   170,   174,   178,   182,   186,   188,   192,   196,   198,
     202,   206,   208,   212,   214,   218,   221,   224,   226,   228,
     230
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    47,    51,    -1,    51,    -1,    41,    -1,
      -1,    -1,    16,    49,    47,    17,    50,    -1,    71,    -1,
      55,    -1,    48,    -1,    64,    -1,    66,    -1,    68,    -1,
      52,    -1,    53,    -1,    73,    -1,    75,    18,    -1,    54,
      45,    18,    -1,    38,    54,    45,    18,    -1,    34,    -1,
      35,    -1,    36,    -1,    -1,    26,    14,    45,    15,    16,
      56,    57,    17,    -1,    58,    -1,    58,    62,    -1,    62,
      -1,    59,    -1,    58,    59,    -1,    -1,    -1,    27,    42,
      19,    60,    47,    61,    28,    18,    -1,    -1,    29,    19,
      63,    47,    28,    18,    -1,    -1,    20,    14,    74,    18,
      75,    18,    74,    15,    16,    65,    47,    17,    -1,    -1,
      21,    14,    75,    15,    16,    67,    47,    17,    -1,    -1,
      -1,    22,    16,    69,    47,    17,    23,    14,    75,    70,
      15,    18,    -1,    -1,    24,    14,    75,    15,    16,    72,
      51,    17,    -1,    45,    13,    75,    18,    -1,    45,    13,
      75,    -1,    76,     5,    75,    -1,    76,     6,    75,    -1,
      76,    -1,    77,     7,    77,    -1,    77,     8,    77,    -1,
      77,     9,    77,    -1,    77,    10,    77,    -1,    77,    11,
      77,    -1,    77,    12,    77,    -1,    77,    -1,    77,    31,
      78,    -1,    77,    30,    78,    -1,    78,    -1,    78,    33,
      79,    -1,    78,    32,    79,    -1,    79,    -1,    80,     3,
      79,    -1,    80,    -1,    14,    75,    15,    -1,    30,    80,
      -1,     4,    80,    -1,    42,    -1,    43,    -1,    44,    -1,
      45,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    57,    58,    61,    64,    61,    76,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    94,   103,
     150,   151,   152,   160,   159,   175,   176,   177,   180,   181,
     185,   197,   184,   217,   216,   272,   270,   306,   305,   336,
     347,   335,   400,   399,   425,   441,   459,   460,   461,   464,
     465,   466,   467,   468,   469,   470,   473,   478,   483,   486,
     487,   498,   501,   502,   505,   510,   515,   520,   525,   530,
     535
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "POW", "NOT", "OR", "AND", "EQ", "NE",
  "LT", "LE", "GT", "GE", "ASSIGN", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "SEMICOLON", "COLON", "FOR", "WHILE", "REPEAT", "UNTIL", "IF", "ELSE",
  "SWITCH", "CASE", "BREAK", "DEFAULT", "SUB", "ADD", "DIV", "MUL",
  "INT_TYPE", "FLOAT_TYPE", "CHAR_TYPE", "VOID_TYPE", "CONST", "RETURN",
  "COMMA", "ERROR", "INTEGER", "FLOAT", "CHAR", "ID", "$accept", "STMTS",
  "BLOCK", "$@1", "$@2", "STMT", "DECLARATION", "CONST_DECLARATION",
  "PARAM_TYPE", "SWITCH_BLOCK", "$@3", "SWITCH_CASE", "CASE_STMTS",
  "CASE_STMT", "$@4", "$@5", "DEFAULT_STMT", "$@6", "FOR_LOOP", "$@7",
  "WHILE_LOOP", "$@8", "REPEAT_UNTIL_LOOP", "$@9", "$@10", "UNMATCHED_IF",
  "$@11", "ASSIGNMENT", "ASSIGNMENT_FORLOOP", "LOGICAL_EXP", "REL_EXP",
  "EXP", "TERM", "POWER", "FACTOR", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    47,    49,    50,    48,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    53,
      54,    54,    54,    56,    55,    57,    57,    57,    58,    58,
      60,    61,    59,    63,    62,    65,    64,    67,    66,    69,
      70,    68,    72,    71,    73,    74,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    77,    78,
      78,    78,    79,    79,    80,    80,    80,    80,    80,    80,
      80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     0,     0,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     4,
       1,     1,     1,     0,     8,     1,     2,     1,     1,     2,
       0,     0,     8,     0,     6,     0,    12,     0,     8,     0,
       0,    11,     0,     8,     4,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     2,     2,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
      20,    21,    22,     0,     4,    67,    68,    69,    70,     0,
      10,     3,    14,    15,     0,     9,    11,    12,    13,     8,
      16,     0,    48,    55,    58,    61,    63,    70,    66,     0,
       0,     0,     0,    39,     0,     0,    65,     0,     0,     1,
       2,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    46,    47,    49,
      50,    51,    52,    53,    54,    57,    56,    60,    59,    62,
       6,     0,     0,     0,     0,     0,     0,    19,    44,     7,
      45,     0,    37,     0,    42,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    28,
      27,     0,    38,    40,    43,     0,    33,    24,    29,    26,
      35,     0,    30,     0,     0,     0,     0,     0,     0,    41,
      31,     0,    36,     0,    34,     0,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    40,    99,    21,    22,    23,    24,    25,
     110,   117,   118,   119,   136,   143,   120,   133,    26,   134,
      27,   107,    28,    71,   131,    29,   109,    30,    69,    31,
      32,    33,    34,    35,    36
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -43
static const yytype_int16 yypact[] =
{
     106,   313,   313,   -43,    17,    23,   -15,    27,    29,   313,
     -43,   -43,   -43,   -13,   -43,   -43,   -43,   -43,     6,    38,
     -43,   -43,   -43,   -43,     1,   -43,   -43,   -43,   -43,   -43,
     -43,    26,    22,    -1,     0,   -43,    46,   -43,   -43,    35,
     106,     8,   313,   -43,   313,    10,   -43,    16,   313,   -43,
     -43,    45,   -43,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   -43,   139,    52,    48,
      54,   106,    56,    62,    49,    60,   -43,   -43,   -43,     5,
       5,     5,     5,     5,     5,     0,     0,   -43,   -43,   -43,
     -43,   313,   313,    63,   172,    68,    69,   -43,   -43,   -43,
     -43,    70,   -43,    64,   -43,   -43,     8,   106,    72,   304,
     -25,    74,   205,   313,    75,    58,    79,    84,   -25,   -43,
     -43,    86,   -43,   -43,   -43,    85,   -43,   -43,   -43,   -43,
     -43,    76,   -43,   106,   106,    87,   106,   238,   271,   -43,
     304,    88,   -43,    80,   -43,    89,   -43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -37,   -43,   -43,   -43,   -19,   -43,   -43,    90,   -43,
     -43,   -43,   -43,    -9,   -43,   -43,    -7,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,     7,     3,
     -43,   -42,   -22,   -39,    11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      50,    43,   115,    67,   116,    39,    55,    56,    57,    58,
      59,    60,    38,    79,    80,    81,    82,    83,    84,    48,
      46,    10,    11,    12,    87,    88,    89,    53,    54,    61,
      62,    41,    63,    64,    94,    61,    62,    42,    49,    85,
      86,    44,     1,    45,    52,    70,    51,    72,    50,    65,
      66,    75,     2,    68,     3,    73,    77,    78,     4,     5,
       6,    74,     7,    76,     8,    91,    92,    97,     9,    93,
     112,    95,    10,    11,    12,    50,    13,    96,    98,   102,
      15,    16,    17,    18,   104,   105,   113,   108,   106,   121,
     114,   135,   124,    50,   100,   101,   137,   138,   126,   140,
     125,   127,   130,    47,   132,   139,   144,   146,   145,   128,
       1,   129,     0,   111,     0,     0,   123,     0,    50,    50,
       2,    50,     3,     0,     0,     0,     4,     5,     6,     0,
       7,     0,     8,     0,     0,     0,     9,     0,     0,     0,
      10,    11,    12,     1,    13,     0,     0,    14,    15,    16,
      17,    18,     0,     2,     0,     3,    90,     0,     0,     4,
       5,     6,     0,     7,     0,     8,     0,     0,     0,     9,
       0,     0,     0,    10,    11,    12,     1,    13,     0,     0,
       0,    15,    16,    17,    18,     0,     2,     0,     3,   103,
       0,     0,     4,     5,     6,     0,     7,     0,     8,     0,
       0,     0,     9,     0,     0,     0,    10,    11,    12,     1,
      13,     0,     0,     0,    15,    16,    17,    18,     0,     2,
       0,     3,   122,     0,     0,     4,     5,     6,     0,     7,
       0,     8,     0,     0,     0,     9,     0,     0,     0,    10,
      11,    12,     1,    13,     0,     0,     0,    15,    16,    17,
      18,     0,     2,     0,     3,     0,     0,     0,     4,     5,
       6,     0,     7,     0,     8,     0,   141,     0,     9,     0,
       0,     0,    10,    11,    12,     1,    13,     0,     0,     0,
      15,    16,    17,    18,     0,     2,     0,     3,   142,     0,
       0,     4,     5,     6,     0,     7,     0,     8,     0,     0,
       0,     9,     0,     0,     0,    10,    11,    12,     1,    13,
       0,     0,     0,    15,    16,    17,    18,     1,     2,     0,
       3,     0,     0,     0,     4,     5,     6,     2,     7,     0,
       8,     0,     0,     0,     9,     0,     0,     0,    10,    11,
      12,     0,    13,     9,     0,     0,    15,    16,    17,    18,
       0,     0,     0,     0,     0,    15,    16,    17,    37
};

static const yytype_int16 yycheck[] =
{
      19,    16,    27,    40,    29,     2,     7,     8,     9,    10,
      11,    12,     1,    55,    56,    57,    58,    59,    60,    13,
       9,    34,    35,    36,    63,    64,    65,     5,     6,    30,
      31,    14,    32,    33,    71,    30,    31,    14,     0,    61,
      62,    14,     4,    14,    18,    42,    45,    44,    67,     3,
      15,    48,    14,    45,    16,    45,    53,    54,    20,    21,
      22,    45,    24,    18,    26,    13,    18,    18,    30,    15,
     107,    15,    34,    35,    36,    94,    38,    15,    18,    16,
      42,    43,    44,    45,    16,    16,    14,    23,    18,    15,
     109,    15,    17,   112,    91,    92,   133,   134,    19,   136,
      42,    17,    16,    13,    19,    18,    18,    18,    28,   118,
       4,   118,    -1,   106,    -1,    -1,   113,    -1,   137,   138,
      14,   140,    16,    -1,    -1,    -1,    20,    21,    22,    -1,
      24,    -1,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    36,     4,    38,    -1,    -1,    41,    42,    43,
      44,    45,    -1,    14,    -1,    16,    17,    -1,    -1,    20,
      21,    22,    -1,    24,    -1,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    34,    35,    36,     4,    38,    -1,    -1,
      -1,    42,    43,    44,    45,    -1,    14,    -1,    16,    17,
      -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    36,     4,
      38,    -1,    -1,    -1,    42,    43,    44,    45,    -1,    14,
      -1,    16,    17,    -1,    -1,    20,    21,    22,    -1,    24,
      -1,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    36,     4,    38,    -1,    -1,    -1,    42,    43,    44,
      45,    -1,    14,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    -1,    24,    -1,    26,    -1,    28,    -1,    30,    -1,
      -1,    -1,    34,    35,    36,     4,    38,    -1,    -1,    -1,
      42,    43,    44,    45,    -1,    14,    -1,    16,    17,    -1,
      -1,    20,    21,    22,    -1,    24,    -1,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    36,     4,    38,
      -1,    -1,    -1,    42,    43,    44,    45,     4,    14,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    14,    24,    -1,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      36,    -1,    38,    30,    -1,    -1,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    14,    16,    20,    21,    22,    24,    26,    30,
      34,    35,    36,    38,    41,    42,    43,    44,    45,    47,
      48,    51,    52,    53,    54,    55,    64,    66,    68,    71,
      73,    75,    76,    77,    78,    79,    80,    45,    80,    75,
      49,    14,    14,    16,    14,    14,    80,    54,    13,     0,
      51,    45,    18,     5,     6,     7,     8,     9,    10,    11,
      12,    30,    31,    32,    33,     3,    15,    47,    45,    74,
      75,    69,    75,    45,    45,    75,    18,    75,    75,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79,    79,
      17,    13,    18,    15,    47,    15,    15,    18,    18,    50,
      75,    75,    16,    17,    16,    16,    18,    67,    23,    72,
      56,    74,    47,    14,    51,    27,    29,    57,    58,    59,
      62,    15,    17,    75,    17,    42,    19,    17,    59,    62,
      16,    70,    19,    63,    65,    15,    60,    47,    47,    18,
      47,    28,    17,    61,    18,    28,    18
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 56 "Parser.y"
    { /* Handle multiple statements */ ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 57 "Parser.y"
    { /* Handle a single statement */ ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 58 "Parser.y"
    { fprintf(stderr, "Syntax error: Skipping invalid statement.\n"); yyerrok; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 61 "Parser.y"
    {
           enterScope();  // Enter a new scope
       ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 64 "Parser.y"
    {
           exitScope();   // Exit the current scope
       ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 67 "Parser.y"
    {
           printf("Block parsed\n");
       ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 94 "Parser.y"
    {
                if (lookupSymbol((yyvsp[(2) - (3)].s)) && isSymbolDeclaredInCurrentScope((yyvsp[(2) - (3)].s))) {
                    yyerror("Variable already declared in this scope");
                } else {
                    addSymbol((yyvsp[(2) - (3)].s), (yyvsp[(1) - (3)].Dtype), false);  // Add variable to current scope
                }
            ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 103 "Parser.y"
    {
                if (lookupSymbol((yyvsp[(3) - (4)].s)) && isSymbolDeclaredInCurrentScope((yyvsp[(3) - (4)].s))) {
                    yyerror("Variable already declared in this scope");
                } else {
                    addSymbol((yyvsp[(3) - (4)].s), (yyvsp[(2) - (4)].Dtype), true);  // Add variable to current scope
                }
            ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 150 "Parser.y"
    { (yyval.Dtype) = "int"; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 151 "Parser.y"
    { (yyval.Dtype) = "float"; ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 152 "Parser.y"
    { (yyval.Dtype) = "char"; ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 160 "Parser.y"
    { 
                enterScope(); 
                currentSwitchVar = (yyvsp[(3) - (5)].s);
                addSymbol((yyvsp[(3) - (5)].s), "int", false);
                endLabel = newLabel();
            ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 167 "Parser.y"
    {
                exitScope();
                currentSwitchVar = NULL;
                endLabel = NULL;

            ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 185 "Parser.y"
    {
    
    // if i!=1 goto label2
    
        SymbolTableEntry *switchVar = lookupSymbol(currentSwitchVar);
        SymbolTableEntry *caseVar = addSymbol((yyvsp[(2) - (3)].s), "int", false);
        SymbolTableEntry *condition = addQuadruple("EQ", switchVar, caseVar);
        nextLabel = newLabel();
        switchcaseQuadruple(condition , nextLabel ,endLabel, true,false);

    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 197 "Parser.y"
    {
     // goto endLabel
     // label2;
        switchcaseQuadruple(NULL , nextLabel ,endLabel, false,false); 
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 203 "Parser.y"
    {
                // check if integer is equal to the value of the variable
                // if not equal, jump to next case
                // if equal, execute the statements and break 
    // label1:
    // if i!=1 goto label2
    // some code
    // goto endLabel
    // label2:
                
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 217 "Parser.y"
    {
        //end label 
        
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 222 "Parser.y"
    {
        printf("Default case\n");

        switchcaseQuadruple(NULL , endLabel ,endLabel, false,false); 

    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 272 "Parser.y"
    {
            // Start a new scope for the loop
            enterScope();
            SymbolTableEntry *condition = (yyvsp[(5) - (9)].symbolTableEntry); // Assuming LOGICAL_EXP returns a SymbolTableEntry*
            Labels *labels = (Labels *)malloc(sizeof(Labels));
            labels->loopLabel = newLabel();
            labels->exitLabel = newLabel();
            addQuadrupleLabel(condition, labels->loopLabel, labels->exitLabel, true);
            pushLabelStack(&labelStack, labels);  // Push labels onto the stack
        ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 284 "Parser.y"
    {   
            Labels *labels = popLabelStack(labelStack);  // Pop labels from the stack
           
            addQuadrupleLabel(NULL, labels->loopLabel, labels->exitLabel, false);
            free(labels);
            exitScope();
        ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 306 "Parser.y"
    {
            // Start a new scope for the loop
            enterScope();
            SymbolTableEntry *condition = (yyvsp[(3) - (5)].symbolTableEntry); // Assuming LOGICAL_EXP returns a SymbolTableEntry*
            Labels *labels = (Labels *)malloc(sizeof(Labels));
            labels->loopLabel = newLabel();
            labels->exitLabel = newLabel();
            addQuadrupleLabel(condition, labels->loopLabel, labels->exitLabel, true);
            pushLabelStack(&labelStack, labels);  // Push labels onto the stack
        ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 317 "Parser.y"
    {   
            Labels *labels = popLabelStack(labelStack);  // Pop labels from the stack
           
            addQuadrupleLabel(NULL, labels->loopLabel, labels->exitLabel, false);
            free(labels);
            exitScope();
        ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 336 "Parser.y"
    {
    enterScope();
    Labels *labels = (Labels *)malloc(sizeof(Labels));
    labels->loopLabel = newLabel();
    
    pushLabelStack(&labelStack, labels);  // Push labels onto the stack
    addQuadrupleLabel(NULL, labels->loopLabel, NULL, true);

;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 347 "Parser.y"
    {
    SymbolTableEntry *condition = (yyvsp[(8) - (8)].symbolTableEntry);
    Labels *labels = popLabelStack(labelStack);  // Pop labels from the stack
    addQuadrupleLabel(condition, labels->loopLabel, NULL, false);
    free(labels);
    exitScope();

;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 400 "Parser.y"
    {
        // Start a new scope for the if block
        enterScope();
        SymbolTableEntry *condition = (yyvsp[(3) - (5)].symbolTableEntry); // Assuming LOGICAL_EXP returns a SymbolTableEntry*
        Labels *labels = (Labels *)malloc(sizeof(Labels));
        labels->loopLabel = newLabel();
        labels->exitLabel = newLabel();
        unmatchedIfQuadruple(condition, labels->loopLabel, labels->exitLabel, true);
        pushLabelStack(&labelStack, labels);  // Push labels onto the stack

    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 411 "Parser.y"
    {
        Labels *labels = popLabelStack(labelStack);  // Pop labels from the stack
        unmatchedIfQuadruple(NULL, labels->loopLabel, labels->exitLabel, false);
        free(labels);
        exitScope();
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 426 "Parser.y"
    { 
        // Assign the value of EXP to the variable ID
        // assign_var($1, $3); 
        SymbolTableEntry *entry = lookupSymbol((yyvsp[(1) - (4)].s));
        if (!entry) {
            yyerror("Variable not declared in any scope");
        } else {
            SymbolTableEntry *temp = addQuadruple("ASSIGN", entry, (yyvsp[(3) - (4)].symbolTableEntry));
            updateSymbolValue((yyvsp[(1) - (4)].s), ((yyvsp[(3) - (4)].symbolTableEntry))->value);
            entry->isInitialized = 1;  // Mark the variable as initialized
        }
        (yyval.symbolTableEntry) = (yyvsp[(3) - (4)].symbolTableEntry);
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 442 "Parser.y"
    { 
        // Assign the value of EXP to the variable ID
        // assign_var($1, $3); 
        SymbolTableEntry *entry = lookupSymbol((yyvsp[(1) - (3)].s));
        if (!entry) {
            yyerror("Variable not declared in any scope");
        } else {
            SymbolTableEntry *temp = addQuadruple("ASSIGN", entry, (yyvsp[(3) - (3)].symbolTableEntry));
            updateSymbolValue((yyvsp[(1) - (3)].s), ((yyvsp[(3) - (3)].symbolTableEntry))->value);
            entry->isInitialized = 1;  // Mark the variable as initialized
        }
        (yyval.symbolTableEntry) = (yyvsp[(3) - (3)].symbolTableEntry);
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 459 "Parser.y"
    { (yyval.symbolTableEntry) = addQuadruple("OR", (yyvsp[(1) - (3)].symbolTableEntry), (yyvsp[(3) - (3)].symbolTableEntry)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 460 "Parser.y"
    { (yyval.symbolTableEntry) = addQuadruple("AND", (yyvsp[(1) - (3)].symbolTableEntry), (yyvsp[(3) - (3)].symbolTableEntry)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 461 "Parser.y"
    { (yyval.symbolTableEntry) = (yyvsp[(1) - (1)].symbolTableEntry);  ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 464 "Parser.y"
    { (yyval.symbolTableEntry) = addQuadruple("EQ", (yyvsp[(1) - (3)].symbolTableEntry), (yyvsp[(3) - (3)].symbolTableEntry)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 465 "Parser.y"
    { (yyval.symbolTableEntry) = addQuadruple("NE", (yyvsp[(1) - (3)].symbolTableEntry), (yyvsp[(3) - (3)].symbolTableEntry)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 466 "Parser.y"
    { (yyval.symbolTableEntry) = addQuadruple("LT", (yyvsp[(1) - (3)].symbolTableEntry), (yyvsp[(3) - (3)].symbolTableEntry)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 467 "Parser.y"
    { (yyval.symbolTableEntry) = addQuadruple("LE", (yyvsp[(1) - (3)].symbolTableEntry), (yyvsp[(3) - (3)].symbolTableEntry)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 468 "Parser.y"
    { (yyval.symbolTableEntry) = addQuadruple("GT", (yyvsp[(1) - (3)].symbolTableEntry), (yyvsp[(3) - (3)].symbolTableEntry)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 469 "Parser.y"
    { (yyval.symbolTableEntry) = addQuadruple("GE", (yyvsp[(1) - (3)].symbolTableEntry), (yyvsp[(3) - (3)].symbolTableEntry)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 470 "Parser.y"
    { (yyval.symbolTableEntry) = (yyvsp[(1) - (1)].symbolTableEntry); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 474 "Parser.y"
    {
        (yyval.symbolTableEntry) = addQuadruple("ADD", (yyvsp[(1) - (3)].symbolTableEntry), (yyvsp[(3) - (3)].symbolTableEntry));
        printf("Adding %s and %s\n", ((yyvsp[(1) - (3)].symbolTableEntry))->name, ((yyvsp[(3) - (3)].symbolTableEntry))->name);
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 479 "Parser.y"
    {
        (yyval.symbolTableEntry) = addQuadruple("SUB", (yyvsp[(1) - (3)].symbolTableEntry), (yyvsp[(3) - (3)].symbolTableEntry));
        printf("Subtracting %s from %s\n", ((yyvsp[(3) - (3)].symbolTableEntry))->name, ((yyvsp[(1) - (3)].symbolTableEntry))->name);
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 483 "Parser.y"
    { (yyval.symbolTableEntry) = (yyvsp[(1) - (1)].symbolTableEntry); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 486 "Parser.y"
    { (yyval.symbolTableEntry) = addQuadruple("MUL", (yyvsp[(1) - (3)].symbolTableEntry), (yyvsp[(3) - (3)].symbolTableEntry)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 488 "Parser.y"
    { 
         if (strcmp(((yyvsp[(3) - (3)].symbolTableEntry))->name, "0") == 0) { 
            yyerror("Division by zero"); 
            exit(1); 
         } else {
            (yyval.symbolTableEntry) = addQuadruple("DIV", (yyvsp[(1) - (3)].symbolTableEntry), (yyvsp[(3) - (3)].symbolTableEntry));
            printf("Dividing %s by %s\n", ((yyvsp[(1) - (3)].symbolTableEntry))->name, ((yyvsp[(3) - (3)].symbolTableEntry))->name);
         }
     ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 498 "Parser.y"
    { (yyval.symbolTableEntry) = (yyvsp[(1) - (1)].symbolTableEntry); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 501 "Parser.y"
    { (yyval.symbolTableEntry) = addQuadruple("POW", (yyvsp[(1) - (3)].symbolTableEntry), (yyvsp[(3) - (3)].symbolTableEntry)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 502 "Parser.y"
    { (yyval.symbolTableEntry) = (yyvsp[(1) - (1)].symbolTableEntry); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 506 "Parser.y"
    { 
            (yyval.symbolTableEntry) = (yyvsp[(2) - (3)].symbolTableEntry); 
            printf("Logical expression evaluated.\n"); 
        ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 511 "Parser.y"
    { 
            (yyval.symbolTableEntry) = addQuadruple("NEG", (yyvsp[(2) - (2)].symbolTableEntry), NULL);
            printf("Negation applied: %f\n", (yyval.symbolTableEntry)); 
        ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 516 "Parser.y"
    { 
            (yyval.symbolTableEntry) = addQuadruple("NOT", (yyvsp[(2) - (2)].symbolTableEntry), NULL);
            printf("Logical NOT applied: %d\n", (yyval.symbolTableEntry)); 
        ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 521 "Parser.y"
    { 
            (yyval.symbolTableEntry) = addSymbol((yyvsp[(1) - (1)].s), "int", false);
            printf("Integer constant: %s\n", (yyvsp[(1) - (1)].s)); 
        ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 526 "Parser.y"
    { 
            (yyval.symbolTableEntry) = addSymbol((yyvsp[(1) - (1)].s), "float", false);
            printf("Float constant: %s\n", (yyvsp[(1) - (1)].s));
        ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 531 "Parser.y"
    { 
            (yyval.symbolTableEntry) = addSymbol((yyvsp[(1) - (1)].s), "char", false);
            printf("Character constant: %s\n", (yyvsp[(1) - (1)].s));
        ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 536 "Parser.y"
    { 
            // Look up the variable in the symbol table
            SymbolTableEntry *entry = lookupSymbol((yyvsp[(1) - (1)].s));
            if (!entry) {
                yyerror("Variable not declared in any scope");
            } else {
                if (!entry->isInitialized) {
                    yyerror("Variable used before initialization");
                }
                entry->isUsed = 1;  // Mark the variable as used
                (yyval.symbolTableEntry) = lookupSymbol((yyvsp[(1) - (1)].s));  // Retrieve its runtime value
                printf("Variable '%s' of type '%s' used. Value: %f\n", (yyvsp[(1) - (1)].s), entry->type, (yyval.symbolTableEntry));
            }
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 2121 "Parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 553 "Parser.y"
 

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(int argc, char **argv) {

     // Clear the contents of quadruples.txt
    FILE *quadFile = fopen("quadruples.txt", "w");
    if (quadFile == NULL) {
        fprintf(stderr, "Error opening quadruples.txt for writing!\n");
        return 1;
    }
    fclose(quadFile);
    
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror(argv[1]);
            return 1;
        }
    } 
  
    if (yyparse() == 0) {
        printf("Parsing successful\n");
        printQuadruples();
    } else {
        printf("Parsing failed\n");
    }
    return 0;
}

