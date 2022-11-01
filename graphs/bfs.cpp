/**
 * Code for Breadth First Search of a graph
 * 
 *     1-----3
 *    /    / |
 *   0    /  |
 *    \  /   |
 *      2----4
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <queue>

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
    cout << "The generated list is\n";
    for(int i = 0; i < vertices; i++)
    {  
        cout << i << " -> ";
        for(int it : adj[i])
            cout << it << " ";
        cout << "\n";
    }
}

void bfs(vector<int> adj[], vector<bool> &visited, int source)
{
    cout << "\nThe BFS is\n";
    queue<int> q;
    visited[source] = true;
    q.push(source);

    while(q.empty() == false)
    {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";

        for(int i = 0; i < adj[vertex].size(); i++)
        {
            if(visited[adj[vertex][i]] == false)
            {
                visited[adj[vertex][i]] = true;
                q.push(adj[vertex][i]);
            }
        }
    }
    cout << "\n";
}

int main()
{
    int vertices = 5;
    vector<int> adj[vertices];
    createGraph(adj);
    printAdjList(adj, vertices);

    vector<bool> visited(vertices, false);

    int source = 0;

    bfs(adj, visited, source);

    return 0;

}