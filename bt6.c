// construct a binary tree from given postorder and inorder traversal
//gives segmentation error --- to be debugged

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node * left;
    struct node * right;
}node;

node * newNode(int data)
{
    node * temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node * buildTreeHelper(int in[], int po[], int inS, int inE, int poS, int poE)
{
    if(inS > inE) return NULL;
    int rootData = po[poE - 1];
    int rootIndex = -1;
    for(int i=inS; i<inE; i++)
    {
        if(in[i] == rootData) {
            rootIndex = i;
            break;
        }
    }
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPoS = poS;
    int lPoE = lInE - lInS + lPoS;
    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPoS = lPoE + 1;
    int rPoE = rootIndex - 1;
    node * root = newNode(rootData);
    root->left = buildTreeHelper(in, po, lInS, lInE, lPoS, lPoE);
    root->right = buildTreeHelper(in, po, rInS, rInE, rPoS, rPoE);
    return root;
}

node *  buildTree (int in[], int po[], int n) {
    return buildTreeHelper(in, po, 0, n-1, 0, n-1);
}

void Inorder(node* root) 
{ 
    if (root == NULL) return;
    /* then recur on left sutree */
    Inorder(root->left);  
  
    /* first print data of node */
    printf("%d ", root->data);

    /* now recur on right subtree */
    Inorder(root->right); 
}


int main()
{
    int arr[9];
    //int in[] = {4,2,5,1,8,6,9,3,7};
    //int po[] = {4,5,2,8,9,6,7,3,1};
    int in[] = {2,3,1};
    int po[] = {2,1,3};
    int n = sizeof(in)/sizeof(in[0]);
    //node * root1 = buildTree(in, po, n);
    node * root1 = buildTree(in, po, n);
    //Inorder(root1);
    return 0;
}