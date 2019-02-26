#include "Calculator.h"
#include "StackCreation.h"
#include "StackCalculation.h"

int calculateStack(bool& isExiting, char*& input)
{
	Stack stack;
	processString(input, stack);
	if (!input)
	{
		isExiting = true;
	}
	else
	{
		return calculateOutput(stack);
	}
	return 0;
}