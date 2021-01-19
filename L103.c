//stores output of command date in 2 files with time gap of 5 secs
#include<stdio.h>
#include<stdlib.h>
int main(){
    system("date>ranu2.txt");           //stores command output value in file ranu2.txt
    system("sleep 5");         //(sleep(5) can be used too)//waits for 5 secs(alwaysinsecsif5 mins convert into secs first5*60)
    system("date>file2.txt");           //stores command output value in file file2.txt
    FILE *fpointer1 , *fpointer2;
    fpointer1=fopen("ranu2.txt","r");
    char d1[100];
    char *c=fgets(d1,100,fpointer1);
    printf("%s", c);

    fpointer2=fopen("file2.txt","r");
    char d2[100];
    char *c1=fgets(d2,100,fpointer2);
    printf("%s", c1);
    return 0;
}