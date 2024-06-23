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

void radixsort(int *arr, int n, int pos)
{
    int count[10] = {0};
    int b[n];
    for (int i = 0; i < n; i++)
    {
        ++count[(arr[i] / pos) % 10];
    }
    for (int i = 0; i < 9; i++)
    {
        count[i + 1] = count[i + 1] + count[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        b[--count[(arr[i] / pos) % 10]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = b[i];
    }
}

void main()
{
    int A[] = {432, 8, 530, 90, 88, 231, 11, 45, 677, 199};
    int n = (sizeof(A)) / sizeof(int);
    int max = maxelement(A, n);
    printArray(A, n); // Printing the array before sorting
    for (int post = 1; max / post > 0; post *= 10)
    {
        radixsort(A, n, post);
    }
    printArray(A, n); // Printing the array before sorting
}