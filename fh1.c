//reading file using fscanf
#include<stdio.h>
int main(){
    FILE * fpointer;
    char write[100];
    fpointer=fopen("ranu1.txt","r");
    while(fscanf(fpointer,"%s",write)!=EOF){
        printf("%s",write);
    }
    fclose(fpointer);
    return 0;
}