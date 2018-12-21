#include <cstdio>
#include "StringOperations.h"

int const stringLength = 256;
int const hashSize = 101;

int hash(char* string, int hashSize);

int main()
{
	fputs("Enter the string:\n", stdout);
	char* string = new char[stringLength];
	fgets(string, stringLength, stdin);
	trim(string);
	fputs("Enter the substring:\n", stdout);
	char* subString = new char[stringLength];
	fgets(subString, stringLength, stdin);
	trim(subString);

	int stringLength = getLength(string);
	int subStringLength = getLength(subString);
	int subStringHash = hash(subString, hashSize);
	char* pattern = new char[subStringLength + 1];

	fputs("Indexes of subString in the string:\n", stdout);
	for (int i = 0; i < stringLength - subStringLength + 1; i++)
	{
		for (int j = 0; j < subStringLength; j++)
		{
			pattern[j] = string[i + j];
		}
		pattern[subStringLength] = '\0';
		if (subStringHash == hash(pattern, hashSize))
		{
			if (equals(subString, pattern))
			{
				char* temp = new char[stringLength];
				temp = intToString(i);
				fputs(temp, stdout);
				fputs(" ", stdout);
				delete[] temp;
			}
		}
	}
	delete[] string;
	delete[] subString;
	delete[] pattern;
	return 0;
}

int hash(char* string, int hashSize)
{
	int result = 0;
	int length = getLength(string);
	for (int i = 0; i < length; i++)
	{
		result = (result + string[i]) % hashSize;
	}
	return result;
}