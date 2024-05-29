#include<iostream>
#include "Tree.h"

BNode::BNode(){
    ele = 0;
    Lchild = Rchild = nullptr;
}

BNode::BNode(int item){
        ele = item;
        Lchild = Rchild = nullptr;
}

BST::BST(){
    root = new BNode();
    root->ele = 0;
    root->Lchild = nullptr;
    root->Rchild = nullptr;
    size = 0;
}

BST::~BST(){
    delete root;
}

void BST::add_left(BNode* pos,int item){
    if (pos->Lchild == nullptr){
        BNode* t = new BNode();
        t->ele = item;
        t->Lchild = nullptr;
        t->Rchild = nullptr;
        pos->Lchild = t;
    }
}

void BST::add_right(BNode* pos,int item){
    if (pos->Rchild == nullptr){
        BNode* t = new BNode();
        t->ele = item;
        t->Lchild = nullptr;
        t->Rchild = nullptr;
        pos->Rchild = t;
    }
}

void BST::insert(int item){
    if (root->ele == 0){
        root->ele = item;
    }
    else{
        BNode* temp = root;
        while(true){
            if(item < temp->ele){
                if(temp->Lchild == nullptr){
                    add_left(temp, item);
                    break;
                }
                else{
                    temp = temp->Lchild;
                }
            }
            else{
                if(temp->Rchild == nullptr){
                    add_right(temp, item);
                    break;
                }
                else{
                    temp = temp->Rchild;
                }
            }
        }
    }
    size++;
}

void BST::del(int item){
    
}
void BST::del(BNode *node){

}
void BST::preorder(){
    if (isEmpty()){
        cout << "Tree is Empty";
        return;
    }
    preorder_helper(root);
}

void BST::preorder_helper(BNode *node){
    if(node == nullptr) return;
    cout << node->ele << " ";
    preorder_helper(node->Lchild);
    preorder_helper(node->Rchild);
}

void BST::postorder(){
    if (isEmpty()){
        cout << "Tree is Empty";
        return;
    }
    postorder_helper(root);
}

void BST::postorder_helper(BNode *node){
    if(node == nullptr) return;
    postorder_helper(node->Lchild);
    postorder_helper(node->Rchild);
    cout << node->ele << " ";
}

void BST::inorder(){
    if (isEmpty()){
        cout << "Tree is Empty";
        return;
    }
    inorder_helper(root);
}

void BST::inorder_helper(BNode *node){
    if(node == nullptr) return;
    inorder_helper(node->Lchild);
    cout << node->ele << " ";
    inorder_helper(node->Rchild);
}

bool BST::search(int item,BNode* pos){
    if (isEmpty()){
        cout << "Tree is Empty";
        return false;
    }
    if(pos == nullptr){
        pos = root;
    }
    if(pos->Lchild == nullptr && pos->Rchild == nullptr){
        return pos->ele == item;//return pos
    }
    else if(item < pos->ele){
        if(pos->Lchild != nullptr){
            return search(item, pos->Lchild);
        }
    }
    else{
        if(pos->Rchild != nullptr){
            return search(item, pos->Rchild);
        }
    }
    return pos->ele == item;
}

BNode *BST::findmin(BNode* pos){
    if (isEmpty()){
        cout << "Tree is Empty";
        return nullptr;
    }
    if(pos == nullptr){
        pos = root;
    }
    if (pos->Lchild == nullptr){
        return pos;
    }
    else{
        return findmin(pos->Lchild);
    }
}

BNode *BST::findmax(BNode* pos){
    if (isEmpty()){
        cout << "Tree is Empty";
        return nullptr;
    }
    if(pos == nullptr){
        pos = root;
    }
    if (pos->Rchild == nullptr){
        return pos;
    }
    else{
        return findmax(pos->Rchild);
    }
}

bool BST::isEmpty(){
    return root->ele == 0;
}