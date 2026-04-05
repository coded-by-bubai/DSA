#include <iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *adjl;
public:
    Graph(int V){
        this->V = V;
        adjl = new list<pair<int, int>> [V];
    }

    void addEdge(int u, int v, int wt){
        adjl[u].push_back({wt, v});
    }
    int primMST(){
        vector<bool> inMST(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int minCost = 0;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto p = pq.top();
            int wt = p.first;
            int u = p.second;
            pq.pop();

            if (!inMST[u])
            {
                inMST[u] = true;
                minCost += wt;

                for(auto it : adjl[u]){
                    pq.push({it.first, it.second});
                }
            }
            
        }
        return minCost;
    }
};


int main(){
    Graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(1,0,10);
    g.addEdge(0,3,30);
    g.addEdge(3,0,30);
    g.addEdge(0,2,15);
    g.addEdge(2,0,15);
    g.addEdge(1,3,40);
    g.addEdge(3,1,40);
    g.addEdge(2,3,50);
    g.addEdge(3,2,50);

    cout << "Cost of MST is : " << g.primMST();
    return 0;
}