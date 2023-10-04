#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool checkBipartite(int n, vector<int> adj[]) {
    vector<int> vis(n, -1);
    for(int i = 0; i < n; i++) {
        if(vis[i] == -1) {
            // store the node and it's color
            queue<pair<int, int>> q;
            q.push({i, 0});
            while(q.size() != 0) {
                auto [currentNode, currentColor] = q.front();
                q.pop();
                vis[currentNode] = currentColor;
                for(auto node : adj[currentNode]) {
                    if(vis[node] == -1) {
                        q.push({node, !currentColor});
                    }
                    else
                    if(vis[node] == currentColor) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
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

    bool result = checkBipartite(nodes, adj);
    (result) ? cout << "YES\n" : cout << "NO\n";
    return 0;
}