#include<stdio.h>
#define MONTHS 12
int main()
{
    int days[MONTHS]={31,28,31,30,31,30,31,31,30,31,30,31};         //i can be referred as index
    for (int i=0;i<MONTHS;++i)
    printf("The number of days in %d are %d\n", i+1,days[i]);
    return 0;
}