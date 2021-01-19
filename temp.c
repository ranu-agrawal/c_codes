#include <stdio.h>
int main()
{
    double c,f;             //c if for celsius an f for farenheit
    printf("enter temperature in celsius :");
    scanf("%lf", &c);
    f= (9*c/5)+ 32;
    printf("%f degree celsius is %f farenheit", c, f);
    return 0;

    
}