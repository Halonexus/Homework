#include <cstdio>
#include "AVLTree.h"
#include "StringTree.h"
#include "StringOperations.h"

int const stringLength = 256;

void sort(Element** elements, int size);
void printCharacterFrequency(Element**, int size);
void createCharacterArray(Element**&, int, int&, AVLTree&, char);
void createStringsArray(Element**&, int, Element**&);
void createStringTree(StringTree*&, Element**&, Element**&, int);
void printBinary(FILE* input, FILE* output, Element**&, int, int);

int main()
{
	char* filename = new char[stringLength];
	fputs("Enter the filename: ", stdout);
	fgets(filename, 256, stdin);
	trim(filename);
	FILE* file = fopen(filename, "r");
	if (!file)
	{
		fputs("Error opening file.", stdout);
	}
	else
	{
		AVLTree tree;
		char character[2] = {};
		while (!feof(file))
		{
			fgets(character, 2, file);
			addTreeElement(tree, character[0]);
		}
		int characterAmount = getNumberOfNodes(tree);
		Element** characters = new Element*[characterAmount] {nullptr};
		int totalAmount = 0;
		createCharacterArray(characters, characterAmount, totalAmount, tree, character[0]);
		sort(characters, characterAmount);
		Element** strings = nullptr;
		createStringsArray(strings, characterAmount, characters);
		StringTree* stringTree = nullptr;
		createStringTree(stringTree, strings, characters, characterAmount);
		makeBinary(stringTree);
		rewind(file);
		fputs("Enter the output filename: ", stdout);
		fgets(filename, 256, stdin);
		trim(filename);
		FILE* output = fopen(filename, "w");
		printCharacterFrequency(characters, characterAmount);
		printTreeNodes(stringTree, output);
		fputs("\n", output);
		printBinary(file, output, characters, characterAmount, totalAmount);
		delete[] filename;
		deleteTree(tree);
		deleteTree(stringTree);
		delete stringTree;
		if (strings)
		{
			delete[] strings;
		}
		delete[] characters;
		fclose(file);
		fclose(output);
	}
	return 0;
}

void printCharacterFrequency(Element** characters, int size)
{
	if (!characters)
	{
		return;
	}
	for (int i = 0; i < size; i++)
	{
		fputs(characters[i]->string, stdout);
		fputs("  ", stdout);
		fputs(intToString(characters[i]->amount), stdout);
		fputs("\n", stdout);
	}
	return;
}

void sort(Element** elements, int size)
{
	if (!elements)
	{
		return;
	}
	for (int i = 1; i < size; i++)
	{
		if (elements[i]->amount < elements[i - 1]->amount)
		{
			Element* temp = elements[i];
			elements[i] = elements[i - 1];
			elements[i - 1] = temp;
		}
	}
	return;
}

void createCharacterArray(Element**& characters, int characterAmount, int& totalAmount, AVLTree& tree, char character)
{
	for (int i = 0; i < characterAmount; i++)
	{
		if (tree.root->character == '\n')
		{
			characters[i] = new Element{ new char[3]{ '\\', 'n', '\0' }, nullptr, tree.root->amount, nullptr, nullptr };
		}
		else
		{
			characters[i] = new Element{ new char[2]{ tree.root->character, '\0' }, nullptr, tree.root->amount, nullptr, nullptr };
		}
		if (tree.root->character == character)
		{
			characters[i]->amount--;
		}
		totalAmount += characters[i]->amount;
		deleteTreeElement(tree, tree.root->character);
	}
	return;
}

void createStringsArray(Element**& strings, int characterAmount, Element**& characters)
{
	if (characterAmount > 1)
	{
		strings = new Element*[characterAmount - 1]{ nullptr };
	}
	int j = 0;
	int k = 0;
	for (int i = 0; i < characterAmount - 1; i++)
	{
		Element* left = nullptr;
		Element* right = nullptr;
		if (j >= characterAmount || strings[k] && strings[k]->amount < characters[j]->amount)
		{
			left = strings[k];
			k++;
		}
		else
		{
			left = characters[j];
			j++;
		}
		if (j >= characterAmount || strings[k] && strings[k]->amount < characters[j]->amount)
		{
			right = strings[k];
			k++;
		}
		else
		{
			right = characters[j];
			j++;
		}
		strings[i] = new Element{ concatenate(left->string, right->string), nullptr, left->amount + right->amount, left, right };
	}
	return;
}

void createStringTree(StringTree*& stringTree, Element**& strings, Element**& characters, int characterAmount)
{
	if (characterAmount > 1)
	{
		stringTree = createTree(strings[characterAmount - 2]);
	}
	else
	{
		stringTree = createTree(characters[0]);
	}
	return;
}

void printBinary(FILE* input, FILE* output, Element**& characters, int characterAmount, int totalAmount)
{
	char character[2] = { '\0' };
	for (int i = 0; i < totalAmount; i++)
	{
		fgets(character, 2, input);
		for (int i = 0; i < characterAmount; i++)
		{
			if (equals(characters[i]->string, character) || equals(characters[i]->string, "\\n") && equals(character, "\n"))
			{
				fputs(characters[i]->binaryString, output);
				break;
			}
		}
	}
	return;
}