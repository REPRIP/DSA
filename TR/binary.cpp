#include<iostream>
#include "Tree_imp.cpp"
using namespace std;



int main(){
    BST bint; 
    bint.insert(10);
    bint.insert(5);
    bint.insert(12);
    bint.insert(5);
    bint.insert(4);
    bint.insert(6);
    bint.insert(7);
    bint.del(7);
    cout << "Preorder" <<endl;
    bint.preorder();
    cout << endl;
    cout << "Postorder" <<endl;
    bint.postorder();
    cout << endl;
    cout << "Inorder" <<endl;
    bint.inorder();
}