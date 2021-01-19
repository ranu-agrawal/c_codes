#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int start,int mid,int end){
    int i=0;
    int j=0;
    int k=0;
    int nl=mid-start+1;
    int nr=end-mid;
    int left[nl];
    int right[nr];
    for(int i=0;i<nl;i++){
        left[i]=arr[start+i];
    }
    for(int j=0;j<nr;j++){
        right[j]=arr[mid+1+j];
    }
    while(i<nl && j<nr){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k]=right[j];
            j++;
        }
        k=k+1;
    }
    while(i<nl){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<nr){
        arr[k]=right[j];
        j++;
        k++;
    }
}
void sort(int arr[],int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        sort(arr,start,mid);
        sort(arr,mid,end);
        merge(arr,start,mid,end);
    }
}
int findMin(int arr[], int n)
{
    int INT_MAX = arr[n-1] - arr[0];
    printf("%d", INT_MAX);
    int min = INT_MAX;
    for(int i=1; i<n; i++)
    {
        if(arr[i]-arr[i-1] < min) min = arr[i] - arr[i-1];
    }
    return min;
}                                        
int main(){
    int n;   //sizeofarray
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int start=0;
    int end=n-1;
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    sort(arr,start,end);
   // int sarr[n];
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
        //arr[i] = sarr[i];
    }
    int a=findMin(arr, n);
    printf("%d", a);
    return 0;
}