#include <iostream>

using namespace std;

class List {
private:
  int *data;
  int size;
  int capacity;

public:
  List(int val) {
    size = 0;
    capacity = val;
    data = new int[capacity];
  }

  ~List() { 
    delete data; 
  }

  int len(); //returns length of list
  void display(); //To display all elements in the list
  bool isempty(); //To check if list is empty
  void insert(int element, int index); //Insert at specified index
  void append(int value); //Append to end
  void append(int* values, int count = 1); //Append another list of of values to end
  void remove(int value); //Delete a value
  int pop(); //Delete element at end
  int get_index(int value); //Returns index of specified element or -1 if not found
  void resize(); //Increases size of underlying array
  void clear(); //Clears the list
  friend ostream& operator<<(ostream& os, const List& list); //Overloading << operator
};