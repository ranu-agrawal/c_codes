/*progrem to create a linked list from an array*/
/*head value is constant as it stores the base address of the list*/
#include<stdio.h>
#include<stdlib.h>
void insert(int x);
void print();             /*fuction prototypes*/
struct node{
    int data;
    struct node * next;
};
struct node* head;            /*global variable, can be accessed throughout the code*/
int main()
{
    head = NULL;
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);      //taking input array
    }
    for(int i=n-1; i>=0; i--)
    {
        insert(arr[i]);              /*inserting elements in list*/
    }
    print();              /*prints the list*/
    return 0;
}
void insert(int x)
{
    struct node * temp = (struct node*)malloc(sizeof(struct node));/*allocates block of memory=node size*/
    temp->data = x;           //first part of node gets x
    temp->next = head;        //2nd gets head
    head = temp;          //head now stores address of temp(temporary variable)
}
void print()                    /*prints the list*/
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