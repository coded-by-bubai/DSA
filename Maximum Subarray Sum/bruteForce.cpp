#include<iostream>
#include<climits>

using namespace std;

int maxSubSum(int arr[], int n){
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        for (int j = i; j < n; j++)
        {
            currSum += arr[j];
            maxSum = max(maxSum, currSum);
        }
        
    }
    return maxSum;
}

int main()
{
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = maxSubSum(arr, n);
    cout << "maximum subarray sum is : " << result;
    return 0;
}