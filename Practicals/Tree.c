#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }

    if (key < root->data)
    {
        root->left = insertNode(root->left, key);
    }
    else
    {
        root->right = insertNode(root->right, key);
    }

    return root;
}

void inorderTraversal(struct Node *root)
{

    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d-> ", root->data);
        inorderTraversal(root->right);
    }
}

struct Node *inordersuccessor(struct Node *root)
{
    struct Node *current = root;

    if (current && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {

        // If node having one child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // If node has two childs

        struct Node *temp = inordersuccessor(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct Node *root = NULL;
    int choice, key;

    printf("\nMenu:\n");
    printf("1. Insert Node\n");
    printf("2. Inorder Traversal\n");
    printf("5. Delete Node\n");
    printf("6. Exit\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insertNode(root, key);
            break;

        case 2:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("NULL\n");
            break;

        case 5:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;
        }
    } while (choice != 6);

    return 0;
}