#include<iostream>
#include "deque.h"
using namespace std;
int main(){
Deque deq;
string s;
cout << "Enter the string: ";
cin >> s;
int i = 0;
int n = s.length();
while (i < n){
    deq.insertrear(s[i]);
    i++;
}
while(!deq.isEmpty()){
    if (deq.getFront() != deq.getRear()) {
            cout << "Not a palindrome";
            break;
    }
    deq.deletefront();
    if (!deq.isEmpty()) {
        deq.deleterear();
    }
}
if (deq.isEmpty())
    cout << "String is a palindrome" << endl;
return 0;
}