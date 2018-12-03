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
	while (numberOfPeople > 1)
	{
		deleteElementInOrder(list, deletionNumber);
		numberOfPeople--;
	}
	int lastPersonNumber = getHeadValue(list);
	deleteList(list);
	printf("The index of the last person is %d\n", lastPersonNumber);
	return 0;
}