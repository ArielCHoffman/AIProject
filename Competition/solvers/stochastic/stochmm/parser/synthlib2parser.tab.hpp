/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_PARSER_SYNTHLIB2PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_SYNTHLIB2PARSER_TAB_HPP_INCLUDED
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
    TK_DEFINE_SORT = 258,
    TK_DEFINE_FUN = 259,
    TK_SET_OPTIONS = 260,
    TK_CHECK_SYNTH = 261,
    TK_SYNTH_FUN = 262,
    TK_DECLARE_VAR = 263,
    TK_LPAREN = 264,
    TK_RPAREN = 265,
    TK_SET_LOGIC = 266,
    TK_BV = 267,
    TK_INT = 268,
    TK_BOOL = 269,
    TK_ENUM = 270,
    TK_CONSTRAINT = 271,
    TK_CONSTANT = 272,
    TK_VARIABLE = 273,
    TK_ERROR = 274,
    TK_INT_LITERAL = 275,
    TK_BOOL_LITERAL = 276,
    TK_ENUM_LITERAL = 277,
    TK_BV_LITERAL = 278,
    TK_SYMBOL = 279,
    TK_QUOTED_LITERAL = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 38 "parser/synthlib2parser.y" /* yacc.c:1909  */

    // yyunion fields
    string* LexerString;
    SortExpr* TheSortExpr;
    Literal* TheLiteral;
    vector<string>* SymbolVector;
    pair<string, SortExpr*>* SymbolSortPair;
    vector<pair<string, SortExpr*> >* SymbolSortVector;
    pair<string, string>* SymbolSymbolPair;
    vector<pair<string, string> >* SymbolSymbolVector;
    Term* TheTerm;
    vector<Term*>* TermVector;
    vector<NTDef*>* NTDefVector;
    NTDef* TheNTDef;
    GTerm* TheGTerm;
    vector<GTerm*>* GTermVector;
    long IntVal;
    bool BoolVal;

#line 100 "parser/synthlib2parser.tab.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_SYNTHLIB2PARSER_TAB_HPP_INCLUDED  */
