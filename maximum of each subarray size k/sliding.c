#include<stdio.h>
#include<stdlib.h>

int* maxSub(int arr[], int n, int k){
    if (k <= 0 || k > n) return NULL;
    int* res = (int *)malloc((n-k+1)*sizeof(int));
    int* deque = (int *)malloc(n*sizeof(int));
    int front = 0, back = -1;
    int idx = 0;

    for (int i = 0; i < k; i++)
    {
        while (front <= back && arr[deque[back]] <= arr[i])
        {
            back--;
        }
        
        deque[++back] = i;
    }
    for (int i = k; i < n; i++)
    {
        res[idx++] = arr[deque[front]];
        while (front <= back && deque[front] <= i-k)
        {
            front++;
        }
        while (front <= back && arr[deque[back]] <= arr[i])
        {
            back--;
        }
        deque[++back] = i;
    }
    res[idx++] = arr[deque[front]];

    free(deque);
    return res;
    
}

int main(){
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    int* result = maxSub(arr, n, k);
    if (result != NULL)
    {
        for (int i = 0; i< n-k+1; i++)
        {
            printf("%d ", result[i]);
        }
        free(result);
    }
    return 0;
}