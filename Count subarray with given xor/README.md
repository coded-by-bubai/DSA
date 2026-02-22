# Count Subarrays With Given XOR

## 📌 Problem Statement

Given an array of integers `arr[]` and an integer `k`, count the number of **subarrays** whose XOR is equal to `k`.

> A subarray is a contiguous part of the array.

It is guaranteed that the answer fits within a 32-bit integer.

---

## 🧾 Examples

### Example 1

**Input**
```
arr = [4, 2, 2, 6, 4]
k = 6
```

**Output**
```
4
```

**Explanation**

Subarrays with XOR = 6:
- [4, 2]
- [4, 2, 2, 6, 4]
- [2, 2, 6]
- [6]

---

### Example 2

**Input**
```
arr = [5, 6, 7, 8, 9]
k = 5
```

**Output**
```
2
```

**Explanation**

Subarrays with XOR = 5:
- [5]
- [5, 6, 7, 8, 9]

---

# 💡 Approach

## 1️⃣ Prefix XOR Concept

Define:

```
prefix[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]
```

The XOR of a subarray from index `l` to `r` can be written as:

```
subarray_xor = prefix[r] ^ prefix[l - 1]
```

We want:

```
prefix[r] ^ prefix[l - 1] = k
```

Rearranging:

```
prefix[l - 1] = prefix[r] ^ k
```

So for every index `r`, we just need to count how many previous prefix values equal:

```
current_prefix ^ k
```

---

## 2️⃣ Why Use a Hash Map?

We store prefix XOR frequencies:

- **Key** → prefix XOR value  
- **Value** → number of times it has appeared  

This allows us to:
- Check required values in O(1)
- Count valid subarrays efficiently

---

# 🚀 Algorithm

1. Initialize:
   - `prefixXor = 0`
   - `count = 0`
   - `freq[0] = 1` (handles subarrays starting at index 0)

2. Traverse the array:
   - Update prefix: `prefixXor ^= arr[i]`
   - If `(prefixXor ^ k)` exists in map → add its frequency to `count`
   - Store current prefix in map


---

# ⏱ Complexity Analysis

### Time Complexity
```
O(n)
```
We traverse the array once and each hash map operation is O(1) on average.

### Space Complexity
```
O(n)
```
In the worst case, all prefix XOR values are unique.

---

# 🧠 Key Insight

Instead of checking all subarrays (O(n²)),  
we reduce the problem to counting prefix XOR frequencies (O(n)) using:

```
prefix[r] ^ prefix[l - 1] = k
```

This transforms a brute-force problem into an optimal linear-time solution.