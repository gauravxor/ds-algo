/** Code to find the DFS of a given graph. It handles different connected/disconnected components as well */
#include <iostream>
#include <vector>
using namespace std;

void getDfs(int source, vector<int> adj[], vector<bool> &visited, vector<int> &dfs) {
    visited[source] = true;
    dfs.push_back(source);
    for(int i : adj[source]) {
        if(visited[i] == false) {
            getDfs(i, adj, visited, dfs);
        }
    }
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

    vector<vector<int>> dfs;
    vector<bool> visited(nodes, false);
    for(int i = 0; i < nodes; i++) {
        if(visited[i] == false) {
            vector<int> temp;
            getDfs(i, adj, visited, temp);
            dfs.push_back(temp);
        }
    }

    cout << "The BFS is\n";
    for(auto list : dfs) {
        for(int i : list) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}