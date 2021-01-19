#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * left;
    struct node * right;
}node;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y ;
    *y = temp;
}

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
        root->left = insertLevelOrder(arr, root->left, 2*i+1, n);

        //inserting right child
        root->right = insertLevelOrder(arr, root->right, 2*i+2, n);
    }
    return root;
}

void printInorder(node * root)
{
    if(root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

void * correctBSTUtil(node * root, node ** first, node ** middle, node ** last, node ** prev)
{
    if(root)
    {
        correctBSTUtil(root->left, first, middle, last, prev);

        if(*prev && root->data < (*prev)->data)
        {
            if(!*first)
            {
                *first = *prev;
                *middle = root;
            }
            else
            {
                *last = root;
            }
            
        }
        *prev = root;

        correctBSTUtil(root->right, first, middle, last, prev);
    }
}
void correctBST(node * root)
{
    node *first, *last, *middle, *prev;
    first = middle = last = prev = NULL;

    correctBSTUtil(root, &first, &middle, &last, &prev);

    if(first && last) swap(&first->data, &last->data);
    else if(first && middle) swap(&first->data, &middle->data);

}

int main()
{
    /*   6 
        /  \ 
       10    2 
      / \   / \ 
     1   3 7  12 
     10 and 2 are swapped 
    */
   int n;
   printf("Enter number of keys : ");
   scanf("%d", &n);
   int arr[n];
   for(int i=0; i<n; i++)
   {
       scanf("%d", &arr[i]);
   }
   node * root = insertLevelOrder(arr, root, 0, n);
   printInorder(root);
   printf("\n");
   correctBST(root);
   printInorder(root);
}