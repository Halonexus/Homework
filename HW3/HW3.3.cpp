#include <cstdio>

int complexity = 0;

double* getArrayOfPowers(int power, double base)
{
	int count = 0;
	while (power > 0)
	{
		power = power / 2;
		count++;
		complexity += 2;
	}
	double* arrayOfPowers = new double[count];
	arrayOfPowers[0] = base;
	for (int i = 1; i < count; i++)
	{
		arrayOfPowers[i] = arrayOfPowers[i - 1] * arrayOfPowers[i - 1];
		complexity++;
	}
	return arrayOfPowers;
}

double calculateOutput(bool isNegative, double* arrayOfPowers, int power) 
{
	double output = 1.0;
	int count = 0;
	while (power > 0)
	{
		if (power % 2 == 1)
		{
			output *= arrayOfPowers[count];
			complexity++;
		}
		power = power / 2;
		count++;
		complexity += 2;
	}
	if (isNegative)
	{
		output = 1 / output;
	}
	return output;
}

int main()
{
	printf("Enter a and n:\n");
	double a = 0.0;
	int n = 0;
	scanf("%lf %d", &a, &n);
	
	bool isNegative = false;
	if (n < 0)
	{
		isNegative = true;
		n = -n;
	}
	double* arrayOfPowers = getArrayOfPowers(n, a);
	double output = calculateOutput(isNegative, arrayOfPowers, n);
	printf("a^n == %f\nComplexity == %d", output, complexity);
	
	delete[] arrayOfPowers;
    return 0;
}