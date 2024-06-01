#include <iostream>

class Stack{
private:
  char *data; //Array to store stack elements
  int top; //Pointer to top of stack
  int capacity; //Capacity of array

public:
  Stack(int capacity); //Stack constructor
  void push(char value); //Push element into top of stack
  char pop(); //Pop element from top of stack
  void retrieve_top(); //Return the top element
  bool isEmpty(); //Return true if stack is empty else returns false
  int size(); //Returns the size of stack
  ~Stack(); //Stack Destructor
};