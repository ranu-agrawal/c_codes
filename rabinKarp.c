//rabin karp algorithm to find pattern in a string
//time complexity for this code is (theta N-M+1) and in worst case is O(n*m)
/*txt = text string
 *pat = pattern
 *q = any prime number
 *p = hash value of pattern
 *t = hash value of text
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void search(char txt[], char pat[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int p = pat[0] - '0';       //gives ascii value of first element in pat
    int t = txt[0] - '0';       //likewise for txt
    int mul = 1;
    int i,j;
    for(i = 1; i<M; i++)
    {
        p = (p*10 + pat[i] - '0') % q;  //hash value of pat
        t = (t*10 +txt[i] - '0') % q;   //initial hash value of txt
        mul *=10;
    }
    for(i=0; i<=N-M; i++)
    {
        if(p == t)
        {
            for(j=0; j<M; j++) //checking for each character by sliding(this is the above loop)
            {
                if(txt[i+j] != pat[j]) 
                {
                    break;
                }
            }
            if(j == M)   //this indicates the above loop is completed without the break
            {
                printf("PAttern found at %d\n", i);    //happens when t = 34
            }
        }
        if(i<= N-M)
        {
            t = ((t - (txt[i]-'0')*mul)*10 + txt[i+M]-'0')%q; //hash value of t updated to 23 and then 34
            if (t<0)
            {
                t = t+q;          //a property of modular arithmatic
            }
        }
    }
}
int main()                      //driver function
{
    char txt[1000], pat[1000];
    int q =12859;                 //prime number
    scanf("%s %s", txt, pat);     //suppose, txt is 1234 and pat is 34
    search(txt, pat, q);
    return 0;
}