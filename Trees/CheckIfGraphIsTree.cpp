#include<bits/stdc++.h>
using namespace std ;

// An undirected graph is tree if it has following properties. 
// 1) There is no cycle. 
// 2) The graph is connected

bool DFS(Graph const &graph, int v, vector<bool> &discovered, int parent)
{
    // mark the current node as discovered
    discovered[v] = true;
 
    // do for every edge `v —> w`
    for (int w: graph.adjList[v])
    {
        // if `w` is not discovered
        if (!discovered[w])
        {
            if (!DFS(graph, w, discovered, v)) {
                return false;
            }
        }
 
        // if `w` is discovered, and `w` is not a parent
        else if (w != parent)
        {
            // we found a back-edge (cycle)
            return false;
        }
    }
 
    // no back-edges were found in the graph
    return true;
}
 
int main()
{
    // initialize edges as per the above diagram
    vector<Edge> edges =
    {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}
        // edge `5 —> 0` introduces a cycle in the graph
    };
 
    // total number of nodes in the graph
    int N = 6;
 
    // build a graph from the given edges
    Graph graph(edges, N);
 
    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(N);
 
    // boolean flag to store if the graph is tree or not
    bool isTree = true;
 
    // Perform DFS traversal from the first vertex
    isTree = DFS(graph, 0, discovered, -1);
 
    for (int i = 0; isTree && i < N; i++)
    {
        // any undiscovered vertex means the graph is disconnected
        if (!discovered[i]) {
            isTree = false;
        }
    }
 
    if (isTree) {
        cout << "The graph is a tree";
    }
    else {
        cout << "The graph is not a tree";
    }
 
    return 0;
}





    
