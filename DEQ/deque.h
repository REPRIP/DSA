#include<iostream>

class Deque{
private:
    char* Data; //Array to store elements 
    int size; //size of deque
    int front; //Pointer to front of deque
    int rear; //Pointer to rear of deque
    int capacity; //capacity of array
public:
    Deque(int cap = 256){
        front = -1;
        rear = 0;
        size = 0;
        capacity = cap;
        Data = new char[cap];
    } //Constructor
    ~Deque(){
        delete[] Data;
    } //Destructor
    void insertfront(char item); //Inserts item at front
    void insertrear(char item); //Inserts item at rear
    void deletefront(); //Deletes item at front
    void deleterear(); //Deletes item at rear
    bool isEmpty(); //Returns true if deque is empty else returns false
    bool isFull(); //Returns true if deque is full else returns false
    char getFront(); //Returns element at front
    char getRear(); //Returns element at rear
    int Size(); //Returns the size of deque
};