#include "StringOperations.h"

int getLength(const char* const string)
{
	if (!string)
	{
		return 0;
	}
	int length = 0;
	while (string[length] != '\0')
	{
		length++;
	}
	return length;
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
	char digits[] = { '0','1','2','3','4','5','6','7','8','9' };
	int result = 0;
	int multiplyer = 1;
	int length = getLength(string);
	for (int i = 0; i < length - isNegative; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (string[length - 1 - i] == digits[j])
			{
				result += multiplyer * j;
				break;
			}
		}
		multiplyer *= 10;
	}
	if (isNegative)
	{
		result *= -1;
	}
	return result;
}

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