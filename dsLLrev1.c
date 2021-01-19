#include<stdio.h>
#include<stdlib.h>
struct node * insert(int x);
void print();                 /*fuction prototypes*/
void reverse();
void manage(int arr[], int n);
struct node{
    int data;
    struct node* next;
};
struct node * head;        /*global variable, can be accessed throughout the code*/
int main()
{
    head = NULL;
    int size,n;
    printf("Enter the number of elements : ");
    scanf("%d", &size);
    int arr[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d", &arr[i]);
    }
    manage(arr, size);
    print();                            /*prints the list*/
    reverse();            
    print();                 /*prints the list after modification*/
    return 0;
}
struct node * insert(int x)
{
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));  /*base address of node assigned*/
    temp1->data=x;                //1st part of node =x                                      /*to temp1*/
    temp1->next=NULL;            //2nd part =0
    return temp1;              //since not void must return something
}
void manage(int arr[], int size)
{
    head = insert(arr[0]);
    struct node* p = head;
    for(int i=1; i<size ;i++)
    {
        p->next = insert(arr[i]);        //p->next is a pointer and therefore,insert=pointer function
        p = p->next;  //moves pointer ahead         //insert() must have to be pointer function
    }                                                           //pointer to pointer passing
}
void print()
{
    struct node * temp = head;
    printf("List is : ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void reverse()
{
    struct node * current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}