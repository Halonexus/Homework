#include <cstdio>

int intParse(const char* const string);
int getLength(const char* const string);
void getInput(char*&, int&);

int const stringLength = 256;

int main()
{
	char* inputString = nullptr;
	int targetLength = 0;
	getInput(inputString, targetLength);

	int amountOfSpaces = 0;
	char* output = new char[stringLength];
	int numberOfWords = 0;
	int i = 0;
	while (inputString[i] != '\0')
	{
		if (inputString[i] == ' ')
		{

			while (inputString[i] == ' ')
			{
				amountOfSpaces++;
				i++;
			}
			numberOfWords++;
		}
		i++;
	}
	int difference = targetLength - (getLength(inputString) - amountOfSpaces);
	int targetNumberOfSpaces = difference / numberOfWords;
	int remainingSpaces = difference % numberOfWords;

	i = 0;
	int j = 0;
	while (inputString[i] != '\0')
	{
		if (inputString[i] != ' ')
		{
			output[j++] = inputString[i];
		}
		else
		{
			for (int k = 0; k < targetNumberOfSpaces; k++)
			{
				output[j++] = ' ';
			}
			if (remainingSpaces > 0)
			{
				output[j++] = ' ';
				remainingSpaces--;
			}
		}
		i++;
	}

	delete[] inputString;
	output[j] = '\0';
	fputs("The resized string:\n", stdout);
	fputs(output, stdout);
	delete[] output;	
	return 0;
}

void getInput(char*& string, int& targetLength)
{
	string = new char[stringLength];
	char* inputInt = new char[stringLength];
	fputs("Enter the string: \n", stdout);
	fgets(string, stringLength, stdin);
	string[getLength(string) - 1] = '\0';
	fputs("Enter the target length: ", stdout);
	fgets(inputInt, stringLength, stdin);
	inputInt[getLength(inputInt) - 1] = '\0';
	targetLength = intParse(inputInt);
	delete[] inputInt;
	return;
}

int intParse(const char* const string)
{
	if (!string)
	{
		return -1;
	}
	char digits[] = { '0','1','2','3','4','5','6','7','8','9' };
	int result = 0;
	int multiplier = 1;
	int length = getLength(string);
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (string[length - 1 - i] == digits[j])
			{
				result += multiplier * j;
				break;
			}
		}
		multiplier *= 10;
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