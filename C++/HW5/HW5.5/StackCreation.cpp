#include "StackCreation.h"
#include "StringOperations.h"

void processString(char*& string, Stack& stack)
{
	int const stringLength = 256;
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
				push(stack, value);
			}
			else
			{
				Stack newStack, reverseStack;
				processString(subString, newStack);
				while (!isEmpty(newStack))
				{
					push(reverseStack, pop(newStack));
				}
				while (!isEmpty(reverseStack))
				{
					push(stack, pop(reverseStack));
				}
			}
			delete[] subString;
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