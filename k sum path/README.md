# Path Sum in a Binary Tree

## Problem

Given the root of a binary tree and an integer `k`, determine the **number of downward-only paths** where the sum of the node values equals `k`.

### Rules

- A path can **start at any node**.
- A path can **end at any node**.
- The path must always move **downward (parent → child)**.
- Count **all valid paths** whose sum equals `k`.

---

## Example
![problem](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700575/Web/Other/blobid0_1738924888.webp)
![result](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700575/Web/Other/blobid0_1722330388.jpg)

# Algorithm

1. Use **DFS traversal**.
2. Maintain:
   - `currentSum`
   - `prefix map` storing prefix sum frequencies.
3. At each node:
   - Add node value to `currentSum`
   - Check if `(currentSum - k)` exists in prefix map
   - Increase path count
4. Store `currentSum` in the prefix map.
5. Traverse left and right children.
6. **Backtrack** by removing the current sum from the map.