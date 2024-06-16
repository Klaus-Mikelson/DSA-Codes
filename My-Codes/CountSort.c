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

int maxelement(int *a, int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

void countsort(int a[], int max, int n)
{
    int i, j;
    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }
    i = 0;
    j = 0;
    while (j <= max)
    {
        if (count[j] > 0)
        {
            while (count[j] != 0)
            {
                a[i] = j;
                count[j] = count[j] - 1;
                i++;
            }
        }
        j++;
    }
    free(count);
}

void main()
{
    int A[] = {12, 54, 65, 7, 23, 9, 9, 9, 9};
    int n = (sizeof(A)) / sizeof(int);
    int max = maxelement(A, n);
    printArray(A, n); // Printing the array before sorting
    countsort(A, max, n);
    printArray(A, n); // Printing the array before sorting
}