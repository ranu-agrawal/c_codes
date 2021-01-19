#include<stdio.h>
int main()
{
    int minutes;
    double days;
    double years;
    //double days, years;
    printf("PLease enter number of minutes:");
    scanf("%d", &minutes);
    days=(minutes/60.0)/24.0;
    years=((minutes/60.0)/24.0)/365.0;
    printf("the no of %d minutes is %f days and %f years\n", minutes, days, years);
    return 0;
}