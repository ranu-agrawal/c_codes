//add elements at the beginning of the linked list
//remember throughout the whole code head never gets updated temp variables do.
//after if statements executes and its time for else, head again begins at its original value(constantforeva)
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void insert(int x);     /*function prototypes */
void print();
struct node* head;      //global variable, can be accessed anywhere throughout the code
int main()
{
    head = NULL;       //empty list
    int n,x;
    printf("How many numbers? : \n");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {    
        printf("Enter the number : \n");
        scanf("%d", &x);
        insert(x);
        print();
    }
    return 0;
}
void insert(int x)
{
    struct node* temp= (struct node*)malloc(sizeof(struct node));  /*gives temp(a different variable could be temp1) address of the node created*/
    temp->data =x;              /*adds the data(1st) part in the none*/
    temp->next=head;            /*next half of the node is assigned the value stored in head*/
    head = temp;              /*head is given th address of temp to store*/
}
void print()
{
    struct node* temp = head;      /*creates a temp variable(copy of head) to prevent modification*/
    printf("The list is :");              /*of the base address stored in head*/
    while(temp != NULL)          /*till tempreaches the last element of the linked list*/
    {
        printf("%d ", temp->data);    /*prints the elements of the list*/
        temp = temp->next;           /*temp is moved to forward element*/
    }
    printf("\n");
}