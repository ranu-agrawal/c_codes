#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *str1 = (char*)malloc(255*sizeof(char));      //dynamic allocation
    char *str2 = (char*)malloc(255*sizeof(char));
    scanf("%s %s", str1, str2);                        //input strings
    char *str3 = (char*)malloc(510*sizeof(char));
    int n,m,a;
    int j=0;
    int i=0;
    a=strlen(str2);
    n=strlen(str1);
    m=n+a;
    for(int j=0;j<n;j++){
        *(str3+j)=*(str1+i);
        i++;
    }
    //}
    for(int i=0;i<=a;i++){
        for(int j=n;j<=m;j++){
            *(str3+j)=*(str2+i);
            i++;
        }
    }
    for(int i=0;i<m;i++)
    {
        printf("%c", *(str3+i));
    }
    return 0;
}