#include<iostream>
#include<vector>
#include<map>
#include<queue>

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

vector<int> topView(Node* root){
    vector<int> result;
    if (!root) return result;
    map<int, int> topViewNodes;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto currNode = q.front();
        Node* node = currNode.first;
        int hd = currNode.second;
        q.pop();

        if (topViewNodes.find(hd) == topViewNodes.end())
        {
            topViewNodes[hd] = node->data;
        }
        if (node->left)
        {
            q.push({node->left, hd-1});
        }
        if (node->right)
        {
            q.push({node->right, hd+1});
        }
        
    }
    
    for(auto it : topViewNodes){
        result.push_back(it.second);
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