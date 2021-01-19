// 1.   fputc()-----to input(write) character in file
// 2.   fputs()-----to input(write) a complete string in file~fprintf()
// 3.   fgets()-----reads only one line of characters from a file
#include<stdio.h>
int main(){
    FILE * fpointer;

//1
    /*fpointer=fopen("ranu1.txt","w");
    fputc('a',fpointer);
    fclose(fpointer);*/

//2
    /*fpointer=fopen("ranu1.txt","w");
    fputs("Hello! How are you today?",fpointer);
    fclose(fpointer);*/

//3
    /*fpointer=fopen("ranu1.txt","r");
    char write[100];
    char *c=fgets(write,100,fpointer);
    printf("%s",c);*/

//4
    fpointer=fopen("ranu1.txt","w");
    return 0;
}