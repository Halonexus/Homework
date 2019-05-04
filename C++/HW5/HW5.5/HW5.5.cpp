#include <cstdio>
#include "StringOperations.h"
#include "Calculator.h"

void printMessage();
void getInput(char*& input);
void printOutput(const int output);
void freeMemory(char*);

int const stringLength = 256;

int main()
{
	bool isExiting = false;
	while (!isExiting)
	{
		char* input = nullptr;
		printMessage();
		getInput(input);
		int result = calculateStack(isExiting, input);
		if (isExiting)
		{
			break;
		}
		printOutput(result);
		freeMemory(input);
	}
	return 0;
}

void printOutput(const int output)
{
	char* temp = intToString(output);
	fputs("Result: ", stdout);
	fputs(temp, stdout);
	fputs("\n\n", stdout);
	delete[] temp;
	return;
}

void printMessage()
{
	fputs("\tEnter the numbers and operations.\n\tEnter \"q\" to exit. Use (- ) to enter negative numbers\n", stdout);
	return;
}

void getInput(char*& input)
{
	input = new char[stringLength];
	fgets(input, stringLength, stdin);
	int length = getLength(input);
	if (length > 0 && input[length - 1] == '\n')
	{
		input[length - 1] = '\0';
	}
	return;
}

void freeMemory(char* string)
{
	if (string)
	{
		delete[] string;
	}
	return;
}