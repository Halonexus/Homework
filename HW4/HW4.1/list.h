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
ListElement* deleteElementInOrder(List*, ListElement*, int);
List* createList(int);
void deleteList(List*);
int getHeadValue(List*);