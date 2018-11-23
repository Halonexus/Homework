#include <cstdio>
#include "List.h"

int const stringLength = 256;

int main()
{
	printf("Enter the numbers a and b:\n");
	int number1 = 0;
	int number2 = 0;
	scanf("%d %d", &number1, &number2);
	printf("Enter the filename: ");
	char* fileName = new char[stringLength];
	scanf("%s", fileName);
	FILE* inputFile = fopen(fileName, "r");
	delete[] fileName;
	FILE* outputFile = fopen("output.txt", "w");
	List* greaterList = new List;
	List* inRangeList = new List;
	while (!feof(inputFile))
	{
		int input = 0;
		fscanf(inputFile, "%d", &input);
		if (input < number1)
		{
			fprintf(outputFile, "%d ", input);
		}
		else if (input > number2)
		{
			addElement(greaterList, input);
		}
		else
		{
			addElement(inRangeList, input);
		}
	}
	while (!isEmpty(inRangeList))
	{
		fprintf(outputFile, "%d ", getHeadValue(inRangeList));
		deleteHead(inRangeList);
	}
	while (!isEmpty(greaterList))
	{
		fprintf(outputFile, "%d ", getHeadValue(greaterList));
		deleteHead(greaterList);
	}
	delete greaterList;
	delete inRangeList;
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}