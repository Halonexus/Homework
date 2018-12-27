#include <cstdio>
#include "phonebook.h"
#include "StringOperations.h"

int main()
{
	int const stringLength = 256;
	PhoneBook* phoneBook = new PhoneBook;
	fputs("Enter the name of the input file or enter anything else to skip: ", stdout);
	char* filename = new char[stringLength];
	fgets(filename, stringLength, stdin);
	trim(filename);
	FILE* input = fopen(filename, "r");
	delete[] filename;
	fillPhoneBookFromFile(phoneBook, input);
	bool exiting = false;
	while (!exiting)
	{
		fputs("0 - Exit.\n1 - Add a new record.\n"
			"2 - Find the phone number by name.\n3 - Find the name by phone number.\n"
			"4 - Save all records to a file.\n", stdout);
		char setting[3] = { '\0' };
		fgets(setting, 3, stdin);
		switch (setting[0])
		{
		case '0':
		{
			exiting = true;
			break;
		}
		case '1':
		{
			char* name = new char[stringLength];
			fputs("Enter the name: ", stdout);
			fgets(name, stringLength, stdin);
			trim(name);
			fputs("Enter the phone number: ", stdout);
			char* number = new char[stringLength];
			fgets(number, stringLength, stdin);
			trim(number);
			int phoneNumber = parseInt(number);
			delete[] number;
			addRecord(phoneBook, name, phoneNumber);
			break;
		}
		case '2':
		{
			char* name = new char[stringLength];
			fputs("Enter the name: ", stdout);
			fgets(name, stringLength, stdin);
			trim(name);
			Record* record = findRecordByName(phoneBook, name);
			delete[] name;
			if (!record)
			{
				fputs("No record found.\n", stdout);
				break;
			}
			int phoneNumber = record->phoneNumber;
			fputs("The phone number is ", stdout);
			char* temp = new char[stringLength];
			sprintf(temp, "%d", phoneNumber);
			fputs(temp, stdout);
			fputs("\n", stdout);
			delete[] temp;
			break;
		}
		case '3':
		{

			fputs("Enter the phone number: ", stdout);
			char* number = new char[stringLength];
			fgets(number, stringLength, stdin);
			trim(number);
			int phoneNumber = parseInt(number);
			delete[] number;
			Record* record = findRecordByPhoneNumber(phoneBook, phoneNumber);
			if (!record)
			{
				fputs("No record found.\n", stdout);
				break;
			}
			char* name = findRecordByPhoneNumber(phoneBook, phoneNumber)->name;
			fputs("The name is ", stdout);
			fputs(name, stdout);
			fputs("\n", stdout);
			break;
		}
		case '4':
		{
			fputs("Enter the new filename: ", stdout);
			char* filename = new char[stringLength];
			fgets(filename, stringLength, stdin);
			trim(filename);
			FILE* file = fopen(filename, "w");
			delete[] filename;
			writeToNewFile(phoneBook, file);
			break;
		}
		default:
		{
			break;
		}
		}
	}
	deletePhoneBook(phoneBook);
	return 0;
}