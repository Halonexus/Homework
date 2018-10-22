#include <cstdio>

void getInput(char*& string, FILE* const file);
void processString(char* string);
char* removeCopiesOfLetters(char* string);
void printWord(const char* const string);
int getLength(const char* const string);
bool isLetter(const char character);

int const stringLength = 256;

int main()
{
	FILE* file;
	file = fopen("test.txt", "r");
	if (file)
	{
		char* string = new char[stringLength];
		while (feof(file) == 0)
		{
			getInput(string, file);
			processString(string);
		}
		delete[] string;
		fclose(file);
	}
	else
	{
		fputs("Error opening file.\n", stdout);
	}
	return 0;
}

void getInput(char*& string, FILE* const file)
{
	fgets(string, stringLength, file);
	int length = getLength(string);
	if (length > 0 && string[length - 1] == '\n')
	{
		string[length - 1] = '\0';
	}
	return;
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

char* removeCopiesOfLetters(char* string)
{
	char* word = new char[stringLength];
	int i = 0;
	int j = 0;
	bool letters[59] = {};
	while (string[i] != '\0')
	{
		int index = 0;
		if (string[i] >= 'A' && string[i] <= 'Z')
		{
			index = (string[i] - 'A') % 26 + 33;
			
		}
		else if (string[i] >= 'a' && string[i] <= 'z')
		{
			index = (string[i] - 'a') % 26 + 33;
		}
		else if (string[i] >= 'а' && string[i] <= 'я')
		{
			index = (string[i] - 'а') % 33;
		}
		else if (string[i] >= 'А' && string[i] <= 'Я')
		{
			index = (string[i] - 'А') % 33;
		}
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
	if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character >= 'а' && character <= 'я') || (character >= 'А' && character <= 'Я'))
	{
		return true;
	}
	return false;
}