#include<stdio.h>
void print(char string[]){
    printf("String is %s",string);
}
int main(){
    char string[10];
    scanf("%s",string);
    print(string);
    return 0;
}