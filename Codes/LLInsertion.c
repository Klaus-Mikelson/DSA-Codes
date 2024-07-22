#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void travsel(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertionAtfirst(struct Node *ptr, int data)
{

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->next = ptr;

    return p;
}

void insertionInBetween(struct Node *head, int data, int index)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
}

void insertionAtEnd(struct Node *head, int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}

void insertionAfternode(struct Node *head, struct Node *pre, int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = pre->next;
    pre->next = ptr;
}

void main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 21;
    head->next = second;

    second->data = 71;
    second->next = third;

    third->data = 91;
    third->next = NULL;

    printf("Before Insertion\n");
    travsel(head);
    // head=insertionAtfirst(head,79);
    // insertionInBetween(head,79,2);
    // insertionAtEnd(head,79);
    insertionAfternode(head, second, 79);
    printf("After Insertion\n");
    travsel(head);
}