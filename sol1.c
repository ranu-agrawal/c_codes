#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct time
{
    int start;
    int end;
};
int dfs(struct node arr[],int t,int *counter,struct time brr[],int visit[])
{
    //printf("%d\n",(*counter));
    struct node *temp;
    temp=arr[t].link;
    if(visit[t]==1) return 0;  //useless since already checked before it came
    visit[t]=1;
    brr[t].start=(*counter)++;
    printf("%d\n", temp->data);
    while(temp!=NULL)
    {
        if(visit[temp->data]==0)
            dfs(arr,temp->data,counter,brr,visit);
        temp=temp->link;
    }
    brr[t].end=(*counter)++;
    return 0;
}
void insert(struct node arr[],int l,int r)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data=r;
    new->link=NULL;
    if(arr[l].link==NULL) arr[l].link=new;
    else
    {
        struct node *temp;
        temp=arr[l].link;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=new;
    }
};
int main()
{
    int i,j,n,a,b,counter=0,q,dir,x,y;
    //printf("enter the no of nodes\n");
    scanf("%d",&n);
    struct node arr[n+50];
    struct time brr[n+50];
    int visit[100050]={0};
    for(i=1;i<=n;i++) arr[i].link=NULL;
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        insert(arr,a,b);
        insert(arr,b,a);
    }
        /*for(i=1;i<=n;i++)
        {
            struct node *temp;
            temp=arr[i].link;
            while(temp!=NULL)
            {
                printf("%d ",temp->data);
                temp=temp->link;
            }
            printf("\n");
        }*/
    dfs(arr,1,&counter,brr,visit);
       /* for(i=1;i<=n;i++)
        {
            printf("%d   %d",brr[i].start,brr[i].end);
            printf("\n");
        }
        printf("enter the no of queries\n");*/
    scanf("%d",&q);
 
    while(q--)
    {
        scanf("%d%d%d",&dir,&x,&y);
        if(dir==0)
        {
            if((brr[x].start<brr[y].start) && (brr[x].end>brr[y].end)) printf("YES\n");
            else printf("NO\n");
        }
        else
        {
            if((brr[x].start>brr[y].start) && (brr[x].end<brr[y].end)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}