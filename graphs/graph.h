#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/** helper function to print the adjacency list. */
void printAdjList(vector<int> adj[], int nodes)
{
    cout << "The Adjacency List is \n";

    for(int i = 0; i < nodes; i++)
    {
        cout << i << " -> ";
        for(int j : adj[i])
            cout << j << " ";
        cout << "\n";
    }
}


/** helper function to an edge to the graph.
 * It accepts the type of the graph, where 1 & 0 indicates
 * an undirected and directed graph respectively.
*/
void addEdge(vector<int> adj[], int u, int v, int type)
{
    adj[u].push_back(v);

    if(type == 1)
        adj[v].push_back(u);
}


/** Helper function to create an undirected graph */
void createUnDirectedGraph(vector<int> adj[])
{
    int e1, e2;
    cout << "Enter single edge pairs. To end, enter -1\n";
    while(true)
    {
        cin >> e1 >> e2;
        if(e1 == -1 || e2 == -1)
            return;
        addEdge(adj, e1, e2, 1);
    }
}


/** Helper function to create an undirected graph
 * The direction of the flow is from [e1 <-> e2]
*/
void createDirectedGraph(vector<int> adj[])
{
    int e1, e2;
    cout << "Enter single edge pairs. To end, enter -1\n";
    while(true)
    {
        cin >> e1 >> e2;
        if(e1 == -1 || e2 == -1)
            return;
        addEdge(adj, e1, e2, 0);
    }
}


/** Helper function for BFS Traversal of Normal Graphs */
void bfs(vector<int> adj[], vector<bool> &visited, int source)
{
    cout << "\nThe BFS is\n";
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";
        for(int it: adj[vertex])
        {
            if(visited[it] == false)
            {
                visited[it] = true;
                q.push(it);
            }
        }
    }
    cout << "\n";
}


/** Helper function for BFS Traversal of Disconnected Graphs */
void bfsDisconnected(vector<int> adj[], vector<bool> &visited)
{
    for(int i = 0; i < visited.size(); i++)
    {
        if(visited[i] == false)
            bfs(adj, visited, i);
    }
}


/** Helper function for DFS Traversal of Normal Graphs */
void dfs(vector<int> adj[], vector<bool> &visited, int source)
{
    visited[source] = true;
    cout << source << " ";
    for(int i = 0; i < adj[source].size(); i++)
    {
        if(visited[adj[source][i]] == false)
        {
            visited[source] = true;
            dfs(adj, visited, adj[source][i]);
        }
    }
}


/** Helper function for DFS Traversal of Disconnected Graphs */
void dfsDisconnected(vector<int> adj[], vector<bool> &visited)
{
    for(int i = 0; i < visited.size(); i++)
    {
        if(visited[i] == false)
            dfs(adj, visited, i);
    }
}
