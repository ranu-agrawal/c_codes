#include <stdio.h>
int main()
{
    int n,i,b=0;
    printf("Enter a number :");
    int array[n];
    array[0]=1;
    array[1]=2;
    //for (n>0)
    for (int i=2; i*i<=n; ++i)
      {
          if (array[i]%i!=0)
            b=b+1; 
      }
    return 0;
}
