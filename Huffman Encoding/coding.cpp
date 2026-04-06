#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Node
{
    int freq;
    int index;
    Node *left, *right;
    Node(int f, int i)
    {
        freq = f;
        index = i;
        left = right = NULL;
    }
    Node(Node *l, Node *r)
    {
        freq = l->freq + r->freq;
        index = min(l->index, r->index);
        left = l;
        right = r;
    }
};
struct compare
{
    bool operator()(Node *l, Node *r)
    {
        if (l->freq != r->freq)
            return (l->freq > r->freq);
        return l->index > r->index;
    }
};

void preorder(Node *root, string code, vector<string> &codes)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        if (code == "")
            code = "0";
        codes.push_back(code);
        return;
    }

    preorder(root->left, code + "0", codes);
    preorder(root->right, code + "1", codes);
}
vector<string> huffmanCodes(string &s, vector<int> f)
{
    // Code here
    priority_queue<Node *, vector<Node *>, compare> pq;

    for (int i = 0; i < s.size(); i++)
    {
        pq.push(new Node(f[i], i));
    }
    if (s.size() == 1)
        return {"0"};

    while (pq.size() >= 2)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *newnode = new Node(left, right);

        pq.push(newnode);
    }
    Node *root = pq.top();
    vector<string> codes;
    preorder(root, "", codes);
    return codes;
}

int main()
{
    string str = "qznwdumxisktyh";
    vector<int> freq = {21, 57, 10, 98, 60, 56, 5, 60, 81, 49, 20, 2, 7, 58};
    vector<string> codes = huffmanCodes(str, freq);
    for (string code : codes)
        cout << code << " ";
    return 0;
}