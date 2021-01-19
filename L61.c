#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);      //input number of elements(integers)
    int *p = (int *)malloc(n*sizeof(int));    //allocates dynamic memory(creates a block of size n integers)
    for(int i = 0;i < n; i++)
    {
        scanf("%d", (p + i));   //input integers
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));    //print integers
    }
    free(p);        //freed p
    return 0;
}