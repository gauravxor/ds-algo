/**
 * Given an unweighted graph and a source vertex. We need to
 * find the shortest distance from the given source node to
 * every other vertex.
 *
 * Idea:
 * We need to do a BFS traversal of the graph, as in this traversal
 * we explore all the nodes close to the source node first.
 *
 * Why we need to explore the nearest node first?
 * When we are finding the shortest distance between the source and
 * all other nodes, the directly connected nodes will have less distance,
 * so we need to set their ditance first.
 * As we go more far away from the source node, the distance is more
 * likey to increase. (it might have a directly connected node).
 *
 * The simple formula used here is
 * distance of a given node = distance needed to reach the node that is
 * directly connected to the given node, from the source node + 1.
 *
 * Example :
 *
 *    -------
 *    |      |
 *    1------2--------3--------4
 *
 *    Distance needed to reach 1 = 0 (as this is the source vertex)    = 0
 *    Distance needed to reach 2 = Distance needed to reach node 1  +1 = (0 + 1)
 *    Distance needed to reach 3 = Distance needed to reach node 2  +1 = (1 + 1)
 */


#include <climits>
#include "graph.h"



void findDistance(vector<int> adj[], vector<int> &dist, int source, int nodes)
{
    vector<bool> visited(nodes, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while(q.empty() == false)
    {
        int currNode = q.front();
        q.pop();
        for(int i = 0; i < adj[currNode].size(); i++)
        {
            if(visited[adj[currNode][i]] == false)
            {
                q.push(adj[currNode][i]);
                visited[adj[currNode][i]] = true;

                // updating the distance vector
                dist[adj[currNode][i]] = dist[currNode] + 1;
            }
        }
    }
}
int main()
{
    int nodes;
    cout << "Enter the number of nodes\n";
    cin >> nodes;

    vector<int> adj[nodes];
    createUnDirectedGraph(adj);


    cout << "Graph Created\n";
    cout << "Enter the source vertex\n";
    int source;
    cin >> source;

    // A separate vector, to store all the distances
    vector<int> distance(nodes, INT_MAX);
    distance[source] = 0;   // distance of src to src is always 0

    findDistance(adj, distance, source, nodes);

    cout << "The distnace vector is\n";
    for(int i: distance)
        cout << i << " ";
    cout << "\n";

    return 0;
}