#include<stdio.h>
int search(int arr[],int start,int end, int n, int x){
    static int mid;
    if(start<=end){
        mid=(start+end)/2;
        if(x==arr[mid]){
            return mid;
        }
        else if(x>arr[mid]){
            start=mid+1;
            return search(arr,start,end,n,x);

        }
        else
        {
            end=mid-1;
            return search(arr,start,end,n,x);
        }
    }
    return -1;
}
int main(){
    int n;
    printf("Enter the size of sorted array: ");
    scanf("%d", &n);
    int start=0;
    int end=n-1;
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
    printf("%d exists at index %d\n",x,search(arr,start,end,n,x));
    return 0;
}