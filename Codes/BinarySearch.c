#include <stdio.h>

int binary(int [],int,int);

void main(){
    int arr[]={1,23,36,42,56,78};
    int size=(sizeof(arr))/(sizeof(int));
    int element=4;
    int index=binary(arr,size,element);
    (index!=-1)?printf("Element found at %d index\n",index):printf("Element not found.\n");

}

int binary(int arr[],int size,int element){
    int low,mid,high; //index values
    low=0;
    high=size-1;
    while (low<=high)
    {
    mid=(low+high)/2;
        if (arr[mid]==element)
        {
            return mid;
        }
        if(arr[mid]<element){
            low=mid+1;
        }
        else{high=mid-1;}
        
    }
    return -1;
    
}