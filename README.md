# LRU Cache Implementation in C++

## Overview

This repository contains a C++ implementation of a **Least Recently Used (LRU) Cache**. The LRU Cache is a data structure that stores a limited number of items and evicts the least recently used item when the cache reaches its capacity. This implementation uses a **Doubly Linked List** and a **Hash Map** to achieve efficient operations with a time complexity of **O(1)** for both insertion and retrieval.

## Features

- **Doubly Linked List**: Used to maintain the order of elements based on their usage.
- **Hash Map**: Maps values to their corresponding nodes in the doubly linked list for quick access.
- **Dynamic Capacity**: The cache can be initialized with any positive capacity.
- **Interactive Interface**: Allows users to interactively insert values into the cache and view the current state of the cache.

## Code Structure

The code is organized into the following classes:

1. **ListNode**: Represents a node in the doubly linked list.
   - Contains `value`, `prev`, and `next` pointers.
   
2. **DoublyLL**: Represents the doubly linked list.
   - Supports operations like `insertAtHead`, `deleteNode`, `removeFirst`, and `printList`.
   - Maintains the length of the list.

3. **Cache**: Represents the LRU Cache.
   - Uses a `DoublyLL` to maintain the order of elements.
   - Uses a `unordered_map` to map values to their corresponding nodes in the list.
   - Supports `insert` and `printCache` operations.

4. **InputHelper**: A utility class to handle user input.
   - Provides methods to get integer and character inputs from the user.

5. **Main Function**: The entry point of the program.
   - Initializes the cache with a user-defined capacity.
   - Allows the user to insert values into the cache and view the current state of the cache.

## How to Use

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/ekanshsaxena/LRU-Cache.git
   cd LRU-Cache
   ```

2. **Compile the Code**:
   ```bash
   g++ -o lru_cache main.cpp
   ```

3. **Run the Program**:
   ```bash
   ./lru_cache
   ```

4. **Follow the Prompts**:
   - Enter the capacity of the cache.
   - Insert values into the cache.
   - View the current state of the cache after each insertion.
   - Choose to continue inserting values or exit the program.

## Example Usage

```
Enter the capacity of Cache: 3
Enter the value to be inserted in Cache: 1
Cache after inserting 1 is: 1 
Do you want to insert more values? (y/n): y
Enter the value to be inserted in Cache: 2
Cache after inserting 2 is: 2 1 
Do you want to insert more values? (y/n): y
Enter the value to be inserted in Cache: 3
Cache after inserting 3 is: 3 2 1 
Do you want to insert more values? (y/n): y
Enter the value to be inserted in Cache: 4
Cache after inserting 4 is: 4 3 2 
Do you want to insert more values? (y/n): n
```

## Dependencies

- **C++ Standard Library**: The code uses standard C++ libraries like `<bits/stdc++.h>` for general utilities, `<unordered_map>` for the hash map, and `<iostream>` for input/output operations.

## Time Complexity

- **Insertion**: O(1)
- **Deletion**: O(1)
- **Access**: O(1)

## Space Complexity

- **O(n)**: Where `n` is the capacity of the cache.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.