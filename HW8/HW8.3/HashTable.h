#pragma once
#include "String.h"

struct HashTable
{
	String* table = nullptr;
	int* uses = nullptr;
	int size = 0;
	int maxTries = 0;
	String maxTryString;
	int tries = 0;
	int words = 0;
};

HashTable* createTable(int size);
void deleteHashTable(HashTable*);
int hash(String, int);
double loadFactor(HashTable*);
void addElement(HashTable*, String);
void deleteElement(HashTable*, String);
int getUnused(HashTable*);
bool isInTable(HashTable*, String);