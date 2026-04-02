#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int v, int u)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "for " << i << ": ";
            for (int v : l[i])
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
    void dfsHelper(int u, vector<bool> &visited)
    {
        cout << u << " ";
        visited[u] = true;
        for (int v : l[u])
        {
            if (!visited[v])
            {
                dfsHelper(v, visited);
            }
                }
    }
    void dfsAlgo()
    {
        cout << "DFS : ";
        vector<bool> visited(V, false);
        dfsHelper(0, visited);
        cout<< endl;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.dfsAlgo();
    return 0;
}