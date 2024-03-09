#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

class Stack
{
private:
    int* items;
    int topOfStack;
    int fullStack;
    int capacity;
    void reserve(int newCapacity);



public:

    Stack();
    ~Stack();
    void stackReload();
    bool isEmpty();
    void clear();
    void push(const int& item);
    const int& top();
    void pop();
};

#endif