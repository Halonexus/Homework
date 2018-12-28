#include <cstdio>
#include "StringOperations.h"

int const stringLength = 256;
int const hours = 24;

int readNumber(FILE*&);
FILE* getFile();
void fillCustomersArray(FILE* file, int* const);
int getMaxHour(const int * const);
void printResult(const int);

int main()
{
	int customersByHour[hours] = { 0 };
	fputs("Enter the filename: ", stdout);
	FILE* file = getFile();
	if (!file)
	{
		fputs("Error opening file.\n", stdout);
		return 0;
	}
	fillCustomersArray(file, customersByHour);
	int maxHour = getMaxHour(customersByHour);
	printResult(maxHour);
	return 0;
}

bool isDigit(char character)
{
	return character >= '0' && character <= '9' ? true : false;
}

int readNumber(FILE*& file)
{
	char character[2] = { '\0' };
	fgets(character, 2, file);
	while (!isDigit(character[0]) && !feof(file))
	{
		fgets(character, 2, file);
	}
	char* number = new char[stringLength];
	int i = 0;
	while (isDigit(character[0]) && !feof(file))
	{
		number[i++] = character[0];
		fgets(character, 2, file);
	}
	number[i] = '\0';
	int result = parseInt(number);
	delete[] number;
	return result;
}

FILE* getFile()
{
	char filename[stringLength] = {};
	fgets(filename, stringLength, stdin);
	trim(filename);
	return fopen(filename, "r");
}

void fillCustomersArray(FILE* file, int* const customersByHour)
{
	while (!feof(file))
	{
		int startHour = readNumber(file);
		int startMinute = readNumber(file);
		int endHour = readNumber(file);
		int endMinute = readNumber(file);
		for (int i = 0; i < endHour - startHour + 1; i++)
		{
			customersByHour[startHour + i]++;
		}
	}
	fclose(file);
	return;
}

int getMaxHour(const int * const customersByHour)
{
	int maxHour = 0;
	int maxCustomers = 0;
	for (int i = 0; i < hours; i++)
	{
		if (customersByHour[i] > maxCustomers)
		{
			maxCustomers = customersByHour[i];
			maxHour = i;
		}
	}
	return maxHour;
}

void printResult(const int maxHour)
{
	fputs("The highest amount of customers was at ", stdout);
	char hour[stringLength] = {};
	sprintf(hour, "%d", maxHour);
	fputs(hour, stdout);
	fputs(" o'clock\n", stdout);
	return;
}