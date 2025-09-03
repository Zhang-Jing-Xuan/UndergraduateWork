// PL0Complier.cpp : Defines the entry point for the console application.

/*
g++ -o lex Lexical.cpp PL0Complier.cpp
./lex
*/

// #include "stdafx.h"
#include "Lexical.h"

//int ParsingAnalysis();
//int GenerateAnalysis();
//void Interpreter();

int main()
{
	Initialization();
	PrintSourceFile();

	LexicalAnalysis();
	getchar();

	/*
	ParsingAnalysis();
	getchar();

	GenerateAnalysis();
	getchar();

	interpreter();
	getchar();
	*/
	return 0;
}
