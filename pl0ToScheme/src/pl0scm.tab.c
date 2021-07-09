
/*  A Bison parser, made from pl0scm.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	B_CONST	257
#define	B_VAR	258
#define	B_PROCEDURE	259
#define	B_FUNCTION	260
#define	B_BEGIN	261
#define	B_END	262
#define	B_IF	263
#define	B_THEN	264
#define	B_ELSE	265
#define	B_WHILE	266
#define	B_DO	267
#define	B_CALL	268
#define	NUMBER	269
#define	COMPOP	270
#define	EQOP	271
#define	ODD	272
#define	WRITE	273
#define	WRITELN	274
#define	ASSIGNOP	275
#define	IDENT	276
#define	STRING	277
#define	LP	278
#define	RP	279
#define	ADDOP	280
#define	SUBOP	281
#define	MULOP	282
#define	DIVOP	283
#define	UMINUS	284

#line 1 "pl0scm.y"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "pl0def.h"

int yylex(void);
void yyerror(char* msg);

#define FUNC_RESULT_SUFFIX "-result"

static int n_indent = 0;

void put_indent();
Farg *new_farg(Node *pnode, Farg *top);
Node *new_node(char op, long val, char *ident, Farg *arglist,
		Node *left, Node *right);
void block_start();
void block_dec_end();
void block_end();
void proc_start(char *procname);
void proc_arg_end();
void proc_end();
void gen_condition(char *op, Node *lp, Node *rp);
void gen_odd(Node *p);
void gen_assign(char *ident, Node *p);
void gen_expr(Node *p);
void push_named_block(char *name);
void pop_named_block();
const char *get_current_block_name();


#line 36 "pl0scm.y"
typedef union {
	Node *pnode;
	Farg *farg;
	long val;
	char op[3];
	char *ident;
	char *string;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		139
#define	YYFLAG		-32768
#define	YYNTBASE	34

#define YYTRANSLATE(x) ((unsigned)(x) <= 284 ? yytranslate[x] : 81)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,    33,     2,    31,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,    32,     2,
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
    27,    28,    29,    30
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,    10,    11,    12,    13,    17,    19,    23,    27,
    28,    32,    34,    38,    40,    41,    44,    46,    48,    49,
    50,    59,    60,    61,    70,    71,    75,    77,    81,    83,
    84,    86,    88,    90,    92,    94,    96,    98,   100,   104,
   105,   110,   114,   115,   120,   121,   125,   127,   131,   132,
   133,   134,   143,   144,   145,   149,   150,   151,   158,   160,
   165,   170,   172,   176,   178,   180,   184,   188,   191,   195,
   199,   203,   207,   211,   214,   216,   218,   223,   224,   226,
   228
};

static const short yyrhs[] = {    35,
    31,     0,    36,    38,    41,    37,    44,    55,     0,     0,
     0,     0,     3,    39,    32,     0,    40,     0,    39,    33,
    40,     0,    22,    17,    15,     0,     0,     4,    42,    32,
     0,    43,     0,    42,    33,    43,     0,    22,     0,     0,
    44,    45,     0,    46,     0,    49,     0,     0,     0,     5,
    22,    47,    52,    32,    48,    35,    32,     0,     0,     0,
     6,    22,    50,    52,    32,    51,    35,    32,     0,     0,
    24,    53,    25,     0,    54,     0,    53,    33,    54,     0,
    22,     0,     0,    59,     0,    60,     0,    57,     0,    64,
     0,    70,     0,    73,     0,    74,     0,    55,     0,    56,
    32,    55,     0,     0,     7,    58,    56,     8,     0,    22,
    21,    78,     0,     0,    14,    22,    61,    62,     0,     0,
    24,    63,    25,     0,    78,     0,    63,    33,    78,     0,
     0,     0,     0,     9,    65,    77,    10,    66,    55,    67,
    68,     0,     0,     0,    11,    69,    55,     0,     0,     0,
    12,    71,    77,    13,    72,    55,     0,    20,     0,    20,
    24,    75,    25,     0,    19,    24,    75,    25,     0,    76,
     0,    75,    33,    76,     0,    78,     0,    23,     0,    78,
    16,    78,     0,    78,    17,    78,     0,    18,    78,     0,
    78,    26,    78,     0,    78,    27,    78,     0,    78,    28,
    78,     0,    78,    29,    78,     0,    24,    78,    25,     0,
    27,    78,     0,    15,     0,    22,     0,    22,    24,    79,
    25,     0,     0,    80,     0,    78,     0,    80,    33,    78,
     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    64,    67,    71,    74,    77,    78,    81,    82,    85,    88,
    89,    92,    93,    96,    99,   100,   103,   104,   107,   108,
   109,   112,   113,   114,   117,   118,   121,   122,   125,   128,
   129,   130,   131,   132,   133,   134,   135,   138,   139,   142,
   143,   146,   149,   150,   153,   154,   157,   158,   161,   162,
   163,   164,   167,   168,   169,   172,   173,   174,   177,   178,
   182,   185,   186,   189,   191,   194,   195,   196,   199,   200,
   201,   202,   203,   204,   206,   207,   208,   211,   212,   215,
   216
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","B_CONST",
"B_VAR","B_PROCEDURE","B_FUNCTION","B_BEGIN","B_END","B_IF","B_THEN","B_ELSE",
"B_WHILE","B_DO","B_CALL","NUMBER","COMPOP","EQOP","ODD","WRITE","WRITELN","ASSIGNOP",
"IDENT","STRING","LP","RP","ADDOP","SUBOP","MULOP","DIVOP","UMINUS","'.'","';'",
"','","program","block","block_start","block_dec_end","const_dec","const_list",
"const_elem","var_dec","var_list","var_elem","proc_func_dec","proc_func","proc_list",
"@1","@2","func_list","@3","@4","arg_list_dec","arg_list","arg_elem","statement",
"stmt_list","block_stmt","@5","assign","call_stmt","@6","actual_arg","expr_list",
"if_stmt","@7","@8","@9","else_part","@10","while_stmt","@11","@12","writeln_stmt",
"write_stmt","write_list","write_elem","condition","expr","farg","farg_list", NULL
};
#endif

static const short yyr1[] = {     0,
    34,    35,    36,    37,    38,    38,    39,    39,    40,    41,
    41,    42,    42,    43,    44,    44,    45,    45,    47,    48,
    46,    50,    51,    49,    52,    52,    53,    53,    54,    55,
    55,    55,    55,    55,    55,    55,    55,    56,    56,    58,
    57,    59,    61,    60,    62,    62,    63,    63,    65,    66,
    67,    64,    68,    69,    68,    71,    72,    70,    73,    73,
    74,    75,    75,    76,    76,    77,    77,    77,    78,    78,
    78,    78,    78,    78,    78,    78,    78,    79,    79,    80,
    80
};

static const short yyr2[] = {     0,
     2,     6,     0,     0,     0,     3,     1,     3,     3,     0,
     3,     1,     3,     1,     0,     2,     1,     1,     0,     0,
     8,     0,     0,     8,     0,     3,     1,     3,     1,     0,
     1,     1,     1,     1,     1,     1,     1,     1,     3,     0,
     4,     3,     0,     4,     0,     3,     1,     3,     0,     0,
     0,     8,     0,     0,     3,     0,     0,     6,     1,     4,
     4,     1,     3,     1,     1,     3,     3,     2,     3,     3,
     3,     3,     3,     2,     1,     1,     4,     0,     1,     1,
     3
};

static const short yydefact[] = {     3,
     0,     5,     1,     0,    10,     0,     0,     7,     0,     4,
     0,     6,     0,    14,     0,    12,    15,     9,     8,    11,
     0,    30,    13,     0,     0,    40,    49,    56,     0,     0,
    59,     0,    16,    17,    18,     2,    33,    31,    32,    34,
    35,    36,    37,    19,    22,    30,     0,     0,    43,     0,
     0,     0,    25,    25,    38,     0,    75,     0,    76,     0,
     0,     0,     0,     0,    45,    65,     0,    62,    64,     0,
    42,     0,     0,     0,    41,    30,    68,    78,     0,    74,
    50,     0,     0,     0,     0,     0,     0,    57,     0,    44,
    61,     0,    60,    29,     0,    27,    20,    23,    39,    80,
     0,    79,    73,    30,    66,    67,    69,    70,    71,    72,
    30,     0,    47,    63,    26,     0,     3,     3,    77,     0,
    51,    58,    46,     0,    28,     0,     0,    81,    53,    48,
    21,    24,    54,    52,    30,    55,     0,     0,     0
};

static const short yydefgoto[] = {   137,
     1,     2,    17,     5,     7,     8,    10,    15,    16,    22,
    33,    34,    53,   117,    35,    54,   118,    73,    95,    96,
    36,    56,    37,    46,    38,    39,    65,    90,   112,    40,
    47,   104,   129,   134,   135,    41,    48,   111,    42,    43,
    67,    68,    62,    69,   101,   102
};

static const short yypact[] = {-32768,
   -26,    26,-32768,    24,    49,    44,   -10,-32768,    35,-32768,
    51,-32768,    24,-32768,    18,-32768,-32768,-32768,-32768,-32768,
    35,    12,-32768,    45,    46,-32768,-32768,-32768,    47,    48,
    50,    52,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    40,    69,    69,-32768,    75,
    75,    21,    53,    53,-32768,    -7,-32768,    21,    61,    21,
    21,    66,    54,    65,    62,-32768,   -21,-32768,   -18,   -19,
   -18,    70,    56,    63,-32768,    40,   -18,    21,    78,-32768,
-32768,    21,    21,    21,    21,    21,    21,-32768,    21,-32768,
-32768,    75,-32768,-32768,    -5,-32768,-32768,-32768,-32768,   -18,
    76,    67,-32768,    40,   -18,   -18,    27,    27,-32768,-32768,
    40,     2,   -18,-32768,-32768,    70,-32768,-32768,-32768,    21,
-32768,-32768,-32768,    21,-32768,    77,    79,   -18,    83,   -18,
-32768,-32768,-32768,-32768,    40,-32768,   108,   110,-32768
};

static const short yypgoto[] = {-32768,
   -54,-32768,-32768,-32768,-32768,    99,-32768,-32768,    92,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    60,-32768,    -1,
   -46,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    68,    25,    72,   -45,-32768,-32768
};


#define	YYLAST		120


static const short yytable[] = {    55,
    75,    63,    63,    91,     3,    93,    71,    84,    85,    86,
    87,    92,    77,    92,    79,    80,    24,    25,    26,   115,
    27,    12,    13,    28,    76,    29,   123,   116,     4,    99,
    30,    31,   100,    32,   124,    57,   105,   106,   107,   108,
   109,   110,    59,   113,    60,     6,    26,    61,    27,    20,
    21,    28,     9,    29,    86,    87,    14,   121,    30,    31,
    11,    32,   126,   127,   122,    18,    44,    45,    49,    82,
    83,    50,    52,    51,   128,    81,    72,    88,   130,    84,
    85,    86,    87,    57,    78,    89,    58,    97,   136,    57,
    59,    94,    60,   133,    98,    61,    59,    66,    60,   120,
   119,    61,   103,    84,    85,    86,    87,   138,   131,   139,
   132,    19,    23,    74,   125,     0,   114,     0,    70,    64
};

static const short yycheck[] = {    46,
     8,    47,    48,    25,    31,    25,    52,    26,    27,    28,
    29,    33,    58,    33,    60,    61,     5,     6,     7,    25,
     9,    32,    33,    12,    32,    14,    25,    33,     3,    76,
    19,    20,    78,    22,    33,    15,    82,    83,    84,    85,
    86,    87,    22,    89,    24,    22,     7,    27,     9,    32,
    33,    12,     4,    14,    28,    29,    22,   104,    19,    20,
    17,    22,   117,   118,   111,    15,    22,    22,    22,    16,
    17,    24,    21,    24,   120,    10,    24,    13,   124,    26,
    27,    28,    29,    15,    24,    24,    18,    32,   135,    15,
    22,    22,    24,    11,    32,    27,    22,    23,    24,    33,
    25,    27,    25,    26,    27,    28,    29,     0,    32,     0,
    32,    13,    21,    54,   116,    -1,    92,    -1,    51,    48
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
#line 64 "pl0scm.y"
{ YYACCEPT; ;
    break;}
case 2:
#line 68 "pl0scm.y"
{ block_end(); ;
    break;}
case 3:
#line 71 "pl0scm.y"
{ block_start(); ;
    break;}
case 4:
#line 74 "pl0scm.y"
{ block_dec_end(); ;
    break;}
case 9:
#line 85 "pl0scm.y"
{ put_indent();printf("  (%s %ld);const\n",yyvsp[-2].ident,yyvsp[0].val);;
    break;}
case 14:
#line 96 "pl0scm.y"
{ put_indent(); printf("  (%s 0)\n",yyvsp[0].ident); ;
    break;}
case 19:
#line 107 "pl0scm.y"
{ proc_start(yyvsp[0].ident); ;
    break;}
case 20:
#line 108 "pl0scm.y"
{ proc_arg_end(); ;
    break;}
case 21:
#line 109 "pl0scm.y"
{ proc_end(); ;
    break;}
case 22:
#line 112 "pl0scm.y"
{ proc_start(yyvsp[0].ident); push_named_block(yyvsp[0].ident); ;
    break;}
case 23:
#line 113 "pl0scm.y"
{ proc_arg_end(); ;
    break;}
case 24:
#line 114 "pl0scm.y"
{ proc_end(); pop_named_block(); ;
    break;}
case 29:
#line 125 "pl0scm.y"
{ printf(" %s", yyvsp[0].ident); ;
    break;}
case 39:
#line 139 "pl0scm.y"
{ free_memory_holder(); ;
    break;}
case 40:
#line 142 "pl0scm.y"
{ put_indent(); printf("(begin\n"); n_indent++; ;
    break;}
case 41:
#line 143 "pl0scm.y"
{ n_indent--; put_indent(); printf(")\n"); ;
    break;}
case 42:
#line 146 "pl0scm.y"
{ gen_assign(yyvsp[-2].ident, yyvsp[0].pnode); ;
    break;}
case 43:
#line 149 "pl0scm.y"
{ put_indent(); printf("(%s ", yyvsp[0].ident); ;
    break;}
case 44:
#line 150 "pl0scm.y"
{ printf(")\n"); ;
    break;}
case 47:
#line 157 "pl0scm.y"
{ gen_expr(yyvsp[0].pnode); ;
    break;}
case 48:
#line 158 "pl0scm.y"
{ gen_expr(yyvsp[0].pnode); ;
    break;}
case 49:
#line 161 "pl0scm.y"
{ put_indent(); printf("(if "); n_indent++; ;
    break;}
case 50:
#line 162 "pl0scm.y"
{ printf("\n"); ;
    break;}
case 51:
#line 163 "pl0scm.y"
{ n_indent--; ;
    break;}
case 52:
#line 164 "pl0scm.y"
{ put_indent(); printf(")\n"); ;
    break;}
case 54:
#line 168 "pl0scm.y"
{ n_indent++; ;
    break;}
case 55:
#line 169 "pl0scm.y"
{ n_indent--; ;
    break;}
case 56:
#line 172 "pl0scm.y"
{ put_indent(); printf("(while "); n_indent++; ;
    break;}
case 57:
#line 173 "pl0scm.y"
{ printf("\n"); ;
    break;}
case 58:
#line 174 "pl0scm.y"
{ n_indent--; put_indent(); printf(")\n"); ;
    break;}
case 59:
#line 177 "pl0scm.y"
{ put_indent(); printf("(display \"\\n\")\n"); ;
    break;}
case 60:
#line 179 "pl0scm.y"
{ put_indent(); printf("(display \"\\n\")\n"); ;
    break;}
case 64:
#line 189 "pl0scm.y"
{ put_indent(); printf("(display ");
				gen_expr(yyvsp[0].pnode); printf(")\n"); ;
    break;}
case 65:
#line 191 "pl0scm.y"
{ put_indent(); printf("(display \"%s\")\n", yyvsp[0].string); ;
    break;}
case 66:
#line 194 "pl0scm.y"
{ gen_condition(yyvsp[-1].op, yyvsp[-2].pnode, yyvsp[0].pnode); ;
    break;}
case 67:
#line 195 "pl0scm.y"
{ gen_condition(yyvsp[-1].op, yyvsp[-2].pnode, yyvsp[0].pnode); ;
    break;}
case 68:
#line 196 "pl0scm.y"
{ gen_odd(yyvsp[0].pnode); ;
    break;}
case 69:
#line 199 "pl0scm.y"
{ yyval.pnode = new_node('+', 0, NULL, NULL, yyvsp[-2].pnode, yyvsp[0].pnode); ;
    break;}
case 70:
#line 200 "pl0scm.y"
{ yyval.pnode = new_node('-', 0, NULL, NULL, yyvsp[-2].pnode, yyvsp[0].pnode); ;
    break;}
case 71:
#line 201 "pl0scm.y"
{ yyval.pnode = new_node('*', 0, NULL, NULL, yyvsp[-2].pnode, yyvsp[0].pnode); ;
    break;}
case 72:
#line 202 "pl0scm.y"
{ yyval.pnode = new_node('/', 0, NULL, NULL, yyvsp[-2].pnode, yyvsp[0].pnode); ;
    break;}
case 73:
#line 203 "pl0scm.y"
{ yyval.pnode = yyvsp[-1].pnode; ;
    break;}
case 74:
#line 205 "pl0scm.y"
{ yyval.pnode = new_node('M', 0, NULL, NULL, NULL, yyvsp[0].pnode); ;
    break;}
case 75:
#line 206 "pl0scm.y"
{ yyval.pnode = new_node('C', yyvsp[0].val, NULL,NULL,NULL,NULL); ;
    break;}
case 76:
#line 207 "pl0scm.y"
{ yyval.pnode = new_node('I', 0, yyvsp[0].ident, NULL, NULL, NULL); ;
    break;}
case 77:
#line 208 "pl0scm.y"
{ yyval.pnode = new_node('F', 0, yyvsp[-3].ident, yyvsp[-1].farg, NULL, NULL); ;
    break;}
case 78:
#line 211 "pl0scm.y"
{ yyval.farg = NULL; ;
    break;}
case 79:
#line 212 "pl0scm.y"
{ yyval.farg = yyvsp[0].farg; ;
    break;}
case 80:
#line 215 "pl0scm.y"
{ yyval.farg = new_farg(yyvsp[0].pnode, NULL); ;
    break;}
case 81:
#line 216 "pl0scm.y"
{ yyval.farg = new_farg(yyvsp[0].pnode, yyvsp[-2].farg); ;
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
#line 218 "pl0scm.y"


static int line_num = 1;

void inc_line_num()
{
	line_num++;
}

int main()
{
	extern int yyparse();
	int exit_code;

	exit_code = yyparse();
	free_memory_holder();
	return exit_code;
}

void yyerror(char *s)
{
	fprintf(stderr, "(%d): %s\n", line_num, s);
}

int yywrap(void)
{
    return 1;
}

void put_indent()
{
	int i;

	for (i = 0; i < n_indent; i++) {
		printf("  ");
	}
}

Farg *new_farg(Node *pnode, Farg *top)
{
	Farg *farg_ptr = hold_memory(malloc(sizeof (Farg)));
	Farg *res = farg_ptr;
	Farg *p;

	assert(farg_ptr != NULL);

	farg_ptr->node = pnode;
	farg_ptr->next = NULL;
	if (top != NULL) {
		res = top;
		for (p = top; p->next != NULL; p = p->next)
			;
		p->next = farg_ptr;
	}
	return res;
}

Node *new_node(char op, long val, char *ident, Farg *arglist,
		Node *left, Node *right)
{
	Node *node_ptr = hold_memory(malloc(sizeof (Node)));
	assert(node_ptr != NULL);

	node_ptr->op = op;
	node_ptr->val = val;
	node_ptr->ident = ident;
	node_ptr->arglist = arglist;
	node_ptr->left = left;
	node_ptr->right = right;
	return node_ptr;
}

void block_start()
{
	const char *blockName = get_current_block_name();

	put_indent();
	printf("(let (");
	if (blockName != NULL) {
		printf("(%s%s #f)", blockName, FUNC_RESULT_SUFFIX);
	}
	printf("\n");
	n_indent++;
}

void block_dec_end()
{
	put_indent();
	printf(")\n");
}

void block_end()
{
	const char *blockName = get_current_block_name();

	if (blockName != NULL) {
		put_indent();
		printf("%s%s\n", blockName, FUNC_RESULT_SUFFIX);
	}
	n_indent--;
	put_indent();
	printf(")\n");
}

void proc_start(char *procname)
{
	put_indent();
	printf("(define (%s ", procname);
	n_indent++;
}

void proc_arg_end()
{
	printf(")\n");
}

void proc_end()
{
	n_indent--;
	put_indent();
	printf(")\n");
}

void gen_condition(char *op, Node *lp, Node *rp)
{
	printf("(%s", op);
	gen_expr(lp);
	gen_expr(rp);
	printf(")");
}

void gen_odd(Node *p)
{
	printf("(odd? ");
	gen_expr(p);
	printf(")");
}

void gen_assign(char *ident, Node *p)
{
	const char *blockName = get_current_block_name();

	put_indent();
	if (blockName != NULL && strcmp(ident, blockName) == 0) {
		printf("(set! %s%s ", blockName, FUNC_RESULT_SUFFIX);
	} else {
		printf("(set! %s ", ident);
	}
	gen_expr(p);
	printf(")\n");
}

void gen_expr(Node *p)
{
	Node *l = p->left;
	Node *r = p->right;
	Farg *args = p->arglist;

	printf(" ");
	switch (p->op) {
	case '+':
		printf("(+");
		gen_expr(l);
		gen_expr(r);
		printf(")");
		break;
	case '-':
		printf("(-");
		gen_expr(l);
		gen_expr(r);
		printf(")");
		break;
	case '*':
		printf("(*");
		gen_expr(l);
		gen_expr(r);
		printf(")");
		break;
	case '/':
		printf("(/");
		gen_expr(l);
		gen_expr(r);
		printf(")");
		break;
	case 'M':
		assert(r != NULL);
		printf("(- ");
		gen_expr(r);
		printf(")");
		break;
	case 'C':
		printf("%ld", p->val);
		break;
	case 'I':
		printf("%s", p->ident);
		break;
	case 'F':	/* function */
		printf("(%s ", p->ident);
		while (args != NULL) {
			gen_expr(args->node);
			args = args->next;
		}
		printf(")");
		break;
	}
}

/*----------------------------------------------------------------*/

typedef struct {
	char *name;
} NamedBlock;

#define MAX_NAMED_BLOCKS	256
static NamedBlock named_blocks[MAX_NAMED_BLOCKS];
static int named_block_index = 0;

void push_named_block(char *name)
{
	NamedBlock *bp;

	assert(named_block_index < MAX_NAMED_BLOCKS - 1);

	bp = &named_blocks[++named_block_index];
	bp->name = strdup(name);
	assert(bp->name != NULL);
}

void pop_named_block()
{
	assert(named_block_index > 0);
	free(named_blocks[named_block_index].name);
	named_block_index--;
}

const char *get_current_block_name()
{
	return named_blocks[named_block_index].name;
}

/*----------------------------------------------------------------*/

typedef struct MemoryHolder {
	void *memory;
	struct MemoryHolder *next;
} MemoryHolder;

static MemoryHolder *memory_holder_head = NULL;

void *hold_memory(void *memory)
{
	MemoryHolder *hp = malloc(sizeof (MemoryHolder));

	assert(memory != NULL);
	assert(hp != NULL);

	hp->memory = memory;
	hp->next = memory_holder_head;
	memory_holder_head = hp;
	return memory;
}

void free_memory_holder()
{
	MemoryHolder *hp = memory_holder_head;
	while (hp != NULL) {
		MemoryHolder *next = hp->next;
		free(hp->memory);
		free(hp);
		hp = next;
	}
	memory_holder_head = NULL;
}
