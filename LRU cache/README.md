# LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

![](https://media.geeksforgeeks.org/wp-content/uploads/20240909142802/Working-of-LRU-Cache-copy-2.webp)

```
Example:

Input: [LRUCache cache = new LRUCache(2) , put(1 ,1) , put(2 ,2) , get(1) , put(3 ,3) , get(2) , put(4 ,4) , get(1) , get(3) , get(4)]
Output: [1 ,-1, -1, 3, 4]
Explanation: The values mentioned in the output are the values returned by get operations. 

Initialize LRUCache class with  capacity = 2.
cache.put(1, 1):  (key, pair) = (1,1) inserted and has the highest priority.
cache.put(2, 2):  (key , pair) = (2,2) inserted and has the highest priority.
cache.get(1):  For key 1, value is 1, so 1 returned and (1,1) moved to the highest priority.
cache.put(3, 3):  Since cache is full, remove least recently used that is (2,2),  (3,3) inserted with the highest priority.
cache.get(2): returns -1 (key 2 not found)
cache.put(4, 4): Since the cache is full, remove least recently used that is (1,1). (4,5) inserted with the highest priority.
cache.get(1): return -1 (not found)
cache.get(3): return 3 , (3,3) will moved to the highest priority.
cache.get(4): return 4 ,  (4,4) moved to the highest priority.

```