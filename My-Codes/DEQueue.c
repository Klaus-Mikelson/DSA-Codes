#include <stdio.h>
#include <stdlib.h>

void enquefront(int *ptr, int x, int *f, int *r)
{
    int n = 6;
    if ((*f == 0 && *r == n - 1) || (*f == *r + 1))
    {
        printf("Queue is full\n");
    }
    else if (*f == -1 && *r == -1)
    {
        (*f)++, (*r)++;
        ptr[*f] = x;
    }
    else if (*f == 0)
    {
        *f = n - 1;
        ptr[*f] = x;
    }
    else
    {
        (*f)--;
        ptr[*f] = x;
    }
}

void enquerear(int *ptr, int x, int *f, int *r)
{
    int n = 6;
    if ((*f == 0 && *r == n - 1) || (*f == *r + 1))
    {
        printf("Queue is full\n");
    }
    else if (*f == -1 && *r == -1)
    {
        (*f)++, (*r)++;
        ptr[*r] = x;
    }
    else if (*r == n - 1)
    {
        *r = 0;
        ptr[*r] = x;
    }
    else
    {
        (*r)++;
        ptr[*r] = x;
    }
}

void display(int *ptr, int *f, int *r)
{
    int i = *f;
    int n = 6;
    if (*f == -1 && *r == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    while (i != *r)
    {
        printf("%d ", ptr[i]);
        i = (i + 1) % n;
    }
    printf("%d\n", ptr[*r]);
}

int main()
{
    int arr[6];
    int f = -1, r = -1;
    printf("Pushing elements in queue\n");
    enquefront(arr, 2, &f, &r);
    enquefront(arr, 5, &f, &r);
    enquerear(arr, -1, &f, &r);
    enquerear(arr, 0, &f, &r);
    enquefront(arr, 7, &f, &r);
    enquefront(arr, 4, &f, &r);
    enquefront(arr, 9, &f, &r);
    display(arr, &f, &r);
    return 0;
}
