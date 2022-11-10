#include <iostream>
#include <vector>

// data structure to store graph edges
struct Edge {
    int src, dest, weight;
};

// class to represent a graph object
extern class Graph;

// Function to print adjacency list representation of graph
extern void printGraph(Graph const &graph, int N);

int kruskal(Graph const &graph, int N)
{
    // stores edge list of the MST
    vector<Edge> MST;

    // initialize a Union-Find data structure
    DisjointSet ds(N);

    // get all edges of the graph in a vector
    vector<Edge> edges;
    for (int i = 0; i < N; i++)
    {
        for (Edge e : graph.adjList[i])
            edges.push_back(e);
    }

    // sort edges by increasing weight
    sort(edges.begin(), edges.end(), [](Edge const &e1, Edge const &e2) {
        return e1.weight < e2.weight;
    });

    // process edges in increasing weight order
    for (Edge const &edge: edges)
    {
        // check if the selected edge creates a cycle or not
        if (ds.find(edge.src) != ds.find(edge.dest))
        {
            // include the current edge in MST
            MST.push_back(edge);

            // merge two components
            ds.merge(edge.src, edge.dest);
        }
    }

    // print MST
    for (Edge const &e: MST)
        cout << "(" << e.src << ", " << e.dest << ", " << e.weight << ") ";

    return 0;
}

// main function
int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {0, 1, 7}, {1, 2, 8}, {0, 3, 5}, {1, 3, 9}, {1, 4, 7}, {2, 4, 5},
        {3, 4, 15}, {3, 5, 6}, {4, 5, 8}, {4, 6, 9}, {5, 6, 11}
    };

    // total number of nodes in the graph
    int N = 7;

    // build a graph from the given edges
    Graph graph(edges, N);

    // print adjacency list representation of graph
    printGraph(graph, N);

    // run Kruskal's algorithm on the graph
    kruskal(graph, N);

    return 0;
}