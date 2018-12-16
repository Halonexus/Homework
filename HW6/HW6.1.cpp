#include <cstdio>

double getFraction(double number)
{
	double fraction = 0.0;
	char* byte = (char*)&number;
	char* fractionByte = (char*)&fraction;
	fractionByte[7] = 0x3f;
	fractionByte[6] = 0xf0 | (byte[6] & 0x0f);
	for (int i = 5; i >= 0; i--)
	{
		fractionByte[i] = byte[i];
	}
	return fraction;
}

int getExponent(double number)
{
	char* byte = (char*)&number;
	int const shift = 1023;
	int exponent = ((byte[7] & 0b01111111) << 4) + ((byte[6] & 0b11110000) >> 4) - shift;
	return exponent;
}

int raisePower(int base, int power)
{
	int result = base;
	for (int i = 0; i < power-1; i++)
	{
		result = result * base;
	}
	return result;
}

int getPrecision(double fraction)
{
	int const maxPrecisionDigits = 6;
	int precision = maxPrecisionDigits;
	int temp = (int)(fraction * raisePower(10, maxPrecisionDigits));
	for (int i = 0; i < maxPrecisionDigits; i++)
	{
		if (temp % 10 == 0)
		{
			precision--;
			temp = temp / 10;
		}
		else
		{
			break;
		}
	}
	return precision;
}

int main()
{
	double number = 0.0;
	printf("Enter a number: ");
	scanf("%lf", &number);
	if (number == 0.0)
	{
		printf("0");
	}
	else
	{
		double fraction = getFraction(number);
		int exponent = getExponent(number);
		char* byte = (char*)&number;
		printf("Result: ");
		printf((byte[7] & 0x80) ? "-" : "+");
		printf("%.*f * 2^%d\n", getPrecision(fraction), fraction, exponent);
	}
	return 0;
}