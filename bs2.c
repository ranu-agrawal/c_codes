#include<stdio.h>
int main()
{
    int arr[4];
    int key;
    for(int i=0;i<5;i++){
        scanf("%d ", &arr[i]);
    }
    for(int i=0;i<5;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4-i;j++){
            key=arr[j];
            if(arr[j]>arr[j+1]){
                arr[j]=arr[j+1];
                arr[j+1]=key;
            }
        }
        /*for(int i=0;i<5;i++){
        printf("%d ", arr[i]);
        }*/
        //printf("\n");
    }
    for(int i=0;i<5;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}