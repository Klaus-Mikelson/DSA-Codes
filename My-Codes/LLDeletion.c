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

struct Node *deletionAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deletionAtIndex(struct Node *head,int index)
{
    struct Node *ptr = head;
    struct Node *q=head->next;
    int i=0;
    while (i!=index-1)
    {
        ptr=ptr->next;
        q=q->next;
        i++;
    }
    ptr->next=q->next;
    free(q);    
    return head;
}

struct Node *deletionAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q=head->next;
    while (q->next!=NULL)
    {
        ptr=ptr->next;
        q=q->next;
    }
    ptr->next=NULL;
    free(q);
    
    return head;
}

struct Node *deletionAtValue(struct Node *head,int value){
    struct Node *ptr=head;
    struct Node *q=head->next;
    while (q->data!=value && q->next!=NULL)
    {
        ptr=ptr->next;
        q=q->next;
    }
    if (q->data==value)
    {
        ptr->next=q->next;
        free(q);
    }
    
    return head;
    
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

    printf("before deletion\n");
    travsel(head);
    // head=deletionAtFirst(head);
    // head=deletionAtIndex(head,1);
    // head=deletionAtEnd(head);
    head=deletionAtValue(head,91);
    printf("after deletion\n");
    travsel(head);
}