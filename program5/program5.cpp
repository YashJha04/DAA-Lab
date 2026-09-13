#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int u, int parent, vector<vector<int>>& graph,
         vector<bool>& visited, vector<int>& discovery,
         vector<int>& low, vector<bool>& articulation) {

    static int timer = 0;

    visited[u] = true;
    discovery[u] = low[u] = ++timer;

    int children = 0;

    for (int v : graph[u]) {

        // Ignore the edge to parent
        if (v == parent)
            continue;

        if (!visited[v]) {
            children++;

            DFS(v, u, graph, visited, discovery, low, articulation);

            // Update low value
            low[u] = min(low[u], low[v]);

            // Check if u is an articulation point
            if (parent != -1 && low[v] >= discovery[u])
                articulation[u] = true;
        }
        else {
            // Back edge
            low[u] = min(low[u], discovery[v]);
        }
    }

    // Root is an articulation point if it has more than one child
    if (parent == -1 && children > 1)
        articulation[u] = true;
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
    vector<int> discovery(V, -1);
    vector<int> low(V, -1);
    vector<bool> articulation(V, false);

    // Run DFS for every unvisited vertex
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            DFS(i, -1, graph, visited, discovery, low, articulation);
    }

    cout << "\nCut Vertices (Articulation Points): ";

    bool found = false;

    for (int i = 0; i < V; i++) {
        if (articulation[i]) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << endl;

    return 0;
}