#include<stdio.h>
#include<stdio.h>
int main(){
    char str[100];
    //int n;
    //printf("Enter size of your string : ");
    //scanf("%d",&n);
    printf("Enter your string :");
    scanf("%s",str);
    printf("%s",str);
    printf("\n");
    char *p=str;
    int x;
    int count=0;
    //int y;
    printf("%d\n",'a');
    //for(int i=0;i<n;i++)
    while(*p!='\0'){
        int y=*p;
        if(y > 90){
            //printf("%d\n",y);
            x=y-'a'+1;
            printf("%d",x);
        }
        else
        {
            x=y-'A'+1;
            printf("%d",x);
        }
        p++;
        //printf("\n");
        count+=x;
        x=0;
        //printf("%d",count);
    }
    printf("\n%d",count);
    return 0;
}