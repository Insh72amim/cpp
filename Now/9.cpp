#include <iostream>
#include <list>
#include <limits.h>
using namespace std;

class Graph
{

    // No. of vertices
    int V;

    // Pointer to an array
    // containing adjacency lists
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], int parent);

public:
    // Constructor
    Graph(int V);

    // To add an edge to graph
    void addEdge(int v, int w);

    // Returns true if there is a cycle
    bool isCyclic();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{

    // Add w to v’s list.
    adj[v].push_back(w);

    // Add v to w’s list.
    adj[w].push_back(v);
}

// A recursive function that
// uses visited[] and parent to detect
// cycle in subgraph reachable
// from vertex v.
bool Graph::isCyclicUtil(int v,
                         bool visited[], int parent)
{

    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i !=
                             adj[v].end();
         ++i)
    {

        // If an adjacent is not visited,
        // then recur for that adjacent
        if (!visited[*i])
        {
            if (isCyclicUtil(*i, visited, v))
                return true;
        }

        // If an adjacent is visited and
        // not parent of current vertex,
        // then there is a cycle.
        else if (*i != parent)
            return true;
    }
    return false;
}

// Returns true if the graph contains
// a cycle, else false.
bool Graph::isCyclic()
{

    // Mark all the vertices as not
    // visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper
    // function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++)
    {

        // Don't recur for u if
        // it is already visited
        if (!visited[u])
            if (isCyclicUtil(u, visited, -1))
                return true;
    }
    return false;
}

public
class Solution
{
    Set<String> res = new HashSet<String>();

public
    List<String> findWords(char[][] board, String[] words)
    {
        Trie trie = new Trie();
        for (String word : words)
        {
            trie.insert(word);
        }

        int m = board.length;
        int n = board[0].length;
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dfs(board, visited, "", i, j, trie);
            }
        }

        return new ArrayList<String>(res);
    }

public
    void dfs(char[][] board, boolean[][] visited, String str, int x, int y, Trie trie)
    {
        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length)
            return;
        if (visited[x][y])
            return;

        str += board[x][y];
        if (!trie.startsWith(str))
            return;

        if (trie.search(str))
        {
            res.add(str);
        }

        visited[x][y] = true;
        dfs(board, visited, str, x - 1, y, trie);
        dfs(board, visited, str, x + 1, y, trie);
        dfs(board, visited, str, x, y - 1, trie);
        dfs(board, visited, str, x, y + 1, trie);
        visited[x][y] = false;
    }
}

// Driver program to test above functions
int
main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic() ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic() ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";

    return 0;
}
if (vis[i])
    return;
vis[i] = true;
if (i - arr[i] >= 0 && i - arr[i] <= n)
    dfs(i - arr[i], n, arr, vis);
if (i + arr[i] >= 0 && i + arr[i] <= n)
    dfs(i + arr[i], n, arr, vis);