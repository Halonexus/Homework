#pragma once

struct Graph
{
	int size;
	int** matrix = nullptr;
};

Graph* createGraph(int** matrix, int size);
void deleteGraph(Graph*);