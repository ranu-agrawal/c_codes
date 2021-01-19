//finding maximum depth(or total height) of binary tree

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * left;
    struct node * right;
}node;

int findMaxDepth(node * root)
{
    if(root == NULL) return -1;
    return (findMaxDepth(root ->left) > findMaxDepth(root ->right) ? findMaxDepth(root->left) +1 : findMaxDepth(root->right) +1);
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
    int a = findMaxDepth(root);
    printf("%d", a);
    return 0;
}

