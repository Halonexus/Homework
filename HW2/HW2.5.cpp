// HW2.5.cpp : Defines the entry point for the console application.
//

#include <cstdio>

void swap(int* input, int index1, int index2)
{
	int temp = input[index1];
	input[index1] = input[index2];
	input[index2] = temp;
	return;
}

void sort(int* input, int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i;
		while ((j > 0) && (input[j] > input[(j - 1) / 2]))
		{
			swap(input, j, (j - 1) / 2);
			j = (j - 1) / 2;
		}
	}
	return;
}

void heapSort(int* input, int size)
{
	for (int i = 0; i < size; i++)
	{
		sort(input, size - i);
		swap(input, 0, size - 1 - i);
	}
	return;
}

void printArray(int* input, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", input[i]);
	}
	printf("\n");
	return;
}

int main()
{
	printf("Heap Sort\nEnter the number of elements:\n");
	int arrayLength = 0;
	scanf("%d", &arrayLength);

	printf("Enter %d elements:\n", arrayLength);
	int* arrayToSort = new int[arrayLength];
	for (int i = 0; i < arrayLength; i++)
	{
		scanf("%d", &arrayToSort[i]);
	}

	heapSort(arrayToSort, arrayLength);

	printf("Sorted array:\n");
	printArray(arrayToSort, arrayLength);

	delete[] arrayToSort;
	return 0;
}
