#include "HashTable.h"

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
	deleteString(table->maxTryString);
	table->size = 0;
	return;
}

int hash(String string, int size)
{
	int result = 0;
	int length = getSize(string);
	for (int i = 0; i < length; i++)
	{
		result = (result * (size - 1) + string[length - 1 - i]) % size;
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
	table->tries += shift;
	table->words++;
	if (isEmpty(table->maxTryString) || table->maxTries < shift)
	{
		table->maxTries = shift;
		table->maxTryString = string;
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

bool isInTable(HashTable* table, String string)
{
	if (!table || isEmpty(string))
	{
		return false;
	}
	int index = hash(string, table->size);
	int shift = 0;
	while (!isEmpty(table->table[index]))
	{
		if (table->table[index] == string)
		{
			return true;
		}
		index = (index + shift * shift) % table->size;
		shift++;
	}
	return false;
}