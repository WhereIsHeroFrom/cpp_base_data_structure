#include <iostream>
using namespace std;

class Graph {
private:
    struct EdgeNode {
        int vertex;
        int weight;
        EdgeNode* next;
    };

    struct VertexNode {
        int vertex;
        EdgeNode* firstEdge;
    };

    int vertices;
    VertexNode* nodes;

public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int u, int v, int w);
    void printGraph();
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    this->nodes = new VertexNode[vertices];
    for (int i = 0; i < vertices; i++) {
        nodes[i].vertex = i;
        nodes[i].firstEdge = NULL;
    }
}

Graph::~Graph() {
    for (int i = 0; i < vertices; i++) {
        EdgeNode* curr = nodes[i].firstEdge;
        while (curr) {
            EdgeNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    delete[] nodes;
}

void Graph::addEdge(int u, int v, int w) {
    EdgeNode* newNode = new EdgeNode;
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = nodes[u].firstEdge;
    nodes[u].firstEdge = newNode;
}

void Graph::printGraph() {
    for (int i = 0; i < vertices; i++) {
        EdgeNode* curr = nodes[i].firstEdge;
        cout << "Vertex " << i << ": ";
        while (curr) {
            cout << curr->vertex << " (" << curr->weight << ") ";
            curr = curr->next;
        }
        cout << endl;
    }
}

int main() {
    Graph graph(5);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 4);
    graph.addEdge(3, 4, 2);

    graph.printGraph();

    return 0;
}