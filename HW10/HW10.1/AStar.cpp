#include <cstdio>
#include "AStar.h"
#include "AVLTree.h"
#include "Stack.h"

bool aStar(Node* start, Node* end, bool** map, int rows, int columns)
{
	if (!isValid(map, rows, columns, start) || !isValid(map, rows, columns, end))
	{
		return false;
	}
	AVLTree open, closed;
	start->h = heuristic(start, end);
	start->f = start->h;
	addTreeElement(open, start);
	while (!isEmpty(open))
	{
		Node* q = getMinElement(open.root)->node;
		deleteTreeElement(open, q);
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if ((i != 0 || j != 0) && isValid(map, rows, columns, q->y + i, q->x + j))
				{
					int y = q->y + i;
					int x = q->x + j;
					Node* child = new Node{ q->y + i , q->x + j, q->g + 1, 0, 0, q };
					child->h = heuristic(child, end);
					child->f = child->g + child->h;
					if (child->x == end->x && child->y == end->y)
					{
						printPath(child);
						delete child;
						delete end;
						delete q;
						deleteTree(open);
						deleteTree(closed);
						return true;
					}
					Node* temp = inTree(open, child);
					if (temp && temp->f < child->f)
					{
						delete child;
						continue;
					}
					temp = inTree(closed, child);
					if (temp && temp->f < child->f)
					{
						delete child;
						continue;
					}
					else
					{
						addTreeElement(open, child);
					}
				}
			}
		}
		addTreeElement(closed, q);
	}
	delete end;
	deleteTree(open);
	deleteTree(closed);
	return false;
}

int abs(int a)
{
	return a > 0 ? a : -a;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int heuristic(Node* current, Node* end)
{
	int yDifference = abs(current->y - end->y);
	int xDifference = abs(current->x - end->x);
	return max(xDifference, yDifference);
}

bool isValid(bool** map, int rows, int columns, Node* node)
{
	if (node->y >= 0 && node->y < rows && node->x >= 0 && node->x < columns && map[node->y][node->x] == 0)
	{
		return true;
	}
	return false;
}

bool isValid(bool** map, int rows, int columns, int row, int column)
{
	if (row >= 0 && row < rows && column >= 0 && column < columns && map[row][column] == 0)
	{
		return true;
	}
	return false;
}

void printPath(Node* node)
{
	Stack stack;
	Node* current = node;
	while (current)
	{
		push(stack, current);
		current = current->parent;
	}
	while (!isEmpty(stack))
	{
		StackElement* temp = pop(stack);
		printf("(%d , %d)->", temp->node->x, temp->node->y);
		deleteElement(*temp);
	}
	printf("end\n");
	deleteStack(stack);
	return;
}