// g++ -o lex Lexical.cpp Parsing.cpp PL0Compiler1_Net.cpp -w

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

// enum	WORD_TYPE_ENUM;

void InitializeSingleCharacterTable();
void InitializeReservedWordTable();
void PrintSourceFile();
int Initialization();
void LexicalAnalysis();
int ParsingAnalysis();
int GenerateAnalysis();
void Interpreter();

//#define		SOURCE_FILE_NAME				"D:\\PL0_SourceFile\\SourceFile1.pl0"
#define SOURCE_FILE_NAME "SourceFile1.pl2"

FILE *fpSourceFile;

int main(int argc, char *argv[])
{
	Initialization();
	PrintSourceFile();
	getchar();

	LexicalAnalysis();
	getchar();

	ParsingAnalysis();
	getchar();

	// GenerateAnalysis();
	// getchar();

	// Interpreter();
	// getchar();

	return 0;
}

int Initialization()
{
	char szFileName[100];

	strcpy(szFileName, SOURCE_FILE_NAME);
	if ((fpSourceFile = fopen(szFileName, "r")) == NULL)
	{
		printf("Can not open source file %s", szFileName);
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
