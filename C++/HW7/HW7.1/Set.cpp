#include "Set.h"
#include <cstdio>

void addSetElement(Set& set, int value)
{
	addTreeElement(set.tree, value);
	return;
}

void deleteSetElement(Set& set, int value)
{
	deleteTreeElement(set.tree, value);
	return;
}

void deleteSet(Set& set)
{
	deleteTree(set.tree);
	return;
}

void printTreeAscending(const TreeElement* const & element)
{
	if (element)
	{
		printTreeAscending(element->leftChild);
		for (int i = 0; i < element->amount; i++)
		{
			printf("%d ", element->value);
		}
		printTreeAscending(element->rightChild);
	}
	return;
}

void printTreeDescending(const TreeElement* const & element)
{
	if (element)
	{
		printTreeDescending(element->rightChild);
		for (int i = 0; i < element->amount; i++)
		{
			printf("%d ", element->value);
		}
		printTreeDescending(element->leftChild);
	}
	return;
}

void printTreeNodes(const TreeElement* const & element)
{
	if (element)
	{
		printf("( ");
		for (int i = 0; i < element->amount; i++)
		{
			printf("%d ", element->value);
		}
		printTreeNodes(element->leftChild);
		printTreeNodes(element->rightChild);
		printf(")");
	}
	else
	{
		printf("null ");
	}
	return;
}

void printSet(const Set& set, int mode)
{
	switch (mode)
	{
	case -1:
	{
		printTreeDescending(set.tree.root);
		break;
	}
	case 0:
	{
		printTreeNodes(set.tree.root);
		break;
	}
	case 1:
	{
		printTreeAscending(set.tree.root);
		break;
	}
	default:
		break;
	}
	printf("\n");
	return;
}

bool isInSet(const Set& set, int value)
{
	TreeElement* current = set.tree.root;
	while (current)
	{
		if (value > current->value)
		{
			current = current->rightChild;
		}
		else if (value < current->value)
		{
			current = current->leftChild;
		}
		else
		{
			return true;
		}
	}
	return false;
}

bool isEmpty(const Set& set)
{
	return !set.tree.root;
}