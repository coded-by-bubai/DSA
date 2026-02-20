#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string largestNumber(vector<int>& arr) {
    vector<string> nums;

    // Convert integers to strings
    for (int num : arr)
        nums.push_back(to_string(num));

    // Custom sort with comparison
    sort(nums.begin(), nums.end(), [](string a, string b) {
        return a + b > b + a;
    });

    // Edge case: if largest is "0"
    if (nums[0] == "0")
        return "0";

    string result = "";
    for (string s : nums)
        result += s;

    return result;
}

int main() {
    vector<int> arr = {3, 30, 34, 5, 9};
    cout << largestNumber(arr) << endl;

    vector<int> arr2 = {54, 546, 548, 60};
    cout << largestNumber(arr2) << endl;

    return 0;
}