#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (m.find(complement) != m.end()) {
            return {m[complement], i};
        }

        m[nums[i]] = i;
    }

    return {};  // No solution
}

int main() {
    vector<int> nums = {5, 2, 11, 7, 1};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
        cout << "Values: " 
             << nums[result[0]] << " + " 
             << nums[result[1]] << " = " 
             << target << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}