// HW3.2.cpp : Defines the entry point for the console application.
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

void getInput(char** string1,char** string2)
{
	int const maxStringLength = 256;
	*string1 = new char[maxStringLength];
	*string2 = new char[maxStringLength];
	printf("Enter the first string:\n");
	scanf("%255s", *string1);
	printf("Enter the second string:\n");
	scanf("%255s", *string2);
	return;
}

struct NumberOfChars 
{
	char character = NULL;
	int numberInString1 = 0;
	int numberInString2 = 0;
};

bool fillCharArray(NumberOfChars* charArray, char* string1, char* string2)
{
	int i = 0;
	while (string1[i] != '\0')
	{
		for (int j = 0; j < 256; j++)
		{
			if (charArray[j].character == string1[i])
			{
				charArray[j].numberInString1++;
				break;
			}
			else if (charArray[j].character == NULL)
			{				
				charArray[j].character = string1[i];
				charArray[j].numberInString1++;
				break;
			}
		}
		i++;
	}
	i = 0;
	while (string2[i] != '\0')
	{
		for (int j = 0; j < 256; j++)
		{
			if (charArray[j].character == string2[i])
			{
				charArray[j].numberInString2++;
				if (charArray[j].numberInString2 > charArray[j].numberInString1)
				{
					return false;
				}
				break;
			}
			else if (charArray[j].character == NULL)
			{				
				return false;
			}
		}
		i++;
	}
	return true;
}

int main()
{	
	char* string1 = nullptr;
	char* string2 = nullptr;
	getInput(&string1, &string2);

	NumberOfChars charArray[256] = {};

	bool charsAreEqual = ((getStringLength(string1) == getStringLength(string2)) && (fillCharArray(charArray, string1, string2)));

	if (charsAreEqual)
	{
		printf("The second string can be made out of the first string\n");
	}
	else
	{
		printf("The second string can NOT be made out of the first string\n");
	}

	delete[] string1;
	delete[] string2;
    return 0;
}