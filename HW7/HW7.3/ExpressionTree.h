#pragma once

struct TreeElement
{
	char operation = '\0';
	int value = 0;
	TreeElement* leftChild = nullptr;
	TreeElement* rightChild = nullptr;
};

struct ExpressionTree
{
	TreeElement* root = nullptr;
};

void deleteTree(ExpressionTree* tree);
void printTree(ExpressionTree* tree);
int calculateOutput(ExpressionTree* tree);