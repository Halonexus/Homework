#include <cstdio>
#include "ExpressionTree.h"
#include "StringOperations.h"

int const stringLength = 256;

void getInput(FILE*& input);
void createTree(ExpressionTree*& tree, FILE* input);

int main()
{
	FILE* input = nullptr;
	getInput(input);
	ExpressionTree* tree = nullptr;
	createTree(tree, input);
	int result = calculateOutput(tree);
	printTree(tree);
	fputs("\nThe result is: ", stdout);
	char* temp = intToString(result);
	fputs(temp, stdout);
	delete[] temp;
	deleteTree(tree);
	delete tree;
	fclose(input);
	return 0;
}

void getInput(FILE*& input)
{
	char* filename = new char[stringLength];
	while (!input)
	{
		fputs("Enter input filename: ", stdout);
		fgets(filename, stringLength, stdin);
		trim(filename);
		input = fopen(filename, "r");
	}
	delete[] filename;
	return;
}

void createTree(TreeElement*& element, FILE*& input)
{
	char character[2] = { '\0' };
	while (!element)
	{
		fgets(character, 2, input);
		if (character[0] >= '0' && character[0] <= '9')
		{
			char* value = new char[stringLength];
			int i = 0;
			while (character[0] >= '0' && character[0] <= '9')
			{
				value[i] = character[0];
				i++;
				fgets(character, 2, input);
			}
			value[i] = '\0';
			element = new TreeElement{ '\0', parseInt(value), nullptr, nullptr };
			delete[] value;
			return;
		}
		if (character[0] == '+' || character[0] == '-' || character[0] == '*' || character[0] == '/')
		{
			element = new TreeElement{ character[0], 0, nullptr, nullptr };
			createTree(element->leftChild, input);
			createTree(element->rightChild, input);
			return;
		}
	}
	return;
}

void createTree(ExpressionTree*& tree, FILE* input)
{
	char character[2] = { '\0' };
	while (character[0] != '+' && character[0] != '-' && character[0] != '*' && character[0] != '/')
	{
		fgets(character, 2, input);
	}
	TreeElement* root = new TreeElement{ character[0], 0, nullptr, nullptr };
	tree = new ExpressionTree{ root };
	createTree(root->leftChild, input);
	createTree(root->rightChild, input);
	return;
}