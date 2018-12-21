#include "StringOperations.h"

char* intToString(int input)
{
	bool isException = false;
	bool isNegative = false;
	if (input == -2147483647 - 1)
	{
		isException = true;
		input++;
	}
	if (input < 0)
	{
		isNegative = true;
		input = -input;
	}
	int temp = input;
	int length = 0;
	while (temp > 0)
	{
		length++;
		temp /= 10;
	}
	if (input == 0)
		length = 1;
	temp = input;
	char* string = new char[length + 1 + isNegative];
	if (isNegative)
		string[0] = '-';
	string[length + isNegative] = '\0';
	char digits[] = { '0','1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < length; i++)
	{
		string[length + isNegative - 1 - i] = digits[temp % 10];
		temp /= 10;
	}
	if (isException)
		string[length + isNegative - 1] = '8';
	return string;
}

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