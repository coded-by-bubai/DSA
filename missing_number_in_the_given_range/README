# Missing Numbers in a Given Range

## Problem Statement

Given an array `arr[]` of integers and a range `[low, high]`, return all numbers within the range that are **not present** in the array.

The result should be returned in **sorted order**.

---

## Examples

### Example 1

**Input**
```
arr = [10, 12, 11, 15]
low = 10
high = 15
```

**Output**
```
[13, 14]
```

**Explanation**  
Numbers 13 and 14 lie in the range `[10, 15]` but are not present in the array.

---

### Example 2

**Input**
```
arr = [1, 4, 11, 51, 15]
low = 50
high = 55
```

**Output**
```
[50, 52, 53, 54, 55]
```

**Explanation**  
Numbers 50, 52, 53, 54 and 55 lie in the range `[50, 55]` but are not present in the array.

---

## Approach

1. Convert the array into a `set` for fast lookups.
2. Iterate from `low` to `high` (inclusive).
3. Add numbers not found in the set to the result list.
4. Return the result.

Using a set ensures constant-time membership checking.

---

## Python Implementation

```python
def missingRange(self, arr, low, high):
    nums = set(arr)
    result = []
    
    for num in range(low, high + 1):
        if num not in nums:
            result.append(num)
    
    return result
```

---

## Time Complexity

Let:
- `n = len(arr)`
- `k = high - low + 1`

Time Complexity:
```
O(n + k)
```

- O(n) to build the set
- O(k) to iterate through the range

---

## Space Complexity

```
O(n)
```

- For storing elements in the set

---

## Edge Cases Considered

- Empty array  
- No missing numbers  
- All numbers missing  
- Large range values  
