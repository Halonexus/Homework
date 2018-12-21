#include <cstdio>
#include "Graph.h"
#include "List.h"

int const stringLength = 256;

void getInput(int**& input, int& size, int*& capitals, int& capitalAmount, char* filename);
void assignCities(Graph* graph, List* countries, bool* takenCities, int size, int capitalAmount);
void printLists(List* countries, int capitalAmount);

int main()
{
	int** input = nullptr;
	int size = 0;
	int* capitals = nullptr;
	int capitalAmount = 0;
	printf("Enter the filename: ");
	char* filename = new char[stringLength];
	scanf("%s", filename);
	getInput(input, size, capitals, capitalAmount, filename);
	delete[] filename;
	Graph* graph = createGraph(input, size);
	List* countries = new List[capitalAmount];
	bool* takenCities = new bool[size] {};
	for (int i = 0; i < capitalAmount; i++)
	{
		addElement(&countries[i], capitals[i]);
		takenCities[capitals[i]] = true;
	}
	assignCities(graph, countries, takenCities, size, capitalAmount);
	printLists(countries, capitalAmount);
	deleteGraph(graph);
	delete[] capitals;
	for (int i = 0; i < capitalAmount; i++)
	{
		deleteList(&countries[i]);
	}
	delete[] countries;
	delete[] takenCities;
	return 0;
}

void getInput(int**& input, int& size, int*& capitals, int& capitalAmount, char* filename)
{
	FILE* file = fopen(filename, "r");
	if (!file)
	{
		return;
	}
	fscanf(file, "%d", &size);
	input = new int*[size];
	for (int i = 0; i < size; i++)
	{
		input[i] = new int[size] {};
	}
	int roads = 0;
	fscanf(file, "%d", &roads);
	for (int i = 0; i < roads; i++)
	{
		int node1 = 0;
		int node2 = 0;
		int length = 0;
		fscanf(file, "%d %d %d", &node1, &node2, &length);
		input[node1][node2] = length;
		input[node2][node1] = length;
	}
	fscanf(file, "%d", &capitalAmount);
	capitals = new int[capitalAmount];
	for (int i = 0; i < capitalAmount; i++)
	{
		int capital = 0;
		fscanf(file, "%d", &capital);
		capitals[i] = capital;
	}
	fclose(file);
	return;
}

void assignCities(Graph* graph, List* countries, bool* takenCities, int size, int capitalAmount)
{
	int freeCities = size - capitalAmount;
	int i = 0;
	while (freeCities > 0)
	{
		ListElement* current = countries[i % capitalAmount].head;
		int minLength = 0;
		int town = 0;
		while (current)
		{
			for (int j = 0; j < size; j++)
			{
				if ((minLength == 0 || graph->matrix[current->value][j] < minLength) && takenCities[j] == false && graph->matrix[current->value][j] > 0)
				{
					minLength = graph->matrix[current->value][j];
					town = j;
				}
			}
			current = current->next;
		}
		if (minLength != 0)
		{
			addElement(&countries[i % capitalAmount], town);
			takenCities[town] = true;
			freeCities--;
		}
		i++;
	}
	return;
}

void printLists(List * countries, int capitalAmount)
{
	for (int i = 0; i < capitalAmount; i++)
	{
		printf("Country #%d: ", i + 1);
		ListElement* current = countries[i].head;
		while (current)
		{
			printf("%d ", current->value);
			current = current->next;
		}
		printf("\n");
	}
	return;
}