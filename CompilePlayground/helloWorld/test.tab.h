typedef union{
	  char name[20];
    int number;
} YYSTYPE;
#define	STRING	257
#define	NUM	258
#define	OTHER	259
#define	SEMICOLON	260


extern YYSTYPE yylval;
