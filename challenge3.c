// c program to convert the number of minutes to days and years

#include <stdio.h>
int main()
{
    int mins;
    //scanf("%d", &mins);
    double days  = (mins/60.0)/24.0;
    double years = days/365.0;
    scanf("%d", &mins);
    printf("Number of days are %f\n", days);
    printf("Number od years are %f\n", years);
    return 0;
}

//problem is scanf should be specified before doing calculations