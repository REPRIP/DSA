//@Author: Vivesh G
#include<iostream>
using namespace std;

//Adjacency Matrix directed Graph
class Graph{
public:
    int** data;
    int n; //No of nodes
    int m; //No of edges
    Graph(int a,int b);
    ~Graph();
    void insert(int x, int y);
    void display();
    void topologicalsort();
};

Graph::Graph(int a,int b){
    n = a;
    m = b;
    data = new int*[n+1];
    for (int i = 0; i < n+1; i++) {
        data[i] = new int[n+1];
    }
    for(int i = 0;i < n+1;i++){
        for(int j = 0;j < n+1;j++){
            data[i][j] = 0;
        }}   
}

Graph::~Graph()
{
    for (int i = 0; i < n+1; i++) {
        delete[] data[i];
    }
    delete[] data;
}

void Graph::insert(int x, int y){
    data[x][y] = 1; 
    //data[y][x] = 1; Include this for undirected graph
}

void Graph::display(){
    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < n+1;j++){
            cout << data[i][j] << "\t";
        }
        cout << endl;
    }
}

void Graph::topologicalsort() {
    int* in_degree = new int[n + 1]();
    int* order = new int[n + 1];
    int index = 0;

    // Calculate in-degree of each node
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (data[j][i] == 1) {
                in_degree[i]++;
            }
        }
    }

    // Find all nodes with zero in-degree
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            order[index++] = i;
        }
    }

    int processed = 0;
    while (processed < index) {
        int u = order[processed++];
        for (int v = 1; v <= n; v++) {
            if (data[u][v] == 1) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    order[index++] = v;
                }
            }
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


int main(){
Graph g(5,6);
g.insert(1,2);
g.insert(1,3);
g.insert(2,4);
g.insert(3,4);
g.insert(3,5);
g.insert(4,5);
g.display();
g.topologicalsort();
return 0;
}