// HW3.4.cpp : Defines the entry point for the console application.
//

#include <cstdio>
#include <cstdlib>
#include <ctime>

int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}

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

void play()
{	
	int targetNumber = rand() % 10000;	
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
		int* targetDigits = getArrayOfDigits(targetNumber);
		int* inputDigits = getArrayOfDigits(input);
		int key = targetNumber;
		int matches = 0;
		int misses = 0;
		for (int i = 0; i < 4; i++)
		{
			if (key % 10 == input % 10)
			{
				matches++;
				inputDigits[input % 10]--;
				targetDigits[input % 10]--;
			}
			key /= 10;
			input /= 10;
		}
		for (int i = 0; i < 10; i++)
		{
			misses += min(inputDigits[i], targetDigits[i]);
		}
		delete[] inputDigits;
		delete[] targetDigits;
		printf("\t You got %d matches and %d misses\n", matches, misses);
		if (matches >= 4)
		{
			isPlaying = false;
		}
		stepCounter++;
	}
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