// HW2.3.cpp : Defines the entry point for the console application.
//

#include <cstdio>

void quickSort(int** input, int size)
{
	int** output = input;
	int q = 0;
	if (size < 2)
	{
		return;
	}
	for (int i = 0; i < size - 1; i++)
	{
		double fraction1 = (double)output[i][0] / (double)output[i][1];
		double fraction2 = (double)output[size - 1][0] / (double)output[size - 1][1];
		if (fraction1 < fraction2)
		{
			int* temp = output[q];
			output[q] = output[i];
			output[i] = temp;
			q++;
		}
	}
	int* temp = output[q];
	output[q] = output[size - 1];
	output[size - 1] = temp;
	quickSort(output, q);
	output = &output[q + 1];
	quickSort(output, size - q - 1);
	return;
}

void printFractions(int** input, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d/%d  ", input[i][0], input[i][1]);
	}
	return;
}

void deleteArray(int** input, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] input[i];
	}
	delete[] input;
	return;
}

int filterArray(int** input, int size)
{
	double e = 1e-8;
	for (int i = 0; i < size - 1; i++)
	{
		double fraction1 = (double)input[i][0] / (double)input[i][1];
		for (int j = i + 1; j < size; j++)
		{
			double fraction2 = (double)input[j][0] / (double)input[j][1];
			if ( !((fraction2 - fraction1 > e) || (fraction1 - fraction2 > e)) )
			{
				delete[] input[j];
				input[j] = input[size - 1];
				size--;
				j--;
			}
		}				
	}
	return size;
}

int main()
{
	printf("Enter a positive integer:\n");
	int input = 0;
	scanf("%d", &input);

	int maxAmount = (1 + input) * input / 2;
	int** fractions = new int*[maxAmount];
	int fractionNumber = 0;
	for (int i = 1; i < input; i++)
	{
		for (int j = i + 1; j <= input; j++)
		{
			if ((j % i != 0) || (i == 1))
			{
				fractions[fractionNumber] = new int[2];
				fractions[fractionNumber][0] = i;
				fractions[fractionNumber][1] = j;
				fractionNumber++;
			}
		}
	}

	fractionNumber = filterArray(fractions, fractionNumber);
	quickSort(fractions, fractionNumber);
	printf("All fractions in (0;1) in ascending order:\n");
	printFractions(fractions, fractionNumber);
	deleteArray(fractions, fractionNumber);

    return 0;
}