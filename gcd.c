#include<stdio.h>
int main()
{
    int a,b;
    printf("Please enter the two numbers you want to find gcd of :");
    scanf("%d: %d:", &a, &b);                            //taking input from the user
    //while (b>0 && a>0)
    if (b>a)
       {
           a=b;
           b=a;
       }
    //else 
       //{
    while (b!=0)
         {
           a =b;
           b=a%b;
           printf("the gcd of the numbers is %d",a);
         }
    
    return 0;
}