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
int findPriority(const char operation);

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
	Stack operations;
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '(')
		{
			i++;
			char* subString = new char[stringLength];
			int innerBrackets = 0;
			int length = 0;
			while (string[i] != ')' || innerBrackets > 0)
			{
				if (string[i] == '(')
				{
					innerBrackets++;
				}
				else if (string[i] == ')')
				{
					innerBrackets--;
				}
				subString[length++] = string[i++];
			}
			subString[length] = '\0';
			int value = 0;
			if (subString[0] == '-')
			{
				value = parse(subString);
			}
			else
			{
				Stack newStack;
				processString(subString, newStack);				
				value = calculateOutput(newStack);
			}
			delete[] subString;
			push(stack, value);			
		}
		else if (string[i] >= '0' && string[i] <= '9')
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
			int priority = findPriority(string[i]);
			while (!isEmpty(operations) && findPriority(*operations.head->operation) >= priority)
			{
				StackElement* temp = pop(operations);
				push(stack, *temp->operation);
				deleteElement(*temp);
			}
			push(operations, string[i]);			
		}
		i++;
	}
	while (!isEmpty(operations))
	{
		StackElement* temp = pop(operations);
		push(stack, *temp->operation);
		deleteElement(*temp);
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

int findPriority(const char operation)
{
	int priority = 0;
	char priorityList[] = { '+', '-', '*', '/' };
	for (int i = 0; i < 4; i++)
	{
		if (priorityList[i] == operation)
		{
			priority = i / 2;
			break;
		}
	}
	return priority;
}