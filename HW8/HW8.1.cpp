#include <cstdio>

int* getInput(int amount)
{
	int* students = new int[amount] {};
	for (int i = 0; i < amount; i++)
	{
		int index = 0;
		int value = 0;
		scanf("%d %d", &index, &value);
		students[index - 1] = value;
	}
	return students;
}

int main()
{	
	int amount = 0;
	while (amount < 3)
	{
		printf("Enter the amount of students: ");
		scanf("%d", &amount);
	}
	printf("Enter student numbers and homework sources: \n");
	int* students = getInput(amount);
	printf("Submitted homework variants:\n");
	for (int i = 0; i < amount; i++)
	{
		if (students[i] > 3) 
		{
			if (students[i] < i + 1)
			{
				students[i] = students[students[i] - 1];
			}
			else
			{
				while (students[i] > 3)
				{
					students[i] = students[students[i] - 1];
				}
			}
		}		
		printf("%d  %d\n", i + 1, students[i]);
	}
	delete[] students;
	return 0;
}