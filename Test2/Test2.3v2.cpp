#include <cstdio>

int const stringLength = 512;

int findMaxAmountOfDiffLeters(char* word)
{
	if (!word)
	{
		return -1;
	}
	int amount = 0;
	bool letters[26] = {0};
	int i = 0;
	while (word[i] != '\0')
	{
		int index = 0;
		if (word[i] >= 'a' && word[i] <= 'z')
		{
			index = word[i] - 'a';
		}
		else
		{
			index = word[i] - 'A';
		}
		if (letters[index] == false)
		{
			letters[index] = true;
			amount++;
		}
		i++;
	}
	return amount;
}

int main()
{
	printf("Enter the sentence:\n");
	char* input = new char[stringLength];
	fgets(input, stringLength, stdin);
	char* word = nullptr;
	int wordAmount = 0;

	int maxWordLength = 0;
	int index = 0;
	int i = 0;
	while (input[i] != '\0')
	{
		if (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z')
		{
			wordAmount++;
			index = i;
			int length = 0;
			while (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z')
			{
				length++;
				i++;
			}
			i--;
			if (length > maxWordLength)
			{
				maxWordLength = length;
				if (word)
				{
					delete[] word;
				}
				word = new char[i - index + 2];
				for (int j = index; j < i + 1; j++)
				{
					word[j - index] = input[j];
				}
				word[i - index + 1] = '\0';			
			}
		}
		i++;
	}
	int maxAmountOfDiffLetters = findMaxAmountOfDiffLeters(word);
	if (maxAmountOfDiffLetters == -1)
	{
		printf("There are no words.\n");
	}
	else
	{
		printf("The amount of different letters in the longest word: %d\n"
			"Amount of words: %d\n", maxAmountOfDiffLetters, wordAmount);
		delete[] word;
	}
	return 0;
}