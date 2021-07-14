// #include "stdafx.h"
#include "Lexical.h"
RESERVED_WORD_NAME_VS_TYPE_STRUCT ReservedWordNameVsTypeTable[NUMBER_OF_RESERVED_WORDS];
WORD_TYPE_ENUM SingleCharacterWordTypeTable[256];
WORD_STRUCT g_Words[MAX_NUMBER_OF_WORDS];
int g_nWordsIndex;
int g_nLineNo = 1;
FILE *fpSourceFile = fopen(SOURCE_FILE_NAME, "r");

int Initialization()
{
	char szFileName[100];

	strcpy(szFileName, SOURCE_FILE_NAME);
	if ((fpSourceFile = fopen(szFileName, "r")) == NULL)
	{
		printf("Can not open source file %s\n", szFileName);
		return ERROR;
	}
	return OK;
}

void PrintSourceFile()
{
	char cACharacter;
	fseek(fpSourceFile, 0L, SEEK_SET);

	while (fscanf(fpSourceFile, "%c", &cACharacter) != EOF)
		printf("%c", cACharacter);
}
// main,using,namespace,std,include,char,int,long,float,double,do,while,for,switch,case,class,if,struct string
void InitializeReservedWordTable() //设置保留字单词的名字字符串和相应类型的对照表
{
	strcpy(ReservedWordNameVsTypeTable[0].szName, "main");
	ReservedWordNameVsTypeTable[0].eType = MAIN;
	strcpy(ReservedWordNameVsTypeTable[1].szName, "using");
	ReservedWordNameVsTypeTable[1].eType = USING;
	strcpy(ReservedWordNameVsTypeTable[2].szName, "namespace");
	ReservedWordNameVsTypeTable[2].eType = NAMESPACE;
	strcpy(ReservedWordNameVsTypeTable[3].szName, "std");
	ReservedWordNameVsTypeTable[3].eType = STD;
	strcpy(ReservedWordNameVsTypeTable[4].szName, "include");
	ReservedWordNameVsTypeTable[4].eType = INCLUDE;
	strcpy(ReservedWordNameVsTypeTable[5].szName, "char");
	ReservedWordNameVsTypeTable[5].eType = CHAR;
	strcpy(ReservedWordNameVsTypeTable[6].szName, "int");
	ReservedWordNameVsTypeTable[6].eType = INT;
	strcpy(ReservedWordNameVsTypeTable[7].szName, "long");
	ReservedWordNameVsTypeTable[7].eType = LONG;
	strcpy(ReservedWordNameVsTypeTable[8].szName, "float");
	ReservedWordNameVsTypeTable[8].eType = FLOAT;
	strcpy(ReservedWordNameVsTypeTable[9].szName, "double");
	ReservedWordNameVsTypeTable[9].eType = DOUBLE;
	strcpy(ReservedWordNameVsTypeTable[10].szName, "do");
	ReservedWordNameVsTypeTable[10].eType = DO;
	strcpy(ReservedWordNameVsTypeTable[11].szName, "while");
	ReservedWordNameVsTypeTable[11].eType = WHILE;
	strcpy(ReservedWordNameVsTypeTable[12].szName, "for");
	ReservedWordNameVsTypeTable[12].eType = FOR;
	strcpy(ReservedWordNameVsTypeTable[13].szName, "switch");
	ReservedWordNameVsTypeTable[13].eType = SWITCH;
	strcpy(ReservedWordNameVsTypeTable[14].szName, "case");
	ReservedWordNameVsTypeTable[14].eType = CASE;
	strcpy(ReservedWordNameVsTypeTable[15].szName, "class");
	ReservedWordNameVsTypeTable[15].eType = CLASS;
	strcpy(ReservedWordNameVsTypeTable[16].szName, "if");
	ReservedWordNameVsTypeTable[16].eType = IF;
	strcpy(ReservedWordNameVsTypeTable[17].szName, "struct");
	ReservedWordNameVsTypeTable[17].eType = STRUCT;
	strcpy(ReservedWordNameVsTypeTable[18].szName, "string");
	ReservedWordNameVsTypeTable[18].eType = STRING;
}

void InitializeSingleCharacterTable() //设置单字符单词的字符和相应类型的对照表
{
	int i;
	for (i = 0; i <= 255; i++)
	{
		SingleCharacterWordTypeTable[i] = INVALID_WORD;
	}

	SingleCharacterWordTypeTable['<'] = LES;
	SingleCharacterWordTypeTable['>'] = GTR;
	SingleCharacterWordTypeTable['+'] = PLUS;
	SingleCharacterWordTypeTable['-'] = MINUS;
	SingleCharacterWordTypeTable['*'] = MULTIPLY;
	SingleCharacterWordTypeTable['/'] = DIVIDE;
	SingleCharacterWordTypeTable['('] = LEFT_BRACKET;
	SingleCharacterWordTypeTable[')'] = RIGHT_BRACKET;
	SingleCharacterWordTypeTable['{'] = LEFT_BRACE;
	SingleCharacterWordTypeTable['}'] = RIGHT_BRACE;
	SingleCharacterWordTypeTable['"'] = DQM;
	SingleCharacterWordTypeTable['='] = ASSIGN;
	SingleCharacterWordTypeTable[','] = COMMA;
	SingleCharacterWordTypeTable['!'] = NOT;
	SingleCharacterWordTypeTable[';'] = SEMICOLON;
	SingleCharacterWordTypeTable['#'] = PREPROCESSOR;

	SingleCharacterWordTypeTable['&'] = AND;
	SingleCharacterWordTypeTable['|'] = OR;
	SingleCharacterWordTypeTable['^'] = XOR;
}

//词法分析
void LexicalAnalysis()
{
	int nResult;
	InitializeReservedWordTable();	   //设置保留字单词的名字字符串和相应类型的对照表
	InitializeSingleCharacterTable();  //设置单字符单词的字符和相应类型的对照表
	fseek(fpSourceFile, 0L, SEEK_SET); //源程序文件的文件指针指向起始位置

	printf("\n----------------Lexical Analysis Begin!--------------\n");

	g_nWordsIndex = 1; //g_nWordsIndex是已识别单词的序号

	nResult = GetAWord(); //词法分析,识别第一个单词
	while (nResult == OK && g_nWordsIndex >= 1)
	{
		PrintInLexis(g_nWordsIndex - 1); //打印一个单词

		nResult = GetAWord(); //词法分析,识别下一个单词
	}

	printf("----------------Lexical Analysis Funished!--------------\n");
}
//从文件中读取一个字符然后返回
char GetACharacterFromFile(char &cACharacter)
{
	//char	cACharacter;

	//从文件中读取的一个字符
	if (fscanf(fpSourceFile, "%c", &cACharacter) == EOF)
		cACharacter = EOF;

	if (cACharacter == RETURN) //如果是回车符
		g_nLineNo++;		   //源代码行数加一

	return cACharacter; //返回从文件中读取的一个字符
}

int GetAWord() //词法分析,获取一个单词
{
	static char cACharacter = ' '; //当前字符
	//char    cACharacter=' ';
	int nAWordIndex;  //单词数组下标,表示单词第几个字符
	int nDigitNumber; //数单词的字符个数
	int i;
	char szAWord[MAX_LENGTH_OF_A_WORD + 1];
	int nNumberValue; //数的值
	//忽略空格、换行和TAB
	while ((cACharacter == SPACE || cACharacter == RETURN || cACharacter == TABLE) && cACharacter != EOF)
		GetACharacterFromFile(cACharacter); //从文件中读取一个字符然后返回
											//	printf("%s",cACharacter);

	if (cACharacter != EOF) //如果不是文件末尾
	{
		if (cACharacter >= 'a' && cACharacter <= 'z' || cACharacter >= 'A' && cACharacter <= 'Z' || cACharacter == '_') //如果当前字符是小写的字母
		{																												//标识符或保留字以a..z开头
			nAWordIndex = 0;																							//单词的第一个字符
			do
			{
				if (nAWordIndex < MAX_LENGTH_OF_A_WORD)
					szAWord[nAWordIndex++] = cACharacter; //把当前字符放进单词数组里,单词数组下标加一

				GetACharacterFromFile(cACharacter); //从文件中再读取一个字符
			} while ((cACharacter >= 'a' && cACharacter <= 'z' || cACharacter >= 'A' && cACharacter <= 'Z' || cACharacter >= '0' && cACharacter <= '9' || cACharacter == '_') && cACharacter != EOF);
			//只要后面继续跟a..z或0..9,就要继续看后面的字符

			//当前字符不再是a..z或0..9
			if (cACharacter != EOF) //如果不是文件末尾
			{
				szAWord[nAWordIndex] = 0; //以0结尾,在单词数组中组成一个单词字符串

				for (i = 0; i < NUMBER_OF_RESERVED_WORDS; i++) //从保留字表中查询当前单词字符串是否为某一保留字字符串
					if (strcmp(szAWord, ReservedWordNameVsTypeTable[i].szName) == 0)
					{
						//如果是保留字,则赋当前单词类型为相应保留字的单词类型枚举值
						g_Words[g_nWordsIndex].eType = ReservedWordNameVsTypeTable[i].eType;
						break;
					}
				if (i >= NUMBER_OF_RESERVED_WORDS)
					//如果在保留字表中查询不出,则当前单词是标识符,单词类型为单词类型枚举值IDENTIFIER
					g_Words[g_nWordsIndex].eType = VAR;

				strcpy(g_Words[g_nWordsIndex].szName, szAWord); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo;		//在源代码文件中单词所在的行数

				g_nWordsIndex++; //识别出的单词个数加一

				return OK;
			}
			else
				return ERROR;
		}
		else if (cACharacter >= '0' && cACharacter <= '9')
		{					  //数字是以0..9开头
			nDigitNumber = 0; //数单词的字符个数
			nNumberValue = 0; //数单词的值
			do
			{
				szAWord[nDigitNumber++] = cACharacter;
				nNumberValue = 10 * nNumberValue + cACharacter - '0'; //计算数单词的值

				//cACharacter=GetACharacterFromFile();//再取下一个字符
				GetACharacterFromFile(cACharacter);
			} while (cACharacter >= '0' && cACharacter <= '9' && cACharacter != EOF); //如果是0..9,则继续拼装数单词

			//如果不是0..9则数单词结束
			if (cACharacter != EOF)
			{
				szAWord[nDigitNumber] = 0; //以0结尾在单词数组中组成一个数单词字符串

				g_Words[g_nWordsIndex].eType = NUMBER;				//单词类型为单词类型枚举值NUMBER
				strcpy(g_Words[g_nWordsIndex].szName, szAWord);		//识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nNumberValue = nNumberValue; //同时将数的值赋给单词的nNumberValue
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo;			//在源代码文件中单词所在的行数

				g_nWordsIndex++; //识别出的单词个数加一

				return OK;
			}
			else
				return ERROR;
		}

		else if (cACharacter == '=') //当前符号是'='？
		{
			//cACharacter=GetACharacterFromFile();//如果当前符号是'=',则要再看下一个符号
			GetACharacterFromFile(cACharacter);

			if (cACharacter >= '0' && cACharacter <= '9' || cACharacter >= 'a' && cACharacter <= 'z')
			//如果下一个符号是数字
			{												//则单词是赋值符号":="
				g_Words[g_nWordsIndex].eType = ASSIGN;		//单词类型为单词类型枚举值ASSIGN
				strcpy(g_Words[g_nWordsIndex].szName, "="); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo; //在源代码文件中单词所在的行数

				g_nWordsIndex++; //识别出的单词个数加一

				//cACharacter=GetACharacterFromFile();//再取一个符号,为下一步准备
				//	GetACharacterFromFile(cACharacter);
				return OK;
			}

			else if (cACharacter == '=')
			//如果下一个符号是=
			{												 //则单词是赋值符号":="
				g_Words[g_nWordsIndex].eType = EQU;			 //单词类型为单词类型枚举值ASSIGN
				strcpy(g_Words[g_nWordsIndex].szName, "=="); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo;	 //在源代码文件中单词所在的行数

				g_nWordsIndex++; //识别出的单词个数加一

				//cACharacter=GetACharacterFromFile();//再取一个符号,为下一步准备
				GetACharacterFromFile(cACharacter);
				return OK;
			}
		}

		//////////////////////////////////////////////////////////////
		else if (cACharacter == '+') //检测是"<"还是"<="单词?
		{
			//cACharacter=GetACharacterFromFile();//再取一个符号
			GetACharacterFromFile(cACharacter);
			if (cACharacter == '+')
			{												 //单词是"<="
				g_Words[g_nWordsIndex].eType = SELFPLUS;	 //单词类型为单词类型枚举值LEQ
				strcpy(g_Words[g_nWordsIndex].szName, "++"); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo;	 //在源代码文件中单词所在的行数

				g_nWordsIndex++; //识别出的单词个数加一

				//cACharacter=GetACharacterFromFile();//再取一个符号,为下一步准备
				GetACharacterFromFile(cACharacter);
				return OK;
			}else{
				g_Words[g_nWordsIndex].eType = PLUS;			//单词类型为单词类型枚举值LES
				strcpy(g_Words[g_nWordsIndex].szName, "+"); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo; //在源代码文件中单词所在的行数

				g_nWordsIndex++; //识别出的单词个数加一

				return OK;
			}
		}

		else if (cACharacter == '-') //检测是"<"还是"<="单词?
		{
			//cACharacter=GetACharacterFromFile();//再取一个符号
			GetACharacterFromFile(cACharacter);
			if (cACharacter == '-')
			{												 //单词是"<="
				g_Words[g_nWordsIndex].eType = SELFMINUS;	 //单词类型为单词类型枚举值LEQ
				strcpy(g_Words[g_nWordsIndex].szName, "--"); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo;	 //在源代码文件中单词所在的行数

				g_nWordsIndex++; //识别出的单词个数加一

				//cACharacter=GetACharacterFromFile();//再取一个符号,为下一步准备
				GetACharacterFromFile(cACharacter);
				return OK;
			}else{
				g_Words[g_nWordsIndex].eType = MINUS;			//单词类型为单词类型枚举值LES
				strcpy(g_Words[g_nWordsIndex].szName, "-"); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo; //在源代码文件中单词所在的行数

				g_nWordsIndex++; //识别出的单词个数加一

				return OK;
			}
		}
		////////////////////////////////////////////////////////////////////
		else if (cACharacter == '<') //检测是"<"还是"<="单词?
		{
			//cACharacter=GetACharacterFromFile();//再取一个符号
			GetACharacterFromFile(cACharacter);
			if (cACharacter == '=')
			{												 //单词是"<="
				g_Words[g_nWordsIndex].eType = LEQ;			 //单词类型为单词类型枚举值LEQ
				strcpy(g_Words[g_nWordsIndex].szName, "<="); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo;	 //在源代码文件中单词所在的行数

				g_nWordsIndex++; //识别出的单词个数加一

				//cACharacter=GetACharacterFromFile();//再取一个符号,为下一步准备
				GetACharacterFromFile(cACharacter);
				return OK;
			}

			if (cACharacter == '<')
			{												 //单词仅是">"
				g_Words[g_nWordsIndex].eType = OUTPUT;		 //单词类型为单词类型枚举值
				strcpy(g_Words[g_nWordsIndex].szName, "<<"); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo;

				g_nWordsIndex++; //识别出的单词个数加一
				GetACharacterFromFile(cACharacter);
				return OK;
			}
			else
			{												//单词仅是"<"
				g_Words[g_nWordsIndex].eType = LES;			//单词类型为单词类型枚举值LES
				strcpy(g_Words[g_nWordsIndex].szName, "<"); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo; //在源代码文件中单词所在的行数

				g_nWordsIndex++; //识别出的单词个数加一

				return OK;
			}
		}
		else if (cACharacter == '>') //检测是">"还是">>"单词?
		{
			//cACharacter=GetACharacterFromFile();//再取一个符号
			GetACharacterFromFile(cACharacter);
			if (cACharacter == '=')
			{												 //单词是">="
				g_Words[g_nWordsIndex].eType = GEQ;			 //单词类型为单词类型枚举值GEQ
				strcpy(g_Words[g_nWordsIndex].szName, ">="); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo;

				g_nWordsIndex++; //识别出的单词个数加一

				//cACharacter=GetACharacterFromFile();//再取一个符号,为下一步准备
				GetACharacterFromFile(cACharacter);
			}
			if (cACharacter == '>')
			{												 //单词仅是">"
				g_Words[g_nWordsIndex].eType = INPUT;		 //单词类型为单词类型枚举值
				strcpy(g_Words[g_nWordsIndex].szName, ">>"); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo;

				g_nWordsIndex++; //识别出的单词个数加一
				GetACharacterFromFile(cACharacter);
				return OK;
			}

			else
			{												//单词仅是">"
				g_Words[g_nWordsIndex].eType = GTR;			//单词类型为单词类型枚举值GTR
				strcpy(g_Words[g_nWordsIndex].szName, ">"); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo;

				g_nWordsIndex++; //识别出的单词个数加一
			}
			return OK;
		}

		if (cACharacter == '!') //检测是"!"还是"!="单词?
		{
			//cACharacter=GetACharacterFromFile();//再取一个符号
			GetACharacterFromFile(cACharacter);
			if (cACharacter == '=')
			{												 //单词是"!="
				g_Words[g_nWordsIndex].eType = NEQ;			 //单词类型为单词类型枚举值NEQ
				strcpy(g_Words[g_nWordsIndex].szName, "!="); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo;

				g_nWordsIndex++; //识别出的单词个数加一

				//cACharacter=GetACharacterFromFile();//再取一个符号,为下一步准备
				GetACharacterFromFile(cACharacter);
			}
			else
			{												//单词仅是"!"
				g_Words[g_nWordsIndex].eType = NOT;			//单词类型为单词类型枚举值NOT
				strcpy(g_Words[g_nWordsIndex].szName, "!"); //识别出的单词放进单词队列g_Words中
				g_Words[g_nWordsIndex].nLineNo = g_nLineNo;

				g_nWordsIndex++; //识别出的单词个数加一
			}
			return OK;
		}

		else
		{ //当不满足上述条件时,则是单字符
			//通过查表寻找单字符的单词类型枚举值
			g_Words[g_nWordsIndex].eType = SingleCharacterWordTypeTable[cACharacter];
			g_Words[g_nWordsIndex].szName[0] = cACharacter; //单词放进单词队列g_Words中
			g_Words[g_nWordsIndex].szName[1] = 0;			//以0结尾组成一个字符串
			g_Words[g_nWordsIndex].nLineNo = g_nLineNo;

			g_nWordsIndex++; //识别出的单词个数加一

			//cACharacter=GetACharacterFromFile();//再取一个符号,为下一步准备
			GetACharacterFromFile(cACharacter);
			return OK;
		}
	}
	return ERROR;
}
/////////////////////////////////////////////////////////////////////////////////
void PrintInLexis(int nIndex) //打印单词队列中的一个单词
{
	char szWordName[100];
	char szWordType[100];

	strcpy(szWordName, g_Words[nIndex].szName);
	WordTypeToString(szWordType, g_Words[nIndex].eType); //将单词类型的枚举值转换成字符串

	switch (g_Words[nIndex].eType)
	{

	case NUMBER:
		printf("%-4d%-15s%-20s%-10d\n", nIndex, szWordName, szWordType, g_Words[nIndex].nNumberValue);
		break;
	case VAR:
	case MAIN:
	case USING:
	case NAMESPACE:
	case STD:
	case INCLUDE:
	case CHAR:
	case INT:
	case LONG:
	case FLOAT:
	case DOUBLE:
	case DO:
	case WHILE:
	case FOR:
	case SWITCH:
	case CASE:
	case CLASS:
	case IF:
	case STRUCT:
	case STRING:
	case LEFT_BRACKET:
	case RIGHT_BRACKET:
	case LEFT_BRACE:
	case RIGHT_BRACE:
	case DQM:
	case INPUT:
	case OUTPUT:
	case EQU:
	case ASSIGN:
	case PREPROCESSOR:
	case SELFMINUS:
	case SELFPLUS:
	case AND:
	case OR:
	case XOR:
	default:
		printf("%-4d%-15s%-20s\n", nIndex, szWordName, szWordType);
	}
}
//将单词类型的枚举值转换成字符串
int WordTypeToString(char strString[100], WORD_TYPE_ENUM eWordType)
{
	switch (eWordType)
	{
	case NUMBER:
		strcpy(strString, "NUMBER");
		break;
	case PLUS:
		strcpy(strString, "PLUS");
		break;
	case MULTIPLY:
		strcpy(strString, "MULTIPLY");
		break;
	case MINUS:
		strcpy(strString, "MINUS");
		break;
	case DIVIDE:
		strcpy(strString, "DIVIDE");
		break;
	case LES:
		strcpy(strString, "LES");
		break;
	case LEQ:
		strcpy(strString, "LEQ");
		break;
	case GTR:
		strcpy(strString, "GTR");
		break;
	case GEQ:
		strcpy(strString, "GEQ");
		break;
	case EQU:
		strcpy(strString, "EQU");
		break;
	case NEQ:
		strcpy(strString, "NEQ");
		break;
	case NOT:
		strcpy(strString, "NOT");
		break;
	case LEFT_BRACKET:
		strcpy(strString, "LEFT_BRACKET");
		break;
	case RIGHT_BRACKET:
		strcpy(strString, "RIGHT_BRACKET");
		break;
	case LEFT_BRACE:
		strcpy(strString, "LEFT_BRACE");
		break;
	case RIGHT_BRACE:
		strcpy(strString, "RIGHT_BRACE");
		break;
	case COMMA:
		strcpy(strString, "COMMA");
		break;
	case SEMICOLON:
		strcpy(strString, "SEMICOLON");
		break;
	case PERIOD:
		strcpy(strString, "PERIOD");
		break;
	case ASSIGN:
		strcpy(strString, "ASSIGN");
		break;
	case CONST:
		strcpy(strString, "CONST");
		break;
	case VAR:
		strcpy(strString, "VAR");
		break;
	case IF:
		strcpy(strString, "IF");
		break;
	case THEN:
		strcpy(strString, "THEN");
		break;
	case WHILE:
		strcpy(strString, "WHILE");
		break;
	case DO:
		strcpy(strString, "DO");
		break;
	case MAIN:
		strcpy(strString, "MAIN");
		break;
	case USING:
		strcpy(strString, "USING");
		break;
	case NAMESPACE:
		strcpy(strString, "NAMESPACE");
		break;
	case STD:
		strcpy(strString, "STD");
		break;
	case INCLUDE:
		strcpy(strString, "INCLUDE");
		break;
	case CHAR:
		strcpy(strString, "CHAR");
		break;
	case INT:
		strcpy(strString, "INT");
		break;
	case LONG:
		strcpy(strString, "LONG");
		break;
	case FLOAT:
		strcpy(strString, "FLOAT");
		break;
	case DOUBLE:
		strcpy(strString, "DOUBLE");
		break;
	case FOR:
		strcpy(strString, "FOR");
		break;
	case SWITCH:
		strcpy(strString, "SWITCH");
		break;
	case CASE:
		strcpy(strString, "CASE");
		break;
	case CLASS:
		strcpy(strString, "CLASS");
		break;
	case STRUCT:
		strcpy(strString, "STRUCT");
		break;
	case STRING:
		strcpy(strString, "STRING");
		break;
	case INPUT:
		strcpy(strString, "INPUT");
		break;
	case OUTPUT:
		strcpy(strString, "OUTPUT");
		break;
	case PREPROCESSOR:
		strcpy(strString, "PREPROCESSOR");
		break;
	case DQM:
		strcpy(strString, "DQM");
		break;
	case INVALID_WORD:
		strcpy(strString, "INVALID_WORD");
		break;
	case SELFMINUS:
		strcpy(strString, "SELFMINUS");
		break;
	case SELFPLUS:
		strcpy(strString, "SELFPLUS");
		break;
	case AND:
		strcpy(strString, "AND");
		break;
	case OR:
		strcpy(strString, "OR");
		break;
	case XOR:
		strcpy(strString, "XOR");
		break;
	}
	return NULL;
}