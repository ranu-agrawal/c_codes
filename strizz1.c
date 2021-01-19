#include<stdio.h>

int filldummy(int n)
{
	int num = 1;
	while(n > 0)
	{
		n /= 2;
		num *= 2;
	}
	return num;
}

void build(int st[], int a[], int n)
{
	for(int i = 0; i < n; i++)
		st[n + i - 1] = a[i];

	for(int i = n - 2; i > -1; i--)
		st[i] = st[2*i +1] + st[2*i + 2];
}

int RSQ(int ST[], int a[], int n, int i, int j, int s, int e, int p)
{
	if(i <= s && e <= j) return ST[p];
	else if(j < s || i > e) return 0;
	int m = (s + e) / 2;
	return RSQ(ST, a, n, i, j, s, m, 2*p + 1) + RSQ(ST, a, n, i, j, m + 1, e, 2*p + 2);
}

void update(int ST[], int a[], int i, int x, int n)
{
	if(i < n)
	{
		a[i] = x;
		ST[n + i - 1] = x;
		i = (n + i - 2) / 2;
		while(i > 0)
		{
			ST[i] = ST[2*i + 1] + ST[2*i + 2];
			i = (i - 1) / 2;
		}
		ST[i] = ST[2*i + 1] + ST[2*i + 2];
	}
}

void printarray(int a[], int n)
{
	for(int i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);		//Input the number of integers
	int num = filldummy(n - 1);	//With the help of filldummy function, we will find the first big integer, which is a multiple of 2 
	int a[num];		//Create an array with first n integers and inputs and fill the remaining space with dummy variables (the dummy variable for sum query will be zeros)

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for(int i = n; i < num; i++)
		a[i] = 0;

	printf("ARRAY: ");
	printarray(a, num);

	int ST[2*num];
	build(ST, a, num);	//The code is very similar to binary heaps. The point you should remember is that for an array of size x, you will need x - 1 extra space that will act as internal nodes.
	printf("SEGTE: ");
	printarray(ST, 2*num - 1);

	int l , r;
	printf("Enter l & r  for range sum query: ");
	scanf("%d %d", &l, &r);
	printf("Range Sum Query of [%d, %d] is %d\n", l, r, RSQ(ST, a, num, l, r, 0, num - 1, 0));

	int index, x;
	printf("Enter index and number to update: ");
	scanf("%d %d", &index, &x);
	update(ST, a, index, x, num);
	printarray(ST, 2*num - 1);
}