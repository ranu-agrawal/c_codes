#include <stdio.h>
int main()
{
enum weekday {Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};
enum weekday today = Wednesday;
switch(today);
    {
      case Monday:  
        { printf("Today is monday");
          //break;
        }
      case Tuesday:
        { printf("Today is tuesday");
         //break;
        } 
      case Wednesday:
        { printf("Today is Wednesday");
         //break;
        } 
      case Thursday:
        { printf("Today is Thursday");
         //break;
        } 
     default:
        { printf("Whatever");
         //break;
        } 
    }
return 0;   
}