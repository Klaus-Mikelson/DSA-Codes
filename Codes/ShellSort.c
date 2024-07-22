#include <stdio.h>
#include <stdlib.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shellshort(int *a, int n)
{
    int gap, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            for (int i = j - gap; i >= 0; i=i-gap)
            {
                if (a[i + gap] >= a[i])
                {
                    break;
                }
                else
                {
                    swap(&a[i + gap], &a[i]);
                }
            }
        }
    }
}

void main()
{
    int A[] = {23, 29, 15, 19, 31, 7, 9, 5, 2};
    int n = (sizeof(A) / sizeof(int));
    printArray(A, n);
    shellshort(A, n);
    printArray(A, n);
}