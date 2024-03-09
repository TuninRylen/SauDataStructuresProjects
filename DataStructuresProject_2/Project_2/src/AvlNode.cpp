/*
 * AvlNode.cpp
 * AvlTree agacinin dugum yapisi
 * 1.Ogretim B gurubu
 * 2. Odev
 * 08.11.2023
 * Uğur Can Çelik, ugur.celik16@ogr.sakarya.edu.tr
 */
#include "AvlNode.hpp"

AvlNode::AvlNode(const int& data, AvlNode* left, AvlNode* right)
{
    this->data = data;
    this->left = left;
    this->right = right;
    height = 0;
}

AvlNode::~AvlNode()
{
}
