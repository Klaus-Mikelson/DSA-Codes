#include<stdio.h>

int main(){
    int i,n,j;
    int temp,comp=0,swap=0;
    printf("Enter the no of the elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array\n");
    for ( i = 0; i < n; i++)
    {
        printf("Enter %d element: ",i+1);
        scanf("%d",&arr[i]);
    }
    int flag=0;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n-1-i; j++)
        {
            ++comp;
            if (arr[j]>arr[j+1])
            {
                ++swap,flag=1;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;            }
            
        }
        if (!flag)
        {
            printf("Already sorted\n");
            break;
        }   
    }
    printf("Array: ");
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nNo of comparisons %d\nNo of swaps %d\n",comp,swap);
    
    
}