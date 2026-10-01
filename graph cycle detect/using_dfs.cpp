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

    bool dfs(int curr, vector<int> &vis, vector<int> &recPath){
        vis[curr] = true;
        recPath[curr] = true;

        for(int v : adjl[curr]){
            if(!vis[v]){
                if(dfs(v, vis, recPath))
                    return true;
            } else if(recPath[v]){
                return true;
            }
        }

        recPath[curr] = false;
        return false;
    }

    bool isCycle(){
        vector<int> vis(V, false);
        vector<int> recPath(V, false);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, vis, recPath)){
                    return true;
                }
            }
        }
        return false;
    }
};



int main(){
    Graph g(4);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    cout << (g.isCycle() ? "Yes" : "NO");
    return 0;
}