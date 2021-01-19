/* converting binary to decimal */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node * task(struct node * head);
struct node * insert(int x);
int print(struct node * head, int a);
struct node * manage(struct node * head, double arr[], int size);

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

node * manage(node * head, double arr[], int size)
{
    //if(arr[0] != 0 | arr[0] !=1 ) return NULL;
    head = insert(arr[0]);
    node * p = head;
    for(int i=1; i<size; i++)
    {
        //if(arr[i] !=0 | arr[i]!=1) return NULL;
        p->next = insert(arr[i]);
        p = p->next;
    }
    return head;
}

int print(node * head, int count)
{
    //node * temp = head;
    printf("List is : ");
    while(head != NULL)
    {
        count++;
        printf("%d ", head->data);
        head = head->next;
    }
    return count;
    printf("\n");
}

int convert(node * head, int a)
{
    int dec = 0;
    node * p = head;
    double i = a - 1;
    if(head == NULL) return 0;
    while(p != NULL)
    {
        int result = (int)pow(2.0, i);
        int y = p->data * result;
        dec += y;
        p = p->next;
        i--;
    }
    return dec;
}
int main()
{
    node * head = NULL;
    int size;
    int count = 0;
    printf("Enter the size of list : ");
    scanf("%d", &size);
    if(size >= 30)
    {
        printf("Enter valid input\n");
        scanf("%d", &size);
    }
    double arr[size];
    for(int i=0; i<size; i++)
    {
        scanf("%lf", &arr[i]);
    }
    head = manage(head, arr, size);
    int a = print(head,count);
    int deci = convert(head, a);
    printf("\n%d\n", deci); 
}