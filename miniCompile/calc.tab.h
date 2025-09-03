typedef union{
	char name[20];
    int int_val;

	struct strVariable{
		int intVar;
		float floatVar;
	}variable;

} YYSTYPE;
#define	TOK_SEMICOLON	257
#define	TOK_ADD	258
#define	TOK_SUB	259
#define	TOK_MUL	260
#define	TOK_DIV	261
#define	TOK_EQ	262
#define	TOK_INT	263
#define	TOK_FLOAT	264
#define	TOK_IDENT	265
#define	TOK_PRINTID	266
#define	TOK_PRINTEX	267
#define	TOK_EXIT	268
#define	TOK_MAIN	269
#define	TOK_OPENCURLY	270
#define	TOK_CLOSECURLY	271
#define	TOK_IDENT_ERR	272
#define	TOK_NUM	273
#define	TOK_FNUM	274


extern YYSTYPE yylval;
