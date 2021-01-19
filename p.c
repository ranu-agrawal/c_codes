#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    printf("\n");
    int arr[n-1];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d", arr[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d\n", arr[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        if(i==n-1){
            printf("%d",arr[i]);
        }
        else{
            printf("%d,", arr[i]);
        }
    }
    return 0;
}