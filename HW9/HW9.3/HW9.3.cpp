#include <cstdio>
#include "StringOperations.h"
#include "StringTree.h"

int const stringLength = 256;

StringTree* getTree(FILE*& file);
void getTree(Element*&, FILE*& file);
void printText(StringTree* tree, FILE* input, FILE* output);


int main()
{
	fputs("Enter the input filename: ", stdout);
	char* filename = new char[stringLength];
	fgets(filename, stringLength, stdin);
	trim(filename);
	FILE* input = fopen(filename, "r");
	if (!input)
	{
		fputs("Error opening file.", stdout);
	}
	else
	{
		fputs("Enter the output filename: ", stdout);
		fgets(filename, stringLength, stdin);
		trim(filename);
		FILE* output = fopen(filename, "w");
		StringTree* tree = getTree(input);
		printText(tree, input, output);
		fclose(input);
		fclose(output);
	}
	delete[] filename;
	return 0;
}

void getTree(Element*& element, FILE*& file)
{
	char* temp = new char[stringLength];
	char character[2] = { '\0' };
	int i = 0;
	while (character[0] != '(')
	{
		fgets(character, 2, file);
		temp[i++] = character[0];
	}
	if (temp[0] != ' ')
	{
		element = nullptr;
		return;
	}
	if (i == 4)
	{
		element = new Element{ new char[2]{ temp[1],'\0' }, nullptr, 0, nullptr, nullptr };
		for (int j = 0; j < 2; j++)
		{
			fgets(character, 2, file);
			while (character[0] != '(' && character[0] != '\n')
			{
				fgets(character, 2, file);
			}
		}
		return;
	}
	if (i == 5 && temp[1] == '\\' && temp[2] == 'n')
	{
		element = new Element{ new char[3]{ temp[1], temp[2], '\0' }, nullptr, 0, nullptr, nullptr };
		for (int j = 0; j < 2; j++)
		{
			while (character[0] != '(' && character[0] != '\n')
			{
				fgets(character, 2, file);
			}
		}
		return;
	}
	element = new Element;
	getTree(element->leftChild, file);
	getTree(element->rightChild, file);
	return;
}

StringTree* getTree(FILE*& file)
{
	char character[2] = { '\0' };
	fgets(character, 2, file);
	fgets(character, 2, file);
	while (character[0] != '(')
	{
		fgets(character, 2, file);
	}
	Element* root = new Element;
	getTree(root->leftChild, file);
	getTree(root->rightChild, file);
	return createTree(root);
}

void printText(StringTree* tree, FILE* input, FILE* output)
{
	char character[2] = { '\0' };
	Element* current = tree->root;
	while (!feof(input))
	{
		fgets(character, 2, input);
		if (character[0] == '0')
		{
			current = current->leftChild;
		}
		else if (character[0] == '1')
		{
			current = current->rightChild;
		}
		if (current->string)
		{
			if (current->string[0] == '\\' && current->string[1] == 'n')
			{
				fputs("\n", output);
			}
			else
			{
				fputs(current->string, output);
			}
			current = tree->root;
		}
	}
	return;
}