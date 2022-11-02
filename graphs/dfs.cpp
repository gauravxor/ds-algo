/**
 * Code for Depth First Search of a graph.
 * Recursive Implementation.
 * 
 *     1-----3
 *    /    / |
 *   0    /  |
 *    \  /   |
 *      2----4
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
    addEdge(adj, 0, 1);    
    addEdge(adj, 0, 2);    
    addEdge(adj, 1, 3);    
    addEdge(adj, 2, 3);    
    addEdge(adj, 2, 4);    
    addEdge(adj, 3, 4);    
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

int main()
{
    int vertices = 5;
    vector<int> adj[vertices];
    createGraph(adj);
    printAdjList(adj, vertices);

    int source = 4;

    vector<bool> visited(vertices, false);
    
    cout << "\nThe dfs is\n";
    dfs(adj, visited, source);
    cout << "\n";
    return 0;
}