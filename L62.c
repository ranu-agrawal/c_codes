//program for strcmp and printing 1 if strings are unequal and 0 if equal 
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char *str1 = (char*)malloc(255*sizeof(char));      //dynamic allocation
    char *str2 = (char*)malloc(255*sizeof(char));
    scanf("%s %s", str1, str2);                        //input strings
    int j=0;                                       //most important step for the code
    for(int i=0; *(str1+i)!='\0';i++)
    {
        //return(*(str1+i) == *(str2+i) ? 0 : 1);
        if (*(str1+i) != *(str2+i))
        {
            printf("1");
            j=1;
            break;
        }
    }
    if(j!=1){
        {
            printf("0");
        }
    }
    free(str1);
    free(str2);
    return 0; 
}