#include<iostream>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next; 
    ListNode(int x){
        val = x;
        next = nullptr;
    }
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = new ListNode(-1);
    ListNode* curr = head;
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            curr->next = list1;
            list1 = list1->next;
        } else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    if (list1)
        curr->next = list1;
    if (list2) 
        curr->next = list2;

    return head->next;
}

void printLinkedList(ListNode* head){
    while(head){
        cout << head->val;
        if(head->next != nullptr) cout << " -> ";
        head = head->next;
    }
}

int main(){
    ListNode* head1 = new ListNode(5);
    head1->next = new ListNode(10);
    head1->next->next = new ListNode(15);
    head1->next->next->next = new ListNode(25);
    head1->next->next->next->next = new ListNode(35);

    ListNode* head2 = new ListNode(0);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(8);
    head2->next->next->next = new ListNode(11);

    ListNode* res = mergeTwoLists(head1, head2);
    printLinkedList(res);
    return 0;
}