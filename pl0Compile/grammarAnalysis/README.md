## Compile the code & Run:

### 编译所有程序

```shell
flex LexicalPl0.l
bison SyntaxPl0.y -d
g++ SyntaxPl0.tab.c lex.yy.c -o res
g++ -std=c++11 draw.cpp -o draw
```

### 对测试程序进行分析

例如：运行test_sum.pl0

```shell
./res < ../tests/test_sum.pl0
```

### 画图

```shell
./draw
dot -Tpng ASTvis.gv -o AST.png
```

### 结果文件

* SynOutput.txt
  * 按照规约顺序用到语法规则序列
* AST.png
  * 语法树

## Instructions:

### 各个文件功能

* draw.cpp
  * 画图函数，通过读取词法和文法分析的输出结果建立抽象语法树(Abstract Syntax Tree, AST)
  * 将AST输出到一个dot可以运行到文件ASTvis.gv中
* SyntaxPl0.y
  * 语法分析器
* LexicalPl0.l
  * 词法分析器
* main.h
  * 语法分析器和词法分析器的共同的头文件
