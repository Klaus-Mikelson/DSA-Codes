#include<stdio.h>
#include<stdlib.h>


void find(int* a,int n){
    //hasmap is a collection of (key,value) pair
    int *hashmap=(int*)calloc(10,sizeof(int));

    for (int i = 0; i < n; i++)
    {
        hashmap[a[i]]++;
    }

    printf("Non-Repeating Elements\n");
    for (int i = 0; i < n; i++)
    {
        if (hashmap[a[i]]==1)
        {
            printf("%d ",a[i]);
        }
        
    }
    free(hashmap);
    
    
}

int main()
{
    int A[]={5,2,2,6,4,1,9,1};
    int n=(sizeof(A))/sizeof(int);
    find(A,n); 
    return 0;
}