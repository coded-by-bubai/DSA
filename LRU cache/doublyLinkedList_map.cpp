#include<iostream>
#include<unordered_map>

using namespace std;

class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int k, int v): key(k), val(v), next(nullptr), prev(nullptr) {}
    };

    Node *head;
    Node *tail;
    unordered_map<int, Node*> cacheMap;
    int limit;

    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        limit = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()){
            return -1;
        }

        Node *node = cacheMap[key];
        remove(node);
        add(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key) != cacheMap.end()){
            Node *oldNode = cacheMap[key];
            remove(oldNode);
            delete oldNode;
        }

        Node *newNode = new Node(key, value);
        add(newNode);
        cacheMap[key] = newNode;

        if(cacheMap.size() > limit){
            Node *deleteNode = tail->prev;
            remove(deleteNode);
            cacheMap.erase(deleteNode->key);
            delete deleteNode;
        }
    }

    void add(Node *newNode){
        newNode->next = head->next;
        newNode->prev = head;

        head->next->prev = newNode;
        head->next = newNode;
    }

    void remove(Node *node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 int main(){
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout << obj->get(1) << endl;
    obj->put(3,3);
    cout << obj->get(2) << endl;
    cout << obj->get(3) << endl;

    return 0;
 }