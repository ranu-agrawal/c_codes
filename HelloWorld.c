#include <stdio.h>
int main()
{
    //printf() displays the string inside quotation
    printf("Hello,World!\n");
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",j);
        }
        for(int j=1;j<=10-i*2;j++){
            printf(" ");
        }
        for(int j=i;j>=1;j--){
            printf("%d ",j);
        }
        printf("\n");
    }
    printf("Hell\n");
    return 0;
}