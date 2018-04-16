/*#include <bits/stdc++.h>
using namespace std;

template <class T> class Graph {
public:
    unordered_map<T, unordered_map<T, double>> nodes;
    bool isDirected;
    Graph(bool isDirected = false) {
        this->isDirected = isDirected;
    }

    bool hasNode(T u) {
        return this->nodes.count(u);
    }

    void addNode(T u) {
        if (!hasNode(u))
            this->nodes[u];
    }

    T nextNode() {
        return this->nodes.begin()->first;
    }

    void addEdge(T u, T v, double cost = 0) {
        addNode(u);
        addNode(v);
        this->nodes[u][v] = cost;
        if (!isDirected)
            this->nodes[v][u] = cost;
    }
};

typedef long long int T;

T maximum = 0;
unordered_set<T> visited;

T dfs (Graph<T> &g, T node) {
    visited.insert(node);
    T max1 = 0, max2 = 0;
    for (auto neigh : g.nodes[node])
        if (!visited.count(neigh.first)) {
            T branchLength = dfs(g, neigh.first);
            if (max1 < branchLength) {
                max2 = max1;
                max1 = branchLength;
            }
        }
    T localMax = max1 + max2;
    if (maximum < localMax)
        maximum = localMax;
    return 1 + max1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Graph<T> g(0);
    T n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        T u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    dfs(g, g.nextNode());
    cout << maximum << endl;

}*/
// C++ program to find longest path of the tree
#include <bits/stdc++.h>
using namespace std;
 
// This class represents a undirected graph using adjacency list
class Graph
{
    int V;              // No. of vertices
    list<int> *adj;     // Pointer to an array containing
                        // adjacency lists
public:
    Graph(int V);              // Constructor
    void addEdge(int v, int w);// function to add an edge to graph
    void longestPathLength();  // prints longest path of the tree
    pair<int, int> bfs(int u); // function returns maximum distant
                               // node from u with its distance
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);    // Add w to v’s list.
    adj[w].push_back(v);    // Since the graph is undirected
}
 
//  method returns farthest node and its distance from node u
pair<int, int> Graph::bfs(int u)
{
    //  mark all distance with -1
    int dis[V];
    memset(dis, -1, sizeof(dis));
 
    queue<int> q;
    q.push(u);
 
    //  distance of u from u will be 0
    dis[u] = 0;
 
    while (!q.empty())
    {
        int t = q.front();       q.pop();
 
        //  loop for all adjacent nodes of node-t
        for (auto it = adj[t].begin(); it != adj[t].end(); it++)
        {
            int v = *it;
 
            // push node into queue only if
            // it is not visited already
            if (dis[v] == -1)
            {
                q.push(v);
 
                // make distance of v, one more
                // than distance of t
                dis[v] = dis[t] + 1;
            }
        }
    }
 
    int maxDis = 0;
    int nodeIdx;
 
    //  get farthest node distance and its index
    for (int i = 0; i < V; i++)
    {
        if (dis[i] > maxDis)
        {
            maxDis = dis[i];
            nodeIdx = i;
        }
    }
    return make_pair(nodeIdx, maxDis);
}
 
//  method prints longest path of given tree
void Graph::longestPathLength()
{
    pair<int, int> t1, t2;
 
    // first bfs to find one end point of
    // longest path
    t1 = bfs(0);
 
    //  second bfs to find actual longest path
    t2 = bfs(t1.first);
 
    /*cout << "Longest path is from " << t1.first << " to "
         << t2.first << " of length " << t2.second;*/
    cout << t2.second << endl;
}
 
// Driver code to test above methods
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, u, v;
    cin >> n;
    // Create a graph given in the example
    Graph g(n);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g.addEdge(u - 1, v - 1);
    }
    g.longestPathLength();
    return 0;
}