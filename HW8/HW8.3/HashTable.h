#pragma once
#include "String.h"

struct HashTable 
{
	String* table = nullptr;
	int* uses = nullptr;
	int size = 0;
};

HashTable* createTable(int size);
void deleteHashTable(HashTable*);
int hash(String, int);
double loadFactor(HashTable*);
void addElement(HashTable*, String);
void deleteElement(HashTable*, String);
double getAverageTries();
int getMaxTries();
int getTotalWords();
int getUnused(HashTable*);
String getMaxTryString();