#include<stdio.h>
#include<limits.h>
//RMQ wrong
//doesnt work for : try : 1 3 2 5 7 9 in(1,4)

//Functions to build segment tree//

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

void build(int ST[], int a[], int n)
{
	for(int i = 0; i < n; i++) ST[n + i - 1] = i;
	for(int i = n - 2; i > -1; i--)
	{
		ST[i] = a[ST[2*i + 1]] > a[ST[2*i + 2]] ? ST[2*i + 2] : ST[2*i + 1];
	}
}

//Function to update segment tree//

void update(int ST[], int a[], int n, int i, int x)
{
	if(i < n)
	{
		a[i] = x;
		i = (n + i - 2) / 2;
		while(i > 0)
		{
			ST[i] = a[ST[2*i + 1]] > a[ST[2*i + 2]] ? ST[2*i + 2] : ST[2*i + 1];
			i = (i - 1) / 2;
		}
		ST[i] = a[ST[2*i + 1]] > a[ST[2*i + 2]] ? ST[2*i + 2] : ST[2*i + 1];
	}
}

//Functions for range minimum query//

int RMQ1(int ST[], int a[], int n, int start, int end, int left, int right, int p)
{
	if(end < left || start > right) return n;
	if(start >= left && end <= right) return ST[p];
	int m = (start + end) / 2;
	int l1 = RMQ1(ST, a, n, start, m, left, right, 2*p);
	int l2 = RMQ1(ST, a, n, m+1, end, left, right, 2*p + 1);
	return (a[l1] < a[l2] ? l1: l2);
}

int RMQ(int ST[], int a[], int n, int l, int r)
{
	if(l > r || r > n || l < 0)
	{
		printf("Invalid input\n");
		return INT_MAX;
	}
	return RMQ1(ST, a, n, 0, n-1, l, r, 1);
}

void printarray(int a[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int n;
	printf("Enter the number of integers: ");
	scanf("%d", &n);
	int num = filldummy(n - 1);
	int a[num];

	for(int i = 0; i < n; i++) 
		scanf("%d", &a[i]);

	for(int i = n; i < num; i++) 
		a[i] = INT_MAX;

	printf("ARRAY: ");
	printarray(a, n);

	int ST[2*num];
	build(ST, a, num);
	printf("SEGTE: ");
	printarray(ST, 2*num - 1);

	/*int index, x;
	printf("Enter the index and the number to update: ");
	scanf("%d %d", &index, &x);
	update(ST, a, num, index, x);
	printf("ARRAY: ");
	printarray(a, n);
	printf("SEGTE: ");
	printarray(ST, 2*num - 1);*/

	int l, r;
	printf("Enter the number l & r for rmq: ");
	scanf("%d %d", &l, &r);
	printf("Range Minimum Query of [%d, %d] is %d\n", l, r, RMQ(ST, a, num, l, r));
}