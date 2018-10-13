#pragma once

struct Record
{
	Record* next = nullptr;
	char* name = nullptr;
	int phoneNumber = 0;
};

struct PhoneBook 
{
	Record* head = nullptr;
};

void addRecord(PhoneBook*, char* name, int phoneNumber);
void addRecord(PhoneBook*, Record*);
Record* findRecordByName(PhoneBook*, char* name);
Record* findRecordByPhoneNumber(PhoneBook*, int phoneNumber);
void deleteRecord(PhoneBook*, Record*);
void deletePhoneBook(PhoneBook*);
void writeToNewFile(PhoneBook*);
void fillPhoneBookFromFile(PhoneBook*);
bool areStringsEqual(char*, char*);