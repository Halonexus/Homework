#pragma once

struct TreeElement
{
	char character;
	int amount;
	int height;
	TreeElement* leftChild;
	TreeElement* rightChild;
};

struct AVLTree
{
	TreeElement* root = nullptr;
};

void addTreeElement(AVLTree& tree, char character);
void deleteTreeElement(AVLTree& tree, char character);
void deleteTree(AVLTree& tree);
int height(const TreeElement* element);
TreeElement*& getMinElement(TreeElement*& element);
TreeElement*& getMaxElement(TreeElement*& element);
bool isEmpty(const AVLTree& tree);
int getNumberOfNodes(const AVLTree& tree);