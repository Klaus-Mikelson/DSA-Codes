#include <stdio.h>
#include<string.h>

int push(char s[] , char stack[],int top){
    if (top==strlen(s)-1)
    {
        return top;
    }
    int i=0;
    while (s[i]!='\0')
    {
        stack[++top]=s[i++];
    }

    return top;  
}

int pop(char stack[],int top){
    if (top==-1)
    {
        return top;
    }
    while (top!=-1)
    {
        printf("%c",stack[top--]);

    }
    return top;
       
}

int main(){
    char s[]="SBJITMR";
    char stack[strlen(s)+1];
    int top=-1;
    top=push(s,stack,top);
    printf("Reversed String\n");
    top=pop(stack,top);
    
    return 0;
}