//@Author: Vivesh G
#include<iostream>
#include "LinkedList_Implementation.cpp"
using namespace std;

// Adjacency List directed Graph
class Graph {
public:
    LinkedList* data;
    int n; // No of nodes
    int m; // No of edges
    Graph(int a, int b);
    ~Graph();
    void insert(int x, int y);
    void display();
    void topologicalsort(); //remove this for undirected graph
};

Graph::Graph(int a, int b) {
    n = a;
    m = b;
    data = new LinkedList[n + 1];
    for(int i = 0; i < n + 1; i++) {
        LinkedList temp;
        data[i] = temp;
    }
}

Graph::~Graph() {
    delete[] data;
}

void Graph::insert(int x, int y) {
    data[x].append(y);
    //data[y].append(x); Include this for undirected graph
}

void Graph::display() {
    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        data[i].print();
    }
}

void Graph::topologicalsort() { //remove this for undirected graph
    int* in_degree = new int[n + 1]();
    int* order = new int[n + 1];
    int index = 0;

    for (int i = 1; i <= n; i++) {
        Node* current = data[i].head;
        while (current != nullptr) {
            in_degree[current->data]++;
            current = current->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            order[index++] = i;
        }
    }

    int processed = 0;
    while (processed < index) {
        int u = order[processed++];
        Node* current = data[u].head;
        while (current != nullptr) {
            in_degree[current->data]--;
            if (in_degree[current->data] == 0) {
                order[index++] = current->data;
            }
            current = current->next;
        }
    }

    if (index != n) {
        cout << "Graph has a cycle, topological sort not possible" << endl;
    } else {
        for (int i = 0; i < index; i++) {
            cout << order[i] << " ";
        }
        cout << endl;
    }

    delete[] in_degree;
    delete[] order;
}


int main() {
    Graph g(5, 6);
    g.insert(1, 2);
    g.insert(1, 3);
    g.insert(2, 4);
    g.insert(3, 4);
    g.insert(3, 5);
    g.insert(4, 5);
    g.display();

    g.topologicalsort();
    return 0;
}
