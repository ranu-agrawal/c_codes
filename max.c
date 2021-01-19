#include<stdio.h>
//int maximum(int);
int main(){
    int n,a;
    printf("Enter the size of array :");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);      //array as input
    }
    for(int i=0;i<n;i++){
        printf("%d", arr[i]);
    }
    printf("\n");
    a=maximum(arr,n);
    printf("%d", a);
}

int maximum(int arr[], int n){             //declaring function
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i]){
            max=arr[i];      //max found
        }
    }
    return max;
}