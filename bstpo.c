// build an efficient algo to construct a bst with given post order traversal

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
    int data;
    struct node * left; 
    struct node * right;
}node;

/*void printInorder(node * root)
{
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}*/

node * newNode(int data)
{
    node * temp2 = (node*)malloc(sizeof(node));
    temp2->data = data;
    temp2->left = NULL;
    temp2->right = NULL;
    return temp2;
}
void printInorder(node * root)
{
    if(root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

node * constructBSTUtil(int a[], int *index, int key, int min, int max, int n)
{
    //base case
    if(index < 0) return NULL;

    node * root = NULL;

    if(key > min && key < max)
    {
        root  = newNode(key);
        *index = *index -1;
        printf("***%d***\n", *index);

        if(index >= 0)
        {
            root->right = constructBSTUtil(a, index, a[*index], key, max, n);
            root->left = constructBSTUtil(a, index, a[*index], min, key, n);
        }
    }
    return root;
}

node * constructBST(int a[], int n)
{
    int index = n-1;
    node * root = constructBSTUtil(a, &index, a[index], INT_MIN, INT_MAX, n);
    return root;
    //printInorder(root);
}
int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    node * root = constructBST(a, n);
    printInorder(root);
    return 0;
}