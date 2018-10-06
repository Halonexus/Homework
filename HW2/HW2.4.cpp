// HW2.4.cpp : Defines the entry point for the console application.
//

#include <cstdio>


int main()
{
	printf("Enter a positive integer:\n");
	int input = 0;
	scanf("%d", &input);

	int digits[10] = {};
	int numberOfDigits = 0;
	while (input > 0)
	{
		digits[input % 10]++;
		input = input / 10;
		numberOfDigits++;
	}

	printf("The smallest number made out of the same digits:\n");
	for (int i = 0; i < numberOfDigits; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ( (i == 0) && (j == 0) )
			{
				j++;
			}
			if (digits[j] > 0)
			{
				printf("%d", j);
				digits[j]--;
				break;
			}
		}
	}

    return 0;
}
