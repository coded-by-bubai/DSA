# Maximum Sum of Subarray of Size K

## Problem Statement

Given an integer array `arr[]` of size `n` and an integer `k`, find the maximum sum of any contiguous subarray of size `k`.

---

## Example

### Input

```
arr = [1, 3, -1, -3, 5, 3, 6, 7]
k = 3
```

### Output

```
16
```

### Explanation

Subarrays of size 3:

```
[1, 3, -1]  → 3  
[3, -1, -3] → -1  
[-1, -3, 5] → 1  
[-3, 5, 3]  → 5  
[5, 3, 6]   → 14  
[3, 6, 7]   → 16  ← Maximum
```

---

## Approach 1: Brute Force

### Idea

For every index `i`, calculate the sum of the next `k` elements and track the maximum.

### Time Complexity

```
O(n × k)
```

### Space Complexity

```
O(1)
```

---

## Approach 2: Sliding Window (Optimized)

### Idea

1. Compute the sum of the first `k` elements.
2. Slide the window one element at a time.
3. Subtract the element leaving the window.
4. Add the new element entering the window.
5. Update the maximum sum.

# Sliding Window Visualization 
## Sliding Formula Used

```
new_sum = previous_sum - outgoing_element + incoming_element
```



---

## Window Movement Table
**Array**
```
Index:  0   1   2   3   4   5   6   7
Value:  1   3  -1  -3   5   3   6   7
```

| Step | Window Index Range | Window Elements     | Calculation                  | Window Sum | Max So Far |
|------|--------------------|--------------------|------------------------------|------------|------------|
| 1    | 0 → 2              | [1, 3, -1]         | 1 + 3 + (-1)                 | 3          | 3          |
| 2    | 1 → 3              | [3, -1, -3]        | 3 - 1 + (-3)                 | -1         | 3          |
| 3    | 2 → 4              | [-1, -3, 5]        | -1 - 3 + 5                   | 1          | 3          |
| 4    | 3 → 5              | [-3, 5, 3]         | 1 - (-1) + 3                 | 5          | 5          |
| 5    | 4 → 6              | [5, 3, 6]          | 5 - (-3) + 6                 | 14         | 14         |
| 6    | 5 → 7              | [3, 6, 7]          | 14 - 5 + 7                   | 16         | 16         |

---

### Time Complexity

```
O(n)
```

### Space Complexity

```
O(1)
```
---