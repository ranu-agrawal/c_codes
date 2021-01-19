//hackerearth mail ques 1- oliver and the game
//this is fucking not a question of topological sort since you've to check both ways
//question of "DFS properties of finish time" by v n murlidara

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node * link;
}node;

void DFS(node arr[], int u, int F[], int D[], int V[], int * count)
{

    struct node * temp = arr[u].link;
    //printf("%d - ", u);
    //printf("%d ", temp->link);
    V[u] = 1;
    //(*count)++ ;
    //printf("%D----", ++(*count));
    D[u] = ++(*count);
    printf("%d - ", temp->data);
    printf("{%d}", D[u]);
    while(temp != NULL)
    {
        //printf("JJJ - ");
        //printf("%d\n", V[temp->data]);
        if(V[temp->data] == 0) DFS(arr, temp->data, F, D, V, count);
        temp = temp->link;
    }
    F[u] = (*count)++;
}

void dfsVisit(node arr[], int n, int F[], int D[], int V[])
{
    int count = 0;

    for(int i=1; i<=n; i++)
    {
        D[i] = 0;          //discover node
        F[i] = 0;          //finish time of node
        V[i] = 0;          //visited or not
    }
    for(int i=1; i<=n; i++)
    {
        if(V[i] == 0)
        {
            DFS(arr, i, F, D, V, &count);
        }
    }
}

void insert(node arr[], int l, int r)
{
    node * new = (node *)malloc(sizeof(node));
    new->data = r;
    new->link = NULL;
    if(arr[l].link == NULL) arr[l].link = new;
    else
    {
        node * temp = arr[l].link;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
    
}

int main()
{
    int n,l,r;
    scanf("%d", &n);
    int D[n], F[n], V[n];
    node arr[n];
    for(int i=1; i<=n; i++)
    {
        arr[i].link = NULL;
    }
    for(int i=1; i<n; i++)
    {
        scanf("%d %d", &l, &r);
        insert(arr, l, r);
        insert(arr, r, l);
    }

    dfsVisit(arr, n, F, D, V);

   // int q, u, v, a; //no. of queries
   // scanf("%d", &q);

   /* while(q--)
    {
        scanf("%d %d %d", &a, &u, &v);
        if(a==0)
        {
            if(D[v]>D[u] && F[v]<F[u])
            {
                printf("Yes\n");
            }
            else printf("No\n");
        }
        else
        {
            if(D[v]<D[u] && F[v]>F[u])
            {
                printf("Yes\n");
            }
            else printf("No\n");
        }
        
    }*/
}