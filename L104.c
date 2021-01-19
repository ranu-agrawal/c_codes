#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE * fp, *fpointer1 , *fpointer2;
    fp=fopen("text.txt","w");
    fpointer1=fopen("ranu2.txt","r");
    fpointer2=fopen("file2.txt","r");
    if(fp==NULL || fpointer1==NULL || fpointer2==NULL){
        printf("No such files exist.");
    }
    char d1[100];
    char *c=fgets(d1,100,fpointer1);
    fprintf(fp,"%s",c);

    char d2[100];
    char *c1=fgets(d2,100,fpointer2);
    fprintf(fp,"%s",c1);
    
    fclose(fpointer1);
    fclose(fpointer2);
    fclose(fp);

    return 0;
}