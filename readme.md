# Sorting Algorithms Performance Comparison (C Language)

## Overview

This program compares the performance of four different sorting algorithms implemented in **C**:

1. **Insertion Sort**
2. **Merge Sort**
3. **Quick Sort (Version 1)** – using the **first element** as pivot
4. **Quick Sort (Version 2)** – using the **median-of-three** pivot strategy

It measures and displays the time taken by each algorithm to sort a large randomized array of integers.

---

## Features

- Automatically generates a dataset of **100,000 integers**.
- Randomly shuffles the array to ensure unbiased testing.
- Uses separate duplicate arrays to ensure each sorting algorithm operates on identical data.
- Measures and displays **execution time** for each algorithm.
- Implements both **standard** and **optimized** versions of Quick Sort.
- Includes efficient memory management and dynamic allocation for large datasets.

---

## How It Works

1. The program initializes an array of sequential integers (`1` to `100,000`).
2. The array is **randomly shuffled** to simulate an unsorted dataset.
3. Four copies of the shuffled array are created:
   - One for **Insertion Sort**
   - One for **Merge Sort**
   - One for **QuickSortV1 (first element pivot)**
   - One for **QuickSortV2 (median-of-three pivot)**
4. Each algorithm sorts its respective array.
5. The program measures and prints the execution time of each sorting algorithm in seconds.

---

## Sorting Algorithms Implemented

### 🧩 Insertion Sort

- Simple, comparison-based algorithm.
- Efficient for small or nearly sorted datasets.
- **Time Complexity:**
  - Best Case: *O(n)*
  - Average/Worst Case: *O(n²)*

---

### ⚙️ Merge Sort

- Divide-and-conquer algorithm that splits the array into halves recursively.
- Merges sorted halves efficiently.
- **Time Complexity:**
  - Best/Average/Worst Case: *O(n log n)*

---

### ⚡ Quick Sort (Version 1)

- Uses the **first element** as the pivot.
- Performs in-place partitioning.
- **Time Complexity:**
  - Best/Average Case: *O(n log n)*
  - Worst Case (already sorted): *O(n²)*

---

### 🔹 Quick Sort (Version 2)

- Uses the **median-of-three** method to select a pivot (first, middle, last elements).
- Reduces the likelihood of poor pivot choices and improves performance on partially sorted data.
- **Time Complexity:**
  - Best/Average Case: *O(n log n)*
  - Worst Case: *O(n²)* (rare with median-of-three)

---



## Key Functions

| Function            | Description                               |
| ------------------- | ----------------------------------------- |
| `shuffleArray()`  | Randomly shuffles the array.              |
| `InsertionSort()` | Performs insertion sort.                  |
| `MergeSort()`     | Recursively divides and merges subarrays. |
| `Merge()`         | Merges two sorted halves.                 |
| `QuickSortV1()`   | Quick sort using first element as pivot.  |
| `QuickSortV2()`   | Quick sort using median-of-three pivot.   |
| `swap()`          | Utility function to swap two integers.    |

---

## Notes

- Array size is defined with `#define array_size 100000` and can be adjusted.
- The program uses `clock()` from `<time.h>` to calculate execution time.
- Ensure sufficient memory is available for large datasets.
- For meaningful results, compile with optimization flags such as:
  ```bash
  gcc main.c -o sort_test -O2
  ```
