//binary search is an algorithm for finding input x in a given sorted array
//it finds the middle element and then compares

#include<stdio.h>
int search(int arr[], int n, int x){
    static int mid;
    int start=0;
    int end=n-1;
    while(start<=end){
        mid=(start+end)/2;
        if(x==arr[mid]){
            return mid;
        }
        else if(x>arr[mid]){
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return -1;
}
int main(){
    int n;
    printf("Enter the size of sorted array: ");
    scanf("%d", &n);
    printf("\n");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int x;
    printf("Enter the element you want to search for: ");
    scanf("%d",&x);
    printf("%d exists at index %d\n",x,search(arr,n,x));
    return 0;
}