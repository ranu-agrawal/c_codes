#include<stdio.h>
int major(int count, int m, int n){
    if(count>n/2){
        return m;
    }
}
int calc(int n,int arr[n-1]){
    for(int i=0;i<n;i++){
        int m;
        m=arr[i];
        int count=0;
        for(int j=0;j<n;j++){
            //int count=0;
            if(m==arr[j]){
                count++;
            }
        }
        return count;
    }
}
int main(){
    int a,n,count,m;
    int arr[n-1];
    for(int i=0;i<n;i++){
        scanf("%d ", &arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    calc(n,arr);
    a=major(count,m,n);
    printf("Majority element is %d",a);
    return 0;
}