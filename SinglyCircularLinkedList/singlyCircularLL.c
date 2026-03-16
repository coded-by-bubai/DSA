#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

struct node
{
    int data;
    struct node *next;
}*head = 0;

void display(){
    struct node *temp = head;
    while (temp->next != head)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> ", temp->data);
    printf("(Back To First Node)\n");
}

void create(){
    struct node *newnode, *temp;
    int choice = 1;
    if (head != 0)
    {
        printf("Linked list already created.\n");
        return;
    }
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter node data: ");
        scanf("%d", &newnode->data);
        if (head == 0)
        {
            head = temp = newnode;
            head->next = newnode;
        }else{
            temp->next = newnode;
            newnode->next = head;
            temp = newnode;
        }
        printf("Do you want to continue (Enter 0/1): ");
        scanf("%d", &choice);
    }
    
}

void lengthCLL(){
    struct node *temp;
    int count = 0;
    if (head == 0)
    {
        printf("No circular linked list.\n");
    }
    
    temp = head;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    count++;
    printf("length of circular linked list is %d\n", count);
    
}

void reverseCLL(){
    struct node *prev = NULL, *curr = head, *next = NULL;
    int choice;
    if (head == 0)
    {
        printf("create linked list first.\n");
        return;
    }
    if (head == head->next)
    {
        return;
    }
    printf("Linked list reverse started...\n");
    do
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);

    head->next = prev;
    head = prev;
    printf("linked list reversal sucessful.\n");
    printf("Do you want to see the linked list (Enter 0/1): ");
    scanf("%d", &choice);
    if (choice) display();
}

void InsertBeg(){
    struct node *newnode, *temp;
    int choice;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocations faliled.\n");
        return;
    }
    printf("Node insertion at begining started...\n");
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = newnode;
        head->next = newnode;
    }else{
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
    printf("Node insertion successful.\n");
    printf("Do you want to see the linked list (Enter 0/1): ");
    scanf("%d", &choice);
    if (choice)
    {
        display();
    }
    
}

void InsertEnd(){
    struct node *newnode, *temp;
    int choice;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Node insertion at end started...\n");
    printf("Enter node data: ");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = newnode;
        newnode->next = head;
    }else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    printf("Node insertion successful.\n");
    printf("Do you want to see the linked list.\n");
    scanf("%d", &choice);
    if (choice) display();
}

void InsertPos(){
    struct node *newnode, *temp;
    int choice, pos, i = 1;
    printf("Enter the node insertion position: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory Allocation Failed.\n");
        return;
    }
    printf("Node insertion at position %d started...\n",pos);
    printf("Enter node data: ");
    scanf("%d", &newnode->data);
    if (pos == 1)
    {
        newnode->next = head;
        head =newnode;
        temp = head;
        while (temp->next!=head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        return;
    }
    
    temp = head;
    while (i < (pos - 1) && temp->next != head)
    {
        temp = temp->next;
        i++;
    }
    if (i != pos-1)
    {
        printf("Invalid position.\n");
        free(newnode);
        return;
    }
    
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Node Insertion successful.\n");
    printf("Do you want to see linked list.\n");
    scanf("%d", choice);
    if (choice) display();
}

void delBeg(){
    struct node *temp;
    if (head == 0)
    {
        printf("linked list is empty.\n");
        return;
    }
    if (head == head->next)
    {
        free(head);
        head = 0;
        return;
    }
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    free(head);
    head = head->next;
}

void delEnd(){
    struct node *temp;
    if (head == 0)
    {
        printf("linked list is empty.\n");
        return;
    }
    if (head == head->next)
    {
        free(head);
        head = 0;
        return;
    }
    temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = head;
}

void delPos() {
    struct node *temp;
    int pos, i = 1, choice;

    if (head == 0) {
        printf("linked list is empty.\n");
        return;
    }

    printf("Enter position to delete node: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        delBeg();
        return;
    }

    temp = head;
    while (i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    // If position is beyond list length
    if (temp->next == head) {
        printf("Invalid position.\n");
        return;
    }
    printf("node deletion started...\n");

    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
    printf("node deletion sucessful.\n");
    printf("Do you want to see the linked list (Enter 0/1): ");
    scanf("%d", &choice);
    if (choice) display();
}


int main(){
    int choice;

    while (1)
    {
        printf("\n==============================\n");
        printf(" SINGLY CIRCULAR LINKED LIST MENU\n");
        printf("==============================\n");
        printf("1. Create singly circular Linked List\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert at position\n");
        printf("5. Delete from beginning\n");
        printf("6. Delete from end\n");
        printf("7. Delete from position\n");
        printf("8. Reverse doubly linked list\n");
        printf("9. Display list\n");
        printf("10. Length of list\n");
        printf("0. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

            case 1:
                create();
                Sleep(5000);
                system("cls");
                break;
            case 2:
                InsertBeg();
                Sleep(5000);
                system("cls");
                break;

            case 3:
                InsertEnd();
                Sleep(5000);
                system("cls");
                break;

            case 4:
                InsertPos();
                Sleep(5000);
                system("cls");
                break;

            case 5:
                delBeg();
                Sleep(5000);
                system("cls");
                break;

            case 6:
                delEnd();
                Sleep(5000);
                system("cls");
                break;

            case 7:
                delPos();
                Sleep(5000);
                system("cls");
                break;

            case 8:
                reverseCLL();
                Sleep(5000);
                system("cls");
                break;

            case 9:
                display();
                Sleep(5000);
                system("cls");
                break;
            case 10:
                lengthCLL();
                Sleep(5000);
                system("cls");
                break;

            case 0:
                printf("Exiting program...\n");
                printf("Thank you for using this system...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}