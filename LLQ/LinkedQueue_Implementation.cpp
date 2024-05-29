#include<iostream>
#include "LinkedQueue.h"
using namespace std;

Node::Node(int item, Node *nxt)
{
    data = item;
    next = nxt;
}

LinkedQueue::LinkedQueue()
{
    front = nullptr;
    rear = nullptr;
    size = 0;
}

LinkedQueue::~LinkedQueue()
{
    Node *current = front;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

bool LinkedQueue::isEmpty()
{
    return size == 0;
}

int LinkedQueue::len()
{
    return this->size;
}

int LinkedQueue::getfront()
{
    if (front)
        return front->data;
    return -1;
}

void LinkedQueue::enqueue(int item){
    if (size == 0){
        front = rear = new Node(item);
    }
    else{
        Node* temp = new Node(item,nullptr);
        rear->next = temp;
        rear = temp;
    }
    size++;
}

void LinkedQueue::dequeue(){
    if (size == 0){
        cout << "Queue is empty cannot dequeue";
        return;
    }
    int item = front->data;
    Node* temp = front;
    front = front->next;
    delete(temp);
}

ostream &operator<<(ostream &os, const LinkedQueue &Queue)
{
    Node *temp = Queue.front;
    while (temp != nullptr)
    {
        os << temp->data << " ";
        temp = temp->next;
    }
    os << endl;
    return os;
}