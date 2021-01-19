#include <stdio.h>
int main(int argc , char * argv[])
{
    int no_of_arguments =argc;
    char * argument1 = argv[0];
    char * argument2 = argv[1];

    printf("no of arguments = %d\n" , no_of_arguments);
    printf("argument1 is the program name :%s\n", argument1);
    printf("argument2 is the comand line argument :%s\n", argument2);
    return 0;
}