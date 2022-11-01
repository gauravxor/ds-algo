/**
 * Adjacency list representation of an undirected graph.
 * 
 *    0-------1------3
 *     \     /
 *      \   /
 *        2
 */    

#include <iostream>
#include <vector>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAdjList(vector<int> adj[], int vertices)
{
    for(int i = 0; i < vertices; i++)
    {
        cout << i << " -> ";
        for(int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    int vertices = 4;
    vector<int> adj[vertices];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);


    cout << "The generated list is\n";
    printAdjList(adj, vertices);
    return 0;
}
