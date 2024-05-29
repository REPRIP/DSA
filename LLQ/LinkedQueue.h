#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int item = 0, Node* nxt = nullptr);
};
class LinkedQueue{
    private:
    int size;
    Node* front;
    Node* rear;
public:
    LinkedQueue(); //Constructor
    ~LinkedQueue(); //Destructor
    bool isEmpty(); //Returns true if queue is empty else returns false
    int len(); //Returns length of queue
    int getfront(); //Returns the first element if empty returns -1
    void enqueue(int item); //Enqueues the given item into the queue
    void dequeue(); //Dequeues an element
    friend ostream& operator<<(ostream& os,const LinkedQueue& Queue); //Overloading << operator
};