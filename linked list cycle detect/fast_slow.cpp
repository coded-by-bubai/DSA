#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast)
            return true;
        }

        return false;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* a = new ListNode(2);
    head->next = a;
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = a;
    cout << (hasCycle(head) ? "True" : "False");
    return 0;
}