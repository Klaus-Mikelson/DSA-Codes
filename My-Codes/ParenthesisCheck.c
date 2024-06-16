#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
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
void push(struct stack *ptr, char value)
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
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int paramaching(char *ptr)
{
    struct stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char)); // stack

    for (int i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] == '(')
        {
            push(s, '(');
        }
        else if (ptr[i] == ')')
        {
            if (isEmpty(s)) // if true then expression is not balanced
            {
                return 0;
            }
            pop(s);
        }
    }
    if (isEmpty(s)) // if false then expression is not balanced
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    char *exp = "((8*(9+1)))"; // array expression

    if (paramaching(exp))
    {
        printf("Expression is Balanced");
    }
    else
    {
        printf("Expression is not Balanced");
    }
}