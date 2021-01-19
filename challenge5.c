#include <stdio.h>
int gcd (int a, int b);
float absolute(int x);
float sqroot(int y);
int a,b,min,max;
float x,y,result;
//declaring gcd function
int gcd ( int a, int b)
{
   //if (a<b)
   //{
     int z;
     while (b!=0)
      {
       //int z;
       a=b;
       b=z;
       z=a%b;
      }
     return min;
   }
   //else
   //{
      /* min =b;
       max =a%b;
       return min;
   }
}*/
float absolute (x)
//float result;
{
    if (x<0)
    {
        result = -x;
        return result;
    }
    else
    {
        result = x;
        return result;
    }
    
}
float sqroot (y)
//float result;
{
    {
        result =y^(1/2);
        return result;
    }
}
//calling of functions
int main()
{
    int result=0;
    result=gcd (10,14);
    printf("%d\n",result);

    result=absolute (5);
    printf("%d\n",result);

    result=sqroot(4);
    printf("%d\n", result);

    return 0;
}



