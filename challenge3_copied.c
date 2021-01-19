#include <stdio.h>
int main()
{
    int MinutesEntered = 0;
    double days =0.0;
    double years=0.0;
    double MinutesInYear=0.0;
    double MinutesInDAys=0.0;

    printf ("Please enter no of units :");
    //taking input from user 
    scanf ("%d", &MinutesEntered);
    MinutesInYear = (365*24*60);
    MinutesInDAys  = 24*60;
    days= MinutesEntered/MinutesInDAys;
    years= MinutesEntered/MinutesInYear;
    printf ("%d Minutes in days are %f and in years are %f", MinutesEntered, days, years);
    return 0;
}