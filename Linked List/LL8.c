/*rotating from right upto k places*/

#include<stdio.h>
#include<stdlib.h>
struct node * insert(int x);
struct node * rotate(struct node * head);
void print(struct node * head);
struct node * manage(struct node * head, int arr[], int size);

typedef struct node{
    int data;
    struct node * next;
}node;

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
node * rotate(node * head)
{
    int k=1;
    if(head == NULL) return NULL;
    node * p = head;
    //node * q = head;
    node * head1 = NULL;
    while(p->next->next!= NULL)
    {
        p = p->next;
    }
    p->next->next = head;
    head1 = p->next->next;
    //free(p->next);
    p->next= NULL;
    //head = p->next->next;
    return head1;
}
int main()
{
    node * head = NULL;
    node * head1 = NULL;
    //node * new;
    int size,k;
    printf("Enter the size of list : ");
    scanf("%d", &size);
    int arr[size];
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter k :");
    scanf("%d", &k);
    head = manage(head, arr, size);
    print(head);
    for(int i=0; i<k; i++)
    {
        head1 = rotate(head);
    }
    //head1 = rotate(head);
    printf("Modified ");
    print(head1);
}