#include <cstdio>

void printNumberInBinary(int number)
{
	char* byte = (char*)&number;
	for (int i = 3; i >= 0; i--)
	{
		int bit = 0x80;
		for (int j = 0; j < 8; j++)
		{
			printf((byte[i] & bit) ? "1" : "0");
			bit = bit >> 1;
		}
	}
	return;
}

int addNumbersInBinary(int lhs, int rhs)
{
	int result = 0;
	char* byteResult = (char*)&result;
	char* byte1 = (char*)&lhs;
	char* byte2 = (char*)&rhs;
	int carry = 0;
	for (int i = 3; i >= 0; i--)
	{
		int bit = 0x01;
		for (int j = 7; j >= 0; j--)
		{
			int currentSum = ((byte1[i] & bit) ? 1 : 0) + ((byte2[i] & bit) ? 1 : 0) + carry;
			bit = bit << 1;
			byteResult[i] = byteResult[i] | ((currentSum % 2) << (7 - j));
			carry = currentSum / 2;
		}
	}
	return result;
}

int main()
{
	int firstNumber = 0;
	int secondNumber = 0;
	printf("Enter two numbers:\n");
	scanf("%d %d", &firstNumber, &secondNumber);
	printf("These numbers in binary:\n");
	printNumberInBinary(firstNumber);
	printf("\n");
	printNumberInBinary(secondNumber);
	printf("\n");
	printf("Sum of these numbers in binary:\n");
	printNumberInBinary(addNumbersInBinary(firstNumber, secondNumber));
	printf("\nSum of these numbers:\n%d\n", firstNumber + secondNumber);
	return 0;
}