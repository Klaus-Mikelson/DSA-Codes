#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void travsel(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertionAtStart(struct Node *head,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    while (p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;  
}

struct Node *insertionAtEnd(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *q=head->next;
    while (q->next!=head)
    {
        q=q->next;
    }
    q->next=ptr;
    ptr->next=head;

    return head;

}

void insertionAfternode(struct Node *head, struct Node *pre, int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = pre->next;
    pre->next = ptr;
}

void insertionAtIndex(struct Node *head, int data, int index)
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
    third->next = head;

    printf("Before Insetion\n");
    travsel(head);
    // head=insertionAtStart(head,79);
    // head=insertionAtEnd(head,79);
    // insertionAtIndex(head,79,2);
    insertionAfternode(head,head,79);
    printf("After Insertion\n");
    travsel(head);
}
