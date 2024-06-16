#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};


void travsel(struct Node *ptr){
    while (ptr!=NULL)
    {
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    }
         
}

struct Node *insertionAtStart(struct Node *head,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;

    ptr->prev=p->prev;
    ptr->next=p;
    head=ptr;

    return head;
}
struct Node *insertionAtEnd(struct Node *head,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;

    struct Node *p=head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    ptr->prev=p;
    ptr->next=p->next;
    p->next=ptr;

    return head;
}

void insertionAfternode(struct Node *head, struct Node *pre, int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->prev=pre;
    ptr->next=pre->next;
    pre->next=ptr;
}


void main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    head->prev=NULL;
    head->data=21;
    head->next=second;

    second->prev=head;
    second->data=71;
    second->next=third;

    third->prev=second;
    third->data=91;
    third->next=NULL;

    printf("Before Insertion\n");
    travsel(head);
    // head=insertionAtStart(head,79);
    // head=insertionAtEnd(head,79);
    insertionAfternode(head,second,79);
    printf("After Insertion\n");
    travsel(head);


}


