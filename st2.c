// Aakash and his assignments - assignment-o-holic aakash haha

#include<stdio.h>
#include<stdlib.h>

int fill0s(int n)
{
    int power = 1;
    while(n > 0)
    {
        n = n/2;
        power *= 2;       
    }   
    return power;
} 
   
void Build(int* segment_tree[], int n)
{
    for(int i = 0; i < 26; i++)
    {
        for(int j = n - 2; j > -1; j--)
        {
            segment_tree[i][j] = segment_tree[i][2*j + 1] + segment_tree[i][2*j + 2];
        }
    }
}
 //function for counting total no. of a's , b's and so on...in range
int RangeSumQuery(int segment_tree[], int LeftLimit, int RightLimit, int start, int end, int p)
{ 
    if (start >= LeftLimit && end <= RightLimit) return segment_tree[p];
    else if (start > RightLimit || end < LeftLimit) return 0;
    else{
        int mid = (start + end) / 2;
        int left_sum = RangeSumQuery(segment_tree, LeftLimit, RightLimit, start, mid, 2 * p + 1);
        int right_sum = RangeSumQuery(segment_tree, LeftLimit, RightLimit, mid + 1, end, 2 * p + 2);
        return left_sum + right_sum;
    }
}
int SmallestChar(int* segment_tree[], int n, int LeftLimit, int RightLimit, int K)
{
    for(int i = 0; i < 26; i++)
    {
        if(K > 0) 
        {
            int sum = RangeSumQuery(segment_tree[i], LeftLimit, RightLimit, 0, n - 1, 0);
            if(sum >= K) return i;
            K -= sum;
        }
        else return -1;
    }
    return -1;
}
   
void Update(int* segment_tree[], char* string, int n, int index, char new_char)
{
    if(string[index] != new_char) 
    {
        char alphabet = string[index];
        string[index] = new_char;
        segment_tree[new_char - 'a'][n - 1 + index] = 1;
        segment_tree[alphabet - 'a'][n - 1 + index] = 0;
        int parent = ( n + index - 2) / 2;
        while( parent > 0)
        {
            segment_tree[new_char - 'a'][parent] += 1;
            segment_tree[alphabet - 'a'][parent] -= 1;
            parent = (parent - 1) / 2;
        }
        segment_tree[new_char - 'a'][0] += 1;
        segment_tree[alphabet - 'a'][0] -= 1;
    }
}
   
   
int main()
{
    int num_of_elements, number_of_operations;
    printf("Enter no. of elements and operations : ");
    scanf("%d %d",&num_of_elements, &number_of_operations);
    int len = fill0s(num_of_elements);
    char* string = calloc(len, sizeof(char));
    printf("Enter the string : ");
    scanf("%s", string); 
    int *segment_tree[26]; 
    for (int i = 0; i < 26; i++) segment_tree[i] = (int *)calloc(2 * len, sizeof(int)); 
    for(int i = 0; i < num_of_elements; i++) segment_tree[string[i] - 'a'][ len - 1 + i ] = 1;
    Build(segment_tree, len);
    for(int i = 0; i < number_of_operations; i++)
    {
        int type;
        scanf("%d",&type);
        if(type == 1)
        {
            int LeftLimit, RightLimit, K;
            scanf("%d %d %d", &LeftLimit, &RightLimit, &K); 
            int answer = SmallestChar(segment_tree, len, LeftLimit - 1, RightLimit - 1, K);
            if(answer != -1) printf("%c\n", answer + 'a');
            else printf("Out of range\n");
        }
        else
        {
            int index; 
            char alphabet; 
            scanf("%d %c",&index, &alphabet);
            Update( segment_tree, string, len, index - 1, alphabet);
            printf("%s", string);
        }
    }
}