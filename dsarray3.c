#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void mergesort1(int a[], int l, int r);
void merge(int a[], int l, int mid, int r);
int findMin(int a[], int n);

int main()
{
	int a[10];
	for(int i = 0; i < 10; i++) scanf("%d", &a[i]);
	mergesort1(a, 0, 9);
	for(int i = 0; i < 10; i++) printf("%d ", a[i]);
    int b=findMin(a, 9);
    printf("%d", b);
}
int findMin(int a[], int n)
{
	int min = INT_MAX ;
	printf("%d\n", min);
	for(int i=1; i<n; i++)
	{
		if(abs(a[i]- a[i-1]) < min)
		{
			min = abs(a[i]- a[i-1]);
		}
		printf("%d\n", min);
	}
    return min;
}                     

void mergesort1(int a[], int l, int r)
{
	int mid = (l + r) / 2;
	if(l < r)
	{
		mergesort1(a, l, mid);
		mergesort1(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}

void merge(int a[], int l, int mid, int r)
{
	int i = l, j = mid + 1, p = 0, b[10];
	while(i <= mid && j <= r)
	{
		if(a[i] <= a[j]) b[p++] = a[i++];
		else b[p++] = a[j++];
	}
	while(i <= mid) b[p++] = a[i++];
	while(j <= r) b[p++] = a[j++];
	p = 0;
	i = l;
	while(i <= r) a[i++] = b[p++];
}