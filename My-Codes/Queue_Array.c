#include <stdio.h>
#include<stdlib.h>


struct queue{
    int size;
    int front;
    int back;
    int *arr;
};

int rearelement(struct queue *l){
    return l->arr[l->back];
}

int firstelement(struct queue *l){
    return l->arr[l->front+1];
}

int isEmpty(struct queue *l){
    if (l->front==l->back)
    {
        return 1;
    }
    return 0;
    
}

int isFull(struct queue *l){
    if (l->back==l->size-1)
    {
        return 1;
    }
    return 0;
    
}

void push(struct queue *l,int data){
    if (isFull(l))
    {
        printf("Queue is full\n");
    }
    else{
        l->back++;
        l->arr[l->back]=data;
    }   
}

int pop(struct queue *l){
    if (isEmpty(l))
    {
        printf("Queue is empty\n");
    return 0;
    }
    else{
        l->front++;
        int val=l->arr[l->front];
        return val;          
    } 
}

void main(){
    struct queue *q;
    q->size=10;
    q->front=q->back=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));

    printf("Pusing elements in queue\n");
    push(q,13);
    push(q,23);
    push(q,33);
    push(q,43);
    
    printf("Rear element of queue %d\n",rearelement(q));

    printf("First element of queue %d\n",firstelement(q));
    printf("Poping element of queue %d\n",pop(q));

    printf("First element of queue %d\n",firstelement(q));

    
}