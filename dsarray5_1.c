//counting sort algorithm (hashtables used here)

#include<stdio.h>
void sort(int arr[], int n);
int main()
{
    int n;
    printf("Enter the size of an array :");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    sort(arr, n);
}
void sort(int arr[], int n)
{
    //int hashtable = calloc(10 , sizeof(int));
    int hashtable[10];
    int output[n];
    for(int i=0; i<10; i++)
    {
        hashtable[i] = 0;
    }
    for(int i=0; i<n; i++)
    {
        hashtable[arr[i]]++ ;
    }
    for(int i=1; i<10; i++)
    {
        hashtable[i] += hashtable[i-1];
    }
    for(int i=0; i<n; i++)
    {
        output[i] = 0;
    }
    for(int i =1; i<=n; i++)
    {
        output[hashtable[arr[i-1]]] = arr[i-1];
        hashtable[arr[i-1]]-- ;
    }
    for(int i=1; i<=n; i++)
    {
        printf("%d ", output[i]);
    }
}