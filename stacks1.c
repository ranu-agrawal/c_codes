//stacks implementation using arrays
// balancing ()

void program(char arr[], char stack[], int n);
void push(char stack[], char x);
void pop(char stack[]);
int result(char stack[]);

#include<stdio.h>
int top = -1 ;
int main() {
    int n;
    printf("Enter size of input array: ");
    scanf("%d", &n);
    char arr[n];
    for(int i=0; i<=n; i++)
    {
        scanf("%c", &arr[i]);
    }
    for(int i=0; i<=n; i++)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
    char stack[n];
    for(int i=0; i<=n; i++)
    {
        stack[i] = 0;
    }
    program(arr, stack, n);
    int a=result(stack);
    printf("\n%d", a);
}
void program(char arr[], char stack[], int n)
{
    if(top == -1)
    {
        printf("*%d*", arr[0]);
        push(stack, arr[0]);
    }
    for(int i=0; i<=n; i++)
    {
        printf("top = %d\n", top);
        //printf("abfdv\n");
       // printf("%c\n", stack[top]);
        printf("%c\n", arr[i]);
        //&&(top == -1 || stack[top] != '(')
        
        if (arr[i] == ')') 
        {
            if(stack[top] != '(' || top == -1)
            {
                //printf("44444\n");
                push(stack , ')');
            }else
            {
                pop(stack);
            }
            
        }
        //else if(arr[i] == ')' && stack[top] == '(') pop(stack);
        else
        {
            push(stack, '(');
        }
    }
}
void push(char stack[], char x)
{
    top++ ;
    stack[top] = x;       //or else, just stack[++top] = x will do
    printf("\n");
    for(int i=0; i<=top; i++)
    {
        printf("%c", stack[i]);
    }
    printf("\n");
}
void pop(char stack[])
{
    stack[top] = 0;
    top--;
}
int result(char stack[])
{
    int m=0;
    int n=0;
    for(int i=0; i<=top; i++)
    {
        if(stack[i] == ')') m++ ;
        else if (stack[i] == '(') n++ ;
    }
    printf("\n%d", m);
    printf("\n%d", n);
    int steps = ((m+1)/2) + ((n+1)/2);
    return steps;
}