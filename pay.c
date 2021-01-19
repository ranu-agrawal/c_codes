//calculating total salary of an employee

#include<stdio.h>
int main()
{   
    int Hours,hourpay=12,a,b,c,d;
    double e,f,g;
    printf("enter the no of hours worked : ");
    scanf("%d", &Hours);
    if (Hours<=40)
    {
      b=Hours*hourpay;
      printf("Your gross pay salary is : %d $\n", Hours*hourpay);
    } 
    else if (Hours>40)
    {
      a=40*12;
      c= (Hours-40)*18;
      b=a+c;
      printf("Your gross pay salary is : %d $\n", b);
    }
    else
    {
      printf("Whatever");
    //printf("For Your Taxrate");
      return 1;
    }
    ///d=a+b+c;
    if (b<=300)
    {
      printf("your taxrate is: 15 percent \n");
      printf("Tax applied : %f",0.15*b);
      //printf("Total salary in hand :", d-(0.15*(d)));
    }
    else if(b>300 && b<450)
    {
      e=0.15*300;
      f=0.20*(b-300);
      printf("Tax applied is : %f\n",e+f);
    }
    else if(b>450)
    {
      e=0.15*300;
      f=0.20*150;
      g=0.25*(b-450);
      printf("Tax applied is: %.2f\n",e+f+g);
    }
    return 0;
    

        


}