#include<iostream>
#include "BSTree.h"
using namespace std;

int main(){
    BST<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    cout << "Preorder Traversal: ";
    tree.preorder();
    cout << endl;
    cout << "Inorder Traversal: ";
    tree.inorder();
    cout << endl;
    cout << "Postorder Traversal: ";
    tree.postorder();
    cout << endl;
    tree.del(tree.findmax());
    cout << "Preorder Traversal after deleting 5: ";
    tree.preorder();
    cout << endl;
    cout << "Maximum Element: " << tree.findmax()->ele << endl;
    cout << "Minimum Element: " << tree.findmin()->ele << endl;
    cout << tree.search(10) << endl;
    return 0;
}