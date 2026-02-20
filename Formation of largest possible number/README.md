# 🏆 Largest Number from Array

## 📌 Problem Statement

Given an array of non-negative integers `arr[]`, arrange them such that after concatenating all elements in order, the result forms the **largest possible number**.

Since the resulting number may be very large, return it as a string.

---

## 🧠 Examples

### Example 1

**Input**
```text
arr = [3, 30, 34, 5, 9]
```

**Output**
```text
9534330
```

**Explanation**

The arrangement `[9, 5, 34, 3, 30]` produces the largest possible number.

---

### Example 2

**Input**
```text
arr = [54, 546, 548, 60]
```

**Output**
```text
6054854654
```

**Explanation**

The arrangement `[60, 548, 546, 54]` produces the maximum value.

---

## 🔍 Understanding the Problem

We are not adding numbers.

We are rearranging them and **concatenating** them.

For example:

```text
[3, 30]
```

Possible results:

```text
"330"
"303"
```

Since `"330"` is larger than `"303"`, `3` should come before `30`.

The challenge is determining the correct order between any two numbers.

---

## 🚀 Approach

### 🔹 Key Insight

For any two numbers `a` and `b`, only two arrangements are possible:

- `a` followed by `b` → `ab`
- `b` followed by `a` → `ba`

To maximize the final number:

- Place `a` before `b` if  
  ```text
  a + b > b + a
  ```
- Otherwise, place `b` before `a`.

This becomes our custom sorting rule.

---

## 🛠 Algorithm Steps

1. Convert all integers to strings.
2. Sort the array using a custom comparator:
   - Compare `(a + b)` and `(b + a)`
3. If the first element after sorting is `"0"`, return `"0"`  
   (this handles cases like `[0, 0]`)
4. Concatenate all strings and return the result.

---

## 💻 C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

string largestNumber(vector<int>& arr) {
    vector<string> nums;

    // Convert integers to strings
    for (int num : arr) {
        nums.push_back(to_string(num));
    }

    // Custom sorting with compare
    sort(nums.begin(), nums.end(), [](string &a, string &b) {
        return a + b > b + a;
    });

    // Edge case: if the largest element is "0"
    if (nums[0] == "0")
        return "0";

    // Concatenate result
    string result = "";
    for (string &s : nums) {
        result += s;
    }

    return result;
}
```

---

## ⏱ Time Complexity

- Sorting: `O(n log n)`
- Each comparison: `O(k)`  
  where `k` = maximum number of digits in an element

**Overall Complexity:**

```text
O(n log n × k)
```

---

## 🧩 Edge Cases

- All elements are zero → return `"0"`
- Single element array → return that element as string
- Large numbers → handled safely using strings

---

## 📚 Concepts Used

- Custom Comparator
- Greedy Strategy
- String Manipulation
- Sorting
- Edge Case Handling

---

## 🎯 Key Takeaway

The core of this problem is defining the correct comparison rule:

> Between two numbers `a` and `b`, the order that produces the larger concatenated result should come first.

Once the comparator is correct, the rest is straightforward sorting.