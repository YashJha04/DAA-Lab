#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dijkstra(int V, vector<vector<pair<int, int>>> &graph, int source) {

    vector<int> distance(V, INT_MAX);
    vector<bool> visited(V, false);

    // Distance from source to itself is 0
    distance[source] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = -1;

        // Find the unvisited vertex with minimum distance
        for (int i = 0; i < V; i++) {
            if (!visited[i] &&
                (u == -1 || distance[i] < distance[u])) {
                u = i;
            }
        }

        visited[u] = true;

        // Update distances of adjacent vertices
        for (auto edge : graph[u]) {

            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] &&
                distance[u] != INT_MAX &&
                distance[u] + weight < distance[v]) {

                distance[v] = distance[u] + weight;
            }
        }
    }

    // Display shortest distances
    cout << "\nShortest distances from source vertex "
         << source << ":\n";

    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " : ";

        if (distance[i] == INT_MAX)
            cout << "INF";
        else
            cout << distance[i];

        cout << endl;
    }
}

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> graph(V);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {

        int u, v, weight;
        cin >> u >> v >> weight;

        // Undirected graph
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(V, graph, source);

    return 0;
}