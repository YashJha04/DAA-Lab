#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Structure for an edge
struct Edge {
    int u, v, weight;
};

// Compare edges according to weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// ---------------- KRUSKAL'S ALGORITHM ----------------

// Find parent of a vertex
int findParent(int parent[], int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}

// Union two sets
void unionSet(int parent[], int rank[], int u, int v) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u != v) {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

void kruskal(int V, vector<Edge> edges) {

    sort(edges.begin(), edges.end(), compare);

    int parent[V];
    int rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalWeight = 0;
    int count = 0;

    cout << "\nKruskal's MST:\n";

    for (Edge e : edges) {
        int u = findParent(parent, e.u);
        int v = findParent(parent, e.v);

        // Add edge if it does not form a cycle
        if (u != v) {
            cout << e.u << " - " << e.v
                 << " : " << e.weight << endl;

            totalWeight += e.weight;
            unionSet(parent, rank, u, v);
            count++;

            if (count == V - 1)
                break;
        }
    }

    cout << "Total weight = " << totalWeight << endl;
}

// ---------------- PRIM'S ALGORITHM ----------------

void prim(int V, vector<vector<pair<int, int>>> graph) {

    vector<int> key(V, INT_MAX);
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;

    for (int i = 0; i < V - 1; i++) {

        int u = -1;

        // Find vertex with minimum key
        for (int j = 0; j < V; j++) {
            if (!visited[j] && (u == -1 || key[j] < key[u]))
                u = j;
        }

        visited[u] = true;

        // Update adjacent vertices
        for (auto edge : graph[u]) {

            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;

    cout << "\nPrim's MST:\n";

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << " : " << key[i] << endl;

        totalWeight += key[i];
    }

    cout << "Total weight = " << totalWeight << endl;
}

// ---------------- MAIN FUNCTION ----------------

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges;
    vector<vector<pair<int, int>>> graph(V);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {

        int u, v, weight;
        cin >> u >> v >> weight;

        edges.push_back({u, v, weight});

        // Undirected graph
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    prim(V, graph);
    kruskal(V, edges);

    return 0;
}