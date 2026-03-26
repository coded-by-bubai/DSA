#include <iostream>
#include <vector>
using namespace std;

/* BST Node */
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    
    return root;
}

class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        
        while (root) {
            if (root->data == key) {
                
                // Predecessor (max in left subtree)
                if (root->left) {
                    Node* temp = root->left;
                    while (temp->right)
                        temp = temp->right;
                    pre = temp;
                }
                
                // Successor (min in right subtree)
                if (root->right) {
                    Node* temp = root->right;
                    while (temp->left)
                        temp = temp->left;
                    suc = temp;
                }
                break;
            }
            else if (key < root->data) {
                suc = root;
                root = root->left;
            }
            else {
                pre = root;
                root = root->right;
            }
        }
        
        return {pre, suc};
    }
};

int main() {
    Node* root = NULL;

    // Construct BST
    vector<int> values = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values) {
        root = insert(root, val);
    }

    int key = 65;

    Solution obj;
    vector<Node*> ans = obj.findPreSuc(root, key);

    cout << "Predecessor: ";
    if (ans[0]) cout << ans[0]->data;
    else cout << "NULL";

    cout << "\nSuccessor: ";
    if (ans[1]) cout << ans[1]->data;
    else cout << "NULL";

    cout << endl;

    return 0;
}