#include <cstdio>
#include "AStar.h"

void createAdjacencyMatrix(int**, bool**&, int, int);

int main()
{
	printf("Enter the amount of rows: ");
	int rows = 0;
	int columns = 0;
	scanf("%d", &rows);
	printf("Enter the amount of columns: ");
	scanf("%d", &columns);
	printf("Enter the elements of the matrix: \n");
	int** matrix = new int*[rows];
	bool** result = new bool*[rows];
	for (int i = 0; i < rows; i++)
	{
		result[i] = new bool[rows] {0};
		matrix[i] = new int[columns];
		for (int j = 0; j < columns; j++)
		{
			int value = 0;
			scanf("%d", &value);
			matrix[i][j] = value;
		}
	}

	createAdjacencyMatrix(matrix, result, rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			printf("%d", result[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < rows; i++)
	{
		int count = 0;
		Node* end = new Node{ i,0,0,0,nullptr };
		for (int j = 0; j < rows; j++)
		{
			Node* start = new Node{ j,0,0,0,nullptr };
			if (aStar(start, end, result, rows))
			{
				count++;
			}
		}
		if (count == rows)
		{
			printf("Point %d is reachable from every point.\n", i);
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
		delete[] result[i];
	}
	delete[] matrix;
	delete[] result;
	return 0;
}

void createAdjacencyMatrix(int** matrix, bool**& adjMatrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		adjMatrix[i][i] = true;
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j] == -1)
			{
				for (int k = 0; k < rows; k++)
				{
					if (matrix[k][j] == 1)
					{
						adjMatrix[i][k] = true;
						break;
					}
				}
			}
		}
	}
	return;
}