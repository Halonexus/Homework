#include <cstdio>

char* getInput(FILE* const file);
void processString(char* string);
char* removeCopiesOfLetters(char* string);
void printWord(const char* const string);
int getLength(const char* const string);
bool isLetter(const char character);

int const stringLength = 256;

int main()
{
	FILE* file;
	fputs("Enter The filename: ", stdout);
	char* fileName = new char[stringLength];
	fgets(fileName, stringLength, stdin);
	fileName[getLength(fileName) - 1] = '\0';
	file = fopen(fileName, "r");
	delete[] fileName;
	if (file)
	{
		while (feof(file) == 0)
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

char* getInput(FILE* const file)
{
	int length = 1;
	fpos_t current;
	fgetpos(file, &current);
	char temp = fgetc(file);
	while (temp != '\n')
	{
		temp = fgetc(file);
		length++;
	}
	char* string = new char[length + 1];
	fsetpos(file, &current);
	fgets(string, length + 1, file);
	if (string[length - 1] == '\n')
	{
		string[length - 1] = '\0';
	}
	//removes unneeded characters from the beginning of the file
	if ((string[0] == -17) && (string[1] = -69) && (string[2] == -65))
	{
		string[0] = '\r';
		string[1] = '\r';
		string[2] = '\r';
	}
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
	int const russianAlphabetLength = 33;
	char const englishUpperFirstLetter = 'A';
	char const englishLowerFirstLetter = 'a';
	char const russianUpperFirstLetter = 'А';
	char const russianLowerFirstLetter = 'а';

	int index = 0;

	if (letter >= 'A' && letter <= 'Z')
	{
		index = (letter - englishUpperFirstLetter) % englishAlphabetLength + russianAlphabetLength;

	}
	else if (letter >= 'a' && letter <= 'z')
	{
		index = (letter - englishLowerFirstLetter) % englishAlphabetLength + russianAlphabetLength;
	}
	else if (letter >= 'а' && letter <= 'я')
	{
		index = (letter - russianLowerFirstLetter) % russianAlphabetLength;
	}
	else if (letter >= 'А' && letter <= 'Я')
	{
		index = (letter - russianUpperFirstLetter) % russianAlphabetLength;
	}
	return index;
}

char* removeCopiesOfLetters(char* string)
{
	char* word = new char[stringLength];
	int i = 0;
	int j = 0;
	bool letters[59] = {};
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


int getLength(const char* const string)
{
	int length = 0;
	while (string[length] != '\0')
	{
		length++;
	}
	return length;
}

bool isLetter(const char character)
{
	return ((character >= 'a' && character <= 'z')
		|| (character >= 'A' && character <= 'Z')
		|| (character >= 'а' && character <= 'я')
		|| (character >= 'А' && character <= 'Я'));
}