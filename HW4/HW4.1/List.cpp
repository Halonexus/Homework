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

ListElement* deleteElementInOrder(List* list, ListElement* currentElement, int step)
{
	while (step > 1)
	{
		currentElement = currentElement->next;
		step--;
	}
	ListElement* nextElement = currentElement->next->next;
	if (currentElement->next == list->head)
	{
		list->head = nextElement;
	}
	delete currentElement->next;
	currentElement->next = nextElement;

	return currentElement;
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