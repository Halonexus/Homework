#pragma once

struct Node
{
	int y = 0;
	int x = 0;
	int g = 0;
	int h = 0;
	int f = 0;
	Node* parent = nullptr;
};

bool AStar(Node* start, Node* end, bool**, int, int);
int heuristic(Node* current, Node* end);
bool isValid(bool** map, int rows, int columns, int row, int column);
bool isValid(bool** map, int rows, int columns, Node* node);
void printPath(Node*);