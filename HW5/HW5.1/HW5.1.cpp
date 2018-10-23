#include <cstdio>
#include "StringOperations.h"

void getInput(int& size);
void printInASpiral(int size);
int** getArray(int size);
void deleteArray(int** input, int size);

int const stringLength = 256;

int main()
{
	int size = 0;
	getInput(size);
	printInASpiral(size);
	return 0;
}

void getInput(int& size)
{
	char* string = new char[stringLength];
	fputs("Enter the size of the array(odd number): ", stdout);
	fgets(string, stringLength, stdin);
	int length = getLength(string);
	if (length > 0 && string[length - 1] == '\n')
	{
		string[length - 1] = '\0';
	}
	size = parse(string);
	delete[] string;
	return;
}

int** getArray(int size)
{
	int** inputArray = new int*[size];
	int value = 0;
	fputs("Array:\n", stdout);
	for (int i = 0; i < size; i++)
	{
		inputArray[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			inputArray[i][j] = j + value;
			fputs(intToString(j + value), stdout);
			fputs("\t", stdout);
		}
		fputs("\n", stdout);
		value += size;
	}
	return inputArray;
}

void deleteArray(int** input, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] input[i];
	}
	delete[] input;
	return;
}

void printInASpiral(int size)
{	
	int** intArray = getArray(size);
	fputs("Printing all elements in a spiral:\n", stdout);
	int step = 1;
	int i = size / 2;
	int j = size / 2;
	fputs(intToString(intArray[i][j]), stdout);
	fputs("\t", stdout);
	while (i < size && i >= 0 && j < size && j >= 0)
	{
		bool isIndexOutOfBounds = false;
		int stepCount = 0;
		while (stepCount < step)
		{
			i -= 1;
			if (i < 0)
			{
				isIndexOutOfBounds = true;
				break;
			}
			fputs(intToString(intArray[i][j]), stdout);
			fputs("\t", stdout);
			stepCount++;
		}
		if (isIndexOutOfBounds)
		{
			break;
		}
		stepCount = 0;
		while (stepCount < step)
		{
			j += 1;
			if (j >= size)
			{
				isIndexOutOfBounds = true;
				break;
			}
			fputs(intToString(intArray[i][j]), stdout);
			fputs("\t", stdout);
			stepCount++;
		}
		if (isIndexOutOfBounds)
		{
			break;
		}
		stepCount = 0;
		step++;
		while (stepCount < step)
		{
			i += 1;
			if (i >= size)
			{
				isIndexOutOfBounds = true;
				break;
			}
			fputs(intToString(intArray[i][j]), stdout);
			fputs("\t", stdout);
			stepCount++;
		}
		if (isIndexOutOfBounds)
		{
			break;
		}
		stepCount = 0;
		while (stepCount < step)
		{
			j -= 1;
			if (j < 0)
			{
				isIndexOutOfBounds = true;
				break;
			}
			fputs(intToString(intArray[i][j]), stdout);
			fputs("\t", stdout);
			stepCount++;
		}
		if (isIndexOutOfBounds)
		{
			break;
		}
		step++;
	}
	deleteArray(intArray, size);
	return;
}