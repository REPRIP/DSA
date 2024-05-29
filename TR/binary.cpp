#include<iostream>
using namespace std;

class BNode{
public:
    int ele;
    BNode* Lchild;
    BNode* Rchild;
    BNode* parent;
    BNode(){
        ele = 0;
        Lchild = Rchild = nullptr;
    }
    BNode(int item){
        ele = item;
        Lchild = Rchild = nullptr;
    }
};

class Btree{
private:
    BNode* root;
    int size;
public:
    Btree();
    ~Btree();
    void add_right(BNode* pos,int item);
    void add_left(BNode* pos,int item);
    void insert(int item);
    void preorder();
    void preorder_helper(BNode* node);
    void postorder_helper(BNode* node);
    void postorder();
    void inorder();
    void inorder_helper(BNode* node);
    bool search(int item);
};


Btree::Btree(){
    root = new BNode();
    root->ele = 0;
    root->Lchild = nullptr;
    root->Rchild = nullptr;
    size = 0;
}

Btree::~Btree(){
    delete root;
}

void Btree::add_left(BNode* pos,int item){
    if (pos->Lchild == nullptr){
        BNode* t = new BNode();
        t->ele = item;
        t->Lchild = nullptr;
        t->Rchild = nullptr;
        pos->Lchild = t;
    }
}

void Btree::add_right(BNode* pos,int item){
    if (pos->Rchild == nullptr){
        BNode* t = new BNode();
        t->ele = item;
        t->Lchild = nullptr;
        t->Rchild = nullptr;
        pos->Rchild = t;
    }
}

void Btree::insert(int item){
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

bool Btree::search(int item){
    if (root->ele == 0){
        return false;
    }
    else{
        BNode* temp = root;
        while(true){
            if(item < temp->ele){
                if(temp->Lchild->ele == item){
                    return true;
                }
                else{
                    temp = temp->Lchild;
                }
            }
            else{
                if(temp->Rchild->ele == item){
                    return true;
                }
                else{
                    temp = temp->Rchild;
                }
            }
        }
    }
}


void Btree::preorder(){
    preorder_helper(root);
}

void Btree::preorder_helper(BNode* node){
    if(node == nullptr) return;
    cout << node->ele << " ";
    preorder_helper(node->Lchild);
    preorder_helper(node->Rchild);
}

void Btree::postorder(){
    postorder_helper(root);
}

void Btree::postorder_helper(BNode* node){
    if(node == nullptr) return;
    postorder_helper(node->Lchild);
    postorder_helper(node->Rchild);
    cout << node->ele << " ";
}

void Btree::inorder(){
    inorder_helper(root);
}

void Btree::inorder_helper(BNode* node){
    if(node == nullptr) return;
    inorder_helper(node->Lchild);
    cout << node->ele << " ";
    inorder_helper(node->Rchild);
}

int main(){
    Btree bint; 
    bint.insert(10);
    bint.insert(5);
    bint.insert(12);
    bint.insert(5);
    bint.insert(4);
    bint.insert(6);
    bint.insert(7);
    cout << "Preorder" <<endl;
    bint.preorder();
    cout << endl;
    cout << "Postorder" <<endl;
    bint.postorder();
    cout << endl;
    cout << "Inorder" <<endl;
    bint.inorder();
}