# Vertical Order Traversal of a Binary Tree

## Problem Statement
Given the root of a Binary Tree, return the **vertical order traversal** of the tree from the **leftmost vertical line to the rightmost vertical line**.

If multiple nodes lie on the same vertical line, they should appear in the **same order as they appear in the level order traversal (BFS)**.

---

## Example
![problem](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/912839/Web/Other/blobid0_1759225165.webp)
![solution](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/912839/Web/Other/blobid1_1759225180.webp)

---

# Approach

To solve this problem efficiently:

1. Use **Breadth First Search (BFS)** to traverse the tree.
2. Track each node’s **horizontal distance (HD)** from the root.
3. Store nodes in a **hash map** where:
   - key = horizontal distance  
   - value = list of nodes
4. Maintain two variables:
   - `minHD`
   - `maxHD`

These track the leftmost and rightmost vertical lines.

5. After traversal, iterate from `minHD` to `maxHD` to build the result.

---

# Algorithm

1. If the tree is empty, return an empty result.
2. Initialize:
   - `unordered_map<int, vector<int>>`
   - `queue<pair<Node*, int>>`
3. Push root into queue with horizontal distance `0`.
4. While queue is not empty:
   - Pop node from queue.
   - Store its value in the map.
   - Push left child with `hd - 1`.
   - Push right child with `hd + 1`.
5. Traverse from `minHD` to `maxHD` and collect results.

---