//invalidate stack sequences

#include<stdio.h>

int validateStackSequences(int pushed[], int popped[], int n);
int main()
{
    int n;
    printf("Enter the number of elements in pushed/popped : ");
    scanf("%d", &n);
    int pushed[n];
    int popped[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &pushed[i]);
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d", &popped[i]);
    }
    int a = validateStackSequences(pushed, popped, n);
    if(a==n) printf("True");
    else printf("False");    
}

int validateStackSequences(int pushed[], int popped[], int n)
{
    int j = 0;
    int stack[n];
    int top = -1;
    for(int i = 0; i<n; i++)
    {
        stack[++top] = pushed[i];
        while(top!= -1 && stack[top] == popped[j])
        {
            top-- ;
            j++ ;
        }
    }
    return j;
}