//radix sort (uses counting sort)

#include<stdio.h>
int getMax(int arr[], int n);
void radixSort(int arr[], int n);
void countSort(int arr[], int n, int exp);

int main()
{
    int n;
    printf("Enter the number of elements in array : ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    radixSort(arr, n);
    return 0;
}
int getMax(int arr[], int n)
{
    int max = arr[0];
    for(int i=0; i<n; i++)
    {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}
void countSort(int arr[], int n, int exp)
{
    int hashtable[10];
    int output[n];
    for(int i=0; i<10; i++)
    {
        output[i] = 0;
    }
    for(int i=0; i<10; i++)
    {
        hashtable[i] = 0;
    }
    for(int i=0; i<n; i++)
    {
        hashtable[(arr[i]/exp) % 10]++ ;
    }
    for(int i=1; i<10; i++)
    {
        hashtable[i] += hashtable[i-1]; 
    }
    for(int i=1; i<=n; i++)
    {
        output[hashtable[(arr[i-1]/exp) % 10]] = arr[i-1];
        hashtable[(arr[i-1]/exp) % 10]-- ;
    }
    for(int i=1; i<=n; i++)
    {
        arr[i] = output[i];
    }
    for(int i=1; i<=n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);
    for(int exp =1; max/exp >0; exp*= 10)
    {
        countSort(arr, n, exp);
    }
    /*for(int i=1; i<=n; i++)
    {
        printf("%d ", arr[i]);
    }*/
}