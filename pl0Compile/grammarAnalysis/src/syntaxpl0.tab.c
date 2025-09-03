
/*  A Bison parser, made from syntaxpl0.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	INTEGER_VAL	257
#define	FLOAT_VAL	258
#define	CHAR_VAL	259
#define	STRING_VAL	260
#define	IDENTIFIER	261
#define	PROCEDURE	262
#define	IF	263
#define	THEN	264
#define	ELSE	265
#define	WHILE	266
#define	DO	267
#define	READ	268
#define	WRITE	269
#define	CALL	270
#define	_BEGIN_	271
#define	END	272
#define	CONST	273
#define	VAR	274
#define	ODD	275
#define	FOR	276
#define	TO	277
#define	REPEAT	278
#define	UNTIL	279
#define	ARRAY	280
#define	OF	281
#define	INT	282
#define	FLOAT	283
#define	CHAR	284
#define	STRING	285
#define	SL_PAREN	286
#define	SR_PAREN	287
#define	LEFTBRAC	288
#define	RIGHTBRAC	289
#define	LL_PAREN	290
#define	LR_PAREN	291
#define	COMMA	292
#define	COLON	293
#define	SEMI	294
#define	OMIT	295
#define	DOT	296
#define	PLUS	297
#define	MINUS	298
#define	TIMES	299
#define	DIVIDE	300
#define	ASSIGN	301
#define	LESS	302
#define	GREATER	303
#define	EQUAL	304
#define	NOTEQUAL	305
#define	GREATER_EQUAL	306
#define	LESS_EQUAL	307
#define	LOWER_THAN_ELSE	308

#line 1 "syntaxpl0.y"

#include"main.h"

FILE *fi;
FILE *fh;
extern int row,column;

extern void yyerror(char const* s);
extern int yylex(void);
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		171
#define	YYFLAG		-32768
#define	YYNTBASE	55

#define YYTRANSLATE(x) ((unsigned)(x) <= 308 ? yytranslate[x] : 93)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     6,     8,    10,    13,    16,    20,    23,    25,
    27,    32,    36,    40,    42,    46,    50,    53,    55,    59,
    63,    65,    71,    75,    77,    81,    85,    87,    91,    93,
    95,    97,    99,   101,   103,   107,   112,   116,   118,   119,
   121,   124,   127,   129,   132,   135,   137,   140,   143,   146,
   151,   153,   157,   159,   163,   167,   171,   175,   179,   182,
   184,   186,   188,   190,   192,   194,   199,   206,   210,   214,
   217,   220,   222,   226,   230,   232,   234,   236,   238,   242,
   247,   256,   262,   267,   272,   277,   281,   283,   285,   287
};

static const short yyrhs[] = {    56,
    42,     0,    57,    72,     0,    72,     0,    58,     0,    58,
    61,     0,    58,    70,     0,    58,    61,    70,     0,    61,
    70,     0,    61,     0,    70,     0,    58,    19,    59,    40,
     0,    19,    59,    40,     0,    59,    38,    60,     0,    60,
     0,     7,    47,     3,     0,     7,    47,     4,     0,    61,
    62,     0,    62,     0,    20,    63,    40,     0,    63,    38,
    64,     0,    64,     0,     7,    26,    65,    27,    68,     0,
     7,    27,    69,     0,     7,     0,    34,    66,    35,     0,
    66,    38,    67,     0,    67,     0,     3,    41,     3,     0,
    28,     0,    29,     0,    28,     0,    29,     0,    30,     0,
    31,     0,    71,    56,    40,     0,    70,    71,    56,    40,
     0,     8,     7,    40,     0,    78,     0,     0,    74,     0,
    73,    74,     0,    77,    40,     0,    81,     0,    85,    40,
     0,    86,    40,     0,    87,     0,    88,    40,     0,    89,
    40,     0,    90,    40,     0,     7,    34,    76,    35,     0,
     7,     0,    76,    38,     3,     0,     3,     0,    75,    47,
    82,     0,    75,    47,     5,     0,    75,    47,     6,     0,
    17,    73,    18,     0,    82,    80,    82,     0,    21,    82,
     0,    50,     0,    51,     0,    48,     0,    49,     0,    53,
     0,    52,     0,     9,    79,    10,    72,     0,     9,    79,
    10,    72,    11,    72,     0,    82,    43,    83,     0,    82,
    44,    83,     0,    43,    83,     0,    44,    83,     0,    83,
     0,    83,    45,    84,     0,    83,    46,    84,     0,    84,
     0,    75,     0,     3,     0,     4,     0,    32,    82,    33,
     0,    12,    79,    13,    72,     0,    22,     7,    47,    82,
    23,    82,    13,    72,     0,    24,    72,    40,    25,    79,
     0,    16,    32,     7,    33,     0,    14,    32,     7,    33,
     0,    15,    32,    91,    33,     0,    91,    38,    92,     0,
    92,     0,    82,     0,     5,     0,     6,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    28,    32,    35,    40,    44,    48,    52,    56,    60,    64,
    69,    73,    78,    82,    87,    91,    97,   101,   107,   112,
   116,   122,   126,   130,   135,   140,   144,   149,   153,   157,
   162,   166,   170,   174,   179,   183,   188,   194,   198,   203,
   207,   211,   215,   219,   223,   227,   231,   235,   239,   245,
   249,   254,   258,   263,   268,   273,   279,   284,   288,   293,
   297,   301,   305,   309,   313,   318,   322,   327,   332,   337,
   342,   347,   353,   358,   363,   369,   374,   379,   384,   390,
   395,   400,   405,   410,   415,   420,   424,   429,   433,   437
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","INTEGER_VAL",
"FLOAT_VAL","CHAR_VAL","STRING_VAL","IDENTIFIER","PROCEDURE","IF","THEN","ELSE",
"WHILE","DO","READ","WRITE","CALL","_BEGIN_","END","CONST","VAR","ODD","FOR",
"TO","REPEAT","UNTIL","ARRAY","OF","INT","FLOAT","CHAR","STRING","SL_PAREN",
"SR_PAREN","LEFTBRAC","RIGHTBRAC","LL_PAREN","LR_PAREN","COMMA","COLON","SEMI",
"OMIT","DOT","PLUS","MINUS","TIMES","DIVIDE","ASSIGN","LESS","GREATER","EQUAL",
"NOTEQUAL","GREATER_EQUAL","LESS_EQUAL","LOWER_THAN_ELSE","Program","SubPro",
"DeclarePart","ConstDec","ConstDef","CDefine","VarDec","VarObj","IdentiDef",
"IdentiObject","Realm","ArrayNDim","ArrayDimObj","ArrayType","ValueType","ProDec",
"ProceHead","Statement","States","Statements","Identifier","INdex_Index","AssignStm",
"ComplexStm","Condition","CMP","CondiStm","Expr","Term","Factor","WhileStm",
"ForStm","RepeatS","CallS","ReadS","WriteS","Wcontent","WconObj", NULL
};
#endif

static const short yyr1[] = {     0,
    55,    56,    56,    57,    57,    57,    57,    57,    57,    57,
    58,    58,    59,    59,    60,    60,    61,    61,    62,    63,
    63,    64,    64,    64,    65,    66,    66,    67,    68,    68,
    69,    69,    69,    69,    70,    70,    71,    72,    72,    73,
    73,    74,    74,    74,    74,    74,    74,    74,    74,    75,
    75,    76,    76,    77,    77,    77,    78,    79,    79,    80,
    80,    80,    80,    80,    80,    81,    81,    82,    82,    82,
    82,    82,    83,    83,    83,    84,    84,    84,    84,    85,
    86,    87,    88,    89,    90,    91,    91,    92,    92,    92
};

static const short yyr2[] = {     0,
     2,     2,     1,     1,     2,     2,     3,     2,     1,     1,
     4,     3,     3,     1,     3,     3,     2,     1,     3,     3,
     1,     5,     3,     1,     3,     3,     1,     3,     1,     1,
     1,     1,     1,     1,     3,     4,     3,     1,     0,     1,
     2,     2,     1,     2,     2,     1,     2,     2,     2,     4,
     1,     3,     1,     3,     3,     3,     3,     3,     2,     1,
     1,     1,     1,     1,     1,     4,     6,     3,     3,     2,
     2,     1,     3,     3,     1,     1,     1,     1,     3,     4,
     8,     5,     4,     4,     4,     3,     1,     1,     1,     1
};

static const short yydefact[] = {    39,
     0,     0,     0,     0,     0,    39,     4,     9,    18,    10,
    39,     3,    38,     0,    51,     0,     0,     0,     0,     0,
     0,    39,     0,    40,     0,     0,    43,     0,     0,    46,
     0,     0,     0,     0,     0,    14,    24,     0,    21,     1,
     2,     0,     5,     6,    17,     8,    39,     0,    37,     0,
    77,    78,     0,     0,     0,     0,    76,     0,     0,    72,
    75,     0,     0,     0,     0,     0,     0,    57,    41,     0,
    42,    44,    45,    47,    48,    49,     0,     0,    12,     0,
     0,     0,    19,     0,     7,     0,    35,    53,     0,    59,
     0,    70,    71,    39,     0,     0,    62,    63,    60,    61,
    65,    64,     0,     0,     0,    39,     0,    89,    90,    88,
     0,    87,     0,     0,     0,    55,    56,    54,    15,    16,
    13,     0,     0,    31,    32,    33,    34,    23,    20,    11,
    36,    50,     0,    79,    66,    68,    69,    58,    73,    74,
    80,    84,    85,     0,    83,     0,     0,     0,     0,    27,
     0,    52,    39,    86,     0,    82,     0,    25,     0,    29,
    30,    22,    67,     0,    28,    26,    39,    81,     0,     0,
     0
};

static const short yydefgoto[] = {   169,
     5,     6,     7,    35,    36,     8,     9,    38,    39,   123,
   149,   150,   162,   128,    10,    11,    12,    23,    24,    57,
    89,    26,    13,    58,   103,    27,    59,    60,    61,    28,
    29,    30,    31,    32,    33,   111,   112
};

static const short yypact[] = {    93,
    30,    83,    50,    64,    60,    36,    95,    28,-32768,   100,
    93,-32768,-32768,    82,   109,    11,    11,   106,   112,   114,
   138,    36,    67,-32768,   103,   108,-32768,   111,   115,-32768,
   116,   117,   118,   105,    46,-32768,   -15,    56,-32768,-32768,
-32768,    50,    28,   100,-32768,   100,    93,   119,-32768,   146,
-32768,-32768,    24,    24,    55,    55,-32768,   143,    75,    -1,
-32768,   141,   153,     3,   155,   120,   123,-32768,-32768,    17,
-32768,-32768,-32768,-32768,-32768,-32768,    74,    50,-32768,   130,
   104,    64,-32768,    71,   100,   125,-32768,-32768,   101,    77,
    73,    -1,    -1,    36,    55,    55,-32768,-32768,-32768,-32768,
-32768,-32768,    24,    55,    55,    36,   133,-32768,-32768,    77,
    37,-32768,   135,    24,   144,-32768,-32768,    77,-32768,-32768,
-32768,   167,   145,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   168,-32768,   162,    -1,    -1,    77,-32768,-32768,
-32768,-32768,-32768,     3,-32768,     7,    11,   134,   102,-32768,
   113,-32768,    36,-32768,    24,-32768,   171,-32768,   167,-32768,
-32768,-32768,-32768,    29,-32768,-32768,    36,-32768,   176,   177,
-32768
};

static const short yypgoto[] = {-32768,
    -7,-32768,-32768,   136,   107,   172,    21,-32768,    98,-32768,
-32768,    22,-32768,-32768,    26,    -5,    -6,-32768,   159,    15,
-32768,-32768,-32768,   -16,-32768,-32768,   -51,   -30,    25,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    39
};


#define	YYLAST		185


static const short yytable[] = {    41,
    62,    90,    91,    48,    47,    51,    52,   108,   109,    15,
    80,    81,   110,    51,    52,    67,    25,    15,   118,    51,
    52,   116,   117,    15,    92,    93,    51,    52,    45,   155,
    15,    53,    44,    46,    54,     1,    14,    25,    47,    86,
    47,   167,    54,   104,   105,    55,    56,     4,    54,    95,
    96,   138,     2,    55,    56,    54,    34,    51,    52,    55,
    56,    15,   146,    45,   136,   137,    55,    56,    85,   143,
    37,    95,    96,    15,   144,    16,   119,   120,    17,    47,
    18,    19,    20,    78,    68,    79,    54,   135,    21,    15,
    22,    16,   110,    82,    17,    83,    18,    19,    20,   141,
     1,    40,     1,   164,    21,   134,    22,     1,    78,     2,
   130,     3,     4,    42,     4,    95,    96,    95,    96,    95,
    96,    49,    97,    98,    99,   100,   101,   102,   139,   140,
   156,   124,   125,   126,   127,   132,   158,    63,   133,   159,
   160,   161,    50,    64,    66,    65,   163,    71,    88,    70,
    72,    77,    94,   106,    73,    74,    75,    76,    87,   107,
   168,   113,   115,   122,   131,   142,   114,   145,   147,   148,
   152,   151,   153,   165,   157,   170,   171,    84,    43,   129,
   166,    69,   154,     0,   121
};

static const short yycheck[] = {     6,
    17,    53,    54,    11,    10,     3,     4,     5,     6,     7,
    26,    27,    64,     3,     4,    22,     2,     7,    70,     3,
     4,     5,     6,     7,    55,    56,     3,     4,     8,    23,
     7,    21,     7,     8,    32,     8,     7,    23,    44,    47,
    46,    13,    32,    45,    46,    43,    44,    20,    32,    43,
    44,   103,    17,    43,    44,    32,     7,     3,     4,    43,
    44,     7,   114,    43,    95,    96,    43,    44,    43,    33,
     7,    43,    44,     7,    38,     9,     3,     4,    12,    85,
    14,    15,    16,    38,    18,    40,    32,    94,    22,     7,
    24,     9,   144,    38,    12,    40,    14,    15,    16,   106,
     8,    42,     8,   155,    22,    33,    24,     8,    38,    17,
    40,    19,    20,    19,    20,    43,    44,    43,    44,    43,
    44,    40,    48,    49,    50,    51,    52,    53,   104,   105,
   147,    28,    29,    30,    31,    35,    35,    32,    38,    38,
    28,    29,    34,    32,     7,    32,   153,    40,     3,    47,
    40,    47,    10,    13,    40,    40,    40,    40,    40,     7,
   167,     7,    40,    34,    40,    33,    47,    33,    25,     3,
     3,    27,    11,     3,    41,     0,     0,    42,     7,    82,
   159,    23,   144,    -1,    78
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 28 "syntaxpl0.y"
{
                fprintf(fi,"Program -> SubPro DOT\n");  
                fprintf(fh,"Program -> SubPro DOT\n");  ;
    break;}
case 2:
#line 32 "syntaxpl0.y"
{
                fprintf(fi,"SubPro -> DeclarePart Statement\n");  
                fprintf(fh,"SubPro -> DeclarePart Statement\n");  ;
    break;}
case 3:
#line 35 "syntaxpl0.y"
{
                fprintf(fi,"SubPro -> Statement\n");  
                fprintf(fh,"SubPro -> Statement\n");  
            ;
    break;}
case 4:
#line 40 "syntaxpl0.y"
{
                  fprintf(fi,"DeclarePart -> ConstDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec\n");
            ;
    break;}
case 5:
#line 44 "syntaxpl0.y"
{
                  fprintf(fi,"DeclarePart -> ConstDec VarDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec VarDec\n");
            ;
    break;}
case 6:
#line 48 "syntaxpl0.y"
{
                  fprintf(fi,"DeclarePart -> ConstDec ProDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec ProDec\n");
            ;
    break;}
case 7:
#line 52 "syntaxpl0.y"
{
                  fprintf(fi,"DeclarePart -> ConstDec VarDec ProDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec VarDec ProDec\n");
            ;
    break;}
case 8:
#line 56 "syntaxpl0.y"
{
                  fprintf(fi,"DeclarePart -> VarDec ProDec\n");
                  fprintf(fh,"DeclarePart -> VarDec ProDec\n");
            ;
    break;}
case 9:
#line 60 "syntaxpl0.y"
{
                  fprintf(fi,"DeclarePart -> VarDec\n");
                  fprintf(fh,"DeclarePart -> VarDec\n");
            ;
    break;}
case 10:
#line 64 "syntaxpl0.y"
{
                  fprintf(fi,"DeclarePart -> ProDec\n");
                  fprintf(fh,"DeclarePart -> ProDec\n");
            ;
    break;}
case 11:
#line 69 "syntaxpl0.y"
{
                fprintf(fi,"ConstDec -> ConstDec const ConstDef SEMI\n");
                fprintf(fh,"ConstDec -> ConstDec const ConstDef SEMI\n");
                  ;
    break;}
case 12:
#line 73 "syntaxpl0.y"
{
                fprintf(fi,"ConstDec -> const ConstDef SEMI\n");
                fprintf(fh,"ConstDec -> const ConstDef SEMI\n");
                  ;
    break;}
case 13:
#line 78 "syntaxpl0.y"
{
                fprintf(fi,"ConstDef -> ConstDef , CDefine\n"); 
                fprintf(fh,"ConstDef -> ConstDef , CDefine\n");
                 ;
    break;}
case 14:
#line 82 "syntaxpl0.y"
{
                fprintf(fi,"ConstDef -> CDefine\n"); 
                fprintf(fh,"ConstDef -> CDefine\n");
            ;
    break;}
case 15:
#line 87 "syntaxpl0.y"
{
                fprintf(fi,"CDefine -> IDENTIFIER := INTEGER_VAL\n");
                fprintf(fh,"CDefine -> IDENTIFIER := INTEGER_VAL\n");
                  ;
    break;}
case 16:
#line 91 "syntaxpl0.y"
{
                fprintf(fi,"CDefine -> IDENTIFIER := FLOAT_VAL\n"); 
                fprintf(fh,"CDefine -> IDENTIFIER := FLOAT_VAL\n");
                 ;
    break;}
case 17:
#line 97 "syntaxpl0.y"
{
                fprintf(fi,"VarDec -> VarDec VarObj\n");
                 fprintf(fh,"VarDec -> VarDec VarObj\n");
                ;
    break;}
case 18:
#line 101 "syntaxpl0.y"
{
                fprintf(fi,"VarDec -> VarObj\n");
                 fprintf(fh,"VarDec -> VarObj\n");
                
            ;
    break;}
case 19:
#line 107 "syntaxpl0.y"
{
                fprintf(fi,"VarObj -> var IdentiDef SEMI\n"); 
                fprintf(fh,"VarObj -> var IdentiDef SEMI\n");
                 ;
    break;}
case 20:
#line 112 "syntaxpl0.y"
{
                fprintf(fi,"IdentiDef -> IdentiDef , IdentiObject\n");  
                fprintf(fh,"IdentiDef -> IdentiDef , IdentiObject\n"); 
            ;
    break;}
case 21:
#line 116 "syntaxpl0.y"
{
                fprintf(fi,"IdentiDef -> IdentiObject\n");  
                fprintf(fh,"IdentiDef -> IdentiObject\n"); 
            ;
    break;}
case 22:
#line 122 "syntaxpl0.y"
{
                fprintf(fi,"IdentiObject -> IDENTIFIER ARRAY Realm OF ArrayType\n"); 
                fprintf(fh,"IdentiObject -> IDENTIFIER ARRAT Realm OF ArrayType\n");
             ;
    break;}
case 23:
#line 126 "syntaxpl0.y"
{
                fprintf(fi,"IdentiObject -> IDENTIFIER OF ValueType\n");
                fprintf(fh,"IdentiObject -> IDENTIFIER OF ValueType\n");
            ;
    break;}
case 24:
#line 130 "syntaxpl0.y"
{
                fprintf(fi,"IdentiObject -> IDENTIFIER\n");
                fprintf(fh,"IdentiObject -> IDENTIFIER\n");
            ;
    break;}
case 25:
#line 135 "syntaxpl0.y"
{
                fprintf(fi,"Realm -> [ ArrayNDim ]\n");  
                fprintf(fh,"Realm -> [ ArrayNDim ]\n"); 
            ;
    break;}
case 26:
#line 140 "syntaxpl0.y"
{
                fprintf(fi,"ArrayNDim -> ArrayNDim COMMA ArrayDimObj\n");  
                fprintf(fh,"ArrayNDim -> ArrayNDim COMMA ArrayDimObj\n");  
            ;
    break;}
case 27:
#line 144 "syntaxpl0.y"
{
                fprintf(fi,"ArrayNDim -> ArrayDimObj\n");  
                fprintf(fh,"ArrayNDim -> ArrayDimObj\n");
            ;
    break;}
case 28:
#line 149 "syntaxpl0.y"
{
                fprintf(fi,"ArrayDimObj -> INTEGER_VAL OMIT INTEGER_VAL\n");  
                fprintf(fh,"ArrayDimObj -> INTEGER_VAL OMIT INTEGER_VAL\n");  
            ;
    break;}
case 29:
#line 153 "syntaxpl0.y"
{
                fprintf(fi,"ArrayType -> INT\n"); 
                fprintf(fh,"ArrayType -> INT\n");  
            ;
    break;}
case 30:
#line 157 "syntaxpl0.y"
{
                fprintf(fi,"ArrayType -> FLOAT\n"); 
                fprintf(fh,"ArrayType -> FLOAT\n"); 
            ;
    break;}
case 31:
#line 162 "syntaxpl0.y"
{
                fprintf(fi,"ValueType -> INT\n");  
                 fprintf(fh,"ValueType -> INT\n");
            ;
    break;}
case 32:
#line 166 "syntaxpl0.y"
{
                fprintf(fi,"ValueType -> FLOAT\n");  
                fprintf(fh,"ValueType -> FLOAT\n");  
            ;
    break;}
case 33:
#line 170 "syntaxpl0.y"
{
                fprintf(fi,"ValueType -> CHAR\n"); 
                fprintf(fh,"ValueType -> CHAR\n"); 
            ;
    break;}
case 34:
#line 174 "syntaxpl0.y"
{
                fprintf(fi,"ValueType -> STRING\n"); 
                fprintf(fh,"ValueType -> STRING\n");
            ;
    break;}
case 35:
#line 179 "syntaxpl0.y"
{
                fprintf(fi,"ProDec -> ProceHead SubPro SEMI\n"); 
                fprintf(fh,"ProDec -> ProceHead SubPro SEMI\n"); 
            ;
    break;}
case 36:
#line 183 "syntaxpl0.y"
{
                fprintf(fi,"ProDec -> ProDec ProceHead SubPro SEMI\n"); 
                fprintf(fh,"ProDec -> ProDec ProceHead SubPro SEMI\n"); 
            ;
    break;}
case 37:
#line 188 "syntaxpl0.y"
{
                fprintf(fi,"ProceHead -> procedure IDENTIFIER SEMI\n");
                fprintf(fh,"ProceHead -> procedure IDENTIFIER SEMI\n");
            ;
    break;}
case 38:
#line 194 "syntaxpl0.y"
{
                fprintf(fi,"Statement -> ComplexStm\n");
                fprintf(fh,"Statement -> ComplexStm\n");
                  ;
    break;}
case 39:
#line 198 "syntaxpl0.y"
{ // empty
                //fprintf(fi,"Statement -> Empty\n");
                //fprintf(fh,"Statement -> Empty\n");
                  ;
    break;}
case 40:
#line 203 "syntaxpl0.y"
{
                fprintf(fi,"States -> Statement\n"); 
                fprintf(fh,"States -> Statement\n");
                 ;
    break;}
case 41:
#line 207 "syntaxpl0.y"
{
                fprintf(fi,"States -> States Statement\n"); 
                fprintf(fh,"States -> States Statement\n");
                 ;
    break;}
case 42:
#line 211 "syntaxpl0.y"
{
                fprintf(fi,"Statements -> AssignStm SEMI\n");
                fprintf(fh,"Statements -> AssignStm SEMI\n");
                  ;
    break;}
case 43:
#line 215 "syntaxpl0.y"
{
                fprintf(fi,"Statements -> CondiStm\n"); 
                fprintf(fh,"Statements -> CondiStm\n");
                 ;
    break;}
case 44:
#line 219 "syntaxpl0.y"
{
                fprintf(fi,"Statements -> WhileStm SEMI\n");
                fprintf(fh,"Statements -> WhileStm SEMI\n");
                  ;
    break;}
case 45:
#line 223 "syntaxpl0.y"
{
                fprintf(fi,"Statements -> ForStm SEMI\n"); 
                fprintf(fh,"Statements -> ForStm SEMI\n");
                 ;
    break;}
case 46:
#line 227 "syntaxpl0.y"
{
                fprintf(fi,"Statements -> RepeatS\n");
                fprintf(fh,"Statements -> RepeatS\n");
                  ;
    break;}
case 47:
#line 231 "syntaxpl0.y"
{
                fprintf(fi,"Statements -> CallS SEMI\n");
                fprintf(fh,"Statements -> CallS SEMI\n");
                  ;
    break;}
case 48:
#line 235 "syntaxpl0.y"
{
                fprintf(fi,"Statements -> ReadS SEMI\n"); 
                fprintf(fh,"Statements -> ReadS SEMI\n");
                 ;
    break;}
case 49:
#line 239 "syntaxpl0.y"
{
                fprintf(fi,"Statements -> WriteS SEMI\n");
                fprintf(fh,"Statements -> WriteS SEMI\n");
                  ;
    break;}
case 50:
#line 245 "syntaxpl0.y"
{
                fprintf(fi,"Identifier -> IDENTIFIER LEFTBRAC INdex_Index RIGHTBRAC\n");
                fprintf(fh,"Identifier -> IDENTIFIER LEFTBRAC INdex_Index RIGHTBRAC\n");
            ;
    break;}
case 51:
#line 249 "syntaxpl0.y"
{
                fprintf(fi,"Identifier -> IDENTIFIER\n");
                fprintf(fh,"Identifier -> IDENTIFIER\n");
            ;
    break;}
case 52:
#line 254 "syntaxpl0.y"
{
                fprintf(fi,"INdex_Index -> INdex_Index COMMA INTEGER_VAL\n");  
                fprintf(fh,"INdex_Index -> INdex_Index COMMA INTEGER_VAL\n");
            ;
    break;}
case 53:
#line 258 "syntaxpl0.y"
{
                fprintf(fi,"INdex_Index -> INTEGER_VAL\n");
                fprintf(fh,"INdex_Index -> INTEGER_VAL\n"); 
            ;
    break;}
case 54:
#line 263 "syntaxpl0.y"
{
                
                fprintf(fi,"AssignStm -> Identifier ASSIGN Expr\n");
                fprintf(fh,"AssignStm -> Identifier ASSIGN Expr\n");
            ;
    break;}
case 55:
#line 268 "syntaxpl0.y"
{
                
                fprintf(fi,"AssignStm -> Identifier ASSIGN CHAR_VAL\n");
                fprintf(fh,"AssignStm -> Identifier ASSIGN CHAR_VAL\n");
            ;
    break;}
case 56:
#line 273 "syntaxpl0.y"
{
                
                fprintf(fi,"AssignStm -> Identifier ASSIGN STRING_VAL\n");
                fprintf(fh,"AssignStm -> Identifier ASSIGN STRING_VAL\n");
            ;
    break;}
case 57:
#line 279 "syntaxpl0.y"
{
                fprintf(fi,"ComplexStm -> _BEGIN_ States END\n"); 
                fprintf(fh,"ComplexStm -> _BEGIN_ States END\n"); 
                ;
    break;}
case 58:
#line 284 "syntaxpl0.y"
{
                fprintf(fi,"Condition -> Expr CMP Expr\n");
                fprintf(fh,"Condition -> Expr CMP Expr\n");
                ;
    break;}
case 59:
#line 288 "syntaxpl0.y"
{
                fprintf(fi,"Condition -> ODD Expr\n");
                fprintf(fh,"Condition -> ODD Expr\n");
              ;
    break;}
case 60:
#line 293 "syntaxpl0.y"
{
                fprintf(fi,"CMP -> EQUAL\n"); 
                fprintf(fh,"CMP -> EQUAL\n"); 
             ;
    break;}
case 61:
#line 297 "syntaxpl0.y"
{
                fprintf(fi,"CMP -> NOTEQUAL\n");
                fprintf(fh,"CMP -> NOTEQUAL\n");
              ;
    break;}
case 62:
#line 301 "syntaxpl0.y"
{
                fprintf(fi,"CMP -> LESS\n"); 
                fprintf(fh,"CMP -> LESS\n");
            ;
    break;}
case 63:
#line 305 "syntaxpl0.y"
{
                fprintf(fi,"CMP -> GREATER\n");
                fprintf(fh,"CMP -> GREATER\n");
              ;
    break;}
case 64:
#line 309 "syntaxpl0.y"
{
                fprintf(fi,"CMP -> LESS_EQUAL\n"); 
                fprintf(fh,"CMP -> LESS_EQUAL\n"); 
             ;
    break;}
case 65:
#line 313 "syntaxpl0.y"
{
                fprintf(fi,"CMP -> GREATER_EQUAL\n");  
                fprintf(fh,"CMP -> GREATER_EQUAL\n");
            ;
    break;}
case 66:
#line 318 "syntaxpl0.y"
{
                fprintf(fi,"CondiStm -> IF Condition THEN Statement\n"); 
                fprintf(fh,"CondiStm -> IF Condition THEN Statement\n"); 
                 ;
    break;}
case 67:
#line 322 "syntaxpl0.y"
{
                fprintf(fi,"CondiStm -> IF Condition THEN Statement ELSE Statement\n");
                fprintf(fh,"CondiStm -> IF Condition THEN Statement ELSE Statement\n");
                  ;
    break;}
case 68:
#line 327 "syntaxpl0.y"
{
                
                fprintf(fi,"Expr -> Expr PLUS Term\n"); 
                fprintf(fh,"Expr -> Expr PLUS Term\n");
                ;
    break;}
case 69:
#line 332 "syntaxpl0.y"
{
                
                fprintf(fi,"Expr -> Expr MINUS Term\n");
                fprintf(fh,"Expr -> Expr MINUS Term\n");
                  ;
    break;}
case 70:
#line 337 "syntaxpl0.y"
{
                
                fprintf(fi,"Expr -> PLUS Term\n");  
                fprintf(fh,"Expr -> PLUS Term\n"); 
                ;
    break;}
case 71:
#line 342 "syntaxpl0.y"
{
                
                fprintf(fi,"Expr -> MINUS Term\n"); 
                fprintf(fh,"Expr -> MINUS Term\n");
                 ;
    break;}
case 72:
#line 347 "syntaxpl0.y"
{
                
                fprintf(fi,"Expr -> Term\n"); 
                fprintf(fh,"Expr -> Term\n");
                 ;
    break;}
case 73:
#line 353 "syntaxpl0.y"
{
                
                fprintf(fi,"Term -> Term TIMES Factor\n"); 
                fprintf(fh,"Term -> Term TIMES Factor\n");
                 ;
    break;}
case 74:
#line 358 "syntaxpl0.y"
{
                
                fprintf(fi,"Term -> Term DIVIDE Factor\n"); 
                fprintf(fh,"Term -> Term DIVIDE Factor\n");
                 ;
    break;}
case 75:
#line 363 "syntaxpl0.y"
{
                
                fprintf(fi,"Term -> Factor\n"); 
                fprintf(fh,"Term -> Factor\n"); 
                 ;
    break;}
case 76:
#line 369 "syntaxpl0.y"
{
                //$$=$1;
                fprintf(fi,"Factor -> Identifier\n"); 
                fprintf(fh,"Factor -> Identifier\n");
                 ;
    break;}
case 77:
#line 374 "syntaxpl0.y"
{
                //$$=$1;
                fprintf(fi,"Factor -> INTEGER_VAL\n"); 
                fprintf(fh,"Factor -> INTEGER_VAL\n");
                 ;
    break;}
case 78:
#line 379 "syntaxpl0.y"
{
                //$$=$1;
                fprintf(fi,"Factor -> FLOAT_VAL\n"); 
                fprintf(fh,"Factor -> FLOAT_VAL\n");
                 ;
    break;}
case 79:
#line 384 "syntaxpl0.y"
{
                //$$=$2;
                fprintf(fi,"Factor -> SL_PAREN Expr SR_PAREN\n");
                fprintf(fh,"Factor -> SL_PAREN Expr SR_PAREN\n");
                  ;
    break;}
case 80:
#line 390 "syntaxpl0.y"
{
                fprintf(fi,"WhileStm -> WHILE Condition DO Statement\n"); 
                fprintf(fh,"WhileStm -> WHILE Condition DO Statement\n");
            ;
    break;}
case 81:
#line 395 "syntaxpl0.y"
{
                fprintf(fi,"ForStm -> FOR IDENTIFIER := Expr TO Expr DO Statement\n");  
                fprintf(fh,"ForStm -> FOR IDENTIFIER := Expr TO Expr DO Statement\n"); 
            ;
    break;}
case 82:
#line 400 "syntaxpl0.y"
{
                fprintf(fi,"RepeatS -> REPEAT Statement SEMI UNTIL Condition\n"); 
                 fprintf(fh,"RepeatS -> REPEAT Statement SEMI UNTIL Condition\n");
            ;
    break;}
case 83:
#line 405 "syntaxpl0.y"
{
                fprintf(fi,"CallS -> call SL_PAREN IDENTIFIER SR_PAREN\n");  
                fprintf(fh,"CallS -> call SL_PAREN IDENTIFIER SR_PAREN\n"); 
            ;
    break;}
case 84:
#line 410 "syntaxpl0.y"
{
                fprintf(fi,"ReadS -> read SL_PAREN IDENTIFIER SR_PAREN\n"); 
                fprintf(fh,"ReadS -> read SL_PAREN IDENTIFIER SR_PAREN\n"); 
            ;
    break;}
case 85:
#line 415 "syntaxpl0.y"
{
                fprintf(fi,"WriteS -> write SL_PAREN Wcontent SR_PAREN\n");
                fprintf(fh,"WriteS -> write SL_PAREN Wcontent SR_PAREN\n");
                  ;
    break;}
case 86:
#line 420 "syntaxpl0.y"
{
                fprintf(fi,"Wcontent -> Wcontent COMMA WconObj\n"); 
                fprintf(fh,"Wcontent -> Wcontent COMMA WconObj\n");
                 ;
    break;}
case 87:
#line 424 "syntaxpl0.y"
{
                fprintf(fi,"Wcontent -> WconObj\n"); 
                fprintf(fh,"Wcontent -> WconObj\n");
                 ;
    break;}
case 88:
#line 429 "syntaxpl0.y"
{
                fprintf(fi,"WconObj -> Expr\n");
                fprintf(fh,"WconObj -> Expr\n");
                  ;
    break;}
case 89:
#line 433 "syntaxpl0.y"
{
                fprintf(fi,"WconObj -> CHAR_VAL\n");
                fprintf(fh,"WconObj -> CHAR_VAL\n");
                ;
    break;}
case 90:
#line 437 "syntaxpl0.y"
{
                fprintf(fi,"WconObj -> STRING_VAL\n");
                fprintf(fh,"WconObj -> STRING_VAL\n");
                ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 443 "syntaxpl0.y"


int main()
{
    fi = fopen("SynOutput.txt", "w+");
    fh = fopen("helperOutput.txt", "w+");
    yyparse();
    return 1;
}

void yyerror(char const* s)
{
    printf("%s,(%d,%d)\n",s,row,column);
    return;
}
