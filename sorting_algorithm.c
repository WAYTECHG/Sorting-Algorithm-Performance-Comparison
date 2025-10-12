#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Define the size of the array to be sorted
#define array_size 100000

// Function prototypes
void shuffleArray(int array[], int n);              // Randomly shuffles the array
void InsertionSort(int A[], int n);                 // Performs Insertion Sort
void MergeSort(int A[], int Temp[], int Lb, int Ub); // Performs Merge Sort
void Merge(int A[], int Temp[], int Lb, int m, int Ub); // Merges sorted halves for Merge Sort
void swap(int* a, int* b);                          // Swaps two elements
void QuickSortV1(int arr[], int low, int high);     // Quick Sort with first element as pivot
void QuickSortV2(int arr[], int low, int high);     // Quick Sort with median-of-three pivot

int main() {
    int i;
    int array[array_size]; // Original array to be shuffled and sorted

    // Dynamically allocate memory for duplicates of the array for each sort
    int *arr_dup1 = (int *)malloc(array_size * sizeof(int));
    int *arr_dup2 = (int *)malloc(array_size * sizeof(int));
    int *arr_dup3 = (int *)malloc(array_size * sizeof(int));
    int *arr_dup4 = (int *)malloc(array_size * sizeof(int));
    int *temp = (int *)malloc(array_size * sizeof(int)); // Temporary array for Merge Sort

    // Check for successful memory allocation
    if (!arr_dup1 || !arr_dup2 || !arr_dup3 || !arr_dup4 || !temp) {
        printf("Memory allocation failed!\n");
        return 1; // Exit the program if allocation fails
    }

    // Initialize the array with sequential values (1 to array_size)
    for(i = 0; i < array_size; i++) {
        array[i] = i + 1;
    }

    // Shuffle the array to create a randomized dataset
    shuffleArray(array, array_size);

    // Copy the shuffled array into each duplicate for fair testing
    for(int j = 0; j < array_size; j++) {
        arr_dup1[j] = array[j];
        arr_dup2[j] = array[j];
        arr_dup3[j] = array[j];
        arr_dup4[j] = array[j];
    }

    double time_spent = 0.0; // Variable to hold time taken for each sort
    clock_t begin, end;      // Variables to measure time

    // Measure and print time taken for Insertion Sort
    begin = clock();
    InsertionSort(arr_dup1, array_size);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("InsertionSort took %f seconds\n", time_spent);

    // Measure and print time taken for Merge Sort
    begin = clock();
    MergeSort(arr_dup2, temp, 0, array_size - 1);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("MergeSort took %f seconds\n", time_spent);

    // Measure and print time taken for Quick Sort V1
    begin = clock();
    QuickSortV1(arr_dup3, 0, array_size - 1);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("QuickSortV1 took %f seconds\n", time_spent);

    // Measure and print time taken for Quick Sort V2
    begin = clock();
    QuickSortV2(arr_dup4, 0, array_size - 1);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("QuickSortV2 took %f seconds\n", time_spent);

    // Free dynamically allocated memory to prevent memory leaks
    free(arr_dup1);
    free(arr_dup2);
    free(arr_dup3);
    free(arr_dup4);
    free(temp);

    return 0;
}

// Function to randomly shuffle the array elements
void shuffleArray(int array[], int n) {
    srand(time(NULL)); // Seed the random number generator with the current time
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Generate a random index
        // Swap array[i] with the element at random index
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to perform Insertion Sort
void InsertionSort(int A[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = A[i]; // Store the current element
        for (j = i - 1; j >= 0 && A[j] > temp; j--) {
            A[j + 1] = A[j]; // Shift larger elements up to make room
        }
        A[j + 1] = temp; // Insert the current element into its sorted position
    }
}

// Function to perform Merge Sort recursively
void MergeSort(int A[], int Temp[], int Lb, int Ub) {
    if (Lb < Ub) {
        int m = (Lb + Ub) / 2;
        MergeSort(A, Temp, Lb, m);        // Sort the left half
        MergeSort(A, Temp, m + 1, Ub);    // Sort the right half
        Merge(A, Temp, Lb, m, Ub);        // Merge the sorted halves
    }
}

// Helper function to merge two halves in Merge Sort
void Merge(int A[], int Temp[], int Lb, int m, int Ub) {
    int i = Lb, j = m + 1, k = Lb;

    // Merge elements from both halves into Temp in sorted order
    while (i <= m && j <= Ub) {
        if (A[i] <= A[j])
            Temp[k++] = A[i++];
        else
            Temp[k++] = A[j++];
    }

    // Copy remaining elements from left half
    while (i <= m)
        Temp[k++] = A[i++];

    // Copy remaining elements from right half
    while (j <= Ub)
        Temp[k++] = A[j++];

    // Copy the merged elements back into the original array
    for (i = Lb; i <= Ub; i++)
        A[i] = Temp[i];
}

// Utility function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for QuickSortV1 with the first element as pivot
int partition(int arr[], int low, int high) {
    int p = arr[low]; // Pivot is the first element
    int i = low;
    int j = high;

    // Partitioning process
    while (i < j) {
        while (arr[i] <= p && i <= high - 1) i++; // Find element greater than pivot
        while (arr[j] > p && j >= low + 1) j--;   // Find element less than pivot
        if (i < j) swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

// QuickSortV1 function with the first element as pivot
void QuickSortV1(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        QuickSortV1(arr, low, pi - 1);   // Recursively sort elements before pivot
        QuickSortV1(arr, pi + 1, high);  // Recursively sort elements after pivot
    }
}

// Function to find the median of three elements (used in QuickSortV2)
int medianOfThree(int arr[], int low, int mid, int high) {
    if ((arr[low] > arr[mid]) != (arr[low] > arr[high])) return low;
    else if ((arr[mid] > arr[low]) != (arr[mid] > arr[high])) return mid;
    else return high;
}

// Partition function using median-of-three as pivot (for QuickSortV2)
int partitions(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    int medianIndex = medianOfThree(arr, low, mid, high);
    swap(&arr[medianIndex], &arr[high]); // Move median to end as pivot

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// QuickSortV2 function with median-of-three as pivot
void QuickSortV2(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitions(arr, low, high);
        QuickSortV2(arr, low, pi - 1);
        QuickSortV2(arr, pi + 1, high);
    }
}
