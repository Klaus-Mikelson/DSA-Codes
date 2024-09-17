#include <stdio.h>


int peek(int arr[],int n,int low,int high){
    int mid=(low+high)/2;
    
    if((mid==0 || arr[mid]>=arr[mid-1]) && (mid==n-1 || arr[mid]>=arr[mid+1])){

        return mid;
    }  

    if(mid>0 && arr[mid]<arr[mid-1]){
        return(arr,n,low,mid-1);      //searching in left half
    }else{
        return(arr,n,mid+1,high);
    }
}


void main(){
    int i,n,key;
    printf("Enter the no of elements ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int index=peek(arr,n,0,n-1);
    printf("Peek element is %d\n",arr[index]);

}