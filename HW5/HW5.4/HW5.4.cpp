#include <cstdio>
#include "Stack.h"
#include "StringOperations.h"

void printMessage();
void getInput(char*& input);
void processString(char*& string, Stack& stack);
int calculateOutput(Stack& stack);
int performOperation(const char operation, int lhsValue, int rhsValue);
void printOutput(const int output);
void freeMemory(char*);

int const stringLength = 256;

int main()
{
	bool isExiting = false;
	while (!isExiting)
	{
		char* input = nullptr;
		Stack stack;
		printMessage();
		getInput(input);
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
	fputs("\tEnter the numbers and operations in postfix notation.\n\tEnter \"q\" to exit.\n", stdout);
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

void processString(char*& string, Stack& stack)
{
	if (!string)
	{
		return;
	}
	if (string[0] == 'q')
	{
		delete[] string;
		string = nullptr;
		return;
	}
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] >= '0' && string[i] <= '9')
		{
			char* number = new char[12];
			int digits = 0;
			while (string[i] >= '0' && string[i] <= '9')
			{
				number[digits++] = string[i++];
			}
			number[digits] = '\0';
			int value = parse(number);
			delete[] number;
			push(stack, value);
			i--;
		}
		else if (string[i] == '*' || string[i] == '+' || string[i] == '-' || string[i] == '/')
		{
			push(stack, string[i]);
		}
		i++;
	}
	return;
}

int calculateOutput(Stack& stack)
{
	int result = 0;
	if (!isEmpty(stack))
	{
		StackElement* temp = pop(stack);
		if (temp->operation)
		{
			result = performOperation(*temp->operation, calculateOutput(stack), calculateOutput(stack));
		}
		else
		{
			result = temp->value;
		}
		deleteElement(*temp);
	}
	return result;
}

int performOperation(const char operation, int lhsValue, int rhsValue)
{
	int result = 0;
	switch (operation)
	{
	case '+':
	{
		result = lhsValue + rhsValue;
		break;
	}
	case '-':
	{
		result = lhsValue - rhsValue;
		break;
	}
	case '*':
	{
		result = lhsValue * rhsValue;
		break;
	}
	case '/':
	{
		result = lhsValue / rhsValue;
		break;
	}
	default:
		break;
	}
	return result;
}