#include <iostream>
#include "List.h"
using namespace std;

int List::len() { 
    return size; 
  }

  void List::display() {
    for (int i = 0; i < size; i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  }

  bool List::isempty() {
    if (size == 0) {
      return true;
    } else {
      return false;
    }
  }

  void List::insert(int element, int index) {
    if (index < 0 || index > size) {
      cout << "Invalid index" << endl;
    } else {
      if (size == capacity) {
        List::resize();
      }
      for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
      }
      data[index] = element;
      size++;
    }
  }

  void List::append(int value) {
    if (size == capacity) {
      List::resize();
    }
    data[size] = value;
    size++;
  }

  void List::append(int* values,int count) {
    if (size + count > capacity) {
      List::resize();
    }
    for (int i = 0; i < count; i++) {
        data[size + i] = values[i];
    }
    size += count;
  }

  void List::remove(int value) {
    for (int i = 0; i < size; i++) {
      if (data[i] == value) {
        for (int j = i; j < size; j++) {
          data[j] = data[j + 1];
        }
        size --;
        break;
      }
    }
  }

  int List::pop() {
    if (isempty()) {
      cout << "List is empty" << endl;
      return 0;
    } else {
      int last = data[size - 1];
      size--;
      return last;
    }
  }

  int List::get_index(int value) {
    for (int i = 0; i < size; i++) {
      if (data[i] == value) {
        return i;
      }
    }
    return -1;
  }

  void List::resize(){
    capacity = capacity * 2;
    int *temp;
    temp = new int[capacity];
    for (int i = 0; i < size; i++) {
      temp[i] = data[i];
    }
    delete[] data;
    data = temp;
  }

  void List::clear() { 
    size = 0;
    free;
  }

  ostream& operator<<(ostream& os, const List& list){
    for (int i = 0; i < list.size; i++) {
      os << list.data[i] << " ";
    }
    os << endl;
  }