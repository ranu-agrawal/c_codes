/*program to read two polynomials and print their degree followed by the sum and product*/
#include<stdio.h>
#include<stdlib.h>
void add(double coeff1[], double coeff2[], int m ,int n);
void mult(double coeff1[], double coeff2[], int m ,int n);  /*function prototypes*/
int max(int m, int n);
int main(){                                      /*driver function*/
    int m,n;
    int degree1 , degree2;
    scanf("%d", &degree1);                       /*input degree of 1st polynomial*/
    m=degree1+1;
    double coeff1[m];
    for(int i=0;i<m;i++)
    {
        scanf("%lf", &coeff1[i]);                /*input coefficients of 1st polynomial*/
    }
    scanf("\n%d", &degree2);                    //input degree of 2nd polynomial
    n=degree2 +1;
    double coeff2[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lf", &coeff2[i]);                 //input coefficientts of 2nd polynomial
    }
    printf("%d ",max(m-1,n-1));                 //printing max degree for addition
    add(coeff1,coeff2,m,n);                 //calling add function(handle transfers to add())
    printf("\n");
    printf("%d ",degree1+degree2);             //print degree for multiplication
    mult(coeff1,coeff2,m,n);                //calling mult function(handle transfers to mult())
}
int max(int m,int n)                            //defining and writing max function(return max degree)
{
    return (m>n? m:n);                       //ternary operator
}        

void add(double coeff1[], double coeff2[], int m,int n)    //function for addition
{
    int x=max(m,n);
    double sum[x];
    for(int i=0;i<m;i++)
    {
        sum[i]=coeff1[i];              //copying all coefficients of 1st poly in sum[]
    }
    for(int i=0;i<n;i++)
    {
        sum[i]+=coeff2[i];            //adding coefficients of 2nd poly in sum[]
    }
    for(int i=0;i<x;i++)
    {
        printf("%lf ", sum[i]);       //printing addition of coefficients
    }
}

void mult(double coeff1[], double coeff2[], int m ,int n)    //function for multiplying coeff of resultant
{
    double product[m+n-1];               //array to store resultant
    for(int i=0;i<m+n-1;i++)
    {
        product[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            product[i+j]+=coeff1[i]*coeff2[j];        //logic for multiplication
        }
    }
    for(int i=0;i<m+n-1;i++)
    {
        printf("%lf ",product[i]);        //printing the resultant array
    }
    return 0;
}
