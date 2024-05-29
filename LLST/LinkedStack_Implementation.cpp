#include<iostream>
#include "LinkedStack.h"
using namespace std;

Node::Node(int item, Node *nxt)
{
    data = item;
    next = nxt;
}

LinkedStack::LinkedStack()
{
    top = nullptr;
    size = 0;
}

LinkedStack::~LinkedStack()
{
    Node *current = top;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

bool LinkedStack::isEmpty()
{
    return size == 0;
}

int LinkedStack::len()
{
    return this->size;
}

int LinkedStack::gettop()
{
    if (top && top->next)
        return top->data;
    return -1;
}

void LinkedStack::push(int item)
{
    top = new Node(item, top);
    size++;
}

int LinkedStack::pop()
{
    if (size == 0)
        return 0;
    Node *temp = top;
    int item = top->data;
    top = top->next;
    delete temp;
    size--;
    return item;
}

ostream &operator<<(ostream &os, const LinkedStack &Stack)
{
    Node *temp = Stack.top;
    while (temp != nullptr)
    {
        os << temp->data << " ";
        temp = temp->next;
    }
    os << endl;
    return os;
}
