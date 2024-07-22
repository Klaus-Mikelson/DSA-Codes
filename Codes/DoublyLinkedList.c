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

void reversetravsel(struct Node *ptr){
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    while (ptr!=NULL)
    {
        printf("Element is %d\n",ptr->data);
        ptr=ptr->prev;
    }    
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

    printf("Forward list\n");
    travsel(head);
    printf("Backward List\n");
    reversetravsel(head);


}


