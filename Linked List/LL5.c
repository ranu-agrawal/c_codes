//all odd nodes followed by all the even nodes

#include<stdio.h>
#include<stdlib.h>
struct node * task(struct node * head);
struct node * insert(int x);
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

node * task(node * head)
{
    if(head == NULL) return NULL;
    node * odd = head;
    node * even = head->next;
    node * evenhead = even;
    while(1)
    {
        if (!odd || !even || !even->next)
        {
            odd->next = evenhead;
            break;
        }
        odd->next = even->next;
        odd = even->next;
        if (odd->next == NULL)
        {
            even->next = NULL;
            odd->next = evenhead;
            break;
        }
        even->next = odd->next;
        even = odd->next;
    }
    return head;
}
int main()
{
    node * head = NULL;
    int size;
    printf("Enter the size of list : ");
    scanf("%d", &size);
    int arr[size];
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    head = manage(head, arr, size);
    head = task(head);
    printf("Modified ");
    print(head);
}