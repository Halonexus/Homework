#include <cstdio>
#include "Set.h"

int main()
{
	printf("Enter a set of numbers:\n");
	Set set;
	int number = 1;
	while (number != 0)
	{
		scanf("%d", &number);
		if(number != 0)
		{
			addSetElement(set, number);
		}
	}
	printTreeAscendingNoCopies(set);
	deleteSet(set);
	return 0;
}