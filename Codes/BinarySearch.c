#include <stdio.h>

int binary(int [],int,int);

void main(){
    int i,n,key;
    printf("Enter the no of elements ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Element to search ");
    scanf("%d",&key);
    int index=binary(arr,n,key);
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