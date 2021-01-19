// path in ZigZag labelled binary tree
#include<stdio.h>
#include<math.h>

void zigzagPath(int label)
{
    int parent=0;
    double level1 = log((double)label)/log((double)2);
    int level = (int)level1;
    int size = level;
    int ans[level+1];
    ans[level] = label ;
    ans[0] = 1;
    while(label > 1)
    {
        if(label % 2 == 0)
        {
            parent = label/2;
        }
        else
        {
            parent = (label-1)/2;
        }
        int n = pow(2,level-1);
        int arr[n];
        int j = n-1;
        for(int i = 0; i< n ; i++)
        {
            arr[i] = (j+1);
            j++;
        }
        int diff = arr[n-1] - parent;
        label = arr[0] + diff;
        ans[--level] = label;

        //OR

        //do
        /*
        int diff = 2*n - parent;
        label = n + diff-1;
        ans[--level] = label;
        */
    }
    for(int i=0; i<=size; i++)
    {
        printf("%d ", ans[i]);
    }
}
int main()
{
    int label = 14;
    zigzagPath(label);
}