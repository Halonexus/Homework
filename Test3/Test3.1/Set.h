#pragma once

#include "AVLTree.h"

struct Set
{
	AVLTree tree;
};

void addSetElement(Set& set, int value);
void deleteSetElement(Set& set, int value);
void deleteSet(Set& set);
void printSet(const Set& set, int mode);
bool isInSet(const Set& set, int value);
bool isEmpty(const Set& set);
void printTreeAscendingNoCopies(const Set& set);