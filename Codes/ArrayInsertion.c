#include<stdio.h>


void display(int arr[],int size){
    printf("Array ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}

void insertion(int arr[],int size,int element,int index){
    for (int i = size-1; i >=index ; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
        
}


void main(){
    int arr[10]={4,23,56,123};
    int size=4,element=45,index=2;
    display(arr,size);
    insertion(arr,size,element,index);
    size++;
    display(arr,size);
}