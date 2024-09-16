#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *temp = NULL;

void createNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter Data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL)
    {
        head = temp = newNode;
    }
    else
    {
        temp->next = newNode;
        temp = newNode;
    }
}

void display()
{
    temp = head;
    while (temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d->NULL\n", temp->data);
}

void reverse()
{
    Node *current = head;
    Node *prevNode = NULL, *nextNode = NULL;

    while (current != NULL)
    {
        nextNode = current->next;  // Save the next node
        current->next = prevNode;  // Reverse the current node's pointer
        prevNode = current;        // Move prevNode to the current node
        current = nextNode;        // Move to the next node
    }

    head = prevNode;  

    display();
}


int main()
{
    printf("\nMenu\n");
    printf("1)Create Node\n");
    printf("3)Display the list\n");
    printf("4)Reverse the list\n");
    printf("5)Exit\n");
    int choice;
    do
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createNode();
            break;
        case 3:
            display();
            break;
        case 4:
            reverse();
            break;
        }
    } while (choice != 5);

    return 0;
}