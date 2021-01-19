#include<stdio.h>
#include<stdlib.h>
struct node * insert(int x);
void manage(int arr[], int size);
void delete(int n);
void print();
void identify(int size);
typedef struct node{
    int data;
    struct node * next;
}node;
node * head;
int main()
{
    head = NULL;
    int size;
    printf("Enter the size of list : ");
    scanf("%d", &size);
    int arr[size];
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    manage(arr, size);
    identify(size);
    return 0;
}
node * insert(int x)
{
    node * temp1 =(node*)malloc(sizeof(node));
    temp1->data = x;
    temp1->next = NULL;
    return temp1;
}
void manage(int arr[], int size)
{
    head = insert(arr[0]);
    node * p = head;
    for(int i=1; i<size; i++)
    {
        p->next = insert(arr[i]);
        p = p->next;
    }
}
void delete(int n)
{
    node * temp1 = head;
    if(n == 1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }                                   /*logic of the code*/
    for(int i=0; i<n-2 ; i++)
    {
        temp1 = temp1->next;
    }
    node * temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}
void identify(int size)
{
    node * temp1 = head;
    int i;
    //node * temp2 = temp1; 
    while(temp1 != NULL)
    {
        i =1;
        node * temp2 = temp1->next;
        if(temp1->data == temp2->data)
        {
            delete(i);
        }
        temp1 = temp1->next;
        i++;
    }
    print();
}
void print()
{
    node * temp = head;
    printf("List is : ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
