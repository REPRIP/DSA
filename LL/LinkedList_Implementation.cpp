#include <iostream>
#include "LinkedList.h"
using namespace std;

Node::Node(int item, Node *nxt)
{
    data = item;
    next = nxt;
}
LinkedList::LinkedList()
{
    head = nullptr;
    size = 0;
}
LinkedList::~LinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
}
bool LinkedList::isEmpty()
{
    return size == 0;
}

int LinkedList::len()
{
    return this->size;
}

int LinkedList::gethead(){
    if(size == 0)
      return -1;
    return head->next->data;  
}

bool LinkedList::search(int value){
    Node* temp = head;
    while(temp != NULL){
      if(temp->data == value)
        return true;
      temp = temp->next;
    }
    return false;
}

void LinkedList::insert(int item, Node *pos)
{
    if (!pos)
    {
        pos = head;
    }
    Node *newNode = new Node(item);
    newNode->next = pos;
    head = newNode;
    if (pos == end)
    {
        end = end->next;
    }
    size++;
}
void LinkedList::append(int item)
{
    Node *newNode = new Node(item);
    if (head == nullptr)
    {
        head = newNode;
        end = newNode;
    }
    else
    {
        end->next = newNode;
        end = newNode;
    }
    size++;
}
void LinkedList::Delete(int item)
{
    if(size == 0)
      return;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL && temp->data != item){
      prev = temp;
      temp = temp->next;
    }
    if(temp == NULL)
      return;
    if(prev == NULL)
      head = head->next;
    else
      prev->next = temp->next;
    delete temp;
    size--;
}
ostream &operator<<(ostream &os, const LinkedList &List)
{
    Node *temp = List.head;
    while (temp != nullptr)
    {
        os << temp->data << " ";
        temp = temp->next;
    }
    os << endl;
    return os;
}