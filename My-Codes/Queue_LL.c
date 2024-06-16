#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void travsel(struct node *ptr){
    while (ptr!=NULL)
    {
        printf("Element %d\n",ptr->data);
        ptr=ptr->next;
    }
    
}
int lastelement()
{
    return r->data;
}

int firstelement()
{
    return f->data;
}
int isFull(struct node *n)
{
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (f == NULL)
    {
        return 1;
    }
    return 0;
}

void push(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (isFull(n))
    {
        printf("Queue is Full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int pop()
{
    if (isEmpty(f))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    else
    {
        struct node *ptr = f;
        f = f->next;
        int val = ptr->data;
        free(ptr);
        return val;
    }
}

void main()
{
    printf("pushing elements\n");
    push( 11);
    push(12);
    push(13);
    push( 14);
    push( 15);
    push( 16);
    travsel(f);
    // printf("Last element %d\n",lastelement());
    printf("first element is %d\n",firstelement());
    pop();
    travsel(f);
    printf("After popping first element is %d\n",firstelement());
}