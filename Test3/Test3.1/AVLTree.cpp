#include "AVLTree.h"

int height(const TreeElement* element)
{
	return element ? element->height : 0;
}

void updateHeight(TreeElement* element)
{
	int heightLeft = height(element->leftChild);
	int heightRight = height(element->rightChild);
	element->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
	return;
}

int balanceFactor(TreeElement* element)
{
	return height(element->rightChild) - height(element->leftChild);
}

TreeElement* rotateRight(TreeElement* element)
{
	TreeElement* pivot = element->leftChild;
	element->leftChild = pivot->rightChild;
	pivot->rightChild = element;
	updateHeight(element);
	updateHeight(pivot);
	return pivot;
}

TreeElement* rotateLeft(TreeElement* element)
{
	TreeElement* pivot = element->rightChild;
	element->rightChild = pivot->leftChild;
	pivot->leftChild = element;
	updateHeight(element);
	updateHeight(pivot);
	return pivot;
}

TreeElement* balance(TreeElement* element)
{
	updateHeight(element);
	if (balanceFactor(element) == 2)
	{
		if ((element->rightChild) < 0)
		{
			element->rightChild = rotateRight(element->rightChild);
		}
		return rotateLeft(element);
	}
	if (balanceFactor(element) == -2)
	{
		if (balanceFactor(element->leftChild) > 0)
		{
			element->leftChild = rotateLeft(element->leftChild);
		}
		return rotateRight(element);
	}
	return element;
}

void addTreeElement(TreeElement*& element, int value)
{
	if (!element)
	{
		element = new TreeElement{ value, 1, 1, nullptr, nullptr };
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
	element = balance(element);
	return;
}

void addTreeElement(AVLTree& tree, int value)
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
	element = balance(element);
	return;
}

void deleteTreeElement(AVLTree& tree, int value)
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

void deleteTree(AVLTree& tree)
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

bool isEmpty(const AVLTree& tree)
{
	return !tree.root;
}