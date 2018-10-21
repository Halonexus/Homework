#include <cstdio>
#include "list.h"

int main()
{
	printf("Enter number of people n and number m:\n");
	int numberOfPeople = 0;
	int deletionNumber = 0;
	scanf("%d %d", &numberOfPeople, &deletionNumber);
	List* list = createList(numberOfPeople);
	deletionNumber = deletionNumber % numberOfPeople;
	ListElement* current = list->head;
	while (numberOfPeople > 1)
	{
		current = deleteElementInOrder(list, current, deletionNumber);
		numberOfPeople--;
	}
	int lastPersonNumber = getHeadValue(list);
	deleteList(list);
	printf("The index of the last person is %d\n", lastPersonNumber);
	return 0;
}