/**
 * Code for Breadth First Search of two disconnected graph
 * While doing the BFS for a disconnected graph, we are
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

void bfsDisconnected(vector<int> adj[], vector<bool> &visited)
{
    cout << "\nThe BFS is\n";
    for(int i = 0; i < visited.size(); i++)
    {
        if(visited[i] == false)
            bfs(adj, visited, i);
    }
}


int main()
{
    int vertices = 7;
    vector<int> adj[vertices];
    createGraph(adj);
    printAdjList(adj, vertices);

    vector<bool> visited(vertices, false);

    int source = 0;

    bfsDisconnected(adj, visited);

    return 0;

}