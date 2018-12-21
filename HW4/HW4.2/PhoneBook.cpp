#include <cstdio>
#include "phonebook.h"
#include "StringOperations.h"

int const stringLength = 256;

void addRecord(PhoneBook* book, char* name, int phoneNumber)
{
	if (!book || !name)
	{
		return;
	}
	Record* newRecord = new Record{ book->head, name, phoneNumber };
	book->head = newRecord;
	return;
}

void addRecord(PhoneBook* book, Record* newRecord)
{
	if (!book || !newRecord)
	{
		return;
	}
	newRecord->next = book->head;
	book->head = newRecord;
	return;
}

void deleteRecord(PhoneBook* book, Record* record)
{
	if (!book || !record)
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
			Record* temp = current->next;
			current->next = temp->next;
			delete[] temp->name;
			delete temp;
			return;
		}
	}
	return;
}

void deletePhoneBook(PhoneBook* book)
{
	if (!book)
	{
		return;
	}
	while (book->head)
	{
		deleteRecord(book, book->head);
	}
	delete book;
	return;
}

void writeToNewFile(PhoneBook* book, FILE* file)
{
	if (!book || !file)
	{
		return;
	}
	Record* current = book->head;
	while (current)
	{
		fputs(current->name, file);
		fputs("\n", file);
		char* temp = intToString(current->phoneNumber);
		fputs(temp, file);
		delete[] temp;
		fputs("\n", file);
		current = current->next;
	}
	fclose(file);
	return;
}

Record* findRecordByPhoneNumber(PhoneBook* book, int phoneNumber)
{
	if (!book)
	{
		return nullptr;
	}
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
	if (!book)
	{
		return nullptr;
	}
	Record* current = book->head;
	while (current)
	{
		if (equals(current->name, name))
		{
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

void fillPhoneBookFromFile(PhoneBook* book, FILE* file)
{
	if (!book)
	{
		return;
	}
	if (!file)
	{
		fputs("No input file\n", stdout);
		return;
	}
	while (!feof(file))
	{
		char* name = new char[stringLength];
		char* number = new char[stringLength];
		fgets(name, stringLength, file);
		trim(name);
		fgets(number, stringLength, file);
		trim(number);
		int phoneNumber = parseInt(number);
		delete[] number;
		if (name)
		{
			addRecord(book, name, phoneNumber);
		}
	}
	fclose(file);
	return;
}