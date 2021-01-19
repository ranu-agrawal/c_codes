//calculate the area and perimeter of a rectangle

#include<stdio.h>
int main()
{
    double length, breadth;
    scanf(" %f %f ", length, breadth);
    double perimeter=2*(length+breadth);
    double area=length*breadth;

    printf("the perimeter of rectangle is: %.2f\n",perimeter);
    printf("the are of rectangle is : %.2f\n", area);
    return 0;
}