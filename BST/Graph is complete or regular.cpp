#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isCompleteGraph(const vector<vector<bool>>& adjacencyMatrix) {
    int V = adjacencyMatrix.size();
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (!adjacencyMatrix[i][j]) {
                return false; // If any pair of distinct vertices is not connected, it's not complete.
            }
        }
    }
    return true;
}

bool isRegularGraph(const vector<vector<bool>>& adjacencyMatrix) {
    int V = adjacencyMatrix.size();
    vector<int> degrees(V, 0);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adjacencyMatrix[i][j]) {
                degrees[i]++;
            }
        }
    }

    int firstDegree = degrees[0];
    for (int i = 1; i < V; i++) {
        if (degrees[i] != firstDegree) {
            return false; // If any vertex has a different degree, it's not regular.
        }
    }
    return true;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Initialize an adjacency matrix
    vector<vector<bool>> adjacencyMatrix(V, vector<bool>(V, false));

    cout << "Enter the number of edges: ";
    cin >> E;

    for (int i = 0; i < E; i++) {
        int u, v;
        cout << "Enter edge " << i + 1 << " (source destination): ";
        cin >> u >> v;
        adjacencyMatrix[u][v] = true;
        adjacencyMatrix[v][u] = true; // Since the graph is undirected
    }

    if (isCompleteGraph(adjacencyMatrix)) {
        cout << "The graph is complete." << endl;
    } else {
        cout << "The graph is not complete." << endl;
    }

    if (isRegularGraph(adjacencyMatrix)) {
        cout << "The graph is regular." << endl;
    } else {
        cout << "The graph is not regular." << endl;
    }

    return 0;
}
