#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void InOrder(struct node *root){
if (root!=NULL)
    {
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
    
}

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

struct node *inorderpre(struct node* n){
    n=n->left;
    while (n->right!=NULL)
    {
        n=n->right;
    }
    return n;
    
}

struct node *deletion(struct node *root,int val){
    struct node* pre;
    if (root==NULL)
    {
        return NULL;
    }
    if (root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    else if (root->data>val)
    {
        root->left=deletion(root->left,val);
    }
    else if (root->data<val){
        root->right=deletion(root->right,val);
    }
    else{
        pre=inorderpre(root);
        root->data=pre->data;
        root->left=deletion(root->left,pre->data);
    }
    return root;
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

    if (isBST(root))
    {
        InOrder(root);
        deletion(root,5);
        printf("\n");
        InOrder(root);

    }
    else
    {
        printf("This is not a bst");
    }
}
