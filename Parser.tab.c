
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
    #include "quadruple.h"  // Include the quadruple header

    void yyerror(const char *s);
    int yylex(void);
    extern FILE *yyin;
    


/* Line 189 of yacc.c  */
#line 88 "Parser.tab.c"

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
     INTEGER_VALUE = 297,
     FLOAT_VALUE = 298,
     CHAR_VALUE = 299,
     ID = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 15 "Parser.y"

    int i;
    char c;
    float f;
    char *s;  
    int type;  // Add a new member for data type



/* Line 214 of yacc.c  */
#line 179 "Parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 191 "Parser.tab.c"

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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   366

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNRULES -- Number of states.  */
#define YYNSTATES  127

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
      22,    24,    26,    28,    30,    32,    34,    37,    41,    46,
      48,    50,    52,    61,    67,    68,    71,    73,    80,    82,
      83,    95,   103,   113,   118,   122,   126,   128,   132,   136,
     140,   144,   148,   152,   154,   158,   162,   164,   168,   172,
     174,   178,   180,   184,   187,   190,   192,   194,   196
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    47,    51,    -1,    51,    -1,    41,    -1,
      -1,    -1,    16,    49,    47,    17,    50,    -1,    55,    -1,
      60,    -1,    61,    -1,    62,    -1,    48,    -1,    52,    -1,
      53,    -1,    63,    -1,    64,    18,    -1,    54,    45,    18,
      -1,    38,    54,    45,    18,    -1,    34,    -1,    35,    -1,
      36,    -1,    26,    14,    45,    15,    16,    57,    56,    17,
      -1,    29,    19,    47,    28,    18,    -1,    -1,    57,    58,
      -1,    58,    -1,    27,    42,    19,    59,    28,    18,    -1,
      47,    -1,    -1,    20,    14,    63,    18,    64,    18,    63,
      15,    16,    47,    17,    -1,    21,    14,    64,    15,    16,
      47,    17,    -1,    22,    16,    47,    17,    23,    14,    64,
      15,    18,    -1,    45,    13,    66,    18,    -1,    65,     5,
      64,    -1,    65,     6,    64,    -1,    65,    -1,    66,     7,
      66,    -1,    66,     8,    66,    -1,    66,     9,    66,    -1,
      66,    10,    66,    -1,    66,    11,    66,    -1,    66,    12,
      66,    -1,    66,    -1,    66,    31,    67,    -1,    66,    30,
      67,    -1,    67,    -1,    67,    33,    68,    -1,    67,    32,
      68,    -1,    68,    -1,    69,     3,    68,    -1,    69,    -1,
      14,    64,    15,    -1,    30,    69,    -1,     4,    69,    -1,
      42,    -1,    43,    -1,    44,    -1,    45,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    52,    53,    56,    59,    56,    73,    74,
      75,    76,    79,    80,    81,    82,    83,    86,    96,   144,
     145,   146,   153,   165,   172,   174,   175,   178,   187,   188,
     192,   200,   209,   265,   274,   279,   284,   287,   292,   297,
     302,   307,   312,   317,   320,   329,   334,   339,   344,   354,
     360,   365,   371,   379,   387,   395,   407,   419,   431
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
  "COMMA", "ERROR", "INTEGER_VALUE", "FLOAT_VALUE", "CHAR_VALUE", "ID",
  "$accept", "STMTS", "BLOCK", "$@1", "$@2", "STMT", "DECLARATION",
  "CONST_DECLARATION", "PARAM_TYPE", "SWITCH_CASE", "CASE_DEFAULT",
  "CASES", "CASE_BLOCK", "CASE_STMTS", "FOR_LOOP", "WHILE_LOOP",
  "REPEAT_UNTIL_LOOP", "ASSIGNMENT", "LOGICAL_EXP", "REL_EXP", "EXP",
  "TERM", "POWER", "FACTOR", 0
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
      51,    51,    51,    51,    51,    51,    51,    52,    53,    54,
      54,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      60,    61,    62,    63,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    66,    66,    66,    67,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     0,     0,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     1,
       1,     1,     8,     5,     0,     2,     1,     6,     1,     0,
      11,     7,     9,     4,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     2,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     0,     0,     0,     0,     0,    19,
      20,    21,     0,     4,    55,    56,    57,    58,     0,    12,
       3,    13,    14,     0,     8,     9,    10,    11,    15,     0,
      36,    43,    46,    49,    51,    58,    54,     0,     0,     0,
       0,     0,     0,    53,     0,     0,     1,     2,     0,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    34,    35,    37,    38,    39,    40,    41,
      42,    45,    44,    48,    47,    50,     6,     0,     0,     0,
       0,    18,    33,     7,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    26,     0,    31,     0,     0,     0,     0,
      25,     0,     0,    29,     0,    22,     0,    32,    28,     0,
       0,     0,     0,     0,    30,    27,    23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    18,    19,    38,    93,    20,    21,    22,    23,    24,
     109,   102,   103,   119,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -38
static const yytype_int16 yypact[] =
{
     123,    12,    12,   -38,     3,    24,    29,    26,    12,   -38,
     -38,   -38,    -3,   -38,   -38,   -38,   -38,     0,    90,   -38,
     -38,   -38,   -38,     8,   -38,   -38,   -38,   -38,   -38,    41,
      22,    -1,    11,   -38,    44,   -38,   -38,    47,   123,    20,
      12,   123,    21,   -38,    23,    12,   -38,   -38,    45,   -38,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,   -38,   156,     0,    49,    54,   189,    55,
      53,   -16,   -38,   -38,   -38,    18,    18,    18,    18,    18,
      18,    11,    11,   -38,   -38,   -38,   -38,    12,    56,    50,
      58,   -38,   -38,   -38,    57,   123,    64,    59,    20,   222,
      12,    38,    10,   -38,    67,   -38,    68,    65,    66,    70,
     -38,    73,    74,   123,   123,   -38,   123,   -38,   321,    63,
     255,   288,    75,    77,   -38,   -38,   -38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -37,   -38,   -38,   -38,   -18,   -38,   -38,    84,   -38,
     -38,   -38,    -5,   -38,   -38,   -38,   -38,   -34,     1,   -38,
     -33,     2,   -26,    17
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      47,    64,    92,    37,    68,    66,    52,    53,    54,    55,
      56,    57,    71,    45,    58,    59,     1,    39,    36,    75,
      76,    77,    78,    79,    80,    43,     2,    50,    51,    58,
      59,     9,    10,    11,    83,    84,    85,   101,    40,   108,
      42,    67,     8,    60,    61,    41,    47,    62,    58,    59,
      47,    73,    74,    48,    14,    15,    16,    35,    99,    49,
      81,    82,    63,    72,   104,    65,    69,    87,    70,    88,
      90,    91,    95,    96,    97,    98,   118,   120,   100,   121,
     107,    47,   111,   112,   113,   114,   101,   115,    94,   116,
      46,   122,   117,   125,     1,   126,    44,   110,     0,     0,
      47,   106,    47,    47,     2,     0,     3,     0,     0,     0,
       4,     5,     6,     0,     0,     0,     7,     0,     0,     0,
       8,     0,     0,     0,     9,    10,    11,     1,    12,     0,
       0,     0,    14,    15,    16,    17,     0,     2,     0,     3,
       0,     0,     0,     4,     5,     6,     0,     0,     0,     7,
       0,     0,     0,     8,     0,     0,     0,     9,    10,    11,
       1,    12,     0,     0,    13,    14,    15,    16,    17,     0,
       2,     0,     3,    86,     0,     0,     4,     5,     6,     0,
       0,     0,     7,     0,     0,     0,     8,     0,     0,     0,
       9,    10,    11,     1,    12,     0,     0,     0,    14,    15,
      16,    17,     0,     2,     0,     3,    89,     0,     0,     4,
       5,     6,     0,     0,     0,     7,     0,     0,     0,     8,
       0,     0,     0,     9,    10,    11,     1,    12,     0,     0,
       0,    14,    15,    16,    17,     0,     2,     0,     3,   105,
       0,     0,     4,     5,     6,     0,     0,     0,     7,     0,
       0,     0,     8,     0,     0,     0,     9,    10,    11,     1,
      12,     0,     0,     0,    14,    15,    16,    17,     0,     2,
       0,     3,     0,     0,     0,     4,     5,     6,     0,     0,
       0,     7,     0,   123,     0,     8,     0,     0,     0,     9,
      10,    11,     1,    12,     0,     0,     0,    14,    15,    16,
      17,     0,     2,     0,     3,   124,     0,     0,     4,     5,
       6,     0,     0,     0,     7,     0,     0,     0,     8,     0,
       0,     0,     9,    10,    11,     1,    12,     0,     0,     0,
      14,    15,    16,    17,     0,     2,     0,     3,     0,     0,
       0,     4,     5,     6,     0,     0,     0,     7,     0,     0,
       0,     8,     0,     0,     0,     9,    10,    11,     0,    12,
       0,     0,     0,    14,    15,    16,    17
};

static const yytype_int8 yycheck[] =
{
      18,    38,    18,     2,    41,    39,     7,     8,     9,    10,
      11,    12,    45,    13,    30,    31,     4,    14,     1,    52,
      53,    54,    55,    56,    57,     8,    14,     5,     6,    30,
      31,    34,    35,    36,    60,    61,    62,    27,    14,    29,
      14,    40,    30,    32,    33,    16,    64,     3,    30,    31,
      68,    50,    51,    45,    42,    43,    44,    45,    95,    18,
      58,    59,    15,    18,    98,    45,    45,    18,    45,    15,
      15,    18,    16,    23,    16,    18,   113,   114,    14,   116,
      42,    99,    15,    15,    19,    19,    27,    17,    87,    16,
       0,    28,    18,    18,     4,    18,    12,   102,    -1,    -1,
     118,   100,   120,   121,    14,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    36,     4,    38,    -1,
      -1,    -1,    42,    43,    44,    45,    -1,    14,    -1,    16,
      -1,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    36,
       4,    38,    -1,    -1,    41,    42,    43,    44,    45,    -1,
      14,    -1,    16,    17,    -1,    -1,    20,    21,    22,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    36,     4,    38,    -1,    -1,    -1,    42,    43,
      44,    45,    -1,    14,    -1,    16,    17,    -1,    -1,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    34,    35,    36,     4,    38,    -1,    -1,
      -1,    42,    43,    44,    45,    -1,    14,    -1,    16,    17,
      -1,    -1,    20,    21,    22,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    36,     4,
      38,    -1,    -1,    -1,    42,    43,    44,    45,    -1,    14,
      -1,    16,    -1,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    26,    -1,    28,    -1,    30,    -1,    -1,    -1,    34,
      35,    36,     4,    38,    -1,    -1,    -1,    42,    43,    44,
      45,    -1,    14,    -1,    16,    17,    -1,    -1,    20,    21,
      22,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    36,     4,    38,    -1,    -1,    -1,
      42,    43,    44,    45,    -1,    14,    -1,    16,    -1,    -1,
      -1,    20,    21,    22,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    36,    -1,    38,
      -1,    -1,    -1,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    14,    16,    20,    21,    22,    26,    30,    34,
      35,    36,    38,    41,    42,    43,    44,    45,    47,    48,
      51,    52,    53,    54,    55,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    45,    69,    64,    49,    14,
      14,    16,    14,    69,    54,    13,     0,    51,    45,    18,
       5,     6,     7,     8,     9,    10,    11,    12,    30,    31,
      32,    33,     3,    15,    47,    45,    63,    64,    47,    45,
      45,    66,    18,    64,    64,    66,    66,    66,    66,    66,
      66,    67,    67,    68,    68,    68,    17,    18,    15,    17,
      15,    18,    18,    50,    64,    16,    23,    16,    18,    47,
      14,    27,    57,    58,    63,    17,    64,    42,    29,    56,
      58,    15,    15,    19,    19,    17,    16,    18,    47,    59,
      47,    47,    28,    28,    17,    18,    18
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
#line 51 "Parser.y"
    { /* Handle multiple statements */ ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 52 "Parser.y"
    { /* Handle a single statement */ ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 53 "Parser.y"
    { fprintf(stderr, "Syntax error: Skipping invalid statement.\n"); yyerrok; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 56 "Parser.y"
    {
           enterScope();  // Enter a new scope
       ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 59 "Parser.y"
    {
           exitScope();   // Exit the current scope
       ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 62 "Parser.y"
    {
           printf("Block parsed\n");
       ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 83 "Parser.y"
    { printf("%d\n", (yyvsp[(1) - (2)].s)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 86 "Parser.y"
    {
                if (lookupSymbol((yyvsp[(2) - (3)].s)) && isSymbolDeclaredInCurrentScope((yyvsp[(2) - (3)].s))) {
                    yyerror("Variable already declared in this scope");
                } else {
                    Value value;
                    addSymbol((yyvsp[(2) - (3)].s), (yyvsp[(1) - (3)].type), false, value);  // Add variable to current scope
                }
            ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 96 "Parser.y"
    {
                if (lookupSymbol((yyvsp[(3) - (4)].s)) && isSymbolDeclaredInCurrentScope((yyvsp[(3) - (4)].s))) {
                    yyerror("Variable already declared in this scope");
                } else {
                    Value value;
                    addSymbol((yyvsp[(3) - (4)].s), (yyvsp[(2) - (4)].type), true, value);  // Add variable to current scope
                }
            ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 144 "Parser.y"
    { (yyval.type) = INTEGER; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 145 "Parser.y"
    { (yyval.type) = FLOAT; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 146 "Parser.y"
    { (yyval.type) = CHAR; ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 154 "Parser.y"
    {
        printf("Switch case\n");
        printf("Switch value: %f\n", (yyvsp[(3) - (8)].s));
        // switch ($3) {
        //     $6;
        //     default:
        //         $9;
        //         break;
        // }
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 166 "Parser.y"
    {
        printf("Default case\n");
        // default:
        //     $4;
        //     break;
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 179 "Parser.y"
    {
        printf("Case %d\n", (yyvsp[(2) - (6)].i));
        // case $2:
        //     $4;
        //     break;
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 193 "Parser.y"
    {
        for ((yyvsp[(3) - (11)].s); (yyvsp[(5) - (11)].s); (yyvsp[(7) - (11)].s)) {
            printf("For loop\n");
            (yyvsp[(10) - (11)].s);  
        }
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 201 "Parser.y"
    {
        while ((yyvsp[(3) - (7)].s)) {
            printf("While loop\n");
            (yyvsp[(6) - (7)].s);  
        }
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 210 "Parser.y"
    {
        do {
            printf("Repeat until loop\n");
            (yyvsp[(3) - (9)].s);  
        } while (!(yyvsp[(7) - (9)].s));
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 266 "Parser.y"
    { 
        char* id = strdup((yyvsp[(1) - (4)].s));
        addQuadruple("=", (yyvsp[(3) - (4)].s), NULL, id);
        Value value;
        updateSymbolValue((yyvsp[(1) - (4)].s), value);
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 274 "Parser.y"
    { 
                char *temp = newTemp();
                addQuadruple("OR", (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].s), temp);
                (yyval.s) = temp; 
            ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 279 "Parser.y"
    { 
                char *temp = newTemp();
                addQuadruple("AND", (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].s), temp);
                (yyval.s) = temp; 
            ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 284 "Parser.y"
    { (yyval.s) = (yyvsp[(1) - (1)].s); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 287 "Parser.y"
    { 
            char *temp = newTemp();
            addQuadruple("EQ", (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].s), temp);
            (yyval.s) = temp; 
        ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 292 "Parser.y"
    { 
            char *temp = newTemp();
            addQuadruple("NE", (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].s), temp);
            (yyval.s) = temp; 
        ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 297 "Parser.y"
    { 
            char *temp = newTemp();
            addQuadruple("LT", (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].s), temp);
            (yyval.s) = temp; 
        ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 302 "Parser.y"
    { 
            char *temp = newTemp();
            addQuadruple("LE", (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].s), temp);
            (yyval.s) = temp; 
        ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 307 "Parser.y"
    { 
            char *temp = newTemp();
            addQuadruple("GT", (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].s), temp);
            (yyval.s) = temp; 
        ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 312 "Parser.y"
    { 
            char *temp = newTemp();
            addQuadruple("GE", (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].s), temp);
            (yyval.s) = temp; 
        ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 317 "Parser.y"
    { (yyval.s) = (yyvsp[(1) - (1)].s); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 320 "Parser.y"
    { 
            printf("Adding %s + %s\n", (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].s));  // Debugging to check the operands
            char *temp1 = (yyvsp[(1) - (3)].s);  // Left operand (could be a temp)
            char *temp2 = (yyvsp[(3) - (3)].s);  // Right operand (could be another temp)
            char *resultTemp = newTemp();  // Create new temp for result
            addQuadruple("ADD", temp1, temp2, resultTemp);  // Use the correct operands
            (yyval.s) = resultTemp;  // Assign result to $$ (final result)
        ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 329 "Parser.y"
    { 
            char *temp = newTemp();
            addQuadruple("SUB", (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].s), temp);
            (yyval.s) = temp; 
        ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 334 "Parser.y"
    { (yyval.s) = (yyvsp[(1) - (1)].s); 
    printf("Term: %s\n", (yyval.s));
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 339 "Parser.y"
    { 
            char *temp = newTemp();
            addQuadruple("MUL", (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].s), temp);
            (yyval.s) = temp; 
        ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 344 "Parser.y"
    { 
            if ((yyvsp[(3) - (3)].s) == 0) { 
                yyerror("Division by zero"); 
                exit(1); 
            } else {
                char *temp = newTemp();
                addQuadruple("DIV", (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].s), temp);
                (yyval.s) = temp; 
            }
        ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 354 "Parser.y"
    { (yyval.s) = (yyvsp[(1) - (1)].s); 
     
     printf("Power: %s\n", (yyval.s));
     ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 360 "Parser.y"
    { 
            char *temp = newTemp();
            addQuadruple("POW", (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].s), temp);
            (yyval.s) = temp; 
        ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 365 "Parser.y"
    { (yyval.s) = (yyvsp[(1) - (1)].s); 
      printf("Factor: %s\n", (yyval.s));
      ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 372 "Parser.y"
    { 
            char *tempVar = newTemp();  // Generate a new temporary variable
            (yyval.s) = tempVar;  // The result of the logical expression will be stored in this temporary variable
            printf("Logical expression evaluated: %f\n", (yyval.s));
            // Add the quadruple for this logical expression
            addQuadruple("LPAREN", "Logical Expression", "", tempVar);
        ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 380 "Parser.y"
    { 
            char *tempVar = newTemp();  // Generate a new temporary variable
            (yyval.s) = tempVar;  // Store the result in a temporary variable
            printf("Negation applied: %f\n", (yyval.s));
            // Add the quadruple for negation
            addQuadruple("SUB", "0", "$2", tempVar);
        ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 388 "Parser.y"
    { 
            char *tempVar = newTemp();  // Generate a new temporary variable
            (yyval.s) = tempVar;  // Store the result in a temporary variable
            printf("Logical NOT applied: %d\n", (yyval.s));
            // Add the quadruple for logical NOT
            addQuadruple("NOT", "$2", "", tempVar);
        ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 396 "Parser.y"
    { 
            char *tempVar = newTemp();  // Generate a new temporary variable
            (yyval.s) = tempVar;  // The result of the constant will be stored in this temporary variable
            printf("Integer constant: %d\n", (yyvsp[(1) - (1)].i));
            // Add the quadruple for integer constant
            addQuadruple("CONST", "", "", tempVar);
            // Add the constant to the symbol table
            Value value;
            value.intValue = (yyvsp[(1) - (1)].i);
            addSymbol((yyval.s), INTEGER, true, value);  // Add to symbol table with constant value
        ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 408 "Parser.y"
    { 
            char *tempVar = newTemp();  // Generate a new temporary variable
            (yyval.s) = tempVar;  // The result of the constant will be stored in this temporary variable
            printf("Float constant: %f\n", (yyvsp[(1) - (1)].f));
            // Add the quadruple for float constant
            addQuadruple("CONST", "", "", tempVar);
            // Add the constant to the symbol table
            Value value;
            value.floatValue = (yyvsp[(1) - (1)].f);
            addSymbol((yyval.s), FLOAT, true, value);  // Add to symbol table with constant value
        ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 420 "Parser.y"
    { 
            char *tempVar = newTemp();  // Generate a new temporary variable
            (yyval.s) = tempVar;  // The result of the constant will be stored in this temporary variable
            printf("Character constant: '%c'\n", (yyvsp[(1) - (1)].c));
            // Add the quadruple for character constant
            addQuadruple("CONST", "", "", tempVar);
            // Add the constant to the symbol table
            Value value;
            value.charValue = (yyvsp[(1) - (1)].c);
            addSymbol((yyval.s), CHAR, true, value);  // Add to symbol table with constant value
        ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 432 "Parser.y"
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
                (yyval.s) = entry->name;  // Use the variable's name for now, may need its value later
                printf("Variable '%s' of type '%s' used. Value: %f\n", (yyvsp[(1) - (1)].s), entry->type, entry->value);
                // Add the quadruple for the variable
                addQuadruple("ID", (yyvsp[(1) - (1)].s), "", "tempVar");
            }
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 2034 "Parser.tab.c"
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
#line 454 "Parser.y"
 

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(int argc, char **argv) {
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

