#pragma once
#include "AStar.h"

struct TreeElement
{
	Node* node;
	int height;
	TreeElement* leftChild;
	TreeElement* rightChild;
};

struct AVLTree
{
	TreeElement* root = nullptr;
};

void addTreeElement(AVLTree& tree, Node*& node);
void deleteTreeElement(AVLTree& tree, Node*& node);
void deleteTree(AVLTree& tree);
int height(const TreeElement* element);
TreeElement*& getMinElement(TreeElement*& element);
TreeElement*& getMaxElement(TreeElement*& element);
bool isEmpty(const AVLTree& tree);
int getNumberOfNodes(const AVLTree& tree);
Node* inTree(AVLTree& tree, Node*& node);