#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    if(fast == NULL || fast->next == NULL)
        return NULL;

    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main(){
    ListNode* head = new ListNode(3);
    ListNode* node = new ListNode(2);
    head->next = node;
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = node;

    cout << detectCycle(head)->val;
    return 0;
}