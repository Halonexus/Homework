// HW2.2.cpp : Defines the entry point for the console application.
//

#include <cstdio>

int getStringLength(char* input)
{
	int i = 0;
	while (input[i] != '\0')
	{
		i++;
	}
	return i;
}

char* concatenateStrings(char* a, char* b)
{
	int lengthA = getStringLength(a);
	int lengthB = getStringLength(b);
	int newLength = lengthA + lengthB + 1;
	char* newString = new char[newLength];
	for (int i = 0; i < lengthA; i++)
	{
		newString[i] = a[i];
	}
	for (int i = lengthA; i < lengthA + lengthB + 1; i++)
	{
		newString[i] = b[i - lengthA];
	}
	return newString;
}

int getIntLength(int input)
{
	int output = 0;
	while (input > 0)
	{
		input = input / 10;
		output++;
	}
	return output;
}

char* convertIntToChars(int input)
{
	int length = getIntLength(input);
	char* output = new char[length + 2];
	
	for (int i = length - 1; i >= 0; i--)
	{
		output[i] = '0' + input % 10;
		input = input / 10;
	}
	output[length] = ' ';
	output[length + 1] = '\0';
	
	return output;
}

void writeNumberAsSum(int number, int max, char* initialString)
{
	
	if (getStringLength(initialString) > 0)
	{
		printf("%s", initialString);
	}
	
	for (int i = 0; i < number; i++)
	{
		printf("1 ");
	}
	printf("\n");
	if ((max < 2) || (number < 1))
	{
		return;
	}
	for (int i = 2; (i <= max) && (number - i >= 0); i++)
	{
		char* addedChars = convertIntToChars(i);				
		char* newInitialString = concatenateStrings(initialString, addedChars);
		delete[] addedChars;
		writeNumberAsSum(number - i, i, newInitialString);
		delete[] newInitialString;
	}


	return;
}

int main()
{
	printf("Enter a positive number:\n");
	int input = 0;
	scanf("%d", &input);
	char* initialString = new char[1];
	initialString[0] = '\0';
	writeNumberAsSum(input, input, initialString);
	delete[] initialString;
    return 0;
}