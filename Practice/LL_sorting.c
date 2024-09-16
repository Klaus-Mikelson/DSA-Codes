#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *temp=NULL;


// Function to split a linked list into two halves
void splitList(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    struct Node* fast;
    struct Node* slow;
    
    if (source == NULL || source->next == NULL) {
        *frontRef = source;
        *backRef = NULL;
    } else {
        //using fast and slow pointer technique to find the middle
        slow = source;
        fast = source->next;

        // Fast pointer moves 2 steps, slow pointer moves 1 step
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;  //ends the first list(frontRef)
    }
}

// Function to merge two sorted linked lists
struct Node* sortedMerge(struct Node* a, struct Node* b) {
    struct Node* result = NULL;

    // Base cases
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    // Pick either a or b and recursively merge them
    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

// Function to perform merge sort on a linked list
void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;

    // Base case: length 0 or 1
    if (head == NULL || head->next == NULL)
        return;

    // Split the list into two halves
    splitList(head, &a, &b);

    // Recursively sort the two halves
    mergeSort(&a);
    mergeSort(&b);

    // Merge the sorted halves
    *headRef = sortedMerge(a, b);
}

struct Node *createNode(struct Node *head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL)
    {
        head = temp = newNode;
    }
    else
    {
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

void display(struct Node *head)
{
    struct Node *current = head;
    while (current->next != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("%d->NULL\n", current->data);
}

int main(){
    struct Node *list1=NULL;
    int n;

    printf("Enter the number of elements in the first sorted list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        list1 = createNode(list1);
    }

    printf("Orignal List\n");
    display(list1);

    mergeSort(&list1);

    printf("Sorted List\n");
    display(list1);
   
}

free(temp);