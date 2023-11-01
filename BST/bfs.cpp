#include <iostream>
#include <queue>
using namespace std;

class Graph {
public:
    int vertices;
    int** adjMatrix;

    Graph(int V) {
        vertices = V;
        adjMatrix = new int*[V];
        for (int i = 0; i < V; i++) {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    void bfs(int startNode) {
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }

        queue<int> q;
        visited[startNode] = true;
        q.push(startNode);

        cout << "Breadth-First Traversal starting from node " << startNode << ": ";

        while (!q.empty()) {
            int current = q.front();
            cout << current << " ";
            q.pop();

            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        delete[] visited;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph graph(vertices);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        cout << "Enter edge " << i + 1 << " (source destination): ";
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    graph.bfs(startNode);
    cout << endl;

    return 0;
}
