#include <cstdio>
#include "phonebook.h"

int const stringLength = 256;

int parse(const char* const string);

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
		fprintf(file, "(%s)  %d\n", current->name, current->phoneNumber);
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
		fputs("No input file\n", stdout);
		return;
	}
	while (feof(file) == 0)
	{
		char* name = nullptr;
		char* string = new char[stringLength];
		int phoneNumber = 0;
		fgets(string, stringLength, file);
		int i = 0;		
		while (string[i] != '\0')
		{
			if (string[i] == '(')
			{
				name = new char[stringLength];
				int j = 0;
				i++;
				while (string[i] != ')')
				{
					name[j++] = string[i++];
				}
				name[j] = '\0';				
			}
			else if (string[i] >= '0' && string[i] <= '9')
			{
				char* number = new char[stringLength];
				int j = 0;
				while (string[i] >= '0' && string[i] <= '9')
				{
					number[j++] = string[i++];
				}
				number[j] = '\0';
				phoneNumber = parse(number);
				delete[] number;
				i--;
			}
			i++;
		}
		delete[] string;
		if (name)
		{
			addRecord(book, name, phoneNumber);
		}
	}
	fclose(file);
	return;
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

int parse(const char* const string)
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