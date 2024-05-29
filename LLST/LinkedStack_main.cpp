#include<iostream>
#include "LinkedStack.h"
using namespace std;
int main()
{
    LinkedStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element of the stack: " << stack.gettop() << endl;
    stack.pop();
    cout << "Stack after popping: " << stack;
    if (stack.isEmpty())
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";
    cout << "Length of stack: " << stack.len() << endl;
    return 0;
}