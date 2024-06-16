#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int val){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;

    return n;
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
    struct node*root=createnode(4);
    struct node*p1=createnode(1);
    struct node*p2=createnode(6);
    struct node*p3=createnode(5);
    struct node*p4=createnode(2);

    root->left=p1;
    root->right=p2;

    p1->left=p3;
    p1->right=p4;

    preOrder(root);
  
}