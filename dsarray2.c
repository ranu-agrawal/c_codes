//finds if sum of two numbers in a sorted array is equal to x
//(if array is not sorted sort it using mergesort with O(nlogn))

#include<stdio.h>
#include<stdlib.h>
int search(int arr[], int x, int n);
int binarySearch(int arr[], int x, int start, int end);



//1. BRUTE FORCE approach with O(n^2)
/*int search(int arr[], int n, int x)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++){
            if(arr[i]+arr[j] == x) return 1;
        }
    }
    return 0;
}
int main()
{
    int n,x;
    printf("Enter the size of array :");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the sorted array :");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter x :");
    scanf("%d", &x);
    int a = search(arr,n,x);
    printf("%d", a);
}  */

//2. USING BINARY SEARCH
/*int binarySearch(int arr[], int x, int start, int end)
{
    int mid;
    while(start<=end)
    {
        mid = (start + end)/2;
        if(x == arr[mid])
        {
            printf("%d", mid);
            return mid;
        }
        else if(x > arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}
int search(int arr[], int x, int n)
{
    int i,j;
    for(i = 0; i <n ; i++)
    {
        j = binarySearch(arr, x-arr[i], 0, n-1);
        if(j!= -1){
            break;
        }
    }
    printf("%d ",i);
    return j;
}
int main()
{
    int n,x;
    printf("Enter the size of array :");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the sorted array :");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter x :");
    scanf("%d", &x);
    search(arr,x,n);
} */

//3. MOST EFFICIENT APPROACH WITH O(n)
void search(int arr[], int n, int x)
{
    int l = 0, r = n-1;
    while(l<r)
    {
        if(arr[l] + arr[r] == x) 
        {
            printf("%d %d", l, r);
            break;
        }
        else if(arr[l] + arr[r] > x) r--;
        else{
        l++;
        }
    }
    
}
int main()
{
    int n,x;
    printf("Enter the size of array :");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the sorted array :");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter x :");
    scanf("%d", &x);
    search(arr,n,x);
}