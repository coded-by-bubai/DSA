# Isomorphic Strings

## 📌 Problem Statement

Given two strings `s1` and `s2`, determine whether they are **isomorphic**.

Two strings are isomorphic if characters in `s1` can be replaced to get `s2`, such that:

- Each character maps to exactly one character.
- No two characters map to the same character.
- The order of characters remains the same.
- The mapping is consistent throughout the string.

---

## 🧠 Intuition

Two strings are isomorphic if they share the same **character pattern structure**.

If a character repeats in `s1`, the corresponding character must repeat in `s2` at the same positions.

### Example 1

**Input**

```
s1 = "aab"
s2 = "xxy"
```

**Output**

```
True
```

**Pattern Comparison**

```
aab → 0 0 1
xxy → 0 0 1
```

The structure matches. ✔

---

### Example 2

**Input**

```
s1 = "aab"
s2 = "xyz"
```

**Output**

```
False
```

**Pattern Comparison**

```
aab → 0 0 1
xyz → 0 1 2
```

The structure differs. ✘

---

# 🚀 Approaches

---

## 1️⃣ Brute Force Approach (O(n²))

### Idea

For every pair of indices `(i, j)`:

- If `s1[i] == s1[j]`, then `s2[i]` must equal `s2[j]`
- If `s1[i] != s1[j]`, then `s2[i]` must not equal `s2[j]`

This checks that both strings share the same equality relationships.

### Complexity

- **Time Complexity:** O(n²)
- **Space Complexity:** O(1)

### Pros

- Simple logic
- No extra memory used

### Cons

- Inefficient for large inputs

---

## 2️⃣ Optimal Approach Using Hash Maps (O(n))

### Idea

Maintain two dictionaries:

- `map1`: maps characters from `s1` → `s2`
- `map2`: maps characters from `s2` → `s1`

This guarantees:

- One-to-one mapping
- No conflicts
- Linear time processing

### Complexity

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

---

# 🧪 Example Usage

```python
s1 = "aab"
s2 = "xxy"

print("Brute Force:", is_isomorphic_bruteforce(s1, s2))
print("Optimal:", is_isomorphic_optimal(s1, s2))
```

---

# 📊 Complexity Comparison

| Approach     | Time Complexity | Space Complexity |
|--------------|----------------|-----------------|
| Brute Force  | O(n²)         | O(1)            |
| Optimal      | O(n)          | O(n)            |

---
