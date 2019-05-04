#include "StackCalculation.h"

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