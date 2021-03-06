#include "Stack.h"

void push(Stack& stack, const int value)
{
	if (!&stack)
	{
		return;
	}
	StackElement* newElement = new StackElement{ stack.head, value, nullptr };
	stack.head = newElement;
	return;
}

void push(Stack& stack, const char operation)
{
	if (!&stack)
	{
		return;
	}
	char* newChar = new char;
	*newChar = operation;
	StackElement* newElement = new StackElement{ stack.head, 0, newChar };
	stack.head = newElement;
	return;
}

StackElement* pop(Stack& stack)
{
	if (&stack && !isEmpty(stack))
	{
		int value = stack.head->value;
		StackElement* topElement = stack.head;
		stack.head = stack.head->next;
		return topElement;
	}
	return nullptr;
}

void deleteStack(Stack& stack)
{
	if (!&stack)
	{
		return;
	}
	while (stack.head)
	{
		StackElement* temp = stack.head->next;
		if (stack.head->operation)
		{
			delete stack.head->operation;
		}
		delete stack.head;
		stack.head = temp;
	}
	return;
}

void deleteElement(StackElement& element)
{
	if (element.operation)
	{
		delete element.operation;
	}
	delete &element;
	return;
}

bool isEmpty(const Stack& stack)
{
	if (&stack && stack.head)
	{
		return false;
	}
	return true;
}