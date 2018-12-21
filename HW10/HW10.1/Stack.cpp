#include "Stack.h"

void push(Stack& stack, Node* node)
{
	if (!&stack)
	{
		return;
	}
	StackElement* newElement = new StackElement{ stack.head, node };
	stack.head = newElement;
	return;
}

StackElement* pop(Stack& stack)
{
	if (&stack && !isEmpty(stack))
	{
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
		if (stack.head->node)
		{
			delete stack.head->node;
		}
		delete stack.head;
		stack.head = temp;
	}
	return;
}

void deleteElement(StackElement& element)
{
	if (element.node)
	{
		delete element.node;
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