#include <cstdio>
#include "StringOperations.h"
#include "AStar.h"

int const stringLength = 256;

void getMapSize(FILE* file, int&, int&);
void getMap(bool**& map, int, int, FILE*);
void getPoints(Node*&, Node*&);

int main()
{
	fputs("Enter the filename: ", stdout);
	char* filename = new char[stringLength];
	fgets(filename, stringLength, stdin);
	trim(filename);
	FILE* file = fopen(filename, "r");
	delete[] filename;
	if (!file)
	{
		fputs("Error opening file.", stdout);
	}
	else
	{
		int rows = 0;
		int columns = 0;
		getMapSize(file, rows, columns);
		bool** map = new bool*[rows];
		for (int i = 0; i < rows; i++)
		{
			map[i] = new bool[columns];
		}
		getMap(map, rows, columns, file);
		fclose(file);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		Node* start = nullptr;
		Node* end = nullptr;
		getPoints(start, end);
		AStar(start, end, map, rows, columns);
	}
	return 0;
}

void getMapSize(FILE* file, int& rows, int& columns)
{
	char character[2] = { '\0' };
	while (!feof(file) && character[0] != '\n')
	{
		fgets(character, 2, file);
		if (character[0] == '0' || character[0] == '1')
		{
			columns++;
		}
	}
	rows = 1;
	while (!feof(file))
	{
		if (character[0] == '\n')
		{
			rows++;
		}
		fgets(character, 2, file);
	}
	rewind(file);
	return;
}

void getMap(bool**& map, int rows, int columns, FILE* file)
{
	char character[2] = { '\0' };
	int i = 0;
	while (!feof(file) && i < rows * columns)
	{
		fgets(character, 2, file);
		if (character[0] == '0')
		{
			map[i / columns][i % columns] = 0;
			i++;
		}
		else if (character[0] == '1')
		{
			map[i / columns][i % columns] = 1;
			i++;
		}
	}
	return;
}

void getPoints(Node*& start, Node*& end)
{
	char* input = new char[stringLength];
	fputs("Enter x coordinate of the start: ", stdout);
	fgets(input, stringLength, stdin);
	trim(input);
	start = new Node;
	end = new Node;
	start->x = parseInt(input);
	fputs("Enter y coordinate of the start: ", stdout);
	fgets(input, stringLength, stdin);
	trim(input);
	start->y = parseInt(input);
	fputs("Enter x coordinate of the end: ", stdout);
	fgets(input, stringLength, stdin);
	trim(input);
	end->x = parseInt(input);
	fputs("Enter y coordinate of the end: ", stdout);
	fgets(input, stringLength, stdin);
	trim(input);
	end->y = parseInt(input);
	delete[] input;
	return;
}
