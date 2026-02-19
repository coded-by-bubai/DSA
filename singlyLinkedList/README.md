# Singly Linked List in C

![Language](https://img.shields.io/badge/Language-C-blue)
![Type](https://img.shields.io/badge/Data%20Structure-Linked%20List-green)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey)
![Status](https://img.shields.io/badge/Status-Complete-success)

A structured, menu-driven implementation of a **Singly Linked List** in C.  
This project demonstrates dynamic memory allocation, pointer manipulation, and fundamental data structure operations using a console-based interface.

---

## 📖 About The Project

This application allows users to create and manipulate a singly linked list interactively.

It focuses on:

- Manual memory management
- Efficient pointer operations
- Clean modular function design
- Core linked list algorithms
- Time complexity awareness

The goal of this project is to build strong fundamentals in low-level programming and data structures.

---

## 🚀 Features

- Create a linked list
- Display linked list
- Insert at beginning
- Insert at end
- Insert at specific position
- Delete at beginning
- Delete at end
- Delete at specific position
- Reverse linked list (in-place)
- Calculate linked list length
- Menu-driven interactive interface

---

## 🧠 Data Structure Design

```c
struct node
{
    int data;
    struct node *next;
};
```

Each node contains:
- `data` → integer value
- `next` → pointer to next node

A global pointer `head` stores the start of the list.

---

## ⚙️ Core Algorithms

### Insert at Beginning
- Time Complexity: **O(1)**
- Direct pointer reassignment

### Insert at End
- Time Complexity: **O(n)**
- Traverses to the last node

### Insert at Position
- Time Complexity: **O(n)**
- Traverses to position - 1 and adjusts links

### Delete Operations
- Beginning → **O(1)**
- End → **O(n)**
- Specific Position → **O(n)**

### Reverse Linked List
- Time Complexity: **O(n)**
- Space Complexity: **O(1)**
- Uses iterative three-pointer technique (`prev`, `curr`, `next`)
- Performs in-place reversal without extra memory

---

## 🖥️ Sample Menu Output

```
1.Create Singly Linked List
2.Display Linked List
3.Insert at Beginning
4.Insert at End
5.Insert at Specific Position
6.Delete at Beginning
7.Delete at End
8.Delete at Specific Position
9.Reverse Linked List
10.Show Length
11.Exit
```

---

## 🛠️ Build & Run

### Windows (MinGW GCC)

```bash
gcc linkedlist.c -o linkedlist
linkedlist.exe
```

---

### Linux / macOS

Modify platform-specific parts:

Remove:
```c
#include <Windows.h>
```

Replace:
```c
Sleep(5000);
```
with:
```c
sleep(5);
```

Replace:
```c
system("cls");
```
with:
```c
system("clear");
```

Compile:

```bash
gcc SinglyLinkedList.c -o SinglyLinkedList
./SinglyLinkedList
```

---

## 📂 Project Structure

```
.
├── SinglyLinkedList.c
└── README.md
```

---

## 🔍 Technical Highlights

- Dynamic memory allocation using `malloc()` and `free()`
- Structured switch-case control flow
- Defensive empty-list checks
- In-place linked list reversal
- Modular function separation
- Iterative traversal logic

---

## ⚠️ Current Limitations

- Minimal input validation
- No full memory cleanup before exit
- Windows-specific functions included
- Console-based interface only

---

## 📈 Future Improvements

- Add search functionality
- Add sorting algorithm
- Implement doubly linked list
- Add circular linked list version
- Add recursion-based reverse
- Improve error handling
- Convert into reusable `.h` + `.c` library
- Add unit tests

---

## 🎯 Learning Outcomes

This project strengthens understanding of:

- Pointers and memory management
- Heap allocation and deallocation
- Linked data structures
- Algorithm complexity analysis
- Modular program design in C

---

## 👨‍💻 Author

Bubai Das  
Programmer | Data Structures & algorithms Enthusiast

---

## 📜 License

This project is open-source and available under the MIT License.
