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
		printf("%f*2^%d\n", fraction, exponent);
	}
	return 0;
}