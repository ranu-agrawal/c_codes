#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool isAnagram(char s[], char t[]);
int main(){
    char s[20];
    char t[20];
    scanf("%s %s",s,t);
    printf("%s %s", s, t);
    printf("\n");
    if(isAnagram(s,t)==true){
        printf("true");
    }
    else {
        printf("false");
    }
}
bool isAnagram(char s[],char t[]){
    //char s[20];
    //char t[20];
    int l=strlen(s);
    int arr[26];
    for(int i=0;i<26;i++){
        arr[i]=0;
    }
    if(l!=strlen(t)) return false;
    for(int i=0;i<l;i++){
        arr[s[i]-'a']++;
        arr[t[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(arr[i]) return false;
    }
    return true;
}