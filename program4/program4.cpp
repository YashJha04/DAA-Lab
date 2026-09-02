#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbour : graph[node]) {
        if (!visited[neighbour]) {
            DFS(neighbour, graph, visited);
        }
    }
}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V);

    cout << "Enter the edges:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(V, false);

    int components = 0;

    cout << "\nConnected Components:\n";

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;

            cout << "Component " << components << ": ";
            DFS(i, graph, visited);
            cout << endl;
        }
    }

    cout << "\nTotal Connected Components = " << components << endl;

    return 0;
}