#include <cstdio>
#include "StringOperations.h"

char* getInput(FILE*& file);
void processString(char* string);
char* removeCopiesOfLetters(char* string);
void printWord(const char* const string);
bool isLetter(const char character);

int const stringLength = 256;

int main()
{
	FILE* file;
	fputs("Enter The filename: ", stdout);
	char* filename = new char[stringLength];
	fgets(filename, stringLength, stdin);
	trim(filename);
	file = fopen(filename, "r");
	delete[] filename;
	if (file)
	{
		while (!feof(file))
		{
			char* string = getInput(file);
			processString(string);
			delete[] string;
		}
		fclose(file);
	}
	else
	{
		fputs("Error opening file.\n", stdout);
	}
	return 0;
}

char* getInput(FILE*& file)
{
	char* string = new char[stringLength];
	fgets(string, stringLength, file);
	trim(string);
	return string;
}

void processString(char* string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		if (isLetter(string[i]))
		{
			char* subString = new char[stringLength];
			int j = 0;
			while (isLetter(string[i]))
			{
				subString[j++] = string[i++];
			}
			subString[j] = '\0';
			char* word = removeCopiesOfLetters(subString);
			printWord(word);
			delete[] word;
			delete[] subString;
			i--;
		}
		i++;
	}
	fputs("\n", stdout);
	return;
}

int normalizeIndex(char letter)
{
	int const englishAlphabetLength = 26;
	char const englishUpperFirstLetter = 'A';
	char const englishLowerFirstLetter = 'a';

	int index = 0;

	if (letter >= 'A' && letter <= 'Z')
	{
		index = (letter - englishUpperFirstLetter) % englishAlphabetLength;

	}
	else if (letter >= 'a' && letter <= 'z')
	{
		index = (letter - englishLowerFirstLetter) % englishAlphabetLength;
	}
	return index;
}

char* removeCopiesOfLetters(char* string)
{
	char* word = new char[stringLength];
	int i = 0;
	int j = 0;
	bool letters[26] = {};
	while (string[i] != '\0')
	{
		int index = normalizeIndex(string[i]);
		if (letters[index] == false)
		{
			letters[index] = true;
			word[j++] = string[i];
		}
		i++;
	}
	word[j] = '\0';
	return word;
}

void printWord(const char* const string)
{
	fputs(string, stdout);
	fputs(" ", stdout);
	return;
}

bool isLetter(const char character)
{
	return ((character >= 'a' && character <= 'z')
		|| (character >= 'A' && character <= 'Z'));
}