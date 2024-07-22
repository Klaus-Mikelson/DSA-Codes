#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;

};


void travsel(struct Node *ptr){
    while (ptr!=NULL)
    {
        printf("Element %d\n",ptr->data);
        ptr=ptr->next;
    }
    
}

void main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    head->data=21;
    head->next=second;

    second->data=71;
    second->next=third;

    third->data=91;
    third->next=NULL;

    travsel(head);


}


