#include <cstdio>
#include "Set.h"

void printMessage();
void getInput(int& input);
void performTask(Set& set, const int task);

int main()
{
	Set set;
	bool exiting = false;
	while (!exiting)
	{
		printMessage();
		int input = 0;
		getInput(input);
		if (input == 0)
		{
			exiting = true;
		}
		else
		{
			performTask(set, input);
		}		
	}
	deleteSet(set);
	return 0;
}

void printMessage()
{
	printf("Choose an option:\n0 - Exit\n1 - Add element\n2 - Delete element\n"
		"3 - Print set in ascending order\n4 - Print set in descending order\n"
		"5 - Print set as subtrees\n6 - Check whether element is in set\n");
	return;
}

void getInput(int& input)
{
	scanf("%d", &input);
	return;
}

void performTask(Set& set, const int task)
{
	switch (task)
	{
	case 1:
	{
		printf("Enter the element value: ");
		int value = 0;
		scanf("%d", &value);
		addSetElement(set, value);
		break;
	}
	case 2:
	{
		printf("Enter the element value: ");
		int value = 0;
		scanf("%d", &value);
		deleteSetElement(set, value);
		break;
	}
	case 3:
	{
		printSet(set, 1);
		break;
	}
	case 4:
	{
		printSet(set, -1);
		break;
	}
	case 5:
	{
		printSet(set, 0);
		break;
	}
	case 6:
	{
		printf("Enter the element value: ");
		int value = 0;
		scanf("%d", &value);
		if (isInSet(set, value))
		{
			printf("%d is in the set.\n", value);
		}
		else
		{
			printf("%d is NOT in the set.\n", value);
		}
		break;
	}
	default:
		break;
	}
	return;
}