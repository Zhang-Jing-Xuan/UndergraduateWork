## bison -d yacc.y

## flex lex.l

## g++ -c lex.yy.c

## g++ -c yacc.tab.c

## g++ lex.yy.o yacc.tab.o -o main

## ./main