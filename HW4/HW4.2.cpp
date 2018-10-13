#include <cstdio>
#include "phonebook.h"

int main()
{
	int const stringLength = 256;
	PhoneBook* phoneBook = new PhoneBook;
	fillPhoneBookFromFile(phoneBook);
	bool exiting = false;
	while (!exiting)
	{
		printf("0 - Exit.\n1 - Add a new record.\n2 - Find the phone number by name.\n3 - Find the name by phone number.\n4 - Save all records to a file.\n");
		char setting = '\n';
		while (setting == '\n')
		{
			scanf("%c", &setting);
		}		
		switch (setting)
		{
		case '0':
		{
			exiting = true;
			break;
		}
		case '1':
		{
			char* name = new char[stringLength];
			int phoneNumber = 0;
			printf("Enter the name: ");
			scanf("%s", name);
			printf("Enter the phone number: ");
			scanf("%d", &phoneNumber);
			addRecord(phoneBook, name, phoneNumber);
			break;
		}
		case '2':
		{
			char* name = new char[stringLength];
			printf("Enter the name: ");
			scanf("%s", name);
			Record* record = findRecordByName(phoneBook, name);
			delete[] name;
			if (!record)
			{
				printf("No record found.\n");
				break;
			}
			int phoneNumber = record->phoneNumber;			
			printf("The phone number is %d.\n", phoneNumber);
			break;
		}
		case '3':
		{
			int phoneNumber = 0;
			printf("Enter the phone number: ");
			scanf("%d", &phoneNumber);
			Record* record = findRecordByPhoneNumber(phoneBook, phoneNumber);
			if (!record)
			{
				printf("No record found.\n");
				break;
			}
			char* name = findRecordByPhoneNumber(phoneBook, phoneNumber)->name;
			printf("The name is %s.\n", name);
			break;
		}
		case '4':
		{
			writeToNewFile(phoneBook);
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