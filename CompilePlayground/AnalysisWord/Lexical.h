#ifndef MyLexical
#define MyLexical

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH_OF_A_WORD 20		//一个单词的最多字符个数
#define NUMBER_OF_RESERVED_WORDS 19 //保留字个数
#define MAX_NUMBER_OF_WORDS 1000	//可识别的最多单词个数
#define OK 1						//返回一个真值
#define ERROR 0						//返回一个假值
#define SPACE 32					//SPACE空格的ASCII码值
#define RETURN 10					//RETURN换行的ASCII码值
#define TABLE 9						//TABLE的ASCII码值

enum WORD_TYPE_ENUM
{				  //单词类型枚举值
	INVALID_WORD, //非法单词
	ReservedWord,
	NUMBER,
	VAR, //用户定义的标识符
	COMMA,
	SEMICOLON,
	PERIOD,
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE,
	MAIN,
	USING,
	NAMESPACE,
	STD,
	INCLUDE,
	CHAR,
	INT,
	LONG,
	FLOAT,
	DOUBLE,
	DO,
	WHILE,
	FOR,
	SWITCH,
	CASE,
	CLASS,
	IF,
	STRUCT,
	STRING,
	THEN,
	NOT,
	CONST,
	LEFT_BRACKET,
	RIGHT_BRACKET,
	LEFT_BRACE,
	RIGHT_BRACE,
	DQM,
	INPUT,
	OUTPUT,
	EQL,
	EQU,
	NEQ,
	LES,
	LEQ,
	GTR,
	GEQ,
	ASSIGN,
	PREPROCESSOR,
	SELFMINUS,
	SELFPLUS,
	AND,
	OR,
	XOR,
};

struct RESERVED_WORD_NAME_VS_TYPE_STRUCT
{
	char szName[20];
	enum WORD_TYPE_ENUM eType;
};

#define SOURCE_FILE_NAME "SourceFile1.pl1"

struct WORD_STRUCT
{
	char szName[MAX_LENGTH_OF_A_WORD];
	enum WORD_TYPE_ENUM eType;
	int nNumberValue;
	int nLineNo;
};

int WordTypeToString(char string[100], WORD_TYPE_ENUM eWordType);
void PrintInLexis(int nWordsIndex);
int GetAWord();
void InitializeReservedWordTable();
void InitializeSingleCharacterTable();
void LexicalAnalysis();
char GetACharacterFromFile();
void PrintInLexis(int nIndex);
int WordTypeToString(char strString[100], WORD_TYPE_ENUM eWordType);
void PrintSourceFile();
int Initialization();
#endif