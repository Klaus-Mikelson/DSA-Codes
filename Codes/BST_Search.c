#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;

    return n;
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *search(struct node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == val)
    {
        return root;
    }
    else if (root->data > val)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}

void main()
{
    struct node *root = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(2);
    struct node *p4 = createnode(4);

    root->left = p1;
    root->right = p2;

    p1->left = p3;
    p1->right = p4;

    struct node *n = search(root, 4);

    if (isBST(root))
    {
        printf("This is bst\n");
        if (n != NULL)
        {
            printf("data found\n");
        }
        else
        {
            printf("Value not found\n");
        }
    }
    else
    {
        printf("This is not a bst");
    }
}
