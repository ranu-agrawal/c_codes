//stacks used here to check proper pairs of brackets
//question in mail

#include<stdio.h>
#include<string.h>
int isEmpty(char stack[]);
int program(char str[], char stack[], int n);
int top = -1;             //declared as a global variable
int main()
{
    char str[100];
    char stack[100];
    scanf("%s", str);
    int n= strlen(str);
    int a = program(str, stack, n);
    if(a == 1) printf("True\n");
    else printf("False\n");
}
int program(char str[], char stack[], int n)
{
    for(int i=0; i<=n; i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            stack[++top] = str[i] ;
        }
        if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if(str[i]==')' && stack[top]=='(') top-- ;
            else if(str[i] == '}' && stack[top] == '{') top-- ;
            else if(str[i] == ']' && stack[top] == '[') top-- ;
            else
            {
                return 0;
            }
            
        }
    }
    return isEmpty(stack);
}
int isEmpty(char stack[])
{
    if(top == -1)
    {
        return 1;
    }
    else return 0;
}