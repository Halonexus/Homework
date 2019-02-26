#pragma once

struct StackElement
{
	StackElement* next = nullptr;
	int value = 0;
	char* operation = nullptr;
};

struct Stack
{
	StackElement* head = nullptr;
};

void push(Stack&, const int);
void push(Stack&, const char);
void push(Stack&, const StackElement* const);
StackElement* pop(Stack&);
void deleteStack(Stack&);
void deleteElement(StackElement&);
bool isEmpty(const Stack&);