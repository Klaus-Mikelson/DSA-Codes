#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack is Full\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty\n");
        return 0;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int i)
{
    int arrayindex = ptr->top - i + 1;
    if (arrayindex < 0)
    {
        printf("Not a Valid postion of stack\n");
        return -1;
    }
    return ptr->arr[arrayindex];
}

void main()
{
    struct stack *s;
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s, 5); // 1
    push(s, 8); // 2
    push(s, 6); // 3
    push(s, 2); // 4
    push(s, 3); // 5
    push(s, 9); // 6
    // push(s, 7); // stack is full

    // printf("Pooped %d from stack\n",pop(s));
    // printf("Pooped %d from stack\n",pop(s));
    // printf("Pooped %d from stack\n",pop(s));
    printf("Element at %d position of stack is %d\n", 3, peek(s, 3));

    free(s->arr);
}