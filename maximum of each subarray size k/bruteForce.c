#include<stdio.h>
#include<stdlib.h>

int* maxSub(int arr[], int n, int k){
    int* res = (int *)malloc((n-k+1)*sizeof(int));
    for (int i = 0; i < n-k+1; i++)
    {
        int max = arr[i];
        for (int j = i; j < i+k; j++)
        {
            if (arr[j]>max)
            {
                max = arr[j];
            }
            
        }
        res[i] = max;
    }
    return res;

}
int main(){
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    int* result = maxSub(arr, n, k);
    for (int i = 0; i<= n-k; i++)
    {
        printf("%d ", result[i]);
    }
    
    return 0;
}