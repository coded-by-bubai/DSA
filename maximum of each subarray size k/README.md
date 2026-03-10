# Sliding Window Maximum (C Implementation)

## 📌 Problem Statement

Given an integer array `arr[]` of size `n` and an integer `k`, find the maximum element in every contiguous subarray (window) of size `k`.

---

## 🧾 Example

**Input:**

```c
arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
k = 3;
```

**Output:**

```
3 3 5 5 6 7
```

Each value represents the maximum element in the current window of size `k`.

---

# 1️⃣ Brute Force Approach

## 🔹 Idea

For every window of size `k`, traverse all `k` elements and compute the maximum manually.

## 🔹 Algorithm

1. Loop from `i = 0` to `n - k`
2. Set `max = arr[i]`
3. Compare the next `k` elements
4. Store the maximum in the result array
5. Repeat for all windows
```
Window 1: [1  3 -1]  -3  5  3  6  7   → Max = 3
Window 2:  1 [3 -1 -3]  5  3  6  7   → Max = 3
Window 3:  1  3 [-1 -3 5]  3  6  7   → Max = 5
Window 4:  1  3 -1 [-3 5 3]  6  7   → Max = 5
Window 5:  1  3 -1 -3 [5 3 6]  7   → Max = 6
Window 6:  1  3 -1 -3  5 [3 6 7]   → Max = 7
```
## 🔹 Time Complexity

```
O(n × k)
```

## 🔹 Space Complexity

```
O(n - k + 1)
```

---

# 2️⃣ Optimized Approach (Deque Method)

## 🔹 Idea

Use a double-ended queue (deque) to store indices of useful elements in decreasing order.

The deque ensures:
- The front always contains the index of the maximum element
- Smaller elements are removed from the back

## 🔹 Working Principle

- Remove elements from the back if they are smaller than the current element.
- Remove elements from the front if they are outside the current window.
- The element at the front is always the maximum for the window.

## 🔹 Algorithm Steps

1. Process first `k` elements and maintain decreasing order.
2. For each new element:
   - Store the previous window maximum.
   - Remove out-of-window indices.
   - Remove smaller elements from the back.
   - Insert current index.
3. Store the maximum for the last window.
## 📊 Deque Processing Table

| i | arr[i] | Action Taken | Deque (Indices) | Deque (Values) | Window Max |
|---|--------|-------------|-----------------|----------------|------------|
| 0 | 1  | Insert 0 | [0] | [1] | — |
| 1 | 3  | Remove 0 (1 < 3), Insert 1 | [1] | [3] | — |
| 2 | -1 | Insert 2 | [1,2] | [3,-1] | 3 |
| 3 | -3 | Insert 3 | [1,2,3] | [3,-1,-3] | 3 |
| 4 | 5  | Remove 1 (out), Remove 3,2 (smaller), Insert 4 | [4] | [5] | 5 |
| 5 | 3  | Insert 5 | [4,5] | [5,3] | 5 |
| 6 | 6  | Remove 5,4 (smaller), Insert 6 | [6] | [6] | 6 |
| 7 | 7  | Remove 6 (smaller), Insert 7 | [7] | [7] | 7 |

## 🔹 Time Complexity

```
O(n)
```

Each element is inserted and removed at most once.

## 🔹 Space Complexity

```
O(n)
```

## 🔹 Why This Is Efficient

Reduces repeated comparisons and improves performance from `O(nk)` to `O(n)`.


---
