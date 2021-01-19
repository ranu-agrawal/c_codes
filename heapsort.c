// sorting elements for a min heap(smallest element at the root)
//top down and bottom up both gives same output
//check out the gadbad when you feel good


#include<stdio.h>
void heapsort(int arr[], int n);
void bottomUpHeapify(int i, int heap[]);
//void heapify(int arr[], int i, int n);
void topDownHeapify(int i, int n, int heap[]);
void print(int arr[], int n);

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void topDownHeapify(int p, int n, int heap[])
{
    int l;
    while(2*p+2 < n)
    {
        l = (heap[2*p+1] < heap[2*p+2] ? 2*p+1 : 2*p+2) ;
        
        /*if(l<n && heap[l] < heap[i]) {
            swap(&heap[l], &heap[i]);
            i = l;
        }
        else break;*/   //incomplete
    
        if(heap[p] > heap[l])
        {
            swap(&heap[p], &heap[l]);
            p = l ;
        }
        else break;
        /*if(2* p + 1<n && heap[p] > heap[2*p + 1])   //when right child is>=n you check for the left child
        {
            swap(&heap[p], &heap[2*p + 1]);
        }*/
    
    }
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
void heapsort(int heap[], int n)
{
    for(int i = n-1; i>=0; i--)
    {
        swap(&heap[0], &heap[i]);
        topDownHeapify(0, n, heap);
    }
}

void add(int x, int heap[], int i) {         //adding at the last position
    heap[i] = x;
    bottomUpHeapify(i, heap);
}

int main()
{
    int n;
    int arr[] = {4,6,3,2,9,7,8};
    n = sizeof(arr)/sizeof(arr[0]);
    int heap[n];
    for(int i=0; i<n; i++) add(arr[i], heap, i);
    print(heap,n);
    printf("\n");
    heapsort(heap, n);
    print(heap,n);
    //for(int i=0; i<n; i++) printf("%d ", heap[i]);
    return 0;
}
void print(int heap[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", heap[i]);
    }
}