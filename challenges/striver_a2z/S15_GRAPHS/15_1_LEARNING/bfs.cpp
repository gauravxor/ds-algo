#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void getBfs(vector<int> adj[], vector<int> &bfs) {
    int nodes = (*adj).size();
    vector<bool> visited(nodes, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(q.empty() == false) {
        int currentNode = q.front();
        bfs.push_back(currentNode);
        q.pop();

        visited[currentNode] = true;
        for(auto it : adj[currentNode]) {
            if(visited[it] == false) {
                visited[it] = true;
                q.push(it);
            }
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

    vector<int> bfs;
    getBfs(adj, bfs);

    cout << "The BFS is\n";
    for(int i : bfs) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}