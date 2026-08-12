#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int maxSubarrayLength(vector<int>& nums, int k) {
    unordered_map<int, int> freq;

    int n = nums.size(), left = 0, right = 0, ans = 0;

    while(right<n){
        freq[nums[right]]++;
        while(freq[nums[right]] > k){
            freq[nums[left]]--;
            left++;
        }
        ans = max(ans, right - left + 1);

        right++;
    }

    return ans;
}

int main(){
    vector<int> arr = {1,2,3,1,2,3,1,2};
    cout << maxSubarrayLength(arr, 2);
    return 0;
}