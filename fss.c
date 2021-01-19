#include<stdio.h>
void print(int arr[]){
    for(int i=0;i<5;i++){
        printf("%d ", arr[i]);
    }
}
void sort(int arr[]){
    int min,key;
    for(int i=0;i<4;i++){
        min=i;
        for(int j=i+1;j<5;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        key=arr[i];
        arr[i]=arr[min];
        arr[min]=key;
    }
}
int main(){
    int arr[5];
    for(int i=0;i<5;i++){
        scanf("%d ", &arr[i]);
    }
    for(int i=0;i<5;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    sort(arr);
    print(arr);
    return 0;
}