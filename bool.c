#include <stdio.h>
#include <stdbool.h>
int main()
{
    enum gender {male,female};
    enum gender mygender = female;
    enum gender anothergender = male;
    bool ifemale= (mygender==anothergender);
    printf( "%i\n" ,mygender);
    return 0;
}