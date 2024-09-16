#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    return newNode;
}

void display(struct Node *head)
{
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d->NULL\n", temp->data);
}

void nodeAtBegginning(struct Node **head)
{
    struct Node *temp = createNode();
    if (*head == NULL)
    {
        (*head) = temp;
    }
    else
    {
        temp->next = *head;
        *head = temp;
    }
}

void nodeAtEnd(struct Node **head)
{
    struct Node *temp = createNode();
    if (*head == NULL)
    {
        (*head) = temp;
    }
    else
    {
        struct Node *p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void nodeAtPlace(struct Node *head, int position)
{
    struct Node *temp = createNode(), *p = head;
    if (head == NULL)
    {
        head = temp;
        // (*tail)=temp;
    }
    else
    {
        int i = 1;
        while (i < position - 1)
        {
            p = p->next;
            i++;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void nodeAtStart(struct Node **head)
{
    if ((*head) == NULL)
        return;

    struct Node *ptr = (*head);

    if ((*head)->next == NULL)
    {
        *head = NULL;
        free(ptr);
    }
    else
    {
        (*head) = (*head)->next;
        free(ptr);
    }
}

void AtEnd(struct Node **head)
{
    if ((*head) == NULL)
        return;

    struct Node *ptr = (*head);

    if ((*head)->next == NULL)
    {
        free(ptr);
        *head = NULL;
    }
    else
    {
        struct Node *ptr = (*head)->next, *prev = *head;
        while (ptr->next != NULL)
        {
            prev = prev->next;
            ptr = ptr->next;
        }
        prev->next = NULL;
        free(ptr);
    }
}

void AtValue(struct Node **head, int val)
{
    if ((*head) == NULL)
        return;

    struct Node *ptr = (*head);

    if ((*head)->next == NULL)
    {
        *head = NULL;
        free(ptr);
    }
    else if ((*head)->data == val)
    {
        (*head) = (*head)->next;
        free(ptr);
    }
    else
    {
        struct Node *ptr = (*head)->next, *prev = *head;
        while (ptr->data != val)
        {
            prev = prev->next;
            ptr = ptr->next;
        }
        prev->next = ptr->next;
        free(ptr);
    }
}

int main()
{
    struct Node *head = NULL;

    printf("Insert Node\n");
    printf("1)At Beginning \n");
    printf("2)At End\n");
    printf("3)At Specific Position\n");
    printf("\nDelete Node\n");
    printf("4)At Beginning \n");
    printf("5)At End\n");
    printf("6)Specific Node\n");
    printf("7)Exit\n");
    int choice, data;
    do
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            nodeAtBegginning(&head);
            display(head);
            break;
        case 2:
            nodeAtEnd(&head);
            display(head);
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &data);
            nodeAtPlace(head, data);
            display(head);
            break;
        case 4:
            nodeAtStart(&head);
            display(head);
            break;
        case 5:
            AtEnd(&head);
            display(head);
            break;
        case 6:
            printf("Enter Element to delete: ");
            scanf("%d", &data);
            AtValue(&head, data);
            display(head);
            break;
        }
    } while (choice != 7);

    return 0;
}