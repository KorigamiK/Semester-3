struct Edge {
    int src, dest, weight;
};

class Graph
{
public:
    // construct a vector of vectors of Edge to represent an adjacency list
    vector<vector<Edge>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to N elements of type vector<Edge>
        adjList.resize(N);

        // add edges to the directed graph
        for (auto &edge: edges)
        {
            // insert at the end
            adjList[edge.src].push_back(edge);
        }
    }
};

// Function to print adjacency list representation of graph
void printGraph(Graph const &graph, int N)
{
    for (int i = 0; i < N; i++)
    {
        // print current vertex number
        cout << i << " --> ";

        // print all neighboring vertices of vertex i
        for (Edge e : graph.adjList[i])
            cout << "(" << e.dest << ", " << e.weight << ") ";

        cout << endl;
    }
}

// Function to perform Prim's algorithm on a graph
int prim(Graph const &graph, int N)
{
    // create a min-heap using std::set in STL
    // we use `std::pair` as the data type of the element stored in the heap
    // the first element of the pair stores the key and the second element stores the vertex number
    set<pair<int, int>> pq;

    // create a vector to store key of the vertices which have been found by the algorithm
    // initialize all keys to infinite (INT_MAX)
    vector<int> key(N, INT_MAX);

    // create a vector to store parent node of a vertex
    // it keeps track of the minimum spanning tree
    vector<int> parent(N, -1);

    // to keep track of vertices included in MST
    vector<bool> inMST(N, false);

    // insert source vertex in the set and make its key 0
    pq.insert(make_pair(0, 0));
    key[0] = 0;

    // run till `pq` is not empty
    while (!pq.empty())
    {
        // find the vertex with the minimum key
        // extract it from the set
        int u = pq.begin()->second;
        pq.erase(pq.begin());

        // include vertex in MST
        inMST[u] = true;

        // do for each adjacent vertex `v` of `u`
        for (Edge e : graph.adjList[u])
        {
            int v = e.dest;
            int weight = e.weight;

            // if `v` is not in MST and weight of (u, v) is smaller than current key of `v`
            if (!inMST[v] && key[v] > weight)
            {
                // update the key of `v` in the set
                pq.erase(make_pair(key[v], v));
                key[v] = weight;
                pq.insert(make_pair(key[v], v));

                // update the parent of `v`
                parent[v] = u;
            }
        }
    }

    // print edges of the MST
    for (int i = 1; i < N; i++)
        cout << parent[i] << " - " << i << endl;

    // return weight of the MST
    return accumulate(key.begin(), key.end(), 0);
}

int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges =
    {
        // (x, y, w) -> edge from x to y having weight w
        { 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
        { 3, 2, 10 }, { 5, 4, 1 }, { 4, 5, 3 }, { 4, 0, 1 }
    };

    // Number of nodes in the graph
    int N = 6;

    // construct graph
    Graph graph(edges, N);

    // print adjacency list representation of graph
    printGraph(graph, N);

    // run Prim's algorithm on graph
    cout << "Weight of the MST is " << prim(graph, N);

    return 0;
}