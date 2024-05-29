#include<stdio.h>
#include "List.h"
using namespace std;
 int main(){
    int n,j,ele;

    cout << "Enter the number of elements in the List" << endl;
    cin >> n;
    List l(n);
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n;i++){
        cin >> j;
        l.append(j);
    }
    cout << "List: " << l;

    int arr[2] = {1,2}; 
    l.append(arr,2); //Appending array at end
    cout << "list after appending [1,2] at end : " << l;

    cout << "Inserting 8 at position 3: "; 
    l.insert(8,3);
    cout << l;

    l.pop();
    cout << "List after popping: " << l;

    cout << "Enter element to search: ";
    cin >> ele;
     
    cout << l.get_index(ele) << endl;
    cout << "Length is: " << l.len() << endl;
    l.clear();
    return 0;
 }