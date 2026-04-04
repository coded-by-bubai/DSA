#include <iostream>
#include<climits>

using namespace std;
int kadaneAlgo(int nums[], int n)
{
    int maxSum = INT_MIN, currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += nums[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}
int main()
{
    int arr[] = {3, -4, 5, 4, -1, 7, -8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = kadaneAlgo(arr, n);
    cout << "maximum subarray sum is : " << result;
    return 0;
}