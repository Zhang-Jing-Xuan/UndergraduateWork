typedef union {
	Node *pnode;
	Farg *farg;
	long val;
	char op[3];
	char *ident;
	char *string;
} YYSTYPE;
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


extern YYSTYPE yylval;
