#pragma once
#include "AStar.h"

struct StackElement
{
	StackElement* next = nullptr;
	Node* node = nullptr;
};

struct Stack
{
	StackElement* head = nullptr;
};

void push(Stack&, Node*);
StackElement* pop(Stack&);
void deleteStack(Stack&);
void deleteElement(StackElement&);
bool isEmpty(const Stack&);