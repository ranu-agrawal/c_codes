// heap sort for min heap using heapify

#include<stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int heap[], int n, int i)
{
    int smallest = i;
    int l = 2*i+1 ;
    int r = 2*i +2;
    if(l < n && heap[l] < heap[smallest]) smallest = l;
    if(r < n && heap[r] < heap[smallest]) smallest = r;
    if(smallest != i)
    {
        swap(&heap[smallest], &heap[i]);
        heapify(heap, n, smallest);
    }
}
void heapsort(int heap[], int n)
{
    for(int i = n-1/2; i>=0; i--)
    {
        heapify(heap, n, i);
    }
    for(int i = n-1; i>=0; i--)
    {
        swap(&heap[0], &heap[i]);
        heapify(heap, i, 0);
    }
}
void print(int heap[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", heap[i]);
    }
}
int main()
{
    int heap[] = {4,6,3,2,9,7,8};
    int n = sizeof(heap)/sizeof(heap[0]);
    heapsort(heap, n);
    //print(heap, n);
    for(int i=n-1; i>=0; i--) printf("%d ", heap[i]);
    return 0;
}