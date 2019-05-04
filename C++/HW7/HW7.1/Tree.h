#pragma once

struct TreeElement
{
	int value;
	int amount;
	TreeElement* leftChild;
	TreeElement* rightChild;
};

struct Tree 
{
	TreeElement* root = nullptr;
};

void addTreeElement(Tree& tree, int value);
void deleteTreeElement(Tree& tree, int value);
void deleteTree(Tree& tree);
TreeElement*& getMinElement(TreeElement*& element);
TreeElement*& getMaxElement(TreeElement*& element);
bool isEmpty(const Tree& tree);