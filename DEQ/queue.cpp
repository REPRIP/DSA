#include<iostream>
using namespace std;

class Queue{
private:
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
public:
    Queue();
    ~Queue();
    void Enqueue(int elem);
    void Dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

Queue::Queue(){
    capacity = 256;
    data = new int[capacity];
    size = 0;
    front = rear = 0;
}
Queue::~Queue(){
    delete[] data;
}
void Queue::Enqueue(int elem){
    if (rear == capacity){
        cout << "Queue is full";
        return;
    }
    data[rear] = elem;
    rear++;
    size++;
}
void Queue::Dequeue(){
    if (front == rear){
        cout << "Queue is empty";
        return;
    }
    front++;
    size--;
}
bool Queue::isEmpty(){
    return front == rear;
}
bool Queue::isFull(){
    return rear == capacity;
}
void Queue::display(){
    for(int i = front;i < rear;i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

int main(){
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Enqueue(60);
    Q.display();
    Q.Dequeue();
    Q.display();

}