// HW2.1.cpp : Defines the entry point for the console application.
//
#include <cstdio>

int recursiveFibonacci(int index)
{
	if (index < 3)
	{
		return index - 1;
	}
	int output = recursiveFibonacci(index - 1) + recursiveFibonacci(index - 2);
	return output;
}

int iterativeFibonacci(int index)
{
	int fibNumbers[2] = { 0 , 1 };
	for (int i = 2; i < index; i++)
	{
		fibNumbers[i % 2] = fibNumbers[0] + fibNumbers[1];
	}
	int output = fibNumbers[(index + 1) % 2];
	return output;
}

int main()
{
	printf("Enter the index of a fibonacci number(>0):\n");
	int index = 0;
	scanf("%d", &index);

	int fibonacciNumber = iterativeFibonacci(index);
	printf("Iterative: The %d st/nd/rd/th fibonacci number is %d\n", index, fibonacciNumber);
	fibonacciNumber = recursiveFibonacci(index);
	printf("Recursive: The %d st/nd/rd/th fibonacci number is %d\n", index, fibonacciNumber);

    return 0;
}