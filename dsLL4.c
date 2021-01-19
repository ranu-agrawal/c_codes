/* merging two sorted linked list into one */

#include<stdio.h>
#include<stdlib.h>
struct node * insert(int x);
struct node * manage(struct node * head, int arr[], int size);       /*prototypes*/
void print();
struct node * merge(struct node * p, struct node * q, struct node * sorting);
typedef struct node{
    int data;
    struct node * next;
}node;                      /*now struct node = node (bcoz of typedef)*/
int main()
{
    /*using local variables for this code*/
    node *p=NULL , *q=NULL , *head1=NULL , *head2=NULL , *sorting= NULL;/*p=list 1 & q=list 2*/
    int size1,size2;                              /*head1 of p and head2 of q and sorting for third*/
    printf("Enter the size of list 1 & 2 :");
    scanf("%d %d", &size1, &size2);
    int arr1[size1];
    int arr2[size2];
    for(int i=0; i<size1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for(int i=0; i<size2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    head1 = manage(head1, arr1, size1);
    head2 = manage(head2, arr2, size2);
    print(head1);
    print(head2);
    sorting = merge(head1, head2, sorting);
    print(sorting);
    return 0;
}
node * insert(int x)
{
    node * temp1 =(node*)malloc(sizeof(node));
    temp1->data = x;
    temp1->next = NULL;
    return temp1;
}
node * manage(node * head, int arr[], int size)
{
    head = insert(arr[0]);
    node * p = head;
    for(int i=1; i<size; i++)
    {
        p->next = insert(arr[i]);
        p = p->next;
    }
    return head;
}
void print(node * head)
{
    //node * temp = head;
    printf("List is : ");
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
node* merge(node * p, node * q, node * sorting)
{
    node * newhead;
    if(p == NULL)        /*if first list is empty return 2nd as it is since its sorted*/
        return q;
    if(q == NULL)        /*same when 2nd is empty*/
        return p;
    if(p && q)         /*if p && q = true i.e when p & q both have values*/
    {
        if(p->data <= q->data)     /*comparing 1st elements of both the list*/
        {
            sorting = p;   /*head of new list is now equal to the pointer to lesser value (here p)*/
            p = sorting->next;    /*pointer p moves forward*/
        }
        else
        {
            sorting = q;
            q = sorting->next;    /*same goes when q is smaller*/
        }
        
    }
    newhead = sorting;       /*head of new list is assigned the value of pointer to smaller value */
    while (p && q)                                   /*among the first elements of the two lists*/
    {
        if(p->data <= q->data)
        {
            sorting->next = p;
            sorting = p;
            p = sorting->next;
        }                         /* logic */
        else
        {
            sorting->next = q;
            sorting = q;
            q = sorting->next;
        }
        
    }
    if(p == NULL) 
    {
        sorting->next = q;
    }
    if(q == NULL) 
    {
        sorting->next = p;
    }
    return newhead;
}