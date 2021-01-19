//finding minimum depth of binary tree

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * left;
    struct node * right;
}node;

int findMinDepth(node * root)
{
    if(root == NULL) return 0;
    if(root->left==NULL && root->right == NULL) return 1;
    if(!root->left) return findMinDepth(root->right)+1;       //for exceptional case when left child is absent
    if(!root->right) return findMinDepth(root->left)+1;      //right child absent
    return (findMinDepth(root ->left) < findMinDepth(root ->right) ? findMinDepth(root->left) +1 : findMinDepth(root->right) +1);
}

node * newNode (int data)
{
    node * temp = (node *)malloc(sizeof(node));
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

int main()
{
    node * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);
    int a = findMinDepth(root);
    printf("%d", a);
    return 0;
}