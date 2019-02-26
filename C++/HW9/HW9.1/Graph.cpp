#include "Graph.h"

Graph* createGraph(int** matrix, int size)
{
	return new Graph{ size, matrix };
}

void deleteGraph(Graph* graph)
{
	if (graph && graph->matrix)
	{
		for (int i = 0; i < graph->size; i++)
		{
			if (graph->matrix[i])
			{
				delete[]graph->matrix[i];
			}
		}
		delete[] graph->matrix;
	}
	if (graph)
	{
		delete graph;
	}
	return;
}