//insert element at nth position of the linked list
//remember throughout the whole code head never gets updated temp variables do.
//after if statements executes and its time for else, head again begins at its original value(constantforeva)
#include<stdio.h>
#include<stdlib.h>
void insert(int x, int n);   /*function prototypes*/
void print();
struct node{ 
    int data;
    struct node* next;
};
struct node* head;          /*global variable, can be accessed throughout the code*/
int main()
{
    struct node* head=NULL;      /*empty list*/
    insert(2,1);    //list 2
    insert(3,2);    //list 2,3
    insert(4,1);   //list 4,2,3
    insert(5,2);   //list 4,5,2,3
    print();
    return 0;
}
void insert(int x, int n)          /*x- data element and n-position where the element is to be inserted*/
{
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));  /*base address of node assigned*/
    temp1->data=x;                //1st part of node =x                                      /*to temp1*/
    temp1->next=NULL;            //2nd part =0
    if(n==1)
    {
        temp1->next=head;
        head = temp1;
    }
    else
    {
        struct node* temp2= head;
        for(int i=0;i<n-2;i++)   /*actually takes us to the n-2 th node which contains the adrss of n-1th node*/
        {
            temp2=temp2->next;     /*points to the address in n-1 th node*/
        }
        temp1->next = temp2->next;     /*main logic where the links are attached*/
        temp2->next = temp1;
    }
}
void print()                 /*prints the elements of the list*/
{
    struct node* temp=head;
    printf("List is :\n");
    while(temp != NULL)         /* goes until end of the list is reached*/
    {
        printf("%d ", temp->data);
        temp=temp->next;               /* moves the pointer forward */
    }
}