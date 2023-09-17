#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool dfs(int source, int parent, vector<bool> &visited, vector<int> adj[]) {
    visited[source] = true;
    for(int adjacentNode : adj[source]) {
        if(visited[adjacentNode] == false) {
            if(dfs(adjacentNode, source, visited, adj) == true) {
                return true;
            }
        }
        else
        if(adjacentNode != parent) {
            return true;
        }

    }
    return false;
}

bool hasCycle(int nodes, vector<int> adj[]) {
    vector<bool> visited(nodes, false);
    for(int i = 0; i < nodes; i++) {
        if(visited[i] == false && dfs(i, -1, visited, adj) == true) {
            return true;
        }
    }
    return false;
}

int main () {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> adj[nodes];

    for(int i = 0 ; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    hasCycle(nodes, adj) ? cout << "YES\n" : cout << "NO\n";
    return 0;
}