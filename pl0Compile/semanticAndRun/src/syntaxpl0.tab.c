
/*  A Bison parser, made from syntaxpl0.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	INTEGER_VAL	257
#define	FLOAT_VAL	258
#define	CHAR_VAL	259
#define	STRING_VAL	260
#define	CMP	261
#define	IDENTIFIER	262
#define	PROCEDURE	263
#define	IF	264
#define	THEN	265
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
#define	INT_	282
#define	FLOAT	283
#define	CHAR	284
#define	STRING	285
#define	SL_PAREN	286
#define	SR_PAREN	287
#define	ML_PAREN	288
#define	MR_PAREN	289
#define	LL_PAREN	290
#define	LR_PAREN	291
#define	COMMA	292
#define	COLON	293
#define	SEMI	294
#define	DOTDOT	295
#define	DOT	296
#define	PLUS	297
#define	MINUS	298
#define	TIMES	299
#define	DIVIDE	300
#define	ASSIGN	301
#define	LOWERELSE	302
#define	ELSE	303

#line 1 "syntaxpl0.y"

#include "define.h"
#define MAGENTA "\033[35m"      /* Magenta */
extern int row,column;
extern void yyerror(char const* s);
extern int yylex(void);


#line 10 "syntaxpl0.y"
typedef union{
      struct {
        int i_val;
        float f_val;
        int type_; //int:0 float:1
      }count;

      struct {
        char* id;
        int offset;
        int type_;//int:0 float:1 char:2 string:3 aryint:4 aryfloat:5
      }Identi;
      
      struct {
	      int dimension;
	      int low[10];
	      int high[10];
        int search[10];
      }array__;

     
      int i_val;
      float f_val;
      char* str; 
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		174
#define	YYFLAG		-32768
#define	YYNTBASE	50

#define YYTRANSLATE(x) ((unsigned)(x) <= 303 ? yytranslate[x] : 89)

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
    47,    48,    49
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     8,    12,    13,    14,    16,    19,    22,    26,
    29,    31,    33,    38,    42,    46,    48,    52,    56,    61,
    65,    69,    71,    75,    83,    89,    93,    95,    97,    99,
   101,   103,   105,   110,   114,   118,   120,   121,   125,   127,
   130,   133,   135,   138,   141,   144,   147,   150,   152,   157,
   159,   163,   165,   169,   173,   177,   181,   184,   191,   202,
   203,   204,   208,   212,   215,   218,   220,   224,   228,   230,
   232,   234,   236,   240,   247,   256,   263,   264,   265,   266,
   271,   276,   281,   286
};

static const short yyrhs[] = {    51,
    42,     0,    52,    54,    53,    66,     0,    52,    53,    66,
     0,     0,     0,    55,     0,    55,    58,     0,    55,    64,
     0,    55,    58,    64,     0,    58,    64,     0,    58,     0,
    64,     0,    55,    19,    56,    40,     0,    19,    56,    40,
     0,    56,    38,    57,     0,    57,     0,     8,    47,     3,
     0,     8,    47,     4,     0,    58,    20,    59,    40,     0,
    20,    59,    40,     0,    59,    38,    60,     0,    60,     0,
     8,    27,    63,     0,     8,    26,    34,    61,    35,    27,
    62,     0,    61,    38,     3,    41,     3,     0,     3,    41,
     3,     0,    28,     0,    29,     0,    28,     0,    29,     0,
    30,     0,    31,     0,    64,    65,    51,    40,     0,    65,
    51,    40,     0,     9,     8,    40,     0,    67,     0,     0,
    17,    68,    18,     0,    69,     0,    68,    69,     0,    72,
    40,     0,    74,     0,    86,    40,     0,    87,    40,     0,
    88,    40,     0,    80,    40,     0,    81,    40,     0,    82,
     0,     8,    34,    71,    35,     0,     8,     0,    71,    38,
    77,     0,    77,     0,    70,    47,    77,     0,    70,    47,
     5,     0,    70,    47,     6,     0,    77,     7,    77,     0,
    21,    77,     0,    10,    73,    75,    11,    67,    40,     0,
    10,    73,    75,    11,    67,    40,    49,    76,    67,    40,
     0,     0,     0,    77,    43,    78,     0,    77,    44,    78,
     0,    43,    78,     0,    44,    78,     0,    78,     0,    78,
    45,    79,     0,    78,    46,    79,     0,    79,     0,    70,
     0,     3,     0,     4,     0,    32,    77,    33,     0,    12,
    83,    73,    13,    84,    66,     0,    22,    72,    23,    83,
    73,    13,    84,    66,     0,    24,    85,    66,    40,    25,
    73,     0,     0,     0,     0,    16,    32,     8,    33,     0,
    14,    32,    70,    33,     0,    15,    32,    70,    33,     0,
    15,    32,     5,    33,     0,    15,    32,     6,    33,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    55,    61,    63,    66,    78,    93,    95,    97,    99,   101,
   103,   105,   109,   111,   114,   116,   119,   129,   141,   143,
   146,   149,   153,   162,   189,   194,   200,   203,   207,   210,
   213,   216,   221,   229,   238,   251,   253,   256,   259,   261,
   263,   265,   267,   269,   271,   273,   275,   277,   282,   317,
   334,   344,   355,   379,   397,   416,   443,   457,   460,   464,
   471,   479,   509,   539,   557,   578,   597,   628,   671,   690,
   718,   728,   738,   757,   764,   771,   777,   781,   789,   794,
   807,   839,   878,   890
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","INTEGER_VAL",
"FLOAT_VAL","CHAR_VAL","STRING_VAL","CMP","IDENTIFIER","PROCEDURE","IF","THEN",
"WHILE","DO","READ","WRITE","CALL","_BEGIN_","END","CONST","VAR","ODD","FOR",
"TO","REPEAT","UNTIL","ARRAY","OF","INT_","FLOAT","CHAR","STRING","SL_PAREN",
"SR_PAREN","ML_PAREN","MR_PAREN","LL_PAREN","LR_PAREN","COMMA","COLON","SEMI",
"DOTDOT","DOT","PLUS","MINUS","TIMES","DIVIDE","ASSIGN","LOWERELSE","ELSE","Program",
"SubPro","BeforeDec","BeforeSta","DeclarePart","ConstDec","ConstDef","CDefine",
"VarDec","IdentiDef","IDefine","Dimension","ArrayType","VarType","ProDec","ProceHead",
"Statement","ComplexS","States","Statements","Identifier","GetDi","AssignS",
"Condition","CondiS","BeforeThen","BeforeElseDo","Expr","Term","Factor","While_Loop",
"For_Loop","Repeat_Loop","BeforeCond","BeforeCondDo","BeforeRepeat","Call_Func",
"Read_Func","Write_Func", NULL
};
#endif

static const short yyr1[] = {     0,
    50,    51,    51,    52,    53,    54,    54,    54,    54,    54,
    54,    54,    55,    55,    56,    56,    57,    57,    58,    58,
    59,    59,    60,    60,    61,    61,    62,    62,    63,    63,
    63,    63,    64,    64,    65,    66,    66,    67,    68,    68,
    69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
    71,    71,    72,    72,    72,    73,    73,    74,    74,    75,
    76,    77,    77,    77,    77,    77,    78,    78,    78,    79,
    79,    79,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    88,    88
};

static const short yyr2[] = {     0,
     2,     4,     3,     0,     0,     1,     2,     2,     3,     2,
     1,     1,     4,     3,     3,     1,     3,     3,     4,     3,
     3,     1,     3,     7,     5,     3,     1,     1,     1,     1,
     1,     1,     4,     3,     3,     1,     0,     3,     1,     2,
     2,     1,     2,     2,     2,     2,     2,     1,     4,     1,
     3,     1,     3,     3,     3,     3,     2,     6,    10,     0,
     0,     3,     3,     2,     2,     1,     3,     3,     1,     1,
     1,     1,     3,     6,     8,     6,     0,     0,     0,     4,
     4,     4,     4,     4
};

static const short yydefact[] = {     4,
     0,     5,     1,     0,     0,     0,    37,     5,     6,    11,
    12,     4,     0,     0,     0,    16,     0,     0,    22,     0,
     3,    36,    37,     0,     7,     8,     0,    10,     4,     0,
    35,     0,     0,    14,     0,     0,     0,    20,    50,     0,
    77,     0,     0,     0,     0,    79,     0,    39,     0,     0,
    42,     0,     0,    48,     0,     0,     0,     2,     0,     9,
     0,     0,    34,    17,    18,    15,     0,    29,    30,    31,
    32,    23,    21,     0,    71,    72,     0,     0,     0,     0,
    70,    60,     0,    66,    69,     0,     0,     0,     0,     0,
    37,    38,    40,     0,    41,    46,    47,    43,    44,    45,
    13,    19,    33,     0,     0,     0,    52,    57,     0,    64,
    65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    77,     0,    54,    55,    53,     0,     0,
     0,    49,     0,    73,     0,    56,    62,    63,    67,    68,
    78,    81,    83,    84,    82,    80,     0,     0,    26,     0,
     0,    51,     0,    37,     0,     0,    27,    28,    24,     0,
    58,    74,    78,    76,    25,    61,    37,     0,    75,     0,
    59,     0,     0,     0
};

static const short yydefgoto[] = {   172,
     1,     2,     7,     8,     9,    15,    16,    10,    18,    19,
   105,   159,    72,    11,    12,    21,    22,    47,    48,    81,
   106,    50,    82,    51,   112,   168,    83,    84,    85,    52,
    53,    54,    86,   154,    91,    55,    56,    57
};

static const short yypact[] = {-32768,
   -27,    39,-32768,    20,    43,    59,    30,-32768,    87,    24,
    88,-32768,    37,    38,    -3,-32768,    78,    15,-32768,    79,
-32768,-32768,    30,    43,    24,    88,    59,    88,-32768,    75,
-32768,   114,    43,-32768,    95,    82,    59,-32768,    96,    13,
-32768,   100,   101,   102,   119,-32768,    68,-32768,    81,    97,
-32768,    98,    99,-32768,   103,   105,   106,-32768,    41,    88,
    76,   107,-32768,-32768,-32768,-32768,   132,-32768,-32768,-32768,
-32768,-32768,-32768,    22,-32768,-32768,    22,    22,    28,    28,
-32768,-32768,    -2,    74,-32768,    13,   119,    94,   128,   117,
    30,-32768,-32768,     6,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   108,   -16,    26,    80,    80,    65,    74,
    74,   130,    22,    28,    28,    28,    28,   129,   115,   118,
   120,   121,   122,-32768,   110,-32768,-32768,    80,   149,   131,
   153,-32768,    22,-32768,    30,    80,    74,    74,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    13,   134,-32768,    93,
   116,    80,   123,    30,   147,    13,-32768,-32768,-32768,   158,
   113,-32768,-32768,-32768,-32768,-32768,    30,    30,-32768,   124,
-32768,   165,   166,-32768
};

static const short yypgoto[] = {-32768,
    -6,-32768,   159,-32768,-32768,   144,   136,   161,   145,   137,
-32768,-32768,-32768,    63,    -8,   -23,  -122,-32768,   126,   -18,
-32768,   133,   -85,-32768,-32768,-32768,   -70,   -40,     9,-32768,
-32768,-32768,    47,    12,-32768,-32768,-32768,-32768
};


#define	YYLAST		178


static const short yytable[] = {    58,
   118,    49,    29,   107,   113,    30,   108,   109,    75,    76,
   126,   127,   153,    39,     3,    75,    76,    29,   130,    29,
    39,   131,    62,   128,    75,    76,    49,    13,    49,    39,
    75,    76,     4,    77,    33,    39,    34,    78,   110,   111,
   114,   115,   136,    27,    78,   170,    20,     4,    79,    80,
    14,    29,    37,    78,    38,    79,    80,     5,     6,    78,
   132,   155,   152,   133,    79,    80,    17,   125,   119,   122,
   164,    26,    28,   137,   138,    39,    31,    40,    33,    41,
   101,    42,    43,    44,    32,    92,    39,    60,    40,    45,
    41,    46,    42,    43,    44,     4,     4,   134,   120,   121,
    45,    39,    46,    35,    36,    24,     6,   114,   115,    68,
    69,    70,    71,    37,    63,   102,    64,    65,   116,   117,
   157,   158,   114,   115,   139,   140,    39,    94,    67,    74,
   162,    87,    88,    89,   104,   123,    95,    96,    97,   124,
   135,   141,    98,   169,    99,   100,   103,   142,   129,   148,
   143,   149,   144,   145,   146,   151,   160,   150,   156,   163,
   165,   166,   161,   171,   173,   174,    23,    59,    66,    25,
   147,    61,    93,    73,   167,     0,     0,    90
};

static const short yycheck[] = {    23,
    86,    20,    11,    74,     7,    12,    77,    78,     3,     4,
     5,     6,   135,     8,    42,     3,     4,    26,    35,    28,
     8,    38,    29,    94,     3,     4,    45,     8,    47,     8,
     3,     4,     9,    21,    38,     8,    40,    32,    79,    80,
    43,    44,   113,    20,    32,   168,    17,     9,    43,    44,
     8,    60,    38,    32,    40,    43,    44,    19,    20,    32,
    35,   147,   133,    38,    43,    44,     8,    91,    87,    88,
   156,     9,    10,   114,   115,     8,    40,    10,    38,    12,
    40,    14,    15,    16,    47,    18,     8,    25,    10,    22,
    12,    24,    14,    15,    16,     9,     9,    33,     5,     6,
    22,     8,    24,    26,    27,    19,    20,    43,    44,    28,
    29,    30,    31,    38,    40,    40,     3,     4,    45,    46,
    28,    29,    43,    44,   116,   117,     8,    47,    34,    34,
   154,    32,    32,    32,     3,     8,    40,    40,    40,    23,
    11,    13,    40,   167,    40,    40,    40,    33,    41,    40,
    33,     3,    33,    33,    33,     3,    41,    27,    25,    13,
     3,    49,    40,    40,     0,     0,     8,    24,    33,     9,
   124,    27,    47,    37,   163,    -1,    -1,    45
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
#line 55 "syntaxpl0.y"
{
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,0,p);
              ;
    break;}
case 2:
#line 61 "syntaxpl0.y"
{
              ;
    break;}
case 3:
#line 63 "syntaxpl0.y"
{
              ;
    break;}
case 4:
#line 66 "syntaxpl0.y"
{
                if(symtable_size()!=0){
                  display_top++;
                  display_stack[display_top]=symtable_size()+1;
                }
                backPatch_table[++backPatch_table_top]=code_line;
                
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JMP,0,0,p);
              ;
    break;}
case 5:
#line 78 "syntaxpl0.y"
{
                if(backPatch_table_top>-1){
                  backpatch(backPatch_table[backPatch_table_top--],code_line);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                if(display_stack[display_top]==1){
                  gen(instruction::INI,0,sym_top+3,p);
                }
                else
                {
                  gen(instruction::INI,0,sym_top-display_stack[display_top]+1+3,p);
                }
              ;
    break;}
case 6:
#line 93 "syntaxpl0.y"
{
              ;
    break;}
case 7:
#line 95 "syntaxpl0.y"
{
              ;
    break;}
case 8:
#line 97 "syntaxpl0.y"
{
              ;
    break;}
case 9:
#line 99 "syntaxpl0.y"
{
              ;
    break;}
case 10:
#line 101 "syntaxpl0.y"
{
              ;
    break;}
case 11:
#line 103 "syntaxpl0.y"
{
              ;
    break;}
case 12:
#line 105 "syntaxpl0.y"
{
              ;
    break;}
case 13:
#line 109 "syntaxpl0.y"
{
              ;
    break;}
case 14:
#line 111 "syntaxpl0.y"
{
              ;
    break;}
case 15:
#line 114 "syntaxpl0.y"
{
              ;
    break;}
case 16:
#line 116 "syntaxpl0.y"
{
              ;
    break;}
case 17:
#line 119 "syntaxpl0.y"
{                
                if(if_declared(yyvsp[-2].str)==0)
                {
                    struct all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    temp.i_val=yyvsp[0].i_val;
                    temp.type_=all_type_val_value::int_;
                    symtable_push(yyvsp[-2].str,Symbol::const_,temp);
                }
              ;
    break;}
case 18:
#line 129 "syntaxpl0.y"
{
                if(if_declared(yyvsp[-2].str)==0)
                {
                    struct all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    temp.f_val=yyvsp[0].f_val;
                    temp.type_=all_type_val_value::float_;
                    symtable_push(yyvsp[-2].str,Symbol::const_,temp);
                }
             ;
    break;}
case 19:
#line 141 "syntaxpl0.y"
{
              ;
    break;}
case 20:
#line 143 "syntaxpl0.y"
{
              ;
    break;}
case 21:
#line 146 "syntaxpl0.y"
{
              
              ;
    break;}
case 22:
#line 149 "syntaxpl0.y"
{
              
              ;
    break;}
case 23:
#line 153 "syntaxpl0.y"
{
                if(if_declared(yyvsp[-2].str)==0)
                {
                    struct all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    temp.type_=all_type_val_value::define(yyvsp[0].i_val);
                    symtable_push(yyvsp[-2].str,Symbol::var_,temp);
                }
              ;
    break;}
case 24:
#line 162 "syntaxpl0.y"
{
                if(if_declared(yyvsp[-6].str)==0)
                {
                    array_stack_top_index++;
                    ary_stack[array_stack_top_index].id=yyvsp[-6].str;
                    ary_stack[array_stack_top_index].dimension=yyvsp[-3].array__.dimension;
                    ary_stack[array_stack_top_index].type_=yyvsp[0].i_val;
                    for(int index=0;index<yyvsp[-3].array__.dimension;index++)
                    {
                      ary_stack[array_stack_top_index].low[index]=yyvsp[-3].array__.low[index];
                      ary_stack[array_stack_top_index].high[index]=yyvsp[-3].array__.high[index];
                    }
                    int s=yyvsp[-3].array__.high[0]-yyvsp[-3].array__.low[0]+1;
	                  if(yyvsp[-3].array__.dimension>1)
		                  for(int i=1;i<yyvsp[-3].array__.dimension;i++)
			                  s=s*(yyvsp[-3].array__.high[i]-yyvsp[-3].array__.low[i]+1);
	                  ary_stack[array_stack_top_index].size=s;
                    
                    all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    temp.type_=all_type_val_value::define(yyvsp[0].i_val);                
                    for(int i=0;i<s;i++)
                      symtable_push(yyvsp[-6].str,Symbol::var_,temp);
                }
              ;
    break;}
case 25:
#line 189 "syntaxpl0.y"
{
                yyval.array__.dimension=yyvsp[-4].array__.dimension+1;
                yyval.array__.low[yyvsp[-4].array__.dimension]=yyvsp[-2].i_val;
                yyval.array__.high[yyvsp[-4].array__.dimension]=yyvsp[0].i_val;
              ;
    break;}
case 26:
#line 194 "syntaxpl0.y"
{
                yyval.array__.dimension=1;
                yyval.array__.low[0]=yyvsp[-2].i_val;
                yyval.array__.high[0]=yyvsp[0].i_val;
              ;
    break;}
case 27:
#line 200 "syntaxpl0.y"
{
                yyval.i_val=4;
              ;
    break;}
case 28:
#line 203 "syntaxpl0.y"
{
                yyval.i_val=5;
              ;
    break;}
case 29:
#line 207 "syntaxpl0.y"
{
                yyval.i_val=0;
              ;
    break;}
case 30:
#line 210 "syntaxpl0.y"
{
                yyval.i_val=1;
              ;
    break;}
case 31:
#line 213 "syntaxpl0.y"
{
                yyval.i_val=2;
              ;
    break;}
case 32:
#line 216 "syntaxpl0.y"
{
                yyval.i_val=3;
              ;
    break;}
case 33:
#line 221 "syntaxpl0.y"
{
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,0,p);
                current_Level--;
                symtable_pop();
                addr=2+symtable_size();
              ;
    break;}
case 34:
#line 229 "syntaxpl0.y"
{
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,0,p);
                current_Level--;
                symtable_pop();
                addr=2+symtable_size();
              ;
    break;}
case 35:
#line 238 "syntaxpl0.y"
{
                addr=3;
                if(if_declared(yyvsp[-1].str)==0 && find_pro(yyvsp[-1].str)==-1)
                {
                    
                    struct all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    symtable_push(yyvsp[-1].str,Symbol::proc,temp);
                    current_Level++;
                }    
              ;
    break;}
case 36:
#line 251 "syntaxpl0.y"
{
              ;
    break;}
case 37:
#line 253 "syntaxpl0.y"
{ 
              ;
    break;}
case 38:
#line 256 "syntaxpl0.y"
{
              ;
    break;}
case 39:
#line 259 "syntaxpl0.y"
{
              ;
    break;}
case 40:
#line 261 "syntaxpl0.y"
{
              ;
    break;}
case 41:
#line 263 "syntaxpl0.y"
{
              ;
    break;}
case 42:
#line 265 "syntaxpl0.y"
{
              ;
    break;}
case 43:
#line 267 "syntaxpl0.y"
{
              ;
    break;}
case 44:
#line 269 "syntaxpl0.y"
{
              ;
    break;}
case 45:
#line 271 "syntaxpl0.y"
{
              ;
    break;}
case 46:
#line 273 "syntaxpl0.y"
{
              ;
    break;}
case 47:
#line 275 "syntaxpl0.y"
{
              ;
    break;}
case 48:
#line 277 "syntaxpl0.y"
{
              ;
    break;}
case 49:
#line 282 "syntaxpl0.y"
{                              
                int arypos=find_ary(yyvsp[-3].str);
                if(arypos==-1)
                {
                  std::cout<<MAGENTA<<"Semantic error! "<<yyvsp[-3].str<<" isn't  array!"<<std::endl;
                  exit(1);
                }
                if(ary_stack[arypos].dimension != yyvsp[-1].array__.dimension)
                { // dimension error
                  std::cout<<MAGENTA<<"Semantic error! "<<yyvsp[-3].str<<"\'s dimension is not right!"<<std::endl;
                  exit(1);
                }
                for(int i=0;i<yyvsp[-1].array__.dimension;i++)
                { // search error
                  if(yyvsp[-1].array__.search[i]<ary_stack[arypos].low[i] || yyvsp[-1].array__.search[i]>ary_stack[arypos].high[i])
                  {
                    std::cout<<MAGENTA<<yyvsp[-1].array__.search[i]<<' '<<ary_stack[arypos].low[i]<<' '<<ary_stack[arypos].high[i]<<std::endl;
                    std::cout<<MAGENTA<<"Semantic Error! Array Dimension Over Bound!"<<std::endl;
                    exit(1);
                  }
                }
                
                int offset=yyvsp[-1].array__.search[0]-ary_stack[arypos].low[0];
                if(yyvsp[-1].array__.dimension>1)
                {
                  for(int i=1;i<yyvsp[-1].array__.dimension;i++)
                  {
                    offset=offset*(ary_stack[arypos].high[i]-ary_stack[arypos].low[i]+1);
                    offset=offset+yyvsp[-1].array__.search[i]-ary_stack[arypos].low[i];
                  }
                }
                yyval.Identi.offset=offset;
                yyval.Identi.id=yyvsp[-3].str;
                yyval.Identi.type_=ary_stack[arypos].type_;
              ;
    break;}
case 50:
#line 317 "syntaxpl0.y"
{                
                int pos=find_sign(yyvsp[0].str);
                if(symtable[pos].symtype_==Symbol::proc)
                {
                  exit(1);
                }
                if(symtable[pos].var.type_==all_type_val_value::aryint || symtable[pos].var.type_==all_type_val_value::aryfloat)
                {
                  
                  exit(1);
                }

                yyval.Identi.offset=0;
                yyval.Identi.id=yyvsp[0].str;  
                yyval.Identi.type_=symtable[pos].var.type_;                              
              ;
    break;}
case 51:
#line 334 "syntaxpl0.y"
{
                yyval.array__.dimension=yyvsp[-2].array__.dimension+1;
                if(yyvsp[0].count.type_==0)
                  yyval.array__.search[yyvsp[-2].array__.dimension]=yyvsp[0].count.i_val;
                else
                {
                  std::cout<<MAGENTA<<"Semantic Error! Array index must be int!"<<std::endl;
                  exit(1);
                }
              ;
    break;}
case 52:
#line 344 "syntaxpl0.y"
{
                yyval.array__.dimension=1;
                if(yyvsp[0].count.type_==0)
                  yyval.array__.search[0]=yyvsp[0].count.i_val;
                else
                {
                  std::cout<<MAGENTA<<"Semantic Error! Array index must be int!"<<std::endl;
                  exit(1);
                }
              ;
    break;}
case 53:
#line 355 "syntaxpl0.y"
{
                int pos=find_sign(yyvsp[-2].Identi.id);
                pos+=yyvsp[-2].Identi.offset;
                if(symtable[pos].symtype_!=Symbol::var_)
                { // type error
                  std::cout<<MAGENTA<<"Semaantic Error! "<<yyvsp[-2].Identi.id<<" type error!"<<std::endl;
                  exit(1);
                }
                
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::define(yyvsp[0].count.type_);
                if(yyvsp[0].count.type_==0)
                {
                  p.i_val=yyvsp[0].count.i_val;
                  symtable[pos].var.i_val=yyvsp[0].count.i_val;
                }
                if(yyvsp[0].count.type_==1)
                {
                  p.f_val=yyvsp[0].count.f_val;
                  symtable[pos].var.f_val=yyvsp[0].count.f_val;
                } 
                gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
              ;
    break;}
case 54:
#line 379 "syntaxpl0.y"
{
                if(yyvsp[-2].Identi.type_!=2)
                {
                  std::cout<<MAGENTA<<"Semantic Error! "<<yyvsp[-2].Identi.id<<" is not char type!"<<std::endl;
                  exit(1);
                }

                int pos=find_sign(yyvsp[-2].Identi.id);
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::char_;
                char* temp=strdup(yyvsp[0].str);
                temp[strlen(temp)-1]='\0';
                p.v_str=temp+1;
                symtable[pos].var.v_str=strdup(yyvsp[0].str);
                gen(instruction::LIT,0,0,p);
                gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
              ;
    break;}
case 55:
#line 397 "syntaxpl0.y"
{
                if(yyvsp[-2].Identi.type_!=3)
                {
                  std::cout<<MAGENTA<<"Setanmic Error! "<<yyvsp[-2].Identi.id<<" is not string type!"<<std::endl;
                  exit(1);
                }

                int pos=find_sign(yyvsp[-2].Identi.id);
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::string_;
                char* temp=strdup(yyvsp[0].str);
                temp[strlen(temp)-1]='\0';
                p.v_str=temp+1;
                symtable[pos].var.v_str=strdup(yyvsp[0].str);
                gen(instruction::LIT,0,0,p);
                gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
              ;
    break;}
case 56:
#line 416 "syntaxpl0.y"
{
                all_type_val_value p;
                init_for_gen_pcode(p);
                if(yyvsp[-2].count.type_==0 && yyvsp[0].count.type_==0)
                {
                  if(!strcmp(yyvsp[-1].str,"=="))  gen(instruction::OPR,0,8,p);
                  if(!strcmp(yyvsp[-1].str,"!="))  gen(instruction::OPR,0,9,p);
                  if(!strcmp(yyvsp[-1].str,"<"))   gen(instruction::OPR,0,10,p);
                  if(!strcmp(yyvsp[-1].str,"<="))  gen(instruction::OPR,0,13,p);
                  if(!strcmp(yyvsp[-1].str,">"))   gen(instruction::OPR,0,12,p);
                  if(!strcmp(yyvsp[-1].str,">="))  gen(instruction::OPR,0,11,p);
                }
                else if(yyvsp[-2].count.type_==1 && yyvsp[0].count.type_==1)
                {
                  if(!strcmp(yyvsp[-1].str,"=="))  gen(instruction::OPR,0,8,p);
                  if(!strcmp(yyvsp[-1].str,"!="))  gen(instruction::OPR,0,9,p);
                  if(!strcmp(yyvsp[-1].str,"<"))   gen(instruction::OPR,0,10,p);
                  if(!strcmp(yyvsp[-1].str,"<="))  gen(instruction::OPR,0,13,p);
                  if(!strcmp(yyvsp[-1].str,">"))   gen(instruction::OPR,0,12,p);
                  if(!strcmp(yyvsp[-1].str,">="))  gen(instruction::OPR,0,11,p);
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error! Only int or float in condition!"<<std::endl;
                  exit(1);
                }
              ;
    break;}
case 57:
#line 443 "syntaxpl0.y"
{
                if(yyvsp[0].count.type_==0)
                {
                  all_type_val_value p;
                  init_for_gen_pcode(p);
                  gen(instruction::OPR,0,6,p);
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error! Only int in odd condition!"<<std::endl;
                  exit(1);
                }
              ;
    break;}
case 58:
#line 457 "syntaxpl0.y"
{
                backpatch(backPatch_table[backPatch_table_top--],code_line);
              ;
    break;}
case 59:
#line 460 "syntaxpl0.y"
{
                backpatch(backPatch_table[backPatch_table_top--],code_line);
              ;
    break;}
case 60:
#line 464 "syntaxpl0.y"
{
                backPatch_table[++backPatch_table_top]=code_line;
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JPC,0,0,p);
              ;
    break;}
case 61:
#line 471 "syntaxpl0.y"
{
                backpatch(backPatch_table[backPatch_table_top--],code_line+1);
                backPatch_table[++backPatch_table_top]=code_line;
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JMP,0,0,p);
              ;
    break;}
case 62:
#line 479 "syntaxpl0.y"
{
                if(yyvsp[-2].count.type_==0 && yyvsp[0].count.type_==0)
                {
                    yyval.count.type_=0;
                    yyval.count.i_val=yyvsp[-2].count.i_val+yyvsp[0].count.i_val;
                }
                else if(yyvsp[-2].count.type_==1 && yyvsp[0].count.type_==1)
                {
                    yyval.count.type_=1;
                    yyval.count.f_val=yyvsp[-2].count.f_val+yyvsp[0].count.f_val;
                }
                else if(yyvsp[-2].count.type_==1 && yyvsp[0].count.type_==0)
                {
                    yyval.count.type_=1;
                    yyval.count.f_val=yyvsp[-2].count.f_val+yyvsp[0].count.i_val;
                }
                else if(yyvsp[-2].count.type_==0 && yyvsp[0].count.type_==1)
                {
                    yyval.count.type_=1;
                    yyval.count.f_val=yyvsp[-2].count.i_val+yyvsp[0].count.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,2,p);
              ;
    break;}
case 63:
#line 509 "syntaxpl0.y"
{
                if(yyvsp[-2].count.type_==0 && yyvsp[0].count.type_==0)
                {
                    yyval.count.type_=0;
                    yyval.count.i_val=yyvsp[-2].count.i_val-yyvsp[0].count.i_val;
                }
                else if(yyvsp[-2].count.type_==1 && yyvsp[0].count.type_==1)
                {
                    yyval.count.type_=1;
                    yyval.count.f_val=yyvsp[-2].count.f_val-yyvsp[0].count.f_val;
                }
                else if(yyvsp[-2].count.type_==1 && yyvsp[0].count.type_==0)
                {
                    yyval.count.type_=1;
                    yyval.count.f_val=yyvsp[-2].count.f_val-yyvsp[0].count.i_val;
                }
                else if(yyvsp[-2].count.type_==0 && yyvsp[0].count.type_==1)
                {
                    yyval.count.type_=1;
                    yyval.count.f_val=yyvsp[-2].count.i_val-yyvsp[0].count.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,3,p);
              ;
    break;}
case 64:
#line 539 "syntaxpl0.y"
{
                //$$=$2;
                if(yyvsp[0].count.type_==0)
                {
                  yyval.count.type_=0;
                  yyval.count.i_val=yyvsp[0].count.i_val;
                }
                else if(yyvsp[0].count.type_==1)
                {
                  yyval.count.type_=1;
                  yyval.count.f_val=yyvsp[0].count.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
              ;
    break;}
case 65:
#line 557 "syntaxpl0.y"
{
                //$$=-$2;
                if(yyvsp[0].count.type_==0)
                {
                    yyval.count.type_=0;
                    yyval.count.i_val=-yyvsp[0].count.i_val;
                }
                else if(yyvsp[0].count.type_==1)
                {
                    yyval.count.type_=1;
                    yyval.count.f_val=-yyvsp[0].count.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,1,p);
              ;
    break;}
case 66:
#line 578 "syntaxpl0.y"
{
                //$$=$1;
                if(yyvsp[0].count.type_==0)
                {
                  yyval.count.type_=0;
                  yyval.count.i_val=yyvsp[0].count.i_val;
                }
                else if(yyvsp[0].count.type_==1)
                {
                  yyval.count.type_=1;
                  yyval.count.f_val=yyvsp[0].count.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
              ;
    break;}
case 67:
#line 597 "syntaxpl0.y"
{
                //$$=$1*$3;
                if(yyvsp[-2].count.type_==0 && yyvsp[0].count.type_==0)
                {
                    yyval.count.type_=0;
                    yyval.count.i_val=yyvsp[-2].count.i_val*yyvsp[0].count.i_val;
                }
                else if(yyvsp[-2].count.type_==1 && yyvsp[0].count.type_==1)
                {
                    yyval.count.type_=1;
                    yyval.count.f_val=yyvsp[-2].count.f_val*yyvsp[0].count.f_val;
                }
                else if(yyvsp[-2].count.type_==1 && yyvsp[0].count.type_==0)
                {
                    yyval.count.type_=1;
                    yyval.count.f_val=yyvsp[-2].count.f_val*yyvsp[0].count.i_val;
                }
                else if(yyvsp[-2].count.type_==0 && yyvsp[0].count.type_==1)
                {
                    yyval.count.type_=1;
                    yyval.count.f_val=yyvsp[-2].count.i_val*yyvsp[0].count.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,4,p);
              ;
    break;}
case 68:
#line 628 "syntaxpl0.y"
{
                //$$=$1/$3;
                if(yyvsp[-2].count.type_==0 && yyvsp[0].count.type_==0)
                {
                    yyval.count.type_=0;
                    if(yyvsp[0].count.i_val==0)
                      yyval.count.i_val=0;
                    else
                      yyval.count.i_val=yyvsp[-2].count.i_val/yyvsp[0].count.i_val;
                }
                else if(yyvsp[-2].count.type_==1 && yyvsp[0].count.type_==1)
                {
                    yyval.count.type_=1;
                    if(yyvsp[0].count.f_val==0)
                      yyval.count.f_val=0;
                    else
                      yyval.count.f_val=yyvsp[-2].count.f_val/yyvsp[0].count.f_val;
                }
                else if(yyvsp[-2].count.type_==1 && yyvsp[0].count.type_==0)
                {
                    yyval.count.type_=1;
                    if(yyvsp[0].count.i_val==0)
                      yyval.count.f_val=0;
                    else
                      yyval.count.f_val=yyvsp[-2].count.f_val/yyvsp[0].count.i_val;
                }
                else if(yyvsp[-2].count.type_==0 && yyvsp[0].count.type_==1)
                {
                    yyval.count.type_=1;
                    if(yyvsp[0].count.f_val==0)
                      yyval.count.f_val=0;
                    else
                      yyval.count.f_val=yyvsp[-2].count.i_val/yyvsp[0].count.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,5,p);
              ;
    break;}
case 69:
#line 671 "syntaxpl0.y"
{
                //$$=$1;
                if(yyvsp[0].count.type_==0)
                {
                  yyval.count.type_=0;
                  yyval.count.i_val=yyvsp[0].count.i_val;
                }
                else if(yyvsp[0].count.type_==1)
                {
                  yyval.count.type_=1;
                  yyval.count.f_val=yyvsp[0].count.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
              ;
    break;}
case 70:
#line 690 "syntaxpl0.y"
{
                int pos=find_sign(yyvsp[0].Identi.id);
                pos+=yyvsp[0].Identi.offset;
                all_type_val_value p;
                init_for_gen_pcode(p);
                if(yyvsp[0].Identi.type_==0 ||yyvsp[0].Identi.type_==4)
                {
                  yyval.count.type_=0;
                  yyval.count.i_val=symtable[pos].var.i_val;
                  p.type_=all_type_val_value::int_;
                  p.i_val=yyval.count.i_val;
                  if(symtable[pos].symtype_==Symbol::const_)
                    gen(instruction::LIT,0,symtable[pos].var.i_val,p);
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if(yyvsp[0].Identi.type_==1||yyvsp[0].Identi.type_==5)
                {
                  yyval.count.type_=1;
                  yyval.count.f_val=symtable[pos].var.f_val;
                  p.type_=all_type_val_value::float_;
                  p.f_val=yyval.count.f_val;
                  if(symtable[pos].symtype_==Symbol::const_)
                    gen(instruction::LIT,0,symtable[pos].var.f_val,p);
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }   
              ;
    break;}
case 71:
#line 718 "syntaxpl0.y"
{
                //$$=$1;
                yyval.count.type_=0;
                yyval.count.i_val=yyvsp[0].i_val;
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::int_;
                p.i_val=yyvsp[0].i_val;
                gen(instruction::LIT,0,yyvsp[0].i_val,p);
              ;
    break;}
case 72:
#line 728 "syntaxpl0.y"
{
                //$$=$1;
                yyval.count.type_=1;
                yyval.count.f_val=yyvsp[0].f_val;
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::float_;
                p.f_val=yyvsp[0].f_val;
                gen(instruction::LIT,0,yyvsp[0].f_val,p);
              ;
    break;}
case 73:
#line 738 "syntaxpl0.y"
{
                //$$=$2;
                if(yyvsp[-1].count.type_==0)
                {
                  yyval.count.type_=0;
                  yyval.count.i_val=yyvsp[-1].count.i_val;
                }
                else if(yyvsp[-1].count.type_==1)
                {
                  yyval.count.type_=1;
                  yyval.count.f_val=yyvsp[-1].count.f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
              ;
    break;}
case 74:
#line 757 "syntaxpl0.y"
{
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JMP,0,whilepos[whiletop--],p);
                backpatch(backPatch_table[backPatch_table_top--],code_line);
              ;
    break;}
case 75:
#line 764 "syntaxpl0.y"
{
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JMP,0,whilepos[whiletop--],p);
                backpatch(backPatch_table[backPatch_table_top--],code_line);
              ;
    break;}
case 76:
#line 771 "syntaxpl0.y"
{ 
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JPC,0,whilepos[whiletop--],p);
              ;
    break;}
case 77:
#line 777 "syntaxpl0.y"
{
                whilepos[++whiletop]=code_line;
              ;
    break;}
case 78:
#line 781 "syntaxpl0.y"
{
                backPatch_table[++backPatch_table_top]=code_line;
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JPC,0,0,p);
              ;
    break;}
case 79:
#line 789 "syntaxpl0.y"
{
                whilepos[++whiletop]=code_line;
              ;
    break;}
case 80:
#line 794 "syntaxpl0.y"
{
                if(find_pro(yyvsp[-1].str)==-1)
                {
                  std::cout<<MAGENTA<<"Semantic error! "<<yyvsp[-1].str<<" not found!"<<std::endl;
                  exit(1);
                }

                int pos=find_pro(yyvsp[-1].str);
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::CAL,current_Level-pro_stack[pos].level,pro_stack[pos].pos-1,p);
              ;
    break;}
case 81:
#line 807 "syntaxpl0.y"
{
                int pos=find_sign(yyvsp[-1].Identi.id);
                pos+=yyvsp[-1].Identi.offset;
                all_type_val_value p;
                init_for_gen_pcode(p);
                if(symtable[pos].var.type_==0||symtable[pos].var.type_==4)
                {
                  p.type_=all_type_val_value::int_;
                  gen(instruction::OPR,0,16,p);
                  gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if(symtable[pos].var.type_==1||symtable[pos].var.type_==5)
                {
                  p.type_=all_type_val_value::float_;
                  gen(instruction::OPR,0,16,p);
                  gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if(symtable[pos].var.type_==2)
                {
                  p.type_=all_type_val_value::char_;
                  gen(instruction::OPR,0,16,p);
                  gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if(symtable[pos].var.type_==3)
                {
                  p.type_=all_type_val_value::string_;
                  gen(instruction::OPR,0,16,p);
                  gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                
              ;
    break;}
case 82:
#line 839 "syntaxpl0.y"
{
                int pos=find_sign(yyvsp[-1].Identi.id);
                pos+=yyvsp[-1].Identi.offset;
                all_type_val_value p;
                init_for_gen_pcode(p);
                if(yyvsp[-1].Identi.type_==0 ||yyvsp[-1].Identi.type_==4)
                {
                  p.type_=all_type_val_value::int_;
                  p.i_val=symtable[pos].var.i_val;
                  if(symtable[pos].symtype_==Symbol::const_)
                    gen(instruction::LIT,0,symtable[pos].var.i_val,p);
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if(yyvsp[-1].Identi.type_==1||yyvsp[-1].Identi.type_==5)
                {
                  p.type_=all_type_val_value::float_;
                  p.f_val=symtable[pos].var.f_val;
                  
                  if(symtable[pos].symtype_==Symbol::const_)
                    gen(instruction::LIT,0,symtable[pos].var.f_val,p);
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if(yyvsp[-1].Identi.type_==2)
                {
                  p.type_=all_type_val_value::char_;
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if(yyvsp[-1].Identi.type_==3)
                {
                  p.type_=all_type_val_value::string_;
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                gen(instruction::OPR,0,14,p);
                gen(instruction::OPR,0,15,p);
              ;
    break;}
case 83:
#line 878 "syntaxpl0.y"
{
              all_type_val_value p;
              init_for_gen_pcode(p);
              p.type_=all_type_val_value::char_;
              char* temp=strdup(yyvsp[-1].str);
              temp[strlen(temp)-1]='\0';
              p.v_str=temp+1;
              gen(instruction::LIT,0,0,p);
              init_for_gen_pcode(p);
              gen(instruction::OPR,0,14,p);
              gen(instruction::OPR,0,15,p);
            ;
    break;}
case 84:
#line 890 "syntaxpl0.y"
{
              all_type_val_value p;
              init_for_gen_pcode(p);
              p.type_=all_type_val_value::string_;
              char* temp=strdup(yyvsp[-1].str);
              temp[strlen(temp)-1]='\0';
              p.v_str=temp+1;
              gen(instruction::LIT,0,0,p);
              init_for_gen_pcode(p);
              gen(instruction::OPR,0,14,p);
              gen(instruction::OPR,0,15,p);
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
#line 904 "syntaxpl0.y"


void yyerror(char const* s)
{
    //printf("%s,(%d,%d)\n",s,row,column);
    std::cout<<MAGENTA<<s<<" ("<<row<<","<<column<<")"<<std::endl;
    return;
}