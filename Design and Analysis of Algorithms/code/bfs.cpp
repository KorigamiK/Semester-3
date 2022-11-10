#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int src, dest;
};

class Graph
{
public:
    vector<vector<int>> adjList;

    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to N elements of type vector<int>
        adjList.resize(N);

        // add edges to the directed graph
        for (auto &edge: edges)
        {
            // insert at the end
            adjList[edge.src].push_back(edge.dest);
            // Uncomment below line for undirected graph
            // adjList[edge.dest].push_back(edge.src);
        }
    }
};

// Perform BFS on graph starting from vertex v
bool BFS(Graph const &graph, int v, vector<bool> &discovered)
{
    queue<int> q;
    // mark source vertex as discovered
    discovered[v] = true;
    // push source vertex into the queue
    q.push(v);

    while (!q.empty())
    {
        // dequeue front node and print it
        v = q.front();
        q.pop();
        cout << v << " ";

        // do for every edge (v -> u)
        for (int u : graph.adjList[v])
        {
            // if vertex u is not discovered yet
            if (!discovered[u])
            {
                discovered[u] = true;
                q.push(u);
            }
        }
    }
}

int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
        {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
        // vertex 0, 13 and 14 are single nodes
    };

    // total number of nodes in the graph
    int N = 15;

    // build a graph from the given edges
    Graph graph(edges, N);

    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(N);

    // Do BFS traversal from all undiscovered nodes to
    // cover all unconnected components of graph
    for (int i = 0; i < N; i++)
        if (discovered[i] == false)
            // start BFS traversal from vertex i
            BFS(graph, i, discovered);

    return 0;
}
