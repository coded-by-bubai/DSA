#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph
{
private:
    int V;
    list<int> *adjl;
public:
    Graph(int V){
        this->V = V;
        adjl = new list<int> [V];
    }
    
    void addEdge(int u, int v){
        adjl[u].push_back(v);
    }

    bool dfs(int curr, vector<int> &vis, int par){
        vis[curr] = true;

        for(int v : adjl[curr]){
            if(!vis[v]){
                if(dfs(v, vis, curr))
                    return true;
            } else if(par != v){
                return true;
            }
        }

        return false;
    }

    bool isCycle(){
        vector<int> vis(V, false);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, vis, -1)){
                    return true;
                }
            }
        }
        return false;
    }
};



int main(){
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 5);

    cout << (g.isCycle() ? "Yes" : "NO");
    return 0;
}