#include <iostream>
#include "BSTree.h"
using namespace std;

template <typename T>
BNode<T>::BNode(){
    ele = 0;
    Lchild = Rchild = nullptr;
}

template <typename T>
BNode<T>::BNode(T item){
        ele = item;
        Lchild = Rchild = nullptr;
}

template <typename T>
BST<T>::BST() {
    root = new BNode<T>();
    root->ele = T();
    root->Lchild = nullptr;
    root->Rchild = nullptr;
    size = 0;
}

template <typename T>
BST<T>::~BST() {
    delete root;
}

template <typename T>
void BST<T>::add_left(BNode<T>* pos, T item) {
    if (pos->Lchild == nullptr) {
        BNode<T>* t = new BNode<T>();
        t->ele = item;
        t->Lchild = nullptr;
        t->Rchild = nullptr;
        pos->Lchild = t;
    }
}

template <typename T>
void BST<T>::add_right(BNode<T>* pos, T item) {
    if (pos->Rchild == nullptr) {
        BNode<T>* t = new BNode<T>();
        t->ele = item;
        t->Lchild = nullptr;
        t->Rchild = nullptr;
        pos->Rchild = t;
    }
}

template <typename T>
void BST<T>::insert(T item) {
    if (root->ele == T()) {
        root->ele = item;
    } else {
        BNode<T>* temp = root;
        while (true) {
            if (item < temp->ele) {
                if (temp->Lchild == nullptr) {
                    add_left(temp, item);
                    break;
                } else {
                    temp = temp->Lchild;
                }
            } else {
                if (temp->Rchild == nullptr) {
                    add_right(temp, item);
                    break;
                } else {
                    temp = temp->Rchild;
                }
            }
        }
    }
    size++;
}

template <typename T>
void BST<T>::del(T item) {
    delHelper(root, item);
}

template <typename T>
BNode<T>* BST<T>::delHelper(BNode<T>* node, T item) {
    if(node == NULL)
        return node;

    if(item < node->ele)
        node->Lchild = delHelper(node->Lchild, item);
    else if(item > node->ele)
        node->Rchild = delHelper(node->Rchild, item);
    else {
        if(node->Lchild == NULL) {
            BNode<T>* temp = node->Rchild;
            delete node;
            return temp;
        }
        else if(node->Rchild == NULL) {
            BNode<T>* temp = node->Lchild;
            delete node;
            return temp;
        }

        BNode<T>* temp = findmin(node->Rchild);
        node->ele = temp->ele;
        node->Rchild = delHelper(node->Rchild, temp->ele);
    }
    return node;
}

template <typename T>
void BST<T>::del(BNode<T>* node) {
    delHelper(root, node->ele);
}

template <typename T>
void BST<T>::preorder() {
    if (isEmpty()) {
        cout << "Tree is Empty";
        return;
    }
    preorder_helper(root);
}

template <typename T>
void BST<T>::preorder_helper(BNode<T>* node) {
    if (node == nullptr) return;
    cout << node->ele << " ";
    preorder_helper(node->Lchild);
    preorder_helper(node->Rchild);
}

template <typename T>
void BST<T>::postorder() {
    if (isEmpty()) {
        cout << "Tree is Empty";
        return;
    }
    postorder_helper(root);
}

template <typename T>
void BST<T>::postorder_helper(BNode<T>* node) {
    if (node == nullptr) return;
    postorder_helper(node->Lchild);
    postorder_helper(node->Rchild);
    cout << node->ele << " ";
}

template <typename T>
void BST<T>::inorder() {
    if (isEmpty()) {
        cout << "Tree is Empty";
        return;
    }
    inorder_helper(root);
}

template <typename T>
void BST<T>::inorder_helper(BNode<T>* node) {
    if (node == nullptr) return;
    inorder_helper(node->Lchild);
    cout << node->ele << " ";
    inorder_helper(node->Rchild);
}

template <typename T>
bool BST<T>::search(T item, BNode<T>* pos) {
    if (isEmpty()) {
        cout << "Tree is Empty";
        return false;
    }
    if (pos == nullptr) {
        pos = root;
    }
    if (pos->Lchild == nullptr && pos->Rchild == nullptr) {
        return pos->ele == item;
    } else if (item < pos->ele) {
        if (pos->Lchild != nullptr) {
            return search(item, pos->Lchild);
        }
    } else {
        if (pos->Rchild != nullptr) {
            return search(item, pos->Rchild);
        }
    }
    return pos->ele == item;
}

template <typename T>
BNode<T>* BST<T>::findmin(BNode<T>* pos) {
    if (isEmpty()) {
        cout << "Tree is Empty";
        return nullptr;
    }
    if (pos == nullptr) {
        pos = root;
    }
    if (pos->Lchild == nullptr) {
        return pos;
    } else {
        return findmin(pos->Lchild);
    }
}

template <typename T>
BNode<T>* BST<T>::findmax(BNode<T>* pos) {
    if (isEmpty()) {
        cout << "Tree is Empty";
        return nullptr;
    }
    if (pos == nullptr) {
        pos = root;
    }
    if (pos->Rchild == nullptr) {
        return pos;
    } else {
        return findmax(pos->Rchild);
    }
}

template <typename T>
bool BST<T>::isEmpty() {
    return root->ele == T();
}

template class BST<int>;