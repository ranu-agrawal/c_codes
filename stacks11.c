//forstacks1 -- look at more precise and an amazing algorithm in mailbox(riz1t)
#include<stdio.h>
#include<string.h>


int program(char str[], char stack[], int n);
int top = -1;             //declared as a global variable
int main()
{
    char str[100];
    char stack[100];
    scanf("%s", str);
    int n= strlen(str);
    int a = program(str, stack, n);
    printf("%d", a);
}
int program(char str[], char stack[], int n)
{
    stack[++top] = str[0];
    for(int i=1; i<n; i++)
    {
        printf("Top = %d\n", top);
        if(str[i] == ')') {
            if(stack[top] != '(') stack[++top] = str[i];
            else top-- ;
        }
        //if(str[i] == '(') stack[++top] = str[i];
        else stack[++top] = str[i];
    }
    int m=0;
    int p=0;
    for(int i=0; i<=top; i++)
    {
        printf("%c", str[i]);
        if(stack[i] == '(') m++ ;
        else p++ ;
    }
    printf("\n");
    printf("%d\n", m);
    printf("%d\n", p);
    return ((m+1)/2) + ((p+1)/2);
}