#include <cstdio>
#include "ExpressionTree.h"
#include "StringOperations.h"

void deleteTree(TreeElement*& element)
{
	if (!element)
	{
		return;
	}
	deleteTree(element->leftChild);
	deleteTree(element->rightChild);
	delete element;
	return;
}

void deleteTree(ExpressionTree* tree)
{
	if (!tree)
	{
		return;
	}
	deleteTree(tree->root);
	return;
}

int performOperation(char operation, int value1, int value2)
{
	switch (operation)
	{
	case '+':
	{
		return value1 + value2;
		break;
	}
	case '-':
	{
		return value1 - value2;
		break;
	}
	case '*':
	{
		return value1 * value2;
		break;
	}
	case '/':
	{
		return value1 / value2;
		break;
	}
	default:
		break;
	}
	return 0;
}

int calculateOutput(TreeElement*& element)
{
	if (!element)
	{
		return 0;
	}
	if (element->operation == '\0')
	{
		return element->value;
	}
	return performOperation(element->operation, calculateOutput(element->leftChild), calculateOutput(element->rightChild));
}

int calculateOutput(ExpressionTree* tree)
{
	if (!tree)
	{
		return 0;
	}
	return calculateOutput(tree->root);
}

void printTree(const TreeElement* const & element)
{
	if (element)
	{
		fputs("( ", stdout);
		if (element->operation == '\0')
		{
			char* temp = intToString(element->value);
			fputs(temp, stdout);
			delete[] temp;
		}
		else
		{
			char temp[2] = { element->operation,'\0' };
			fputs(temp, stdout);
		}
		fputs(" ", stdout);
		printTree(element->leftChild);
		printTree(element->rightChild);
		fputs(")", stdout);
	}
	else
	{
		fputs("null ", stdout);
	}
	return;
}

void printTree(ExpressionTree* tree)
{
	printTree(tree->root);
	return;
}