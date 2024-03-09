/*
 * Node.cpp
 * Liste yapisinin Node adli dugumu
 * 1.Ogretim B gurubu
 * 2. Odev
 * 08.11.2023
 * Uğur Can Çelik, ugur.celik16@ogr.sakarya.edu.tr
 */
#include "Node.hpp"

Node::Node(AvlTree* data)
{
    this->data = data;
    next = NULL;
}

Node::~Node()
{
    nodeClear();
}

void Node::nodeClear()
{
    delete this->data;
}

