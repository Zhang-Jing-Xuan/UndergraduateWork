## 编译运行

```bash
bison -d yacc.y
flex lex.l
g++ -c lex.yy.c
g++ -c yacc.tab.c
g++ lex.yy.o yacc.tab.o -o main
./main
```

或者

```bash
mkdir build
cd build
make
将file.txt复制到build目录下
./main
```