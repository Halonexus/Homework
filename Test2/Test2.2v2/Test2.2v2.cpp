#include <cstdio>
#include "List.h"

void sortRec(ListElement*& first)
{
	if (!first->next)
	{
		return;
	}
	ListElement* beforeMin = nullptr;
	ListElement* minElement = first;
	ListElement* current = first;
	while (current->next)
	{
		if (current->next->value < minElement->value)
		{
			beforeMin = current;
			minElement = current->next;
		}
		current = current->next;
	}
	if (minElement != first)
	{
		ListElement* temp = first;
		ListElement* temp2 = minElement->next;
		first = minElement;
		minElement->next = temp;
		beforeMin->next = temp2;
	}
	sortRec(minElement->next);
	return;
}

void sortRec(List* list)
{
	ListElement* beforeMin = nullptr;
	ListElement* minElement = list->head;
	ListElement* current = list->head;
	while (current->next)
	{
		if (current->next->value < minElement->value)
		{
			beforeMin = current;
			minElement = current->next;
		}
		current = current->next;
	}
	if (minElement != list->head)
	{
		ListElement* temp2 = minElement->next;
		ListElement* temp = list->head;
		list->head = minElement;
		minElement->next = temp;
		beforeMin->next = temp2;
	}
	sortRec(minElement->next);
}

int main()
{
	List* list = new List;
	printf("Enter the number of elements: ");
	int amount = 0;
	scanf("%d", &amount);
	printf("Enter %d elements:\n", amount);
	for (int i = 0; i < amount; i++)
	{
		int value = 0;
		scanf("%d", &value);
		addElement(list, value);
	}
	sortRec(list);
	printf("Sorted list:\n");
	ListElement* current = list->head;
	while (current)
	{
		printf("%d  ", current->value);
		current = current->next;
	}
	deleteList(list);
	return 0;
}