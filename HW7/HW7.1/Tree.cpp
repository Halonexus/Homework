#include "Tree.h"

void addTreeElement(TreeElement*& element, int value)
{
	if (!element)
	{
		element = new TreeElement{ value, 1, nullptr, nullptr };
		return;
	}
	if (element->value > value)
	{
		addTreeElement(element->leftChild, value);
	}
	else if (element->value < value)
	{
		addTreeElement(element->rightChild, value);
	}
	else
	{
		element->amount++;
	}
	return;
}

void addTreeElement(Tree& tree, int value)
{
	addTreeElement(tree.root, value);
	return;
}

void deleteTreeElement(TreeElement*& element, int value)
{
	if (!element)
	{
		return;
	}
	if (value > element->value)
	{
		deleteTreeElement(element->rightChild, value);
	}
	else if (value < element->value)
	{
		deleteTreeElement(element->leftChild, value);
	}
	else
	{
		if (element->amount > 1)
		{
			element->amount--;
			return;
		}
		TreeElement* temp = nullptr;
		if (element->leftChild && element->rightChild)
		{
			temp = getMaxElement(element->leftChild);
			getMaxElement(element->leftChild) = nullptr;
			temp->rightChild = element->rightChild;
			getMinElement(temp)->leftChild = element->leftChild;
		}
		else if (element->leftChild)
		{
			temp = element->leftChild;
		}
		else
		{
			temp = element->rightChild;
		}
		delete element;
		element = temp;
	}
	return;
}

void deleteTreeElement(Tree& tree, int value)
{
	deleteTreeElement(tree.root, value);
	return;
}

void deleteTree(TreeElement*& element)
{
	if (element)
	{
		deleteTree(element->leftChild);
		deleteTree(element->rightChild);
		delete element;
	}
	return;
}

void deleteTree(Tree& tree)
{
	deleteTree(tree.root);
	return;
}

TreeElement*& getMinElement(TreeElement*& element)
{
	if (element->leftChild)
	{
		return getMinElement(element->leftChild);
	}
	return element;
}

TreeElement*& getMaxElement(TreeElement*& element)
{
	if (element->rightChild)
	{
		return getMaxElement(element->rightChild);
	}
	return element;
}

bool isEmpty(const Tree& tree)
{
	return !tree.root;
}