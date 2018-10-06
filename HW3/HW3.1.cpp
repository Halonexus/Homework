// HW3.1.cpp : Defines the entry point for the console application.
//

#include <cstdio>

int* getInput(int* inputLength)
{
	printf("Enter the number of elements:\n");
	int arrayLength = 0;
	scanf("%d", &arrayLength);
	int* input = new int[arrayLength];
	printf("Enter %d elements:\n", arrayLength);
	for (int i = 0; i < arrayLength; i++)
	{
		scanf("%d", &input[i]);
	}
	*inputLength = arrayLength;
	return input;
}

void quickSort(int* input, int size)
{
	int* output = input;
	int q = 0;
	if (size < 2)
	{
		return;
	}
	for (int i = 0; i < size - 1; i++)
	{
		if (output[i] > output[size - 1])
		{
			int temp = output[q];
			output[q] = output[i];
			output[i] = temp;
			q++;
		}
	}
	int temp = output[q];
	output[q] = output[size - 1];
	output[size - 1] = temp;
	quickSort(output, q);
	output = &output[q + 1];
	quickSort(output, size - q - 1);
	return;
}

int findRequiredElement(int* input, int inputLength, bool* elementExists)
{
	for (int i = 1; i < inputLength; i++)
	{
		if (input[i] == input[i - 1])
		{
			return input[i];
		}
	}
	*elementExists = false;
	return NULL;
}

int main()
{
	int inputLength = 0;
	int* input = getInput(&inputLength);
	quickSort(input, inputLength);
	bool elementExists = true;
	int output = findRequiredElement(input, inputLength, &elementExists);
	delete[] input;
	if (!elementExists)
	{
		printf("Required element not found\n");
		return 0;
	}
	printf("Maximum element that appears at least 2 times is %d\n", output);
        return 0;
}
