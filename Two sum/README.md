# Two Sum 


Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to `target`.

You may assume:
- Each input has at most one solution.
- You may not use the same element twice.
- You can return the answer in any order.

---

## Example

### Input

```
nums = [5, 2, 11, 7, 1]
target = 9
```

### Output

```
Indices: 1, 3
Values: 2 + 7 = 9
```

---
# Approach 1: Brute Force

## Idea

Check every possible pair in the array using two nested loops.

For each element:
- Compare it with every other element after it.
- If their sum equals `target`, return their indices.



---

## Time & Space Complexity

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## Approach 2: HashMap (Optimal)

### Idea

While iterating through the array:

1. For each element `nums[i]`, compute:
   ```
   complement = target - nums[i]
   ```
2. Check if `complement` already exists in the hashmap.
3. If it exists:
   - We found the pair.
   - Return the stored index and current index.
4. Otherwise:
   - Store current number and its index in the hashmap.

This avoids nested loops and reduces time complexity.

---

## Why This Works

At each step, the hashmap stores elements we have already seen.

Instead of searching the entire array for a matching pair, we check in **O(1)** time using the hashmap.

---

## Step-by-Step Execution

| i | nums[i] | complement | HashMap Before | Action |
|---|---------|------------|---------------|--------|
| 0 | 5       | 4          | {}            | Store 5 → 0 |
| 1 | 2       | 7          | {5:0}         | Store 2 → 1 |
| 2 | 11      | -2         | {5:0,2:1}     | Store 11 → 2 |
| 3 | 7       | 2          | {5:0,2:1,11:2}| Found 2 → Return |

---

## Time & Space Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---
