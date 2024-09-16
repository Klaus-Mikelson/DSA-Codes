#include <stdio.h>


int push(int n , int stack[],int top){
    if (top==9)
    {
        return top;
    }
    while (n != 0) {
        stack[++top]=n%10;
        n /= 10;
    }
    return top;
}
    
int pop(int stack[],int top){
    if (top==-1)
    {
        return top;
    }
    int i=0;
    while (i<=top)
    {
        printf("%d",stack[i++]);

    }
    return top;
       
}

int main(){
    int n;
    printf("Enter the number ");
    scanf("%d",&n);
    int stack[10];
    int top=-1;
    top=push(n,stack,top);
    printf("Reversed Order\n");
    top=pop(stack,top);
    
    return 0;
}