#include<stdio.h>


void printArray(int *a,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    
}

int partition(int a[],int low,int high){
    int key=a[low],temp;
    int i=low+1;//index
    int j=high;//index

    do
    {
        while (a[i]<=key)
        {
            i++;
        }
        while (a[j]>key)
        {
            j--;
        }
        if (i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        
               
    } while (i<j);

    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
    
}

void quicksort(int a[],int low, int high){
    int partitionindex;
    if (low<high)
    {
    partitionindex=partition(a,low,high);
    quicksort(a,low,partitionindex-1);
    quicksort(a,partitionindex+1,high);
    }
    
}

void main(){
    int A[] = {12, 54, 65, 7, 23, 9};
    int n =(sizeof(A))/sizeof(int);
    printArray(A, n); // Printing the array before sorting
    quicksort(A,0,n-1);
    printArray(A, n); // Printing the array before sorting
}

