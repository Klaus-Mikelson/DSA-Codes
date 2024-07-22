#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *head)
{
    if (head == NULL)
    {
        printf("Stack is Empty\n");
        return 1;
    }
    return 0;
}

int isFull(struct Node *n)
{
    if (n == NULL)
    {
        printf("Stack is Full\n");
        return 1;
    }
    return 0;
}

struct Node *push(struct Node *head, int data)
{
    if (isFull(head))
    {
        return head;
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = data;

        n->next = head;
        head = n;

        return head;
    }
}

int pop(struct Node **head){
    if (isEmpty(*head))
    {
        return 0;
    }
    struct Node *n=*head;
    *head=(*head)->next;
    int val=n->data;
    free(n);
    return val; 
}


void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head = push(head, 67);
    head = push(head, 85);
    head = push(head, 90);

    printf("Head data before pop\n");
    printf("%d\n",head->data);
    printf("Element Delete %d\n",pop(&head));
    printf("Head data after pop\n");
    printf("%d\n",head->data);

}