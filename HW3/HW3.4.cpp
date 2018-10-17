// HW3.4.cpp : Defines the entry point for the console application.
//

#include <cstdio>
#include <cstdlib>
#include <ctime>

int* getArrayOfDigits(int number)
{
	int* digitArray = new int[10]{};
	int digits = 0;
	while (digits < 4)
	{
		digitArray[number % 10]++;
		number /= 10;
		digits++;
	}
	return digitArray;
}

int getNumber()
{
	int number = 0;
	int digits[] = { 0,1,2,3,4,5,6,7,8,9 };
	int const numberOfDigits = 4;
	int multiplyer = 1;
	for (int i = 0; i < numberOfDigits; i++)
	{
		int temp = digits[9 - i];
		int random = rand() % (10 - i);
		digits[9 - i] = digits[random];
		digits[random] = temp;		
		number += digits[9 - i] * multiplyer;
		multiplyer *= 10;
	}
	return number;
}

void play()
{	
	int targetNumber = getNumber();
	int* targetDigits = getArrayOfDigits(targetNumber);
	bool isPlaying = true;
	printf("Try to guess a 4 digit number:\n");
	int stepCounter = 0;
	while (isPlaying)
	{
		int input = 0;
		scanf("%d", &input);
		while (input > 9999)
		{
			scanf("%d", &input);
		}
		int* inputDigits = getArrayOfDigits(input);
		int key = targetNumber;
		int matches = 0;
		int misses = 0;
		for (int i = 0; i < 4; i++)
		{
			if (key % 10 == input % 10)
			{
				matches++;
			}
			else if(targetDigits[input % 10] > 0)
			{
				misses++;
			}
			key /= 10;
			input /= 10;
		}
		delete[] inputDigits;	
		printf("\t You got %d matches and %d misses\n", matches, misses);
		if (matches >= 4)
		{
			isPlaying = false;
		}
		stepCounter++;
	}
	delete[] targetDigits;
	printf("You've won in %d steps\n", stepCounter);
	return;
}

int main()
{
	srand(time(NULL));
	bool isPlaying = true;
	while (isPlaying)
	{
		printf("Would you like to play?(y/n)\n");
		char input = '\n';
		while (input == '\n') 
		{
			scanf("%c", &input);
		}		
		switch (input)
		{
		case 'y':
		{
			play();
			break;
		}
		case 'n':
		{
			isPlaying = false;
			break;
		}
		default:
			break;
		}
	}	
	return 0;
}