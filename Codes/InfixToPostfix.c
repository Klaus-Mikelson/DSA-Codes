#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct stack
{
    int size;
    int top;
    char *arr;
};

char stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}


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

int precedence(char c){
   if (c=='*'|| c=='/')
   {
    return 3;
   }
   else if (c=='+'||c=='-')
   {
    return 2;
   }
   return 0;    
   
}

int operator(char c){
    if (c=='*'||c=='/'||c=='+'||c=='-')
    {
        return 1;
    }
    return 0;
    
}


char *infixTOpostfix(char *ptr)
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char)); // stack
    char *postfix=(char*)malloc(strlen(ptr)+1*sizeof(char));

    int i=0,j=0;
    while(ptr[i]!='\0')
    {
        if (!operator(ptr[i]))
        {
            postfix[j]=ptr[i];
            i++,j++;
        }
        else{
            if (precedence(ptr[i])>precedence(stackTop(s)))
            {
                push(s,ptr[i]);
                i++;
            }
            else{
                postfix[j]=pop(s);
                j++;
            }
            
        }
        
    }
    while (!isEmpty(s))
    {
        postfix[j]=pop(s);
        j++;
    }
    postfix[j]='\0';
    return postfix;

}

void main()
{
    char *exp = "x-y*z-k*d"; // array expression
    printf("Infix %s\n",exp);
    printf("Postfix %s ",infixTOpostfix(exp));
}