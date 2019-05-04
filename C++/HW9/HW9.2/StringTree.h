#pragma once
#include <cstdio>

struct Element
{
	char* string = nullptr;
	char* binaryString = nullptr;
	int amount = 0;
	Element* leftChild = nullptr;
	Element* rightChild = nullptr;
};

struct StringTree
{
	Element* root = nullptr;
};

StringTree* createTree(Element* root);
void deleteTree(StringTree* tree);
void makeBinary(StringTree* tree);
void printTreeNodes(const StringTree* const & tree, FILE* file);