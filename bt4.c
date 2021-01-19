// binary tree pruning

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
    
}node;

node * newNode(int data)
{
    node * temp2 = (node *)malloc(sizeof(node));
    temp2->data = data;
    temp2->left = temp2->right = NULL;
    return temp2;
}

node * insertLevelOrder(int arr[], node * root, int i, int n)
{
    //base case for recursion/ exit condition
    if(i<n)
    {
        node * temp = newNode(arr[i]);
        root = temp;

        //inserting left child
        root->left = insertLevelOrder(arr, root->left, 2*i + 1, n);

        //inserting right child
        root->right = insertLevelOrder(arr, root->right, 2*i +2, n);
    }
    return root;
}

node * pruneTree(node * root)
{
    if(root == NULL) return NULL;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if(root->data == 0 && root->left == NULL && root->right == NULL) {
        root = NULL;
        //return root;
    }
    //if(root->left->data == 0 && root->left->left == NULL && root->left->right == NULL) root->left = NULL;
    //if(root->right->data == 0 && root->right->left == NULL && root->right->right == NULL) root->right = NULL;
    return root;
}

void printPreorder(node* root) 
{ 
    if (root == NULL)
        return;
  
    /* first print data of node */
    printf("%d ", root->data);
  
    /* then recur on left sutree */
    printPreorder(root->left);  
  
    /* now recur on right subtree */
    printPreorder(root->right); 
}

int main()
{
    int arr[5];
    for(int i=0; i<5; i++)
    {
        scanf("%d", &arr[i]);
    }
    node * root = insertLevelOrder(arr, root, 0, 5);
    pruneTree(root);
    printPreorder(root);
    return 0;
}