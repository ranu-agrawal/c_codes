#include <stdio.h>
int main()
{
    //printf() displays the string inside quotation
   // printf("Hello,World!\n");
   char g =" ";
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            if(j==i)
            printf("%d",j);
            else
            printf("%d ",j);
        }
        for(int j=1;j<=10-i*2;j++){
            printf("  ");
        }
        for(int j=i;j>=1;j--){
            if(j==1)
            printf("%d",j);
            else
            printf("%d ",j);
        }
        printf("\n");
    }
    //printf("Hell\n");
    printf("%d",10-1*2);
    return 0;
}