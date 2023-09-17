#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool bfs(int source, vector<bool> &visited, vector<int> adj[]) {
    queue<pair<int, int>> q;
    q.push({source, -1});
    while(!q.empty()) {
        int currentNode = q.front().first;
        int papaNode = q.front().second;
        q.pop();

        visited[currentNode] = true;
        for(int adjancentNode : adj[currentNode]) {
            if(visited[adjancentNode] == false) {
                q.push({adjancentNode, currentNode});
            }
            else
            if(adjancentNode != papaNode) {
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(int nodes, vector<int> adj[]) {
    vector<bool> visited(nodes, false);
    for(int i = 0; i < nodes; i++) {
        if(visited[i] == false && bfs(i, visited, adj) == true) {
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