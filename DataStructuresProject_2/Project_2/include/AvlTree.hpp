#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "AvlNode.hpp"
#include "Stack.hpp"
#include <iostream>
#include <cmath>

using namespace std;

class AvlTree
{
private:

    AvlNode* SearchAndAdd(AvlNode*& subNode, const int& newItem);
    AvlNode* SwapWithLeftChild(AvlNode* subNode);
    AvlNode* SwapWithRightChild(AvlNode* subNode);
    bool SearchAndDelete(AvlNode*& subNode, const int& data);
    bool DeleteNode(AvlNode*& subNode);
    void postorder(AvlNode* subNode);
    void leaf(AvlNode* subNode);
    int Height(AvlNode* subNode);
    void PrintLevel(AvlNode* subNode, int level);
    bool Search(AvlNode* subNode, const int& item);

public:
    AvlNode* root;
    Stack* stack;
    int totalExceptLeafs;
    int ascii;
    int avlNo;

    AvlTree()
    {
        avlNo = 0;
        root = NULL;
        totalExceptLeafs = 0;
        ascii = 0;
        stack = new Stack();
    }

    ~AvlTree()
    {
        Clear();
    }

    bool isEmpty() const;
    void Add(const int& newItem);
    void Delete(const int& data);
    void postorder();
    void levelorder();
    void leaf();
    bool Search(const int& item);
    void Clear();
    int Height();
};

#endif // !AVLTREE_HPP