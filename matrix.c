#include<stdio.h>
int main(){
    int arow,acol,brow,bcol;
    int i,k,j;
    printf("Enter number of rows in a");
    scanf("%d",&arow);
    printf("Enter number of columns in a");
    scanf("%d",&acol);
    printf("Enter number of rows in b");
    scanf("%d",&brow);
    printf("Enter number of columns in b");
    scanf("%d",&bcol);
    if(acol!=brow) return -1;
    int a[arow][acol];
    int b[brow][bcol];
    int r[arow][bcol];
    printf("matrix a\n");
    for(int i=0;i<arow;i++){
        for(int k=0;k<acol;k++){
            scanf("%d",&a[i][k]);          //taking matrix 1 as input
           // r[i][j]=0;
        }
    }
    printf("Matrix b");
    printf("\n");
    for(int k=0;k<brow;k++){
        for(int j=0;j<bcol;j++){
            scanf("%d",&b[k][j]);          //taking matrix 2 as input
        }
    }
    for(int i=0;i<arow;i++){
        for(int j=0;j<bcol;j++){
            for(int k=0;k<brow;k++){
                r[i][j]+= a[i][k] * b[k][j];      //logic of code
            }
        }
    }
    printf("Resultant matrix\n");
    for(int i=0;i<arow;i++){
        for(int j=0;j<bcol;j++){
            printf("%d ",r[i][j]);                  //printing resultant matrix
        }
        printf("\n");
    }
    return 0;
}