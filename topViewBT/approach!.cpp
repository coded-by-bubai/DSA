#include<iostream>
#include<vector>
#include<map>

using namespace std;
class Node
{ 
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

void dfs(Node* node, int hd, int level, map<int, pair<int, int>>& topviewNodes){
    if(!node) return;

    if (topviewNodes.find(hd) == topviewNodes.end() || topviewNodes[hd].second > level)
    {
        topviewNodes[hd] = {node->data, level};
    }
    
    dfs(node->left, hd - 1, level + 1, topviewNodes);
    dfs(node->right, hd + 1, level + 1, topviewNodes);
}

vector<int> topView(Node* root){
    vector<int> result;
    if (!root) return result;
    map<int, pair<int, int>> topViewNodes;

    dfs(root, 0, 0, topViewNodes);
    for(auto it : topViewNodes){
        result.push_back(it.second.first);
    }
    return result;
}

int main(){
    // Create a sample binary tree
    //     10
    //    /  \
    //   20   30
    //  / \   / \
    // 40  60 90  100

    Node* root = new Node(10);
    root->left = new Node(20);       
    root->right = new Node(30);            
    root->left->left = new Node(40);     
    root->left->right = new Node(60);   
    root->right->left = new Node(90);   
    root->right->right = new Node(100); 

    vector<int> result = topView(root);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}