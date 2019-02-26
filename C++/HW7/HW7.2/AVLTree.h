#pragma once

struct TreeElement
{
	int value;
	int amount;
	int height;
	TreeElement* leftChild;
	TreeElement* rightChild;
};

struct AVLTree
{
	TreeElement* root = nullptr;
};

void addTreeElement(AVLTree& tree, int value);
void deleteTreeElement(AVLTree& tree, int value);
void deleteTree(AVLTree& tree);
int height(const TreeElement* element);
TreeElement*& getMinElement(TreeElement*& element);
TreeElement*& getMaxElement(TreeElement*& element);
bool isEmpty(const AVLTree& tree);