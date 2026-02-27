# Second Largest Element in an Array

## Problem Statement

Given an array of positive integers `arr[]`, return the **second largest element** in the array.

If the second largest element does not exist, return `-1`.

### Note:
- The second largest element must be **strictly less than** the largest element.
- Duplicate values of the largest element should not be considered as the second largest.

---

## Example

### Input
```
arr = [2, 5, 8, 6, 10, 2, 0, 22, 100, 99, 98, 50]
```

### Output
```
99
```

---

## Edge Cases

- Array has fewer than 2 elements → return `-1`
- All elements are equal → return `-1`
- Array contains duplicates of the largest element
- Array is already sorted
- Array contains negative values (if allowed)

---

# Approach 1: Single Pass (Optimal)

### Idea

Use two variables:
- `largest`
- `secondLargest`

Traverse the array once:
- If current element > largest → update both
- If current element < largest but > secondLargest → update secondLargest

### Time Complexity
```
O(n)
```

### Space Complexity
```
O(1)
```

---

# Approach 2: Two Pass Method

### Idea

1. First pass → Find largest element
2. Second pass → Find largest element not equal to largest

### Time Complexity
```
O(2n) ≈ O(n)
```

### Space Complexity
```
O(1)
```

---

# Approach 3: Sorting

### Idea

1. Sort the array
2. Traverse from the end
3. Return first element not equal to largest

### Time Complexity
```
O(n log n)
```

### Space Complexity
```
O(1)  (ignoring sort implementation space)
```

---

# Comparison

| Approach        | Time Complexity | Space Complexity | Recommended |
|---------------|-----------------|-----------------|-------------|
| Single Pass   | O(n)           | O(1)            | Yes         |
| Two Pass      | O(n)           | O(1)            | Acceptable  |
| Sorting       | O(n log n)     | O(1)            | No (Slower) |

---
