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

int parse(const char* const string)
{
	if (!string)
	{
		return -1;
	}
	char* croppedString = crop(string);
	bool isNegative = false;
	if (croppedString[0] == '-')
	{
		isNegative = true;
	}
	char digits[] = { '0','1','2','3','4','5','6','7','8','9' };
	int result = 0;
	int multiplyer = 1;
	int length = getLength(croppedString);
	for (int i = 0; i < length - isNegative; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (croppedString[length - 1 - i] == digits[j])
			{
				result += multiplyer * j;
				break;
			}
		}
		multiplyer *= 10;
	}
	delete[] croppedString;
	if (isNegative)
	{
		result *= -1;
	}
	return result;
}

int getLength(const char* const string)
{
	int length = 0;
	while (string[length] != '\0')
	{
		length++;
	}
	return length;
}

char* crop(const char* string)
{
	if (!string)
	{
		return nullptr;
	}
	int length = getLength(string);
	int j = 0;
	char* newString = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		if ((string[i] >= '0' && string[i] <= '9') || string[i] == '-')
		{
			newString[j++] = string[i];
		}
	}
	newString[j] = '\0';
	return newString;
}