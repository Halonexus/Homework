#include <cstdio>

int const stringLength = 256;

int main()
{
	char* fileName = new char[stringLength];
	printf("Enter the fileName: ");
	scanf("%255s", fileName);
	FILE* file = fopen(fileName, "r");
	delete[] fileName;
	char* string = new char[stringLength];//
	int const days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int minDay = -1;
	int minMonth = -1;
	int minYear = -1;
	while (!feof(file))
	{
		int day = 0;
		int month = 0;
		int year = 0;
		fscanf(file, "%d.%d.%d", &day, &month, &year);
		if ((year >= 0) && (month <= 12) && (month > 0) && (day > 0) && 
			(day <= days[month - 1]) && 
			((month != 2) || (year % 4 == 0) && (year % 100 != 0) && (day <= days[1] + 1)))
		{
			if (((minYear < 0) || (year < minYear)) || ((year == minYear)
				&& ((month < minMonth) || ((month == minMonth) && (day < minDay)))))
			{
				minDay = day;
				minMonth = month;
				minYear = year;
			}
		}
	}
	printf("The smallest date is %d.%d.%d\n", minDay, minMonth, minYear);
	fclose(file);
	return 0;
}