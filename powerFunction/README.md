# ⚡ Power Function (a^k)

Implement a function to compute:

```
aᵏ
```

Where:
- `a` → base (double)
- `k` → exponent (integer, can be negative)

We will look at:

1. ✅ Brute Force Approach  
2. 🚀 Binary Exponentiation (Optimized)

---

# 🥉 Approach 1: Brute Force (Naive Method)

## 💡 Idea

Multiply the base `a` by itself `k` times.

Mathematically: `a × a × a × a × .... k times`


---

## 🔎 Example

Compute:

```
2^5
```

Step-by-step:

```
result = 1
result = 1 × 2 = 2
result = 2 × 2 = 4
result = 4 × 2 = 8
result = 8 × 2 = 16
result = 16 × 2 = 32
```

Total multiplications = 5

---

## ⏱ Complexity

Time Complexity:

```
O(n)
```

Space Complexity:

```
O(1)
```

### ❌ Problem

If `k = 1,000,000`, we perform 1,000,000 multiplications.

This is slow for large inputs.

---

# 🚀 Approach 2: Binary Exponentiation (Fast Exponentiation)

## 💡 Core Idea

Instead of multiplying `a` `k` times:

- Convert exponent into binary
- Square the base each step in binary formation
- Multiply the current base with answer only when the binary bit is `1`

Mathematical foundation:

`n = b0·2⁰ + b1·2¹ + b2·2² + ... + bk·2ᵏ = b0b1b2...`

`ans = b0·a + b1·a² + b2·a⁴ + ... + bk·(a^(k-1))^2`

---

## 🔎 Visual Walkthrough

### Example: `2^5`

Binary of 5:

```
5 → 101
```

Process from right to left:

| Binary Bit | Current Base | Action | Result |
|------------|-------------|--------|--------|
| 1 | 2¹ = 2 | Multiply | 2 |
| 0 | 2² = 4 | Skip | 2 |
| 1 | 2⁴ = 16 | Multiply | 2 × 16 = 32 |

Final Answer:

```
32
```

---

## 🔁 Why It’s Faster

Instead of 5 multiplications:

```
2 × 2 × 2 × 2 × 2
```

We only perform:

```
log₂(5) + 1 ≈ 3 iterations
```
---

# 📊 Comparison

| Approach | Time Complexity | Space Complexity |
|----------|-----------------|-----------------|
| Brute Force | O(n) | O(1) |
| Binary Exponentiation | O(log n) | O(1) |

---

# 🎯 Key Takeaways

- Brute force multiplies `a` exactly `k` times.
- Binary exponentiation reduces operations using binary representation.
- Works for negative exponents.
- Efficient for very large powers.

---

# 🏷️ Tags

```
Math
Bit Manipulation
Binary Representation
Divide and Conquer
Optimization
```

---

## ✅ Final Insight

Every number can be expressed as a sum of powers of 2.

Binary exponentiation leverages this idea to compute powers efficiently.