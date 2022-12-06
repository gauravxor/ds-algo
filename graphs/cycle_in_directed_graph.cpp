/**
 * Write a DIRECTED GRAPH, we need to detect if there is a cycle present
 * in the graph.
 *
 * IDEA:
 *
 * We will use the DFS Traversal to solve this problem.
 * The basic idea is to keep a record of the visited nodes. If any nodes
 * has an adjacent node, that has been visited already, then we know there
 * is a cycle.
 *
 *  Why the solution for UNDIRECTED Graph does not work for DIRECTED Graph?
 *
 *  1---->2<-----3---->4(to 5)
 *                \    |
 *                 \   |
 *                  \  |
 *                   5(to 3)
 *
 * In the above example of a directed graph, when performing a DFS traversal,
 * the first traversal ends at node 2, as it doesnot have any adjacent nodes.
 * No traversing the node 3, it has two two children i.e. 2 and 4, where 2 is
 * already visited and 4 is not. So upon checking, as 2 is not the parent and
 * 2 is also visited, the logic for UNDIRECTED graph will identify this as a
 * cycle.
 *
 *
 * To solve the problem, we need to maintain a record of all the nodes that has
 * been visied during a traversal. In the traversal if we detect a cycle then
 * it is okay, but if we dont that we at the end of the traversal, we need to
 * mark all the visited nodes during our resursive call, unvisited.
 *
 * So when we do s DFS on node 3, it will see that node 2 and 4 both are not
 * visited hence, they will not call it a cycle.
 *
 * To keep records of the nodes REACHED during the traversal, use a different
 * vector just like the visited() vector.
 *
 * The only difference betweeen the visited vector and the callstack() vector
 * is that, once the content of visitor() vector is set, it is not begin changed
 * where as callstack() vector's data will be changed at the end of every call.
 *
 **/

#include "graph.h"



bool dfs(vector<int> adj[], vector<bool> &visited, vector<int> &callstack, int source)
{
    visited[source] = true;
    callstack[source] = true;

    for(int i = 0; i < adj[source].size(); i++)
    {
        if(visited[adj[source][i]] == false && dfs(adj, visited, callstack, adj[source][i]) == true)
            return true;
        else
        if(callstack[adj[source][i]] == true)
            return true;
    }
    callstack[source] = false;
    return false;
}



bool detectCycle(vector<int> adj[], int nodes)
{
    vector<bool> visited(nodes, false);
    vector<int> callstack(nodes,false);


    for(int i = 0; i < nodes; i++)
    {
        if(visited[i] == false)
        {
            if(dfs(adj, visited, callstack, i) == true)
                return true;
        }
    }
    return false;
}


int main()
{
    int nodes;
    cout << "Enter the nodes\n";
    cin >> nodes;

    vector<int> adj[nodes];
    createDirectedGraph(adj);
    printAdjList(adj, nodes);

    if(detectCycle(adj, nodes) == true)
        cout << "Cycle Detected\n";
    else
        cout << "Cycle Doesnot Exists\n";
    return 0;

}