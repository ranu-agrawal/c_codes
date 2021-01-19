//enum type

#include <stdio.h>
int main()
{
    enum company { GOOGLE , FACEBOOK , XEROX , YAHOO=10 , EBAY , MICROSOFT };
    enum company name1 = XEROX;
    enum company name2 = GOOGLE;
    enum company name3 = EBAY;

    //%i and %u both can be used for integers

    printf ("%u\n%i\n%u\n", name1, name2, name3);
    return 0;
}