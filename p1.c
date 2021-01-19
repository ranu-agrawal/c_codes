#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    printf("\n");
    for(int i=1;i<n+1;i++){
        for(int j=1; j<i+1;j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    for(int i=n;i>0;i--){
        for(int j=1; j<i+1;j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n-i+1;j++){
            printf(" ");
        }
        for(int j=1;j<i+1;j++){         //or : for(int j=i;j>=1;j--)
            printf("*");
        }
        printf("\n");
    }
    return 0;
}