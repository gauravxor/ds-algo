#include <iostream>
#include <vector>

using namespace std;

bool dfs(int source, vector<int> &vis, vector<int> &path, vector<int> adj[]) {
    vis[source] = true;
    path[source] = true;
    for (int node : adj[source]) {
        if (vis[node] == false) {
            bool result = dfs(node, vis, path, adj);
            if (result == true) {
                return true;
            }
        }
        else if (path[node] == true) {
            return true;
        }
    }
    path[source] = false;
    return false;
}

bool checkCycle(int nodes, vector<int> adj[]) {
    vector<int> vis(nodes, false);
    vector<int> path(nodes, false);

    for (int i = 0; i < nodes; i++) {
        if (vis[i] == false) {
            bool result = dfs(i, vis, path, adj);
            if (result == true) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> adj[nodes];
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    bool result = checkCycle(nodes, adj);
    (result) ? cout << "YES\n" : cout << "NO\n";
    return 0;
}