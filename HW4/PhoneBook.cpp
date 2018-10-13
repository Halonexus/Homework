#include <cstdio>
#include "phonebook.h"

int const stringLength = 256;

void addRecord(PhoneBook* book, char* name, int phoneNumber)
{
	Record* newRecord = new Record{ book->head, name, phoneNumber };
	book->head = newRecord;
	return;
}

void addRecord(PhoneBook* book, Record* newRecord)
{
	newRecord->next = book->head;
	book->head = newRecord;
	return;
}

bool areStringsEqual(char* string1, char*string2)
{
	bool endNotReached = true;
	int index = 0;
	while (endNotReached)
	{
		if (string1[index] != string2[index])
		{
			return false;
		}
		if (string1[index] == '\0')
		{
			endNotReached = false;
		}
		index++;
	}
	return true;
}

void deleteRecord(PhoneBook* book, Record* record)
{
	if (!record)
	{
		return;
	}	
	Record* current = book->head;
	if (current == record)
	{
		Record* nextRecord = current->next;
		delete[] current->name;
		delete current;
		book->head = nextRecord;
		return;
	}
	while (current)
	{
		if (current->next == record)
		{
			Record* temp = current->next->next;
			delete[] current->next->name;
			delete current->next;
			current->next = temp;
			return;
		}
	}
	return;
}

void deletePhoneBook(PhoneBook* book)
{
	while (book->head)
	{
		deleteRecord(book, book->head);
	}
	delete book;
	return;
}

void writeToNewFile(PhoneBook* book)
{
	FILE* file = fopen("input.txt", "w");
	Record* current = book->head;
	while (current)
	{
		fprintf(file, "%s  %d\n", current->name, current->phoneNumber);
		current = current->next;
	}
	fclose(file);
	return;
}

Record* findRecordByPhoneNumber(PhoneBook* book, int phoneNumber)
{
	Record* current = book->head;
	while (current)
	{
		if (current->phoneNumber == phoneNumber)
		{
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

Record* findRecordByName(PhoneBook* book, char* name)
{
	Record* current = book->head;
	while (current)
	{
		if (areStringsEqual(current->name, name))
		{
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

void fillPhoneBookFromFile(PhoneBook* book)
{
	FILE* file = fopen("input.txt", "r");
	if (!file)
	{
		return;
	}
	int count = 1;
	while (!feof(file))
	{		
		char* name = new char[stringLength];
		int phoneNumber = 0;
		if (fscanf(file, "%s %d", name, &phoneNumber) == EOF)
		{
			break;
		}
		printf("%d %s %d\n", count, name, phoneNumber);
		addRecord(book, name, phoneNumber);
		count++;
	}
	fclose(file);
	return;
}