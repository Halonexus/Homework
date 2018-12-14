#include "List.h"

void addElement(List* list, int value)
{
	if (list->head == nullptr)
	{
		list->head = new ListElement;
		list->head->next = nullptr;
		list->head->value = value;
		return;
	}
	ListElement* newElement = new ListElement{ nullptr, value };
	ListElement* current = list->head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = newElement;
	return;
}

void deleteHead(List* list)
{
	if ((list->head) && list)
	{
		ListElement* temp = list->head->next;
		delete list->head;
		list->head = temp;
	}
	return;
}

void deleteElementInOrder(List* list, int index)
{
	ListElement* current = list->head;
	while (index > 1)
	{
		current = current->next;
		index--;
	}
	deleteNextElement(list, current);
	list->head = current;
	return;
}

List* createList(int numberOfElements)
{
	List* newList = new List;
	for (int i = 0; i < numberOfElements; i++)
	{
		addElement(newList, numberOfElements - i);
	}
	return newList;
}

void deleteNextElement(List* list, ListElement* element)
{
	ListElement* temp = element->next;
	element->next = temp->next;
	delete temp;
	return;
}

void deleteList(List* list)
{
	ListElement* current = list->head;
	while (current)
	{
		ListElement* temp = current->next;
		delete current;
		current = temp;
	}
	delete list;
	return;
}

int getHeadValue(List* list)
{
	return list->head->value;
}

bool isEmpty(List* list)
{
	return !list->head;
}