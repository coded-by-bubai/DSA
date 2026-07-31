#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

double medianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    if (n > m)
        return medianSortedArrays(nums2, nums1);
    int l = 0, r = n;
    while (l <= r) {
        int mid1 = (l + r) / 2;
        int mid2 = (n + m + 1) / 2 - mid1;

        int l1 = (mid1 == 0 ? INT_MIN : nums1[mid1 - 1]);
        int r1 = (mid1 == n ? INT_MAX : nums1[mid1]);
        int l2 = (mid2 == 0 ? INT_MIN : nums2[mid2 - 1]);
        int r2 = (mid2 == m ? INT_MAX : nums2[mid2]);

        if (l1 <= r2 && l2 <= r1) {
            if ((n + m) % 2 == 0)
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            else
                return max(l1, l2);
        }

        if (l1 > r2)
            r = mid1 - 1;
        else
            l = mid1 + 1;
    }
    return 0;
}

int main() {
    
    vector<int> a = { -5, 3, 6, 12, 15 };
    vector<int> b = { -12, -10, -6, -3, 4, 10 };
    cout << medianSortedArrays(a, b);
    
    return 0;
}