#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*tail = 0;
void display(){
    struct node *head;
    if (tail == 0)
    {
        printf("no linked list to display.\n");
        return;
    }
    head = tail->next;
    while (head->next != tail->next)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("%d <-> First Node.\n", head->data);
    
}

void create(){
    struct node *newnode;
    int choice = 1;
    if (tail != 0)
    {
        printf("Linked list already created.\n");
        return;
    }
    
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter node data: ");
        scanf("%d", &newnode->data);
        if (tail == 0)
        {
            tail = newnode;
            tail->next = newnode;
            tail->prev = newnode;
        }else
        {
            newnode->prev = tail;
            newnode->next = tail->next;
            tail->next->prev = newnode;
            tail->next = newnode;
            tail = newnode;
        }
        printf("Do you want to continue insertion (Enter 0/1) :");
        scanf("%d", &choice);
    }
    printf("Do you want to see linked list (Enter 0/1): ");
    scanf("%d", &choice);
    if (choice)
    {
        display();
    }
    
}

void reverseDCLL(){
    struct node *curr , *next;
    if (tail == 0)
    {
        printf("no linked list to reverse.\n");
        return;
    }
    if (tail == tail->next)
    {
        return;
    }
    curr = tail->next;
    do
    {
        next = curr->next;
        curr->next = curr->prev;
        curr->prev = next;
        curr = next;
    } while (curr != tail->next);
    tail = curr;
    printf("Reverse successfull.\n");
}

void InsertBeg(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter node data: ");
    scanf("%d", &newnode->data);
    if (tail == 0)
    {
        tail = newnode;
        newnode->prev = newnode;
        newnode->next = newnode;
        return;
    }
    newnode->next = tail->next;
    newnode->prev = tail;
    tail->next->prev = newnode;
    tail->next = newnode;
    printf("NOde insert at beggining.\n");
}

void InsertEnd(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter node data: ");
    scanf("%d", &newnode->data);

    if (tail == 0)
    {
        tail = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
        return;
    }

    newnode->prev = tail;
    newnode->next = tail->next;
    tail->next->prev = newnode;
    tail->next = newnode;
    tail = newnode;
    printf("Node insertion at end successfull.\n");
}

void InsertPos(){
    int pos, i = 1;
    struct node *newnode, *temp;

    if (tail == 0)
    {
        printf("linked list is empty first create a linked list.\n");
        return;
    }
    
    printf("Enter position to indert node: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("You enter a invalid position.\n");
        return;
    }
    if (pos == 1)
    {
        InsertBeg();
        return;
    }
    temp = tail->next;
    while (i < pos-1 && temp != tail)
    {
        temp = temp->next;
        i++;
    }
    if (i != pos-1)
    {
        printf("YOu enter a invalid position.\n");
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter node data:");
    scanf("%d", &newnode->data);

    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    
    if (temp == tail)
    {
        tail = newnode;
    }
    printf("Node inserted at position %d is successfull.\n", pos);
}

void delBeg(){
    struct node *temp;
    if (tail == 0)
    {
        printf("no node to delete.\n");
        return;
    }
    if (tail == tail->next)
    {
        free(tail);
        tail = 0;
        printf("Node deleted. List is now empty.\n");
        return;
    }
    temp = tail->next;
    temp->next->prev = tail;
    tail->next = temp->next;
    free(temp);
    printf("node deleted from beggininng.\n");
}

void delEnd(){
    struct node *temp;
    if (tail == 0)
    {
        printf("No node to delete.\n");
        return;
    }
    if (tail == tail->next)
    {
        free(tail);
        tail = 0;
        printf("NOde deleted successfull. now list is empty.\n");
        return;
    }
    
    temp = tail;
    tail = temp->prev;
    tail->next = temp->next;
    temp->next->prev = tail;
    free(temp);

    printf("node deleted from end.\n");
}

void delPos(){
    struct node *temp;
    int pos, i = 1;
    if (tail == 0)
    {
        printf("list is empty.\n");
        return;
    }
    printf("Enter position to delete node: ");
    scanf("%d", &pos);
    if (pos<1)
    {
        printf("Invalid position.\n");
        return;
    }
    if (tail == tail->next)
    {
        if (pos == 1)
        {
            free(tail);
            tail = NULL;
            printf("Node deleted. List is now empty.\n");
        }
        else
        {
            printf("Invalid position.\n");
        }
        return;
    }
    if (pos == 1)
    {
        delBeg();
        return;
    }
    temp = tail->next;
    while (i<pos && temp != tail)
    {
        temp = temp->next;
        i++;
    }
    if (i != pos)
    {
        printf("Invaid position.\n");
        return;
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    
    if (temp == tail)
    {
        tail = temp->prev;
    }
    free(temp);
    printf("Node deleted successfull.\n");
}

void lengthDCLL(){
    struct node *temp;
    int length = 0;

    if (tail == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = tail->next;

    do
    {
        length++;
        temp = temp->next;
    } while (temp != tail->next);

    printf("List length is %d\n", length);
}

int main(){
    int choice;

    while (1)
    {
        printf("\n==============================\n");
        printf(" DOUBLy CIRCULAR LINKED LIST MENU\n");
        printf("==============================\n");
        printf("1. Create doubly circular Linked List\n");
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
                reverseDCLL();
                Sleep(5000);
                system("cls");
                break;

            case 9:
                display();
                Sleep(5000);
                system("cls");
                break;
            case 10:
                lengthDCLL();
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