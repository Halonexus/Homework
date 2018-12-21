#include <cstdio>
#include "AStar.h"
#include "AVLTree.h"

bool aStar(Node* start, Node* end, bool** map, int size)
{
	AVLTree open, closed;
	addTreeElement(open, start);
	while (!isEmpty(open))
	{
		Node* q = getMinElement(open.root)->node;
		deleteTreeElement(open, q);
		for (int i = 0; i < size; i++)
		{
			if (map[q->number][i])
			{
				Node* child = new Node{ i, 0, 0, 0, q };
				child->g = q->g + 1;
				child->f = child->g;
				if (child->number == end->number)
				{
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
		addTreeElement(closed, q);
	}
	deleteTree(open);
	deleteTree(closed);
	return false;
}