#include<stdio.h>


void display(int arr[],int size){
    printf("Array ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}

void deletion(int arr[],int size,int index){
    for (int i = index; i <size-1 ; i++)
    {
        arr[i]=arr[i+1];
    }
        
}


void main(){
    int arr[10]={4,23,56,123};
    int size=4,index=2;
    display(arr,size);
    deletion(arr,size,index);
    size--;
    display(arr,size);
}