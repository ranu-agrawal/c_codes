#include<stdio.h>
int part(int arr[],int start,int end){
    int x=start;
    int pivot=arr[end];
    for(int i=start;i<end;i++){
        if(arr[i]<=pivot){
            int temp=arr[i];
            arr[i]=arr[x];
            arr[x]=temp;
            //swap(arr[i],arr[x]);
            x++;
        }
    }
    //swap(pivot,arr[x]);
    int temp=pivot;
    pivot=arr[x];
    arr[x]=temp;
    return x;
}
void sort(int arr[],int start, int end){
    if(start<end){
        int x=part(arr,start,end);
        sort(arr,start,x-1);
        for(int i=0;i<end;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        sort(arr,x+1,end);
    }
}
int main(){
    int n;
    printf("Enter the size of sorted array: ");
    scanf("%d", &n);
    int start;
    int end;
    printf("\n");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}