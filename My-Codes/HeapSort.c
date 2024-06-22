#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void maxheap(int *ptr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && ptr[left] > ptr[largest]) {
        largest = left;
    }
    if (right < n && ptr[right] > ptr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(&ptr[largest], &ptr[i]);
        maxheap(ptr, n, largest);
    }
}

void heapsort(int *ptr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxheap(ptr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&ptr[0], &ptr[i]);
        maxheap(ptr, i, 0);
    }
}

void display(int *ptr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

int main() {

/*           15
            /  \
           5    20
          / \   / \ 
         1  17 10 30
*/


    int arr[] = {15, 5, 20, 1, 17, 10, 30};
    int n = sizeof(arr) / sizeof(int);
    heapsort(arr, n); //max heap sort gives array in ascending order
    display(arr, n);
    return 0;
}
