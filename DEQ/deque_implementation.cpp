#include<iostream>
#include "deque.h"
using namespace std;

void Deque::insertfront(char item) {
    if (isFull()) {
        cout << "Queue is Full";
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        if (front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }
    }
    Data[front] = item;
    size++;
}
void Deque::insertrear(char item){
    if (isFull()) {
        cout << "Queue is Full";
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == capacity - 1) {
        rear = 0;
    } else {
        rear++;
    }
    Data[rear] = item;
    size++;
}
void Deque::deletefront(){
    if (isEmpty()) {
        cout << "Queue is Empty";
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        if (front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }
    }
    size--;
}
void Deque::deleterear(){
    if (isEmpty()) {
        cout << "Queue is Empty";
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = capacity - 1;
    } else {
        rear--;
    }
    size--;
}
bool Deque::isEmpty(){
    return (front == -1);
}
bool Deque::isFull(){
    return ((rear + 1) % capacity == front);
}
char Deque::getFront(){
    if (isEmpty()) {
        cout << "Queue is Empty";
        return '\0'; 
    }
    return Data[front];
}
char Deque::getRear(){
    if (isEmpty()) {
        cout << "Queue is Empty";
        return '\0';
    }
    return Data[rear];
}
int Deque::Size(){
    return size;
}
