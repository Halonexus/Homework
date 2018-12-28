#include "StringTree.h"
#include "StringOperations.h"

StringTree* createTree(Element* root)
{
	return new StringTree{ root };
}

void deleteTree(Element*& element)
{
	if (!element)
	{
		return;
	}
	deleteTree(element->leftChild);
	deleteTree(element->rightChild);
	if (element->string)
	{
		delete[] element->string;
	}
	if (element->binaryString)
	{
		delete[] element->binaryString;
	}
	delete element;
	return;
}

void deleteTree(StringTree* tree)
{
	if (!tree)
	{
		return;
	}
	deleteTree(tree->root);
	return;
}

void makeBinary(Element* element, char* string)
{
	if (!element)
	{
		return;
	}
	element->binaryString = string;
	if (element->leftChild)
	{
		makeBinary(element->leftChild, concatenate(string, "0"));
	}
	if (element->rightChild)
	{
		makeBinary(element->rightChild, concatenate(string, "1"));
	}
	return;
}

void makeBinary(StringTree* tree)
{
	if (!tree->root->leftChild && !tree->root->rightChild)
	{
		tree->root->binaryString = new char[2]{ '0', '\0' };
		return;
	}
	if (tree->root->leftChild)
	{
		makeBinary(tree->root->leftChild, new char[2]{ '0', '\0' });
	}
	if (tree->root->rightChild)
	{
		makeBinary(tree->root->rightChild, new char[2]{ '1', '\0' });
	}
	return;
}

void printTreeNodes(const Element* const & element, FILE* file)
{
	if (!file)
	{
		return;
	}
	if (element)
	{
		fputs("( ", file);
		fputs(element->string, file);
		fputs(" ", file);
		printTreeNodes(element->leftChild, file);
		printTreeNodes(element->rightChild, file);
		fputs(")", file);
	}
	else
	{
		fputs("()", file);
	}
	return;
}

void printTreeNodes(const StringTree* const & tree, FILE* file)
{
	printTreeNodes(tree->root, file);
	return;
}