#include<stdio.h>
#include<limits.h>

int maximumSubArraySum(int arr[],int n, int k){
    int max = INT_MIN;
    for (int i = 0; i<=n-k; i++){
        int currSum = 0;
        for (int j = i; j < i+k; j++)
        {
            currSum += arr[j];
        }
        if (currSum > max){
            max = currSum;
        }
        
    }
    return max;
}

int main(){
    int arr[] ={1,3,-1,-3,5,3,6,7};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = maximumSubArraySum(arr,n , k);
    printf("maximum subarray sum with size %d is : %d", k, max);
}