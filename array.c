#include<stdio.h>
int main()
{
    int grades[10];
    int count=10;
    long sum=0;
    float average;

    printf("\nEnter the 10 grades :\n");     //promp innput

    //read the 10 numbers to be averaged
    for (int i=0; i<count; ++i)
    {
       printf("%d: ",i+1);
       scanf("%d", &grades[i]);             //read a grade
       sum+=grades[i];                      //add it to sum
    }
    average= (float)sum/count;                     //average   //casting to float is done
    printf("The average of the ten numbers is %.2f \n",average);
    return 0;

}