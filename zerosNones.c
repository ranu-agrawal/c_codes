//hackerrank problem for segment trees
#include<stdio.h>
#include<math.h>

void buildTree(int tree[], int num, int n)
{
    for(int i=0; i<n; i++) tree[num-1+i] = 1;
    for(int i=n; i<num; i++) tree[num-1+i] = 0;
    for(int i=num-2; i>-1; i--) tree[i] = tree[2*i+1] + tree[2*i+2];
}

void update(int arr[], int tree[], int k, int n)
{
    arr[k] = 0;
    if(tree[n-1+k] == 0) return;
    else
    {
        tree[n-1+k] = 0;
    }
    int parent = (n-1+k-1)/2;
    while(parent > 0)
    {
        tree[parent]--;
        parent = (parent-1)/2;
    }
    tree[0] --;
}

int position(int tree[], int n, int k, int start, int end, int root)
{
    if(k > tree[root] || start < 0 || end > n-1 || start>end)
    {
        return -1;
    }
    if(k == tree[root] && start == end) return n-1 - start;
    int mid = (start + end)/2;
    if(k > tree[2*root+1]) return position(tree, n, k-tree[2*root+1], start, mid, 2*root+2);
    else return position(tree, n, k, mid+1, end, 2*root+1);
}

void printarray(int a[], int n)
{
	for(int i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int num = (int)pow(2,(int)ceil(log2(n)));
    int arr[num];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i=n; i<num; i++)
    {
        arr[i] = 0;
    }
    printarray(arr, num);

    int tree[2 * num];
    buildTree(tree, num, n);
    printarray(tree, 2*num-1);
    int q , k;
    scanf("%d %d", &q, &k);
    if (q == 0)
    {
        update(arr, tree, k, num);
        printf("Updated Array :");
        printarray(arr, num);
        printf("Updated tree  :");
        printarray(tree, 2*num-1);
    }
    else if(q == 1)
    {
        int a = position(tree, num, k, 0, num-1, 0);
        printf("%d \n", a);
    }
    else printf("Invalid Input(Enter 0 or 1)");
    //printarray(tree, 2*num-1);
    return 0;
}