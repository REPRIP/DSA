#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int item = 0, Node* nxt = nullptr);
};

class LinkedList{
public:
    int size;
    Node* head;
    Node* end;

    LinkedList(); //Constructor
    ~LinkedList(); //Destructor
    bool isEmpty(); //Returns true if Linked List is empty else returns false
    int len(); //Returns length of Linked List
    int gethead(); //Returns the first element(head), if empty returns -1
    bool search(int item); //Search for an item
    void insert(int item,Node* pos = nullptr); //Inserts at the specified pos, by default inserts at head
    void append(int item); //Appends at end of list
    void Delete(int item); //Deletes the given element
    void print();
    
};