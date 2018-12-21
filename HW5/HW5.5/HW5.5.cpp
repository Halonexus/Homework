#include <cstdio>
#include "Stack.h"
#include "StringOperations.h"
#include "StackCreation.h"
#include "StackCalculation.h"

void printMessage();
void getInput(char*& input);
void printOutput(const int output);
void freeMemory(char*);
void calculateStack(bool&, char*&);

int const stringLength = 256;

int main()
{
	bool isExiting = false;
	while (!isExiting)
	{
		char* input = nullptr;
		printMessage();
		getInput(input);
		calculateStack(isExiting, input);
	}
	return 0;
}

void calculateStack(bool& isExiting, char*& input)
{
	Stack stack;
	processString(input, stack);
	if (!input)
	{
		isExiting = true;
	}
	else
	{
		int output = calculateOutput(stack);
		printOutput(output);
		freeMemory(input);
	}
	return;
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