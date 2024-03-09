/*
 * Stack.cpp
 * Stack yapisi
 * 1.Ogretim B gurubu
 * 2. Odev
 * 08.11.2023
 * Uğur Can Çelik, ugur.celik16@ogr.sakarya.edu.tr
 */
#include "Stack.hpp"

Stack::Stack()
{
    capacity = 60;
    topOfStack = -1;
    fullStack = topOfStack;
    items = new int[capacity];
}

Stack::~Stack()
{
    delete[] items;
}

void Stack::stackReload()
{
    topOfStack = fullStack;
}

void Stack::reserve(int newCapacity)
{
    int* tmp = new int[newCapacity];
    for (int index = 0; index < capacity; index++)
    {
        tmp[index] = items[index];
    }

    delete[] items;
    items = tmp;
    capacity = newCapacity;
}

bool Stack::isEmpty()
{
    return topOfStack == -1;
}

void Stack::clear()
{
    topOfStack = -1;
}

void Stack::push(const int& item)
{
    if (topOfStack + 1 == capacity)
    {
        reserve(2 * capacity);
    }

    topOfStack++;
    fullStack++;
    items[topOfStack] = item;
}

const int& Stack::top()
{
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        return items[topOfStack];
    } 
}

void Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        topOfStack--;
    }   
}
