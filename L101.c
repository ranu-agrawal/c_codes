#include<stdio.h>
#include<stdlib.h>
int main(int argc, char * argv[]){
    int count=0;
    int sum=0;
    for(int i=1;i<argc;i++){
        count++;
        sum+=atoi(argv[i]);
    }
    printf("%d %d\n",count,sum);
    return 0;
}