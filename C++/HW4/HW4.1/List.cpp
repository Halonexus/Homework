#include "list.h"

void addElement(List* list, int value)
{
	if (list->head == nullptr)
	{
		list->head = new ListElement;
		list->head->next = list->head;
		list->head->value = value;
		return;
	}
	ListElement* newElement = new ListElement{ list->head->next, value };
	list->head->next = newElement;
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
	while (list->head != list->head->next)
	{
		ListElement* temp = list->head->next->next;
		delete list->head->next;
		list->head->next = temp;
	}
	delete list->head;
	delete list;
	return;
}

int getHeadValue(List* list)
{
	return list->head->value;
}