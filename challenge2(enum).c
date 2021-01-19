//enum type

#include <stdio.h>
int main()
{
    enum company { GOOGLE , FACEBOOK , XEROX , YAHOO , EBAY , MICROSOFT };
    enum company name1 = "XEROX";
    enum company name2 = "GOOGLE";
    enum company name3 = "EBAY";

    printf ("%s\n %s\n %s\n", name1, name2, name3);
    return 0;
}