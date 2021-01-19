#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *str1 = (char*)malloc(255*sizeof(char));      //dynamic allocation
    char *str2 = (char*)malloc(255*sizeof(char));
    scanf("%s %s", str1, str2);                        //input strings
    int flag=0;                                     //most important step for the code
    /*for(int i=0; *(str1+i)!='\0';i++)
    {
        int flag=0;
    }*/
    while(flag)
    {
        //return(*(str1+i) == *(str2+i) ? 0 : 1);
        if (*(str1+i) != *(str2+i))
        {
            //printf("1");
            flag=1;
            //break;
        }
    }
    if(flag){
        printf("0");
    }
    else
    {
        printf("1");
    }
    /*if(j!=1){
        {
            printf("0");
        }
    }*/
    free(str1);
    free(str2);
    return 0; 
}