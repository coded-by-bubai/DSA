#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = 0;

void display(){
    if (head == 0)
    {
        printf("LinkedList is Empty.\n");
        return;
    }
    
    struct node *temp = head;
    while (temp != 0)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Null\n");
    
}

void create(){
    if (head != 0)
    {
        printf("LinkedList Is Already Created.\n");
        return;
    }
    printf("start creating a linked list\n");
    int choice = 1;
    struct node *newnode, *temp;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter node data: ");
        scanf("%d",&newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = newnode;
        }else{
            temp = head;
            while (temp->next != 0)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        printf("Do you want to continue:(Enter 0/1): ");
        scanf("%d",&choice);
    }
    printf("LInkedLIst Creation Successfull.\n");
    printf("Do you want to see LinkedList:(Enter 0/1): ");
    scanf("%d",&choice);
    if (choice)
    {
        display();
    }
}

void linkedlist_length(){
    struct node *temp = head;
    int count = 0;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    printf("LinkedList length is %d.\n",count);
    
}

void reverseLinkedlist(){
    if (head == 0)
    {
        printf("Create a LinkedList first.\n");
        return;
    }
    struct node *prev = 0, *curr = head, *next;
    int choice;
    while (curr != 0)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    
    printf("LinkedList Reverse successfull.\nDo you want to see the LinkedList (Enter 0/1).: ");
    scanf("%d",&choice);
    if (choice)
    {
        display();
    }
    
}

void insertAtBeg(){
    int choice;
    struct node *newnode;
    printf("Node insertion at beginning started.\n");
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    printf("Node insert at beginning successfull.\n");
    printf("Do you want to see linkedlist (Enter 0/1): ");
    scanf("%d",&choice);
    if (choice) {
        display();
    }
}

void insertAtEnd(){
    int choice;
    struct node *newnode, *temp;
    printf("Node insert at end started.\n");
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (head == 0)
    {
        head = newnode;
    }else
    {
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    
    printf("Node insert at end successfull.\n");
    printf("Do you want to see linkedlist (Enter 0/1): ");
    scanf("%d",&choice);
    if (choice) {
        display();
    }
}

void insertAtPos(){
    if (head == 0)
    {
        printf("Create LinkedList First.\n");
        return;
    }
    
    int pos, choice;
    printf("Insertion started at position %d.\n",pos);
    printf("Enter Position: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid Position.\nEnter a valid position.\n");
        return;
    }
    
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
        printf("Insertion successfull at position %d.\n",pos);
        return;
    }

    temp = head;
    for (int i = 1; i < pos-1; i++)
    {
        if (temp == 0)
        {
            printf("Position is out of range.\n");
            free(newnode);
            return;
        }
        
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Insertion successfull at position %d.\n",pos);
    printf("Do you want see LinkedList (Enter 0/1). : ");
    scanf("%d", &choice);
    if (choice){
        display();
    }
}

void deleteBeg(){
    struct node *temp;
    int choice;
    if (head == 0)
    {
        printf("No node to delete.\n");
        return;
    }
    printf("Node deletion started.\n");
    temp = head;
    head = head->next;
    free(temp);
    printf("Node deletion successful.\n");
    printf("Do you want to see LinkedList.(Enter 0/1): ");
    scanf("%d",&choice);
    if (choice)
    {
        display();
    }
    
}

void deleteEnd(){
    struct node *temp,*prev;
    int choice;
    if (head == 0)
    {
        printf("No node to delete.");
        return;
    }
    printf("Node deletion started.\n");
    temp = head;
    while (temp->next != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = 0;
    }
    else
    {
        prev->next = 0;
    }
    free(temp);
    printf("Node deletion successful.\n");
    printf("Do you want to see LinkedList.(Enter 0/1): ");
    scanf("%d",&choice);
    if (choice)
    {
        display();
    }
   
}

void deletePos(){
    struct node *temp, *next;
    int choice, pos, i=1;
    if (head == 0)
    {
        printf("No node to delete.");
        return;
    }
    printf("Enter position to delete node: ");
    scanf("%d",&pos);
    if (pos < 1)
    {
        printf("Enter a valid position to delete node.");
        return;
    }
    
    printf("Node deletion started.\n");
    temp = head;
    if (pos == 1)
    {
        head = head->next;
        free(temp);
    }else
    {
        while (i < pos - 1 && temp->next != 0)
        {
            temp = temp->next;
            i++;
        }
        next = temp->next;
        if (next == 0)
        {
            printf("position is out of range.\n");
            return;
        }
        temp->next = next->next;
        free(next);

    }
    printf("Node deletion successful.\n");
    printf("Do you want to see LinkedList.(Enter 0/1): ");
    scanf("%d",&choice);
    if (choice)
    {
        display();
    }
        
}


int main(){
    int choice;
    while (1)
    {
        printf("1.Create Singly Linked List \n2.Display Linked List \n3.Insert at Beginning \n4.Insert at End \n5.Insert at Specific Position \n6.Delete at Beginning \n7.Delete at End \n8.Delete at Specific Position \n9.Reverse Linked List \n10.Show Length \n11.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            create();
            Sleep(5000);
            system("cls");
            break;
        case 2:
            system("cls");
            display();
            break;
        case 3:
            insertAtBeg();
            Sleep(5000);
            system("cls");
            break;
        case 4:
            insertAtEnd();
            Sleep(5000);
            system("cls");
            break;
        case 5:
            insertAtPos();
            Sleep(5000);
            system("cls");
            break;
        case 6:
            deleteBeg();
            Sleep(5000);
            system("cls");
            break;
        case 7:
            deleteEnd();
            Sleep(5000);
            system("cls");
            break;
        case 8:
            deletePos();
            Sleep(5000);
            system("cls");
            break;
        case 9:
            reverseLinkedlist();
            Sleep(5000);
            system("cls");
            break;
        case 10:
            system("cls");
            linkedlist_length();
            break;
        case 11:
            system("cls");
            printf("Thank you for using my system.");
            exit(0);
            break;
        default:
            printf("Invalid choice.");
            break;
        }
    }
    return 0;
}