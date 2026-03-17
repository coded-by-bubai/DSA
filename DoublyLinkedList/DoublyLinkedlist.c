#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
} *tail = 0, *head = 0;

void lengthDLL(){
    int count = 0;
    struct node *temp = head;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    printf("Length of doubly linkedlist is %d\n",count);
}

void display(){
    struct node *temp = head;
    while (temp != 0)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("Null\n");
    
}

void create(){
    struct node *newnode;
    int choice = 1;
    if (head != 0)
    {
        printf("Linked list is already created.");
        return;
    }
    
    printf("Doubly limkedlist creation started.\n");
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        printf("enter node data: ");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;
        if (head == 0)
        {
            tail = head = newnode;
        }else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("Do you want to continue insertion (Enter 0/1): ");
        scanf("%d",&choice);
    }
    printf("Doubly linked list creation successful.\n");
    printf("Do you want to see created doubly linked list (Enter 0/1): ");
    scanf("%d",&choice);
    if (choice)
    {
        display();
    }
    
}

void InsertBeg(){
    struct node *newnode;
    int choice;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Node insertion at begining started...\n");
    printf("Enter node data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->prev = 0;
    if (head == 0)
    {
        head = tail = newnode;
    }
    else{
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
    printf("Node insertion at begining successful.\n");
    printf("Do you want to see DLL (Enter 0/1): ");
    scanf("%d", &choice);
    if (choice) display();
}

void InsertEnd(){
    struct node *newnode;
    int choice;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Node insertion at end started...\n");
    printf("Enter node data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (head == 0)
    {
        newnode->prev = 0;
        head = tail = newnode;
    }else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    printf("Node insertion at end successful.\n");
    printf("Do you want to see DLL (Enter 0/1): ");
    scanf("%d", &choice);
    if (choice) display();
}

void InsertPos(){
    struct node *newnode, *temp = head;
    int pos, choice, i = 1;
    printf("Enter Insert node position: ");
    scanf("%d",&pos);
    if (pos<1)
    {
        printf("Invalid positions.\n");
        return;
    }
    if (pos == 1)   InsertBeg();
    else
    {
        while (i < pos -1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        if(temp == 0){
            printf("invalid position.\n");
            return;
        }
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter node data: ");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newnode;
        else
            tail = newnode; //end

        temp->next = newnode;
        
    }
    printf("Do you want to see DLL (Enter 0/1): ");
    scanf("%d", &choice);
    if (choice) display();
}

void delBeg(){
    struct node *temp;
    int choice;
    if (head == 0)
    {
        printf("Doubly linked list is empty.");
        return;
    }
    printf("node deletion at begining started...\n");
    temp = head;
    if (head == tail)
    {
        head = 0;
        tail = 0;
    }else{
        head = head->next;
        head->prev = 0;
    }
    free(temp);
    printf("node deletion at beginning successful.\n");
    printf("do you want to see linked list (enter 0\1): ");
    scanf("%d", &choice);
    if (choice) display();
    
}

void delEnd(){
    struct node *temp;
    int choice;
    if (head == 0)
    {
        printf("no node to delete.\n");
        return;
    }
    printf("node deletion at end started...\n");
    temp = tail;
    if (head == tail)
    {
        tail = head = 0;
    }
    else
    {
        tail = tail->prev;
        tail->next = 0;
    }
    free(temp);
    printf("node deletion at end successful.\n");
    printf("do you want to see linked list (enter 0\1): ");
    scanf("%d", &choice);
    if (choice) display();
}

void delPos(){
    struct node *temp;
    int pos, i = 1, choice;
    if (head == 0)
    {
        printf("no node to delete.\n");
        return;
    }
    printf("Enter node position to delete:");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    printf("node deletion at position %d started...\n", pos);
    if (pos == 1)
    {
        delBeg();
        return;
    }

    temp = head;
    while ( temp != 0 && i < pos)
    {
        temp = temp->next;
        i++;
    }
    if (temp == 0)
    {
        printf("Invalid position.\n");
        return;
    }
    if (temp == tail)
    {
        tail = tail->prev;
        tail->next = 0;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("node deletion at position %d successful.\n", pos);
    printf("do you want to see linked list (enter 0\1): ");
    scanf("%d", &choice);
    if (choice) display();
}

void reverseDLL(){
    struct node *currnode, *nextnode;
    int choice;
    if (head == 0)
    {
        printf("create a doubly linked list first.\n");
        return;
    }
    
    printf("Doubly linked list reversal started...\n");
    currnode = head;
    while (currnode != 0)
    {
        nextnode = currnode->next;
        currnode->next = currnode->prev;
        currnode->prev = nextnode;
        currnode =nextnode;
    }
    currnode = head;
    head = tail;
    tail = currnode;

    printf("Doubly linked list reversal successful.\n");
    printf("do you want to see linked list (enter 0/1): ");
    scanf("%d", &choice);
    if (choice) display();
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n==============================\n");
        printf(" DOUBLY LINKED LIST MENU\n");
        printf("==============================\n");
        printf("1. Create Doubly Linked List\n");
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
                reverseDLL();
                Sleep(5000);
                system("cls");
                break;

            case 9:
                display();
                Sleep(5000);
                system("cls");
                break;
            case 10:
                lengthDLL();
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
