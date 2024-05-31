#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* Lchild;
    Node* Rchild;
    int height;
    Node(int val) : data(val), Lchild(nullptr), Rchild(nullptr), height(1) {}
};

class AVL {
public:
    Node* root;
    AVL() : root(nullptr) {}
    ~AVL() { deleteTree(root); }

    Node* insert(int elem, Node* node);
    Node* leftrotate(Node* pos);
    Node* rightrotate(Node* pos);
    int height(Node* node);
    int balance(Node* pos);
    void preorder(Node* node);
    int max(int a, int b);
    void deleteTree(Node* node);
    void insert(int elem) { root = insert(elem, root); }
    void preorder() { preorder(root); }
    Node* deleteNode(int elem, Node* node);
    void deleteNode(int elem);
    Node* minValueNode(Node* node);
};

int AVL::max(int a, int b) {
    return (a > b) ? a : b;
}

int AVL::height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

Node* AVL::leftrotate(Node* pos) {
    Node* x = pos->Rchild;
    Node* temp = x->Lchild;

    x->Lchild = pos;
    pos->Rchild = temp;

    pos->height = max(height(pos->Lchild), height(pos->Rchild)) + 1;
    x->height = max(height(x->Lchild), height(x->Rchild)) + 1;

    return x;
}

Node* AVL::rightrotate(Node* pos) {
    Node* x = pos->Lchild;
    Node* temp = x->Rchild;

    x->Rchild = pos;
    pos->Lchild = temp;

    pos->height = max(height(pos->Lchild), height(pos->Rchild)) + 1;
    x->height = max(height(x->Lchild), height(x->Rchild)) + 1;

    return x;
}

int AVL::balance(Node* pos) {
    if (pos == nullptr)
        return 0;
    return height(pos->Lchild) - height(pos->Rchild);
}

Node* AVL::insert(int elem, Node* node) {
    if (node == nullptr)
        return new Node(elem);

    if (elem < node->data) {
        node->Lchild = insert(elem, node->Lchild);
    } else if (elem > node->data) {
        node->Rchild = insert(elem, node->Rchild);
    } else {
        return node;
    }

    node->height = 1 + max(height(node->Lchild), height(node->Rchild));
    
    int Balance = balance(node);

    if (Balance > 1 && elem < node->Lchild->data) {
        return rightrotate(node);
    }
    if (Balance < -1 && elem > node->Rchild->data) {
        return leftrotate(node);
    }
    if (Balance > 1 && elem > node->Lchild->data) {
        node->Lchild = leftrotate(node->Lchild);
        return rightrotate(node);
    }
    if (Balance < -1 && elem < node->Rchild->data) {
        node->Rchild = rightrotate(node->Rchild);
        return leftrotate(node);
    }

    return node;
}

void AVL::preorder(Node* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preorder(node->Lchild);
        preorder(node->Rchild);
    }
}

void AVL::deleteTree(Node* node) {
    if (node != nullptr) {
        deleteTree(node->Lchild);
        deleteTree(node->Rchild);
        delete node;
    }
}

Node* AVL::minValueNode(Node* node) {
    Node* current = node;
    while (current->Lchild != nullptr)
        current = current->Lchild;
    return current;
}

void AVL::deleteNode(int elem) { root = deleteNode(elem, root); }

Node* AVL::deleteNode(int elem, Node* root) {
    if (root == nullptr)
        return root;

    if (elem < root->data)
        root->Lchild = deleteNode(elem, root->Lchild);
    else if (elem > root->data)
        root->Rchild = deleteNode(elem, root->Rchild);
    else {
        if ((root->Lchild == nullptr) || (root->Rchild == nullptr)) {
            Node* temp = root->Lchild ? root->Lchild : root->Rchild;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->Rchild);
            root->data = temp->data;
            root->Rchild = deleteNode(temp->data, root->Rchild);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->Lchild), height(root->Rchild));

    int Balance = balance(root);

    if (Balance > 1 && balance(root->Lchild) >= 0)
        return rightrotate(root);
    if (Balance > 1 && balance(root->Lchild) < 0) {
        root->Lchild = leftrotate(root->Lchild);
        return rightrotate(root);
    }
    if (Balance < -1 && balance(root->Rchild) <= 0)
        return leftrotate(root);
    if (Balance < -1 && balance(root->Rchild) > 0) {
        root->Rchild = rightrotate(root->Rchild);
        return leftrotate(root);
    }

    return root;
}


int main() {
    AVL avltree;
    avltree.insert(10);
    avltree.insert(20);
    avltree.insert(30);
    avltree.insert(40);
    avltree.insert(50);
    avltree.insert(25);
    avltree.preorder();
    return 0;
}
