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

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int b[100];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++, i++;
        }
        else
        {
            b[k] = a[j];
            j++, k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++, k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++, k++;
    }
    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = (sizeof(A)) / sizeof(int);
    printArray(A, n); // Printing the array before sorting
    mergesort(A, 0, n - 1);
    printArray(A, n); // Printing the array before sorting
}
