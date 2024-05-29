#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int item = 0, Node* nxt = nullptr);
};
class LinkedStack{
    private:
    int size;
    Node* top;
public:
    LinkedStack(); //Constructor
    ~LinkedStack(); //Destructor
    bool isEmpty(); //Returns true if queue is empty else returns false
    int len(); //Returns length of queue
    int gettop(); //Returns the top of if empty returns -1
    void push(int item); //Pushes element into the stack
    int pop(); //Pops an element from the stack
    friend ostream& operator<<(ostream& os,const LinkedStack& Stack); //Operator Overloading
};