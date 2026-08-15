#include<iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}
};

void removeLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (fast == nullptr || fast->next == nullptr)
        return;
    
    slow = head;
    if (slow == fast) {
        while (fast->next != slow) {
            fast = fast->next;
        }
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    fast->next = nullptr;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;
    removeLoop(head);

    Node* curr = head;
    while(curr != nullptr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}