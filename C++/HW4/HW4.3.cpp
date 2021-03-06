#include <cstdio>

int const stringLength = 256;

int main()
{
	char* name = new char[stringLength];
	printf("Enter the name of the file: ");
	scanf("%255s", name);
	FILE* file = fopen(name, "r");
	delete[] name;
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
		if ((character != '\t') && (character != ' ') && (character != '\r'))
		{
			isEmpty = false;
			amountOfNonEmptyLines++;
		}
	}
	fclose(file);
	printf("There are %d non empty lines in the file.\n", amountOfNonEmptyLines);
	return 0;
}