#include <cstdio>

int main()
{
	int columns = 0;
	int rows = 0;
	printf("Enter the number of columns: ");
	scanf("%d", &columns);
	printf("Enter the amount of rows: ");
	scanf("%d", &rows);
	int** twoDimArray = new int*[rows];
	int* rowMin = new int[rows];
	int* colMax = new int[columns];
	for (int i = 0; i < rows; i++)
	{
		int min = 0;
		twoDimArray[i] = new int[columns];
		printf("Enter a row:\n");
		for (int j = 0; j < columns; j++)
		{
			int input = 0;
			scanf("%d", &input);
			twoDimArray[i][j] = input;
			if (i == 0)
			{
				colMax[j] = input;
			}
			else if (input > colMax[j])
			{
				colMax[j] = input;
			}
			if (j == 0)
			{
				min = input;
			}
			else if(input < min)
			{
				min = input;
			}
			rowMin[i] = min;
		}
	}
	printf("Points that are min of a row and max of a column:\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (rowMin[i] == colMax[j])
			{
				printf("Row %d, Column %d\n", i, j);
			}
		}
	}
	delete[] rowMin;
	delete[] colMax;
	for (int i = 0; i < rows; i++)
	{
		delete[] twoDimArray[i];
	}
	delete[] twoDimArray;
	return 0;
}