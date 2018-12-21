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
	if (!element)
	{
		return nullptr;
	}
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

void addTreeElement(TreeElement*& element, Node*& node)
{
	if (!element)
	{
		element = new TreeElement{ node, 1, nullptr, nullptr };
		return;
	}
	if (element->node->f >= node->f)
	{
		addTreeElement(element->leftChild, node);
	}
	else if (element->node->f < node->f)
	{
		addTreeElement(element->rightChild, node);
	}
	element = balance(element);
	return;
}

void addTreeElement(AVLTree& tree, Node*& node)
{
	addTreeElement(tree.root, node);
	return;
}

void deleteTreeElement(TreeElement*& element, Node*& node)
{
	if (!element)
	{
		return;
	}
	if (element->node->f < node->f)
	{
		deleteTreeElement(element->rightChild, node);
	}
	else if (element->node->f > node->f)
	{
		deleteTreeElement(element->leftChild, node);
	}
	else
	{
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

void deleteTreeElement(AVLTree& tree, Node*& node)
{
	deleteTreeElement(tree.root, node);
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

int getNumberOfNodes(const TreeElement* element)
{
	if (!element)
	{
		return 0;
	}
	return getNumberOfNodes(element->leftChild) + getNumberOfNodes(element->rightChild) + 1;
}

int getNumberOfNodes(const AVLTree& tree)
{
	return getNumberOfNodes(tree.root);
}

Node* inTree(TreeElement*& tree, Node*& node)
{
	if (!tree)
	{
		return nullptr;
	}
	if (tree->node->number == node->number)
	{
		return tree->node;
	}
	Node* result = inTree(tree->leftChild, node);
	if (!result)
	{
		return inTree(tree->rightChild, node);
	}
	return result;
}

Node* inTree(AVLTree& tree, Node*& node)
{
	return inTree(tree.root, node);
}