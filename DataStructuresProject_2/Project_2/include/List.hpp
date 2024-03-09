#ifndef LIST_HPP
#define LIST_HPP
#include "Node.hpp"
#include "AvlTree.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class List
{
public:
	List();
	~List();

	void add(AvlTree* data);
	void removeNode(Node* data);
	void printAscii();
	void compareAndRemove();
	void stacksReload();
	Node* biggerStackTop();
	Node* smallerStackTop();


	Node* head;

private:
	void fillFromTxt();
};

#endif 