/**
 * Given an UNDIRECTED graph, we have to check if it contains
 * cycle or not.
 *
 * Idea:
 * We can do this using either BFS or DFS traversal.
 * The idea is to keep track of the parent node.
 * If the next connected node is equal to the node that is
 * visited previously, then we have a cycle in the graph.
 *
 * The edge case is that, if the visited node is the parent
 * node of the current node, then that is not a cycle.
 *
 */

#include "graph.h"


bool dfs(vector<int> adj[], vector<int> &visited, int source, int parent)
{
    visited[source] = true;
    for(int i = 0; i < adj[source].size(); i++)
    {
        if(visited[adj[source][i]] == false)
        {
            if(dfs(adj, visited, adj[source][i], source) == true)
                return true;
        }
        else
        if(adj[source][i] != parent)
            return true;
    }
    return false;
}

bool detectCycle(vector<int> adj[], int nodes)
{
    vector<int> visited(nodes, false);
    for(int i = 0; i < nodes; i++)
    {
        if(visited[i] == false)
        {
            if(dfs(adj, visited, i, -1) == true)
                return true;
        }
    }
    return false;
}


int main()
{
    int nodes;
    cout << "Enter the number of Nodes\n";
    cin >> nodes;

    vector<int> adj[nodes];
    createUnDirectedGraph(adj);

    if(detectCycle(adj, nodes) == true)
        cout << "Cycle Exists\n";
    else
        cout << "No Cycle Detected\n";
    return 0;
}