/** Code to accept the number of nodes and edges, and generate an undirected graph from the inputs */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> adj[nodes];

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "The undirected graph is\n";
    for (int i = 0; i < nodes; i++) {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}