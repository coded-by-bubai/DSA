#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include<stack>

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
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
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
    void dfs(int u, vector<bool> &visited, stack<int> &st)
    {
        visited[u] = true;
        for (int v : l[u])
        {
            if (!visited[v])
            {
                dfs(v, visited, st); 
            }
        }
        st.push(u);
    }
    void topoSort(){
        vector<bool> visited(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(i, visited, st);
        }
        while (!st.empty())
        {
            cout<< st.top() << " ";
            st.pop();
        }
        
    }
};

int main()
{
    Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.topoSort();
    return 0;
}