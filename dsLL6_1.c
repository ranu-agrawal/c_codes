/* if we are not considering priting the original list */

/*delete a node from the linked list*/
/*head value is constant as it stores the base address of the list*/
#include<stdio.h>
#include<stdlib.h>
struct node * insert(int x);
void print(struct node * head);                 /*fuction prototypes*/
struct node * delete(int n);
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
    int count =0;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d", &arr[i]);
    }
    manage(arr, size);
    print(head);
    //printf("%d", a);                            /*prints the list*/
    printf("Enter position of the node to be deleted from the last :");
    scanf("%d",&n);
    delete(n);            
    print(head);                 /*prints the list after deletion of the node*/
    //printf("%d",a);
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
struct node * delete(int n)
{
    struct node * fast = head;
    struct node * slow = head;
    for(int i=1; i<=n; i++)
    {
        fast = fast->next;
    }
    if(fast == NULL)
    {
        head = head->next;
        return head;
    }                                   /*logic of the code*/
    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}
void print(struct node * head)
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