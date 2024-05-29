#include<iostream>
#include "LinkedQueue.h"
using namespace std;
int main()
{
    LinkedQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    cout << "Front element of the queue: " << queue.getfront() << endl;
    queue.dequeue();
    cout << "Queue after dequeue: " << queue;
    if (queue.isEmpty())
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";
    cout << "Length of queue: " << queue.len() << endl;
    return 0;
}