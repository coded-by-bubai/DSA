#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countSubarraysWithXorK(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int prefixXor = 0;
    int count = 0;

    // Important: handles subarrays starting from index 0
    freq[0] = 1;

    for (int num : arr) {
        prefixXor ^= num;

        // Check if there exists a prefix that gives XOR = k
        if (freq.find(prefixXor ^ k) != freq.end()) {
            count += freq[prefixXor ^ k];
        }

        // Store current prefixXor
        freq[prefixXor]++;
    }

    return count;
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    cout << countSubarraysWithXorK(arr, k);

    return 0;
}