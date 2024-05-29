#include <iostream>
using namespace std;

template <typename T>
class BNode {
public:
    T ele;
    BNode* Lchild;
    BNode* Rchild;
    BNode();
    BNode(T item);
};

template <typename T>
class BST {
public:
    BNode<T>* root;
    int size;
    BST();
    ~BST();
    void add_left(BNode<T>* pos, T item);
    void add_right(BNode<T>* pos, T item);
    void insert(T item);
    void del(T item);
    void del(BNode<T>* node);
    BNode<T>* delHelper(BNode<T>* node, T item);
    void preorder();
    void preorder_helper(BNode<T>* node);
    void postorder();
    void postorder_helper(BNode<T>* node);
    void inorder();
    void inorder_helper(BNode<T>* node);
    bool search(T item, BNode<T>* pos = nullptr);
    BNode<T>* findmin(BNode<T>* pos = nullptr);
    BNode<T>* findmax(BNode<T>* pos = nullptr);
    bool isEmpty();
};

