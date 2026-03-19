#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<vector<int>> verticalOrder(Node *root) {

        vector<vector<int>> ans;
        if (!root) return ans;

        unordered_map<int, vector<int>> mp;
        queue<pair<Node*, int>> q;

        int minHd = 0, maxHd = 0;

        q.push({root, 0});

        while (!q.empty()) {

            auto curr = q.front();
            q.pop();

            Node* node = curr.first;
            int hd = curr.second;

            mp[hd].push_back(node->data);

            minHd = min(minHd, hd);
            maxHd = max(maxHd, hd);

            if (node->left)
                q.push({node->left, hd - 1});

            if (node->right)
                q.push({node->right, hd + 1});
        }

        for (int i = minHd; i <= maxHd; i++) {
            ans.push_back(mp[i]);
        }

        return ans;
    }
};

int main() {

    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    vector<vector<int>> result = obj.verticalOrder(root);

    cout << "Vertical Order Traversal:\n";

    for (auto column : result) {
        for (int val : column) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}