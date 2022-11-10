#include <iostream>
#include <vector>
#include <stack>
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

// Perform DFS on graph starting from vertex v
bool DFS(Graph const &graph, int v, vector<bool> &discovered)
{
    // create a stack used to do DFS
    stack<int> stack;

    // push the source node into stack
    stack.push(v);

    // loop till stack is empty
    while (!stack.empty())
    {
        // we pop a vertex from stack and print it
        v = stack.top();
        stack.pop();

        // if the vertex is already discovered yet, ignore it
        if (discovered[v])
            continue;

        // we print the vertex and mark it as discovered
        discovered[v] = true;
        cout << v << " ";

        // do for every edge (v -> u)
        for (int u : graph.adjList[v])
        {
            // if vertex u is not discovered, push it into stack
            if (!discovered[u])
                stack.push(u);
        }
    }

    return true;
}

// Depth First Search Algorithm
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
        {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
        // vertex 0, 13 and 14 are single nodes
    };

    // Number of nodes in the graph
    int N = 15;

    // create a graph from edges
    Graph graph(edges, N);

    // stores vertex is discovered or not
    vector<bool> discovered(N);

    // Do DFS traversal from all undiscovered nodes to
    // cover all unconnected components of graph
    for (int i = 0; i < N; i++)
        if (discovered[i] == false)
            // start DFS traversal from vertex i
            DFS(graph, i, discovered);

    return 0;
}
