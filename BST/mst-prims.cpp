#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<pair<int, int>> > adjacencyList;

    Graph(int V) {
        vertices = V;
        adjacencyList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjacencyList[u].push_back(make_pair(v, weight));
        adjacencyList[v].push_back(make_pair(u, weight)); // Undirected graph
    }
};

int minKey(vector<int> key, vector<bool>& mstSet) {
    int min = INT_MAX, minIndex = -1;

    for (int v = 0; v < key.size(); v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void primMST(Graph& graph) {
    int V = graph.vertices;
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0; // Start from the first vertex

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (pair<int, int> neighbor : graph.adjacencyList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!mstSet[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    cout << "Edge   Weight" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "   " << key[i] << endl;
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph graph(vertices);

    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cout << "Enter edge (u, v) and weight: ";
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    cout << "Minimum Spanning Tree using Prim's algorithm:" << endl;
    primMST(graph);

    return 0;
}
