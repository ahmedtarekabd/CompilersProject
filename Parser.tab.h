
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 14 "Parser.y"

    int i;
    char c;
    float f;
    char *s;  
    char *Dtype;
    SymbolTableEntry *symbolTableEntry;



/* Line 1676 of yacc.c  */
#line 108 "Parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


