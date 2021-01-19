#include<stdio.h>
#include<stdlib.h>
//in mail of padhai kar le

int Count(int arr[], int n, int x)
{
    int count = 0;
    int b = 0;
    int i= 1;
    int j=1;
    while(j != n) 
    {
        while(arr[j] - arr[i] < x)
        {
            j++;
        }
        b = n - j;
        count += b;
        i++;
        j++;
    }
    return count;
}

void mergesort(int a[], int l, int r, int n)
{
	int mid = (l + r) / 2;
	if(l < r)
	{
		mergesort(a, l, mid, n);
		mergesort(a, mid + 1, r, n);
		merge(a, l, mid, r, n);
	}
}

void merge(int a[], int l, int mid, int r, int n)
{
	int i = l, j = mid + 1, p = 0, b[n];
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
int main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int x;
    printf("Enter x : ");
    scanf("%d", &x);
    mergesort(arr, 0, n-1, n);
    int a = Count(arr, n, x);
    printf("%d", a);
}