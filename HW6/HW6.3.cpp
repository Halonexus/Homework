#include <cstdio>

void getInput(int*&, int&);
int getNumberLength(int number);
int absolute(int number);
void printPowers(int*, int);
void printPolynomial(int*, int);

int main()
{
	int* input = nullptr;
	int length = 0;
	getInput(input, length);
	printPolynomial(input, length);
	delete[] input;
	return 0;
}

void getInput(int*& result, int& resultLength)
{
	printf("Enter the length of the array: ");
	resultLength = 0;
	scanf("%d", &resultLength);
	result = new int[resultLength];
	printf("Enter the elements of the array:\n");
	for (int i = 0; i < resultLength; i++)
	{
		int input = 0;
		scanf("%d", &input);
		result[i] = input;
	}
}

int getNumberLength(int number)
{
	int length = 0;
	number = absolute(number);
	while (number > 0)
	{
		number = number / 10;
		length++;
	}
	return length;
}

int absolute(int number)
{
	return number > 0 ? number : -number;
}

void printPolynomial(int* input, int length)
{
	printPowers(input, length);
	for (int i = 0; i < length; i++)
	{
		if (input[i] == 0)
		{
			continue;
		}
		printf(input[i] < 0 ? "- " : "+ ");
		if (absolute(input[i]) > 1)
		{
			printf("%d", absolute(input[i]));
		}
		if (i != length - 1)
		{
			printf("x");
		}
		int spaces = getNumberLength(length - i - 1);
		for (int j = 0; j < spaces; j++)
		{
			printf(" ");
		}
	}
	printf("\n");
	return;
}

void printPowers(int* input, int length)
{
	for (int i = 0; i < length - 2; i++)
	{
		if (input[i] == 0)
		{
			continue;
		}
		int spaces = 3;
		if (absolute(input[i]) > 1)
		{
			spaces += getNumberLength(input[i]);
		}
		for (int j = 0; j < spaces; j++)
		{
			printf(" ");
		}
		printf("%d", length - i - 1);
	}
	printf("\n");
	return;
}