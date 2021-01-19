#include<stdio.h>
int main()
{
    int arr[4];
    int key;
    for(int i=0; i<5;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<5;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i=0;i<4;i++){
        for(int j=i;j<4;j++){
            key=arr[j];
            if(key >arr[j+1]){
                key=arr[j+1];
            }
            //key=arr[j];
            //arr[i]=key;
            for(j=3; j>=0;j--){
             arr[j+1]=arr[j];
            }
            arr[i]=key;
            for(int i=0;i<5;i++){
              printf("%d ", arr[i]);
            }
            printf("\n");
        }
        arr[i]=key;
        //printf("\n");
    }
    for(int i=0;i<5;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}