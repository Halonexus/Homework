#include "HashTable.h"

int maxTries = 0;
String maxTryString;
int tries = 0;
int words = 0;

HashTable* createTable(int size)
{
	return new HashTable{ new String[size] , new int[size] {}, size };
}

void deleteHashTable(String* table, int size)
{
	if (!table)
	{
		return;
	}
	for (int i = 0; i < size; i++)
	{
		if (!isEmpty(table[i]))
		{
			deleteString(table[i]);
		}
	}
	return;
}

void deleteHashTable(HashTable* table)
{
	if (!table || !table->table)
	{
		return;
	}
	deleteHashTable(table->table, table->size);
	delete[] table->table;
	delete[] table->uses;
	table->size = 0;
	return;
}

int hash(String string, int size)
{
	int result = 0;
	int length = getSize(string);
	for (int i = 0; i < length; i++)
	{
		result = (result + string[i]) % size;
	}
	return result;
}

void addElement(HashTable* table, String string)
{
	if (!table || !table->table)
	{
		return;
	}
	int shift = 0;
	int index = hash(string, table->size);
	while (!isEmpty(table->table[index]))
	{
		if (table->table[index] == string)
		{
			table->uses[index]++;
			break;
		}
		index = (index + shift * shift) % table->size;
		shift++;
	}
	tries += shift;
	words++;
	if (isEmpty(maxTryString) || maxTries < shift)
	{
		maxTries = shift;
		maxTryString = string;
	}
	table->table[index] = string;
	table->uses[index]++;
	return;
}

double loadFactor(HashTable* table)
{
	return (double)(table->size - getUnused(table)) / (double)table->size;
}

int getUnused(HashTable* table)
{
	int count = 0;
	for (int i = 0; i < table->size; i++)
	{
		if (isEmpty(table->table[i]))
		{
			count++;
		}
	}
	return count;
}

double getAverageTries()
{
	return (double)tries / (double)words;
}

int getMaxTries()
{
	return maxTries;
}

int getTotalWords()
{
	return words;
}

String getMaxTryString()
{
	return maxTryString;
}