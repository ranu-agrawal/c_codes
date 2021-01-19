/*printing max sum of subarray in a given array using KADANE's algorithm*/
#include<stdio.h>
#include<limits.h>

int maxSumOfSubarray( int arr[], int n);
int main()
{
    int n;
    printf("Ener the size of an array :");
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
    int a = maxSumOfSubarray(arr,n);
    printf("\n%d", a);
}
int maxSumOfSubarray( int arr[], int n)
{
    int max_so_far = INT_MIN, max_ends_here = 0;  //you can directly use 0 here bcoz only +ve cases are considered
    printf("\n%d", max_so_far);
    for(int i=0; i<n; i++)
    {
        max_ends_here += arr[i];
        if(max_ends_here <0) max_ends_here = 0;
        
        //if(max_so_far < max_ends_here) max_so_far = max_ends_here; //here we are comparing for all elements
        
        else if(max_so_far < max_ends_here) max_so_far = max_ends_here;//comparing only for +ves
    }                                                          //i.e when max_ends_here is positive
    return max_so_far;    
}