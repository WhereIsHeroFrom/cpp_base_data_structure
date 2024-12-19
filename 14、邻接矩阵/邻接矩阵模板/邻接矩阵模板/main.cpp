#include <iostream>
using namespace std;

#define inf -1

class Graph {
private:
    int vertices;
    int** edges;

public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int u, int v, int w);
    void printGraph();
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    edges = new int* [vertices];
    for (int i = 0; i < vertices; i++) {
        edges[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            edges[i][j] = inf;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < vertices; i++) {
        delete[] edges[i];
    }
    delete[] edges;
}

void Graph::addEdge(int u, int v, int w) {
    edges[u][v] = w;
}

void Graph::printGraph() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices = 5;
    Graph graph(vertices);

    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 3, 7);
    graph.addEdge(3, 4, 9);
    graph.addEdge(4, 0, 4);
    graph.addEdge(4, 2, 5);

    cout << "邻接矩阵表示的图：" << endl;
    graph.printGraph();
    return 0;
}