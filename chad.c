#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    //int n;                                  //also works with n
    //printf("Enter size of your string : ");
    //scanf("%d",&n);
    printf("Enter your string :");
    scanf("%s",str);
    printf("%s",str);
    printf("\n");
    int x;
    int count=0;
    for(int i=0;str[i]!='\0';i++){             //also works with i<n
        //printf("%c",str[i]);
        int y=str[i];                          //int y itself gives the ascii value ('y' not required)
        //int z='y';
        if(y>90){
            x=y-'a'+1;                 
            printf("%d",x);
        }
        else{
            x=y-'A'+1;
            printf("%d",x);
        }
        count+=x;
        x=0;
    }
    printf("\n%d ", count);
    return 0;
}