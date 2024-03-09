#ifndef NODE_HPP
#define NODE_HPP
#include "AvlTree.hpp"
#include <iostream>

class Node
{
public:
	Node(AvlTree* data);
	~Node();

	void nodeClear();

	AvlTree* data;
	Node* next;
};


#endif 