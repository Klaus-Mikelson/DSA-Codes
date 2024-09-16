#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *temp=NULL;

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


int main(){
    struct Node *list1=NULL,*list2=NULL;
    int n, data;

    printf("Enter the number of elements in the first sorted list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        list1 = createNode(list1);
    }

    printf("Enter the number of elements in the second sorted list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        list2 = createNode(list2);
    }

    printf("First List\n");
    display(list1);
    
    printf("Second List\n");
    display(list2);


    struct Node *merge=sortedMerge(list1,list2);

    printf("Merged List\n");
    display(merge);

    


}