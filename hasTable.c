#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int index;
    struct node * next;
}node;
void insert_into_table(node ** hashtable, int index, int t);
void insert_new_node(node **head , int index);
void search(node ** hashtable, char txt[], char pat[], int M, int p);

int main()
{
    node ** table = calloc(108, sizeof(node*));
    char txt[1000], pat[1000];
    printf("Enter the string : ");
    scanf("%s", txt);
    printf("Enter the pattern : ");
    scanf("%s", pat);
    int i,j,q= 12859;
    int M = strlen(pat);
    int N = strlen(txt);
    int t = txt[0] - '0';
    int p = pat[0] - '0';
    int mul= 1;
    for(i = 1; i<M; i++)
    {
        t = 10*t + txt[i] - '0' % q;
        p = 10*p + pat[i] - '0' % q;
        mul *= 10;
    }
    insert_into_table(table, 0, t);
    for(i = 1; i<= N-M; i++)
    {
        t = ((t - (txt[i]-'0')*mul)*10 + txt[i+M]-'0')%q;
        insert_into_table(table, i, t);
    }
    search(table, txt, pat, M, p);
    return 0;
}
void insert_into_table(node ** hashtable, int index, int t)
{
    if(hashtable[t] == NULL)
    {
        hashtable[t] = malloc(sizeof(node*));
        node * head = NULL;
        insert_new_node(&head, index);
        hashtable[t] = head;
    }
    else
    {
        node * head = hashtable[t];
        insert_new_node(&head, index);
        hashtable[t] = head;
    }
    
}

void insert_new_node(node ** head, int index)
{
    node* new_node = malloc(sizeof(node*));
    new_node->index = index;
    new_node->next = NULL;
    if(*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        node* current = *head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    
}
void search(node ** hashtable, char txt[], char pat[], int M, int p)
{
    node* head = hashtable[p];
    int i;
    while(head!=NULL)
    {
        for(i = 0; i<M; i++)
        {
            if(txt[head->index + i] != pat[i]) break;
        }
        if(i == M)
        {
            printf("Match found at :%d", head->index);
        }
        head = head->next;
    }
}
