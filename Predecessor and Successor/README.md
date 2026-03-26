# Inorder Predecessor and Successor in BST

## 📌 Problem Statement

Given the root of a Binary Search Tree (BST) and an integer `key`, find the **inorder predecessor** and **inorder successor** of the given key.

- **Predecessor** → Largest value smaller than the key  
- **Successor** → Smallest value greater than the key  

If either does not exist, return `NULL`.

---

## 🌳 Example

**Input:**
## 🌳 Example

**Input:**
```
BST = [50, 30, 70, 20, 40, 60, 80]
Key = 65
```
**Output:**
```
Predecessor: 60
Successor: 70
```

---

## 💡 Approach

We use BST properties to efficiently find predecessor and successor in **O(h)** time.

### Logic

- If `key == node->data`:
  - Predecessor = **maximum in left subtree**
  - Successor = **minimum in right subtree**

- If `key < node->data`:
  - Current node is a potential **successor**
  - Move to **left subtree**

- If `key > node->data`:
  - Current node is a potential **predecessor**
  - Move to **right subtree**

---