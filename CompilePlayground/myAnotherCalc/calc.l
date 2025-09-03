%{
#include <stdio.h>
#include <stdlib.h>
#include "calc.tab.h" // bison -d calc.y
// int yylex();
%}

/* %option noyywrap */

%%
[0-9]+(\.[0-9]+)?([eE][0-9]+)?  {yylval.f = atof(yytext);return NUM;}    
[-+()*/]                        {return yytext[0];}
[ \t\f\v\n]                     { ;}
%%

int yywrap (void) {return 1;}
