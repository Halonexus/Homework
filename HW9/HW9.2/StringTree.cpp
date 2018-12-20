#include "StringTree.h"
#include "StringOperations.h"

StringTree* createTree(Element* root)
{
	StringTree* tree = new StringTree{ root };
	return tree;
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
	makeBinary(element->leftChild, concatenate(string, "0"));
	makeBinary(element->rightChild, concatenate(string, "1"));
	return;
}

void makeBinary(StringTree* tree)
{
	if (!tree->root->leftChild && !tree->root->rightChild)
	{
		makeBinary(tree->root, new char[2]{ '0', '\0' });
		return;
	}
	makeBinary(tree->root->leftChild, new char[2]{ '0', '\0' });
	makeBinary(tree->root->rightChild, new char[2]{ '1', '\0' });
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