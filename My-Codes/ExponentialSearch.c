#include <stdio.h>

int binarysearch(int *a, int low, int high, int val)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == val)
        {
            return mid;
        }
        else if (a[mid] < val)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int expotential(int *a, int low, int high, int val)
{
    if (a[low] == val)
    {
        return low;
    }

    int i = 1;
    while (i <= high && a[i] <= val)
    {
        i *= 2;
    }

    return binarysearch(a, i / 2, high, val);
}

int main()
{
    int A[] = {12, 14, 53, 64, 98};
    int n = (sizeof(A) / sizeof(int));
    // printf("%d\n",n);
    int element = expotential(A, 0, n - 1, 12);
    (element != -1) ? printf("Element found at index %d\n", element) : printf("Element not present in array\n");

    return 0;
}