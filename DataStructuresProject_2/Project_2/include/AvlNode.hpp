#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>

class AvlNode
{
public:

    int data;
    int height;
    AvlNode* left;
    AvlNode* right;

    AvlNode(const int& data, AvlNode* left = NULL, AvlNode* right = NULL);
    ~AvlNode();
};



#endif