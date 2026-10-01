#include<iostream>
#include<vector>
#include<stack>

using namespace std;


bool isCycle(int src, vector<int> &vis, vector<int> &recPath, vector<vector<int>>& prerequisites){
    vis[src] = true;
    recPath[src] = true;

    for(int i = 0; i < prerequisites.size(); i++){
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];
        if(u == src){
            if(!vis[v]){
                if(isCycle(v, vis, recPath, prerequisites))
                    return true;
            }else if(recPath[v])
                return true;
        }
    }
    recPath[src] = false;
    return false;
}

void topoSort(int src, vector<int> &vis, stack<int> &stack, vector<vector<int>>& prerequisites){
    vis[src] = true;
    for(int i=0; i<prerequisites.size(); i++){
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];
        if(u == src){
            if(!vis[v]){
                topoSort(v, vis, stack, prerequisites);
            }
        }
    }
    stack.push(src);
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> vis(numCourses, false);
    vector<int> recPath(numCourses, false);
    vector<int> result;

    for(int i = 0; i<numCourses; i++){
        if(!vis[i]){
            if(isCycle(i, vis, recPath, prerequisites))
                return result;
        }
    }

    vis.assign(numCourses, false);
    stack<int> stack;

    for(int i = 0; i<numCourses; i++){
        if(!vis[i]){
            topoSort(i, vis, stack, prerequisites);
        }
    }

    while(stack.size()>0){
        result.push_back(stack.top());
        stack.pop();
    }

    return result;
}

int main(){
    vector<vector<int>> prerequisites = {{1,0}, {2,0}, {3,1}, {3,2}};
    vector<int> res = findOrder(4, prerequisites);
    cout<<"Course Schedule: ";
    for(int x:res)
        cout<<x << " ";
    return 0;
}