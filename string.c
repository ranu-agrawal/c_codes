#include<stdio.h>
#include<string.h>
int main(){
    char str1[21];
    char str2[21];
    scanf("%s %s", str1, str2);
    printf("%s %s", str1, str2);
    printf("\n");
    char str3[41];
    int m,a,n;
    int i=0;
    int j=0;
    n=strlen(str1);
    m=strlen(str2);
    a=m+n;
    //for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            str3[i]=str1[j];           //j goes till n anyways so no special additional loop required
            j++;                       //j becomes 4
        }
    //}
    j=0;
    //}
    //for(int j=0;j<=m;j++){              // as j became 4 we need to initialize it to 0 again.
        for(int i=n;i<=a;i++){                       //or else it wont copy first 4 elements of str2 in str3
            str3[i]=str2[j];             //loop <=a not <a maybe because of '\0'
            j++;
        }
    //}
    printf("%s", str3);
    return 0;
}