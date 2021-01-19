// basic(update) operations on binary heap

#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bottomUpHeapify(int i, int heap[])
{
    int p = (i-1)/2;
    while(p >=0 && heap[p] > heap[i])
    {
        swap(&heap[p] , &heap[i]);
        i = p;
        p = (i-1)/2;
    }
}
void topDownHeapify(int i, int n, int heap[])
{
    int l;
    while(2*i+2 < n)
    {
        l = (heap[2*i+1] < heap[2*i+2] ? 2*i+1 : 2*i+2) ;
        
        /*if(l<n && heap[l] < heap[i]) {
            swap(&heap[l], &heap[i]);
            i = l;
        }
        else break;*/   //incomplete
    
        if(heap[i] > heap[l])
        {
            swap(&heap[i], &heap[l]);
            i = l ;
        }
        else break;
        if(2* i + 1<n && heap[i] > heap[2*i + 1])   //when right child is>=n you check for the left child
        {
            swap(&heap[i], &heap[2*i + 1]);
        }
    
    }
}

void update(int i, int x, int n, int heap[])
{
    if(heap[i] < x) {
        heap[i] = x;
        topDownHeapify(i, n, heap);
    }
    else if(heap[i] > x) {
        heap[i] = x;
        bottomUpHeapify(i, heap);
    }
    //else return;
}

void add(int x, int heap[], int i) {         //adding at the last position
    heap[i] = x;
    bottomUpHeapify(i, heap);
}
int main()
{
    int n;
    printf("Enter number of inputs : ");
    scanf("%d", &n);
    int arr[n], heap[n];
    printf("Enter the elements : ");
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<n; i++) add(arr[i], heap, i);
    for(int i=0; i<n; i++) printf("%d ", heap[i]);
    printf("\n");
    update(2, 120, n, heap);
    //topDownHeapify(0, n, heap);
    for(int i=0; i<n; i++) printf("%d ", heap[i]);
    printf("\n");
    return 0;
}