#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack(int capacity = 32) {
    this->capacity = capacity;
    data = new char[capacity];
    top = -1;
  }

void Stack::push(char value)
{
    if (top == capacity - 1)
    {
        return;
    }
    data[++top] = value;
}

char Stack::pop()
{
    if (top == -1)
    {
        return 0;
    }
    return data[top--];
}

void Stack::retrieve_top()
{
    cout << data[top] << endl;
    return;
}

bool Stack::isEmpty()
{
    return top == -1; 
}

int Stack::size()
{
    return top + 1; 
}

 Stack::~Stack() { delete[] data; }