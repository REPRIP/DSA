#include<iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    cout << "List after appending: " << list;
    list.insert(5);
    cout << "List after insertion: " << list;
    if (list.isEmpty())
        cout << "List is empty\n";
    else
        cout << "List is not empty\n";
    cout << "Length of list: " << list.len() << endl;
    cout << "Head value of list: " << list.gethead() << endl;
    if (list.search(20))
        cout << "Value 20 found in the list\n";
    else
        cout << "Value 20 not found in the list\n";
    list.Delete(20);
    cout << "List after deletion: " << list;
    return 0;
}