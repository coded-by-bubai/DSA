#include<stdio.h>

int maximumSubArraySum(int arr[], int n, int k){
    int currSum = 0;
    //for first window
    for (int i = 0; i<k; i++){
        currSum += arr[i];
    }
    int max = currSum;
    for (int i = k; i < n; i++)
    {
        currSum += arr[i] - arr[i-k];
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