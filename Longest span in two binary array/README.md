# Longest Span with Same Sum in Two Binary Arrays

## 🧩 Problem Statement

Given two binary arrays `a1[]` and `a2[]` of equal length `n`, find the maximum length of a subarray `[i...j]` such that:

```
a1[i] + a1[i+1] + ... + a1[j] 
= 
a2[i] + a2[i+1] + ... + a2[j]
```

---

## 📌 Examples

### Example 1

**Input**
```text
a1 = [0, 1, 0, 0, 0, 0]
a2 = [1, 0, 1, 0, 0, 1]
```

**Output**
```text
4
```

**Explanation**  
The longest span is from index `1` to `4`.

---

### Example 2

**Input**
```text
a1 = [0, 1, 0, 1, 1, 1, 1]
a2 = [1, 1, 1, 1, 1, 0, 1]
```

**Output**
```text
6
```

**Explanation**  
The longest span is from index `1` to `6`.

---

### Example 3

**Input**
```text
a1 = [0, 0, 0]
a2 = [1, 1, 1]
```

**Output**
```text
0
```

**Explanation**  
There is no span where the sums are equal.

---

# 🧠 Approaches

---

## 1️⃣ Naive Approach — Checking All Subarrays

### 💡 Idea

- Fix a starting index `i`
- Extend ending index `j`
- Maintain running sums of both arrays
- If sums match → update maximum length

### 🔎 Why It Works

It checks every possible subarray and compares sums directly.

### ⏱ Complexity

- **Time:** O(n²)
- **Space:** O(1)

---

## 2️⃣ Optimal Approach — Prefix Difference Technique

### 🔥 Core Observation

We want:

```
sum(a1[i..j]) = sum(a2[i..j])
```

Rewrite it as:

```
sum(a1[i..j]) - sum(a2[i..j]) = 0
```

---

### Step 1: Use Prefix Sums

Let:

```
prefix1[i] = sum(a1[0..i])
prefix2[i] = sum(a2[0..i])
```

Define:

```
diff[i] = prefix1[i] - prefix2[i]
```

---

### 🔑 Key Logic

If for two indices `i` and `j` (where j < i):

```
diff[i] == diff[j]
```

Then:

```
sum(a1[j+1..i]) = sum(a2[j+1..i])
```

So that span has equal sum.

---

### ⚙ Implementation Logic

- Maintain running difference:
  ```
  diff = prefix1 - prefix2
  ```

- If `diff == 0`
  → span from `0` to `i` is valid

- If `diff` seen before
  → span length = `i - firstOccurrence[diff]`

- Store only the first occurrence of each difference

---

### ⏱ Complexity

- **Time:** O(n)
- **Space:** O(n)

---

## 🧮 Alternative: Using Difference Array Instead of Hash Map

Since prefix difference can range from `-n` to `+n`,  
we can use an array of size `2*n + 1`.

To handle negative values:

```
index = diff + n
```

This shifts range from:

```
[-n, n] → [0, 2n]
```

---

## 📌 Intuition Summary

Think of:

```
diff = how much a1 is ahead of a2 so far
```

If at two indices the difference is the same,  
then between those indices neither array gained extra over the other.

So the sums in that span must be equal.

---

## ⚖ Final Comparison

| Approach         | Time  | Space | Notes                  |
|------------------|-------|--------|------------------------|
| Naive            | O(n²) | O(1)   | Brute force            |
| Prefix + Array   | O(n)  | O(n)   | Uses shifted indexing  |
| Prefix + HashMap | O(n)  | O(n)   | Clean and practical    |

---

## 🎯 Pattern Used

- Prefix Sum  
- Hash Map for first occurrence  
- Longest Zero-Sum Subarray concept  

---

## 🏁 Final Takeaway

This problem reduces to:

> Find the longest subarray with sum = 0  
> in the prefix difference array.

This pattern is common in:
- Equal number of 0s and 1s  
- Longest zero-sum subarray  
- Balanced binary array problems  