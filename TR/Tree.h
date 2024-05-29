#include<iostream>
using namespace std;

class BNode{
public:
    int ele;
    BNode* Lchild;
    BNode* Rchild;
    BNode* parent;
    BNode();
    BNode(int item);
};

class BST{
public:
    BNode* root;
    int size;
    BST();
    ~BST();
    void add_right(BNode* pos,int item);
    void add_left(BNode* pos,int item);
    void insert(int item);
    void del(int item);
    void del(BNode* node);
    //Traversal Functions
    void preorder();
    void preorder_helper(BNode* node);
    void postorder();
    void postorder_helper(BNode* node);
    void inorder();
    void inorder_helper(BNode* node);
    bool search(int item, BNode* pos = nullptr);
    BNode* findmin(BNode* pos = nullptr);
    BNode* findmax(BNode* pos = nullptr);
    bool isEmpty();
    BNode* find_pos();
    bool isLeaf();
    
};