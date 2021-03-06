#include "StringOperations.h"

void trim(char* string)
{
	if (!string)
	{
		return;
	}
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	if (string[0] != '\0' && string[i - 1] == '\n')
	{
		string[i - 1] = '\0';
	}
	return;
}

int getLength(const char* string)
{
	if (!string)
	{
		return 0;
	}
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}

char* concatenate(const char* string1, const char* string2)
{
	int length1 = getLength(string1);
	int length2 = getLength(string2);
	char* result = new char[length1 + length2 + 1];
	for (int i = 0; i < length1; i++)
	{
		result[i] = string1[i];
	}
	for (int i = 0; i < length2; i++)
	{
		result[length1 + i] = string2[i];
	}
	result[length1 + length2] = '\0';
	return result;
}

int parseInt(const char* const string)
{
	if (!string)
	{
		return -1;
	}
	bool isNegative = false;
	if (string[0] == '-')
	{
		isNegative = true;
	}
	int result = 0;
	int multiplier = 1;
	int length = getLength(string);
	for (int i = 0; i < length - (isNegative ? 1 : 0); i++)
	{
		result += multiplier * (string[length - 1 - i] - '0');
		multiplier *= 10;
	}
	if (isNegative)
	{
		result *= -1;
	}
	return result;
}

bool equals(const char* string1, const char* string2)
{
	if (!string1 || !string2)
	{
		return false;
	}
	int length1 = getLength(string1);
	int length2 = getLength(string2);
	for (int i = 0; i < length1 + 1; i++)
	{
		if (string1[i] != string2[i])
		{
			return false;
		}
	}
	return true;
}