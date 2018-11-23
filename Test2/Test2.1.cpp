#include <cstdio>

int fibonacciNumber(int index)//0 1 1 2...
{
	int tempNumber[2] = { 0, 1 };
	for (int i = 3; i <= index; i++)
	{
		tempNumber[(i + 1) % 2] = tempNumber[0] + tempNumber[1];
	}
	return tempNumber[(index+1)%2];
}

int main()
{
	printf("Enter the index of the fibonacci number: ");
	int index = 0;
	scanf("%d", &index);
	printf("%dth fibonacci number: %d\n",index, fibonacciNumber(index));
	return 0;
}