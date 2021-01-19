#include<stdio.h>
int main()
{
    int r;
    float a;
    printf("Enter radius of circle: ");
    scanf("%d", &r);
    if(r>0)
      printf( "Area = %.2f\n", 3.14*r*r);
    else
      printf("Invalid Input");
    return 0;
}