#include<stdio.h>
#include<stdlib.h>
int main(int argc, char*argv[]){
	if(argc==4){
		int a=atoi(argv[1]);
		int b=atoi(argv[2]);
		char *c=argv[3];
		switch(*c){                             //considers default as integer not compulsory.*c is element here
			case '+':{                          //sinle quotes because a character is surrounded by''
				printf("%d ",a+b);
				break;
			}
			case '-':{
				printf("%d ",a-b);
				break;
			}
			case '*':{
				printf("%d ",a*b);
				break;
			}
			case '/':{
				printf("%d ",a/b);
				break;
			}
		}
	}
	return 0;
}