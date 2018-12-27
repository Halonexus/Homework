#include <cstdio>
#include "String.h"
#include "StringOperations.h"
#include "HashTable.h"

int const stringLength = 256;

void processString(String string, HashTable* table);
void printResults(HashTable* table);

int main()
{
	fputs("Enter the filename: ", stdout);
	String filename;
	allocate(filename, stringLength);
	fgets(filename.cString, stringLength, stdin);
	trim(filename.cString);
	FILE* input = fopen(filename.cString, "r");
	deleteString(filename);
	if (!input)
	{
		fputs("Error opening file.", stdout);
	}
	else
	{
		HashTable* table = createTable(stringLength);
		String string;
		allocate(string, stringLength);
		while (!feof(input))
		{
			fgets(string.cString, stringLength, input);
			processString(string, table);
		}
		printResults(table);
		deleteHashTable(table);
		delete table;
		deleteString(string);
		fclose(input);
	}
	return 0;
}

bool isLetter(char character)
{
	return character >= 'a' && character <= 'z' || character >= 'A' && character <= 'Z';
}

void processString(String string, HashTable* table)
{
	int length = getSize(string);
	for (int i = 0; i < length; i++)
	{
		if (isLetter(string[i]))
		{
			String word;
			allocate(word, stringLength);
			int j = 0;
			while (isLetter(string[i]))
			{
				word[j++] = string[i++];
			}
			word[j] = '\0';
			addElement(table, word);
			deleteString(word);
		}
	}
	return;
}

void printResults(HashTable* table)
{
	fputs("Words and their amounts:\n", stdout);
	for (int i = 0; i < table->size; i++)
	{
		if (!isEmpty(table->table[i]))
		{
			fputs(table->table[i].cString, stdout);
			fputs(" ", stdout);
			String temp;
			allocate(temp, stringLength);
			sprintf(temp.cString, "%d", table->uses[i]);
			fputs(temp.cString, stdout);
			fputs("\n", stdout);
			deleteString(temp);
		}
	}
	printf("Load Factor: %f\n", loadFactor(table));
	printf("Average amount of tries: %f\n", (double)table->tries / (double)table->words);
	String temp;
	allocate(temp, stringLength);
	sprintf(temp.cString, "%d", table->maxTries);
	fputs("Max amount of tries: ", stdout);
	fputs(temp.cString, stdout);
	fputs("\n", stdout);
	temp = table->maxTryString;
	fputs("The word with most tries: ", stdout);
	fputs(temp.cString, stdout);
	fputs("\n", stdout);
	sprintf(temp.cString, "%d", table->words);
	fputs("Total amount of words: ", stdout);
	fputs(temp.cString, stdout);
	fputs("\n", stdout);
	sprintf(temp.cString, "%d", getUnused(table));
	fputs("Amount of unused array elements: ", stdout);
	fputs(temp.cString, stdout);
	fputs("\n", stdout);
	deleteString(temp);
	return;
}