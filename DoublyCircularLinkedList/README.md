# Doubly Circular Linked List (DCLL) in C

A complete implementation of a **Doubly Circular Linked List (DCLL)** in C using dynamic memory allocation and a menu-driven interface.

This project is part of Data Structures and Algorithms (DSA) practice and focuses on pointer manipulation, circular linking, and efficient insertion/deletion logic.

---

# 📌 Table of Contents

- Introduction  
- What is a Doubly Circular Linked List  
- Structure Definition  
- Internal Working Concept  
- Operations Implemented  
- Algorithm Explanation  
- Time Complexity Analysis  
- Edge Cases Handled  
- Memory Management  
- Compilation & Execution  
- Learning Outcomes  
- Future Improvements  

---

# 📖 Introduction

A linked list is a dynamic linear data structure where elements (nodes) are connected using pointers.

Unlike arrays:
- Memory is not contiguous
- Size is dynamic
- Insertions and deletions are efficient

This implementation focuses on a **Doubly Circular Linked List**, which combines:

- Doubly Linked List properties
- Circular Linked List properties

---

# 🧠 What is a Doubly Circular Linked List?

A Doubly Circular Linked List is a linked list where:

- Each node contains:
  - `data`
  - `next` pointer
  - `prev` pointer
- The last node's `next` points to the first node
- The first node's `prev` points to the last node
- There is no `NULL` at either end

This forms a closed loop.

---

## 🔁 Conceptual Representation

```
 ┌───────────────────────┐
 ↓                       ↓
[10] ⇄ [20] ⇄ [30] ⇄ [40]
 ↑                       ↑
 └───────────────────────┘
```

If `tail` points to `[40]`:

- `tail->next` → `[10]` (Head)
- `[10]->prev` → `[40]`

---

# 🏗 Structure Definition

```c
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *tail = 0;
```

## Design Decision

Instead of maintaining both `head` and `tail`, this implementation keeps only:

```
tail
```

The head is always accessed as:

```c
tail->next
```

This simplifies circular linking.

---

# ⚙️ Internal Working Concept

## 1️⃣ Empty List

```
tail = NULL
```

No nodes exist.

---

## 2️⃣ Single Node

```
   tail
     ↓
   [10]
   ↑  ↓
   └──┘
```

- `next` points to itself
- `prev` points to itself

---

## 3️⃣ Multiple Nodes

```
            tail → [30]
                 ↓
[10] ⇄ [20] ⇄ [30]
 ↑               ↓
 └───────────────┘
```

---

# 📌 Operations Implemented

---

# 1️⃣ Create List

Creates nodes dynamically using `malloc()`.

### Logic

1. Allocate memory
2. If first node:
   - `next = prev = itself`
   - `tail = newnode`
3. Otherwise:
   - Insert after tail
   - Fix circular links
   - Move tail

### Time Complexity

```
O(n)
```

---

# 2️⃣ Display List

Traversal starts from:

```c
head = tail->next;
```

Since the list is circular:

```c
do {
    print node
    move to next
} while(current != head);
```

### Time Complexity

```
O(n)
```

---

# 3️⃣ Insert Operations

---

## 🔹 Insert at Beginning

### Steps

1. Create new node
2. `newnode->next = head`
3. `newnode->prev = tail`
4. Update:
   - `head->prev`
   - `tail->next`

### Time Complexity

```
O(1)
```

---

## 🔹 Insert at End

### Steps

1. Create new node
2. Attach after tail
3. Update circular links
4. Move tail

### Time Complexity

```
O(1)
```

---

## 🔹 Insert at Position

### Steps

1. Traverse to position - 1
2. Adjust links
3. Update tail if needed

### Time Complexity

```
O(n)
```

---

# 4️⃣ Delete Operations

---

## 🔹 Delete from Beginning

### Steps

1. Store head
2. Move `tail->next` to second node
3. Update `prev`
4. Free old head

### Time Complexity

```
O(1)
```

---

## 🔹 Delete from End

### Steps

1. Store tail
2. Move tail to `tail->prev`
3. Update links
4. Free old tail

### Time Complexity

```
O(1)
```

---

## 🔹 Delete from Position

### Steps

1. Traverse to node
2. Update adjacent links
3. Update tail if needed
4. Free node

### Time Complexity

```
O(n)
```

---

# 5️⃣ Reverse Doubly Circular Linked List

### Core Idea

For every node:

- Swap `next` and `prev`
- Move using original next

Since it is circular, use `do-while`.

### Pseudocode

```
current = head
do:
    temp = current->next
    current->next = current->prev
    current->prev = temp
    current = temp
while(current != head)
```

### Time Complexity

```
O(n)
```

### Space Complexity

```
O(1)
```

---

# 6️⃣ Length of List

Traverse the entire circle and count nodes.

### Time Complexity

```
O(n)
```

---

# ⏱ Time Complexity Summary

| Operation | Complexity |
|------------|------------|
| Insert at Beginning | O(1) |
| Insert at End | O(1) |
| Insert at Position | O(n) |
| Delete from Beginning | O(1) |
| Delete from End | O(1) |
| Delete from Position | O(n) |
| Display | O(n) |
| Reverse | O(n) |
| Length | O(n) |

---

# 🧪 Edge Cases Handled

- Empty list operations
- Single node deletion
- Invalid position input
- Reverse empty list
- Insert into empty list
- Delete last remaining node

---

# 💾 Memory Management

- Memory allocated using `malloc()`
- Memory released using `free()`
- Prevents memory leaks on deletion
- Handles single-node memory cleanup

---

# 🖥 Menu Interface

```
1. Create doubly circular Linked List
2. Insert at beginning
3. Insert at end
4. Insert at position
5. Delete from beginning
6. Delete from end
7. Delete from position
8. Reverse doubly linked list
9. Display list
10. Length of list
0. Exit
```

---

# ▶️ Compilation & Execution

## Compile

```
gcc doublyCircular.c -o doublyCircular
```

## Run (Linux / Mac)

```
./doublyCircular
```

## Run (Windows)

```
doublyCircular.exe
```

---


# 📚 Concepts Covered

- Self-referential structures
- Dynamic memory allocation
- Pointer manipulation
- Circular data structures
- Doubly linked traversal
- Time complexity analysis
- Edge case handling
- Menu-driven programs

---

# 🎯 Learning Outcomes

After completing this project, you will understand:

- How circular linking removes NULL boundaries
- Why maintaining only tail simplifies logic
- How O(1) insertion works at boundaries
- How pointer swapping reverses the list
- Safe memory handling in C

---

# 🚀 Future Improvements

- Add backward traversal display
- Add search functionality
- Add sorting
- Make the Program Cross-Platform
- Modularize into header and source files
- Add unit testing
- Convert to generic linked list
- Add Full Memory Cleanup Function
- Add Visualization / Debug Mode
- Add File Handling Support (Save & Load)
- Add Memory Cleanup Before Exit
---


Developed as part of Data Structures and Algorithms practice.