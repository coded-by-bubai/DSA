# 📚 H-Index

## 🧠 Problem Statement

You are given an integer array `citations[]`, where `citations[i]` represents the number of citations received by the **i-th** paper of a researcher.

Your task is to compute the researcher’s **H-index**.

---

## 📌 Definition

The **H-index** is the maximum value `H` such that:

- The researcher has **at least H papers**
- Each of those papers has **at least H citations**

Mathematically:

```
H = max { h | at least h papers have ≥ h citations }
```

---

## 📝 Examples

### Example 1

**Input**
```
citations = [3, 0, 5, 3, 0]
```

**Output**
```
3
```

**Explanation**

There are 3 papers with at least 3 citations → `[3, 5, 3]`.

There are not 4 papers with at least 4 citations.

So, H-index = 3.

---

### Example 2

**Input**
```
citations = [5, 1, 2, 4, 1]
```

**Output**
```
2
```

**Explanation**

There are 3 papers with at least 2 citations → `[5, 2, 4]`.

But there are not 3 papers with at least 3 citations.

So, H-index = 2.

---

## 🔍 Key Insight

The H-index is NOT:

- Maximum citations
- Total citations
- Average citations

It measures a balance between:

- Number of papers
- Citations per paper

We are looking for the largest number `H` such that:

```
Number of papers ≥ H
AND
Each of those papers has citations ≥ H
```

---

## 🚀 Approach 1: Sorting (O(n log n))

### Steps

1. Sort the array in descending order.
2. Traverse the array.
3. Find the largest index `i` where:

```
citations[i] ≥ i + 1
```

4. Return `i + 1`.

### 🔎 Visual Walkthrough

### Example

```
citations = [3, 0, 5, 3, 0]
```

### Step 1: Sort in descending order

```
[5, 3, 3, 0, 0]
```

### Step 2: Compare index vs citation

Check condition:

| Index | Citation | Condition |
|--------|----------|------------|
| 0 | 5 | 5 ≥ 1 ✔ |
| 1 | 3 | 3 ≥ 2 ✔ |
| 2 | 3 | 3 ≥ 3 ✔ |
| 3 | 0 | 0 ≥ 4 ✘ |
| 4 | 0 | 0 ≥ 5 ✘ |

The last valid position is `3`, so:

```
H-index = 3
```
---

## 🧩 Why This Works

After sorting:

- Position `i` represents `i + 1` papers.
- If the citation at that position is still ≥ `i + 1`, it satisfies the condition.

We are looking for the largest such position.

---

### Time Complexity

```
O(n log n)
```

### Space Complexity

```
O(1)  (ignoring sorting space)
```

---

## ⚡ Approach 2: Counting (O(n))

Since H-index cannot exceed the total number of papers `n`, we can use a counting array.

### Idea

- Create a frequency array of size `n + 1`
- Count how many papers have each citation value
- Traverse from highest possible `H` downwards

### 🔎 Visual Walkthrough

### Example

```
citations = [3, 0, 5, 3, 0]
n = 5
```

### Step 1: Build frequency array

We cap values greater than `n` at index `n`.

```
Index (Citation count): 0  1  2  3  4  5
Frequency:              2  0  0  2  0  1
```

Meaning:

- 2 papers have 0 citations
- 2 papers have 3 citations
- 1 paper has 5 citations


### Step 2: Traverse from high to low

We accumulate total papers:

```
i = 5 → total = 1      (1 ≥ 5 ? No)
i = 4 → total = 1      (1 ≥ 4 ? No)
i = 3 → total = 3      (3 ≥ 3 ? Yes ✅)
```

Stop here.

```
H-index = 3
```

---

## 🧠 Visual Intuition

Counting approach builds this mental model:

```
Citation threshold ↓

5 → 1 paper
4 → 1 paper
3 → 3 papers  ← enough to satisfy condition
2 → 3 papers
1 → 3 papers
0 → 5 papers
```

We look for the highest level where:

```
papers available ≥ citation level
```

That level is the H-index.

---
### Time Complexity

```
O(n)
```

### Space Complexity

```
O(n)
```

---

## 🎯 Why This Problem Matters

The H-index is widely used to measure:

- Research productivity
- Scientific impact
- Academic performance

It ensures a researcher has **consistent impact**, not just one highly cited paper.

---

## 🏷️ Tags

```
Array
Sorting
Counting
Greedy
```

---

## 📌 Final Takeaway

The H-index finds the maximum number `H` such that:

```
H papers have at least H citations each.
```

It’s a classic problem that tests sorting, counting, and logical reasoning.