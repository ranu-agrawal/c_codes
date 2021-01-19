#include<stdio.h>
void print(int arr[]){
    for(int i=0;i<5;i++){
        printf("%d ", arr[i]);
    }
}
void sort(int arr[]){
    int key,j;
    for(int i=1;i<5;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            arr[j]=key;
            j=j-1;
        }
    }
}
int main(){
    //int key,j,i;
    int arr[4];
    for(int i=0;i<5;i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<5;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    sort(arr);
    print(arr);
    return 0;
}