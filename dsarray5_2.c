//bucket sort  //hashscore and hashtables used

#include<stdio.h>
typedef struct node{
    int data;
    struct node *next;
}node;

int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;  i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n)
}
node * insert(int x)
{
    node * temp1 =(node*)malloc(sizeof(node));
    temp1->data = x;
    temp1->next = NULL;
    return temp1;
}
void bucketSort(int arr[], int n)
{
    node * head = NULL;
    node * hashtable = calloc(10, sizeof(node*));
    for(int i=0; i<n; i++)
    {
        hashtable[arr[i]*10] = arr[i];
        head = hashtable;
        head = insert(arr[i]);
        /*if(head == NULL)
        {
            head = insert(head);
        }
        else
        {

        }*/
    }
}