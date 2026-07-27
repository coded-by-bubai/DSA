#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = nullptr;
    };
};

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isIdentical(Node* n1, Node* n2){
    for(;n1 && n2; n1 = n1->next, n2 = n2->next){
        if(n1->data != n2->data)
            return 0;
    }
    return 1;
}

bool isPalindrome(Node* head){
    if(!head || !head->next)
        return true;
    
    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* head2 = reverse(slow->next);
    slow->next = nullptr;

    bool ret = isIdentical(head, head2);

    head2 = reverse(head2);
    slow->next = head2;
    return ret;
}

int main(){
    Node head(1);
    head.next = new Node(2);
    head.next->next = new Node(3);
    head.next->next->next = new Node(2);
    head.next->next->next->next = new Node(1);

    bool result = isPalindrome(&head);
    cout << (result ? "True": "False");
    return 0;
}