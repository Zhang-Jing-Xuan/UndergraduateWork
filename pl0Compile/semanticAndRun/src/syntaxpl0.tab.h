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


extern YYSTYPE yylval;
