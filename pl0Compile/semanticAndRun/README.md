## Compile the code & Run:

### 编译所有程序

```bash
flex LexicalPl0.l
bison SyntaxPl0.y -d
g++ -o pl0 main.cpp interpret.cpp lex.yy.c SyntaxPl0.tab.c define.cpp
```
或者

```bash
mkdir build
cd build
make
```
### 对测试程序进行分析

例如：运行test_sum.pl0

```shell
./pl0  ../succ_pl0/gcd.pl0 ../gcd.pcode
./pl0 ../error_pl0/column.pl0 ../column.pcode
```

## 文件夹描述

* src：源程序
* error_pl0:错误的pl0程序，用于测试报错
* succ_pl0: 正确的pl0程序
* pcode：生成的pcode文件
