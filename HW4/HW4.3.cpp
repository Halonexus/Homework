#include <cstdio>

int main()
{
	FILE* file = fopen("input.txt", "r");
	int amountOfNonEmptyLines = 0;
	bool isEmpty = true;
	char character = '\0';
	while (fscanf(file, "%c", &character) != EOF)
	{
		if (character == '\n')
		{
			isEmpty = true;
			continue;
		}
		if (!isEmpty)
		{
			continue;
		}
		if ((character != '\t') && (character != ' '))
		{
			isEmpty = false;
			amountOfNonEmptyLines++;
		}
	}
	fclose(file);
	printf("There are %d non empty lines in the file.\n", amountOfNonEmptyLines);
	return 0;
}