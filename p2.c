#include<stdio.h>
#include<stdlib.h>
//float a,b;
//scanf("%f\n",&b);
//scanf("%f\n", &a);
float greater(float a, float b){
    float c;
    if(a>b){
        //printf("Greatest no is %f", a);
        c=a;
    }                            //ternary operator can be used
    else{
        //printf("Greatest no is %f", b);
        c=b;
    }
    return c;
}
void small(float a, float b){
    //float c=0.00;
    if(b>a){
        printf("Smallest no is %f", a);
    }
    else{
        printf("Snallest no is %f", b);
    }
    //return c;
}
int main(){
    float a,b;
    //float c=0.00;
    printf("Enter the numbers upto 5 decimal places : ");
    scanf("%f %f",&b, &a);
    printf(" greatest number is %.5f\n", greater(a,b));
    //printf("Smaller number is %.5f",small(a,b));
    //greater(a,b);
    printf("\n");
    small(a,b);
    
}
