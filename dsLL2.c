/*delete a node from the linked list*/
/*head value is constant as it stores the base address of the list*/
#include<stdio.h>
#include<stdlib.h>
struct node * insert(int x);
void print();                 /*fuction prototypes*/
void delete(int n);
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
    printf("Enter position of the node to be deleted :");
    scanf("%d",&n);
    delete(n);            
    print();                 /*prints the list after deletion of the node*/
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
void delete(int n)
{
    struct node * temp1 = head;
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
    struct node * temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
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