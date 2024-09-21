#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createNode();
void deleteNode(int);
void search(int);
void display();

int main()
{
    printf("\nMenu\n");
    printf("1)Create/Insert Node\n");
    printf("2)Delete Node\n");
    printf("3)Traverse/Search list\n");
    printf("4)Display list\n");
    printf("5)Exit\n");
    int choice, data;
    do
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createNode();
            display();
            break;
        case 2:
            printf("Enter data element to delete: ");
            scanf("%d", &data);
            deleteNode(data);
            display();
            break;
        case 3:
            printf("Enter data element to search: ");
            scanf("%d", &data);
            search(data);
            display();
            break;
        case 4:
            display();
            break;
        }
    } while (choice != 5);

    return 0;
}

void createNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newNode;
    }
}

void display()
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void search(int val)
{
    struct Node *current = head;
    int i=0;
    while (current != NULL && current->data != val)
    {
        current = current->next;
        i++;
    }
    if (current == NULL)
    {
        printf("%d Not found in list\n", val);
    }
    else
    {
        printf("Data Found at %d position in list\n", i+1);
    }
}

void deleteNode(int val)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (head->data == val)
    {
        head = head->next;
    }
    else
    {
        struct Node *prev = head;
        struct Node *ptr = head->next;
        while (ptr != NULL && ptr->data != val)
        {
            prev = prev->next;
            ptr = ptr->next;
        }
        if (ptr != NULL)
        {
            prev->next = ptr->next;
            free(ptr);
        }
        else
        {
            printf("%d not found\n", val);
        }
    }
}
