#include<stdio.h>
#define max 10

int push(char stack[],char c,int top){
    if(top==max-1){
        return top;
    }
    stack[++top]=c;
    return top;
}


int pop(char stack[],int top)
{
    if(top==-1){
        return top;
    }
    --top;
    return top;
}

int para(char *para){
    char stack[max];
    int top=-1;

    for (int i = 0; para[i]!='\0'; i++)
    {
        if (para[i]=='{' ||para[i]=='('||para[i]=='[')
        {
            top=push(stack,para[i],top);
        }
        else if(para[i]=='}'||para[i]==')'||para[i]==']'){
            if(top==-1){
                return 0;
            }
            top=pop(stack,top);
        }
        
    }
    if(top==-1){
        return 1;
    }else{return 0;}
       
}



int main(){
    char *exp="[({)]";

    if (para(exp))
    {
        printf("Expression is Balanced");
    }else{
        printf("Expression is not Balanced");
    }
    
}