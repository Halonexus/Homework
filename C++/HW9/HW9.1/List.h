#pragma once

struct ListElement
{
	ListElement* next = nullptr;
	int value = 0;
};

struct List
{
	ListElement* head = nullptr;
};

void addElement(List*, int);
void deleteElementInOrder(List*, int);
void deleteNextElement(List* list, ListElement* element);
List* createList(int);
void deleteList(List*);
void deleteHead(List*);
int getHeadValue(List*);
bool isEmpty(List*);