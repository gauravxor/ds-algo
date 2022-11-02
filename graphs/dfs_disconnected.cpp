/**
 * Code for Depth First Search of two disconnected graph
 * While doing the DFS for a disconnected graph, we are
 * unaware of the source, as the mentioned source may not
 * have any incoming or outgoing edges.
 * 
 *      0              4
 *    /   \           / \
 *   /     \         /   \
 *  1       2       /     \
 *   \     /       5-------6
 *    \   /
 *      3
 * 
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void createGraph(vector<int> adj[])
{
    // for first graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    // for second graph
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);  
}

void printAdjList(vector<int> adj[], int vertices)
{
    cout << "The genereted adjacency list is \n";
    for(int i = 0; i < vertices; i++)
    {
        cout << i << " -> ";
        for(int it : adj[i])
            cout << it << " ";
        cout << "\n";
    }
}

void dfs(vector<int> adj[], vector<bool> &visited, int source)
{
    visited[source] = true;
    cout << source << " ";
    for(int it : adj[source])
    {
        if(visited[it] == false)
            dfs(adj, visited, it);
    }
}


void dfsDisconnected(vector<int> adj[], vector<bool> &visited)
{
    for(int i = 0; i < visited.size(); i++)
    {
        if(visited[i] == false)
            dfs(adj, visited, i);
    }
}
int main()
{
    int vertices = 7;
    vector<int> adj[vertices];
    createGraph(adj);
    printAdjList(adj, vertices);

    int source = 4;

    vector<bool> visited(vertices, false);
    
    cout << "\nThe dfs is\n";
    dfsDisconnected(adj, visited);
    cout << "\n";
    return 0;
}