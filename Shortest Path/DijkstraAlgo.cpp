#include <iostream>
#include<list>
#include<vector>
#include<queue>
#include<climits>

using namespace std;
class Graph
{
public:
    int V;
    list<pair<int, int>> *adjl;
    Graph(int V){
        this->V = V;
        adjl = new list<pair<int, int>> [V];
    }
    ~Graph() {
        delete[] adjl;
    }
    void addEdge(int u, int v, int wt){
        adjl[u].push_back({wt, v});
        adjl[v].push_back({wt, u});
    }
};

vector<int> dijkstra(int n,list<pair<int, int>> *adjList, int src){
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq; // {dist, v}
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for(auto edg : adjList[u]){
            int wt = edg.first;
            int v = edg.second;
            if (dist[v] > dist[u] + wt )
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
            
        }
    }
    return dist;
}

int main(){
    Graph g(6);
    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,7);
    g.addEdge(2,4,3);
    g.addEdge(3,5,1);
    g.addEdge(4,3,2);
    g.addEdge(4,5,5);
    vector<int> distance = dijkstra(g.V, g.adjl, 0 );
    cout << "Shortest distances from source 0 : ";
    for(int it : distance)
        cout<< it << " ";
    return 0;
}