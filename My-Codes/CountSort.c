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

void countsort(int *a, int n, int max)
{
    int count[max+1];
    int b[n], i;
    for (i = 0; i <= max; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        ++count[a[i]];
    }
    for (i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        b[--count[a[i]]] = a[i];
    }
    for (i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

void main()
{
    int A[] = {1, 5, 6, 7, 2, 9};
    int n = (sizeof(A)) / sizeof(int);
    int max = maxelement(A, n);
    printArray(A, n); // Printing the array before sorting
    countsort(A, n, max);
    printArray(A, n); // Printing the array before sorting
}