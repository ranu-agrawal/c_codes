#include<stdio.h>
int main(){
    int key,j,i;
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
    for(i=1;i<5;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            arr[j]=key;
            j=j-1;
        }
    /*for(int i=0;i<5;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    //arr[j+1]=key;*/
    }
    for(int i=0;i<5;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}