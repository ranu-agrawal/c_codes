#include<stdio.h>
#include<stdlib.h>
struct part{                 /*structure containing real(x) and imaginary(y) parts
    double x;                               of the two integers*/      
    double y;
};
struct complex{
    struct part a;              /*structure containing the 2 complex numbers*/
    struct part b;
};
void add(struct complex c)     /*defining add*/
{
    double r,i;
    r = c.a.x + c.b.x;                /*real part of result*/
    i = c.a.y + c.b.y;                 /*imaginary part of result*/
    printf("%.2lf + %.2lfi\n", r, i);
}
void sub(struct complex c)
{
    double r,i;
    r = c.a.x - c.b.x;                 /*same as add*/
    i = c.a.y - c.b.y;
    printf("%.2lf + %.2lfi\n", r, i);
}
void mul(struct complex c)
{
    double r,i;
    r = (c.a.x * c.b.x) - (c.a.y * c.b.y);       /*same as add*/
    i = (c.a.x * c.b.y) + (c.a.y * c.b.x);
    printf("%.2lf + %.2lfi\n", r, i);
}
int main()                       /*driver function*/
{
    struct complex c;                    /*including contents of c in main()*/
    scanf("%lf %lf\n", &c.a.x, &c.a.y);  
    scanf("%lf %lf", &c.b.x, &c.b.y);
    add(c);
    sub(c);                     /*calling functions*/
    mul(c);
    return 0;
}