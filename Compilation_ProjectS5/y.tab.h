/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROG = 258,
    DEBUT = 259,
    FIN = 260,
    POINT = 261,
    POINT_VIRGULE = 262,
    DEUX_POINTS = 263,
    VIRGULE = 264,
    GUILLEMET = 265,
    TYPE = 266,
    IDF = 267,
    STRUCT = 268,
    FSTRUCT = 269,
    TABLEAU = 270,
    DE = 271,
    CROCHET_OUVRANT = 272,
    CROCHET_FERMANT = 273,
    PARENTHESE_OUVRANTE = 274,
    PARENTHESE_FERMANTE = 275,
    FLECHE = 276,
    FLECHE_FONC = 277,
    ENTIER = 278,
    REEL = 279,
    BOOLEEN = 280,
    CARACTERE = 281,
    CHAINE = 282,
    CSTE_ENTIERE = 283,
    CSTE_REELLE = 284,
    CSTE_BOOLEEN = 285,
    CSTE_CARACTERE = 286,
    CSTE_CHAINE = 287,
    VARIABLE = 288,
    PROCEDURE = 289,
    FONCTION = 290,
    RETOURNE = 291,
    VIDE = 292,
    SI = 293,
    ALORS = 294,
    SINON = 295,
    TANT_QUE = 296,
    FAIRE = 297,
    FINBLOC = 298,
    OPAFF = 299,
    LETTRE_FORMAT = 300,
    LIRE = 301,
    ECRIRE = 302,
    OP_NON = 303,
    ET = 304,
    OU = 305,
    OP_CMP = 306,
    PLUS = 307,
    MOINS = 308,
    DIV = 309,
    MULT = 310,
    SYMB_DEC = 311,
    SYMB_INC = 312
  };
#endif
/* Tokens.  */
#define PROG 258
#define DEBUT 259
#define FIN 260
#define POINT 261
#define POINT_VIRGULE 262
#define DEUX_POINTS 263
#define VIRGULE 264
#define GUILLEMET 265
#define TYPE 266
#define IDF 267
#define STRUCT 268
#define FSTRUCT 269
#define TABLEAU 270
#define DE 271
#define CROCHET_OUVRANT 272
#define CROCHET_FERMANT 273
#define PARENTHESE_OUVRANTE 274
#define PARENTHESE_FERMANTE 275
#define FLECHE 276
#define FLECHE_FONC 277
#define ENTIER 278
#define REEL 279
#define BOOLEEN 280
#define CARACTERE 281
#define CHAINE 282
#define CSTE_ENTIERE 283
#define CSTE_REELLE 284
#define CSTE_BOOLEEN 285
#define CSTE_CARACTERE 286
#define CSTE_CHAINE 287
#define VARIABLE 288
#define PROCEDURE 289
#define FONCTION 290
#define RETOURNE 291
#define VIDE 292
#define SI 293
#define ALORS 294
#define SINON 295
#define TANT_QUE 296
#define FAIRE 297
#define FINBLOC 298
#define OPAFF 299
#define LETTRE_FORMAT 300
#define LIRE 301
#define ECRIRE 302
#define OP_NON 303
#define ET 304
#define OU 305
#define OP_CMP 306
#define PLUS 307
#define MOINS 308
#define DIV 309
#define MULT 310
#define SYMB_DEC 311
#define SYMB_INC 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "projet.y" /* yacc.c:1909  */

    char a[100];
    float f;
    int e;
    char c;
    unsigned int b;
 

#line 177 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
