#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(){
    int x;
    struct node *root=(struct node*)malloc(sizeof(struct node));
    printf("Enter valof node(-1 for no node) ");
    scanf("%d",&x);
    if (x==-1)
    {
        return NULL;
    }
    root->data=x;
    printf("Enter left child of %d\n",x);
    root->left=createnode();
    printf("Enter right child of %d\n",x);
    root->right=createnode();

    return root;
  
}

void preOrder(struct node *root){
if (root!=NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    
}

void main(){
    struct node*root=createnode();
    preOrder(root);
  
}