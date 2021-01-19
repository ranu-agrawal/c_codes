//trapping rain water (efficient algorithm-----O(n)for both)
//non-efficient algorithm = brute force (O(n2) and space O(1))
//explained in video of arrays by prepByte

#include<stdio.h>
int findWater(int arr[], int n) {
    int left[n];
    int right[n];
    int water = 0;
    left[0] = arr[0];
    for(int i =1; i<n; i++)
    {
        if(arr[i] > left[i-1]) left[i] = arr[i];
        else left[i] = left[i-1];
    }
    for(int i = n-1; i>=0; i--)
    {
        if(arr[i] > right[i+1]) right[i] = arr[i];
        else right[i] = right[i+1];
    }
    for(int i = 0; i < n-1; i++)
    {
        water += (left[i] > right[i] ? right[i] : left[i]) - arr[i];
    }
    return water;
}
int main(){
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int a = findWater(arr, n);
    printf("%d", a);
}