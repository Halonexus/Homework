#pragma once

struct Node
{
	int number = 0;
	int g = 0;
	int h = 0;
	int f = 0;
	Node* parent = nullptr;
};

bool aStar(Node* start, Node* end, bool** map, int size);