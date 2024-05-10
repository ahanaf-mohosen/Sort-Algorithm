#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort implementation
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort implementation
void selectionSort(int arr[], int n) {
    int minIndex;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

// Insertion Sort implementation
void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort implementation
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Quick Sort implementation
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to generate random arrays of given size
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Generate random numbers between 0 and 9999
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Array sizes to test
    int sizes[] = {100, 1000, 10000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    // Test each sorting algorithm with different array sizes
    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int arr[size];

        // Generate random input array
        generateRandomArray(arr, size);

        printf("Array of size %d:\n", size);

        // Bubble Sort
        int bubble_arr[size];
        for (int j = 0; j < size; j++) {
            bubble_arr[j] = arr[j];
        }
        clock_t start = clock();
        bubbleSort(bubble_arr, size);
        clock_t end = clock();
        double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Bubble Sort: %.6f seconds\n", cpu_time_used);

        // Selection Sort
        int selection_arr[size];
        for (int j = 0; j < size; j++) {
            selection_arr[j] = arr[j];
        }
        start = clock();
        selectionSort(selection_arr, size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Selection Sort: %.6f seconds\n", cpu_time_used);

        // Insertion Sort
        int insertion_arr[size];
        for (int j = 0; j < size; j++) {
            insertion_arr[j] = arr[j];
        }
        start = clock();
        insertionSort(insertion_arr, size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Insertion Sort: %.6f seconds\n", cpu_time_used);

        // Merge Sort
        int merge_arr[size];
        for (int j = 0; j < size; j++) {
            merge_arr[j] = arr[j];
        }
        start = clock();
        mergeSort(merge_arr, 0, size - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Merge Sort: %.6f seconds\n", cpu_time_used);

        // Quick Sort
        int quick_arr[size];
        for (int j = 0; j < size; j++) {
            quick_arr[j] = arr[j];
        }
        start = clock();
        quickSort(quick_arr, 0, size - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Quick Sort: %.6f seconds\n", cpu_time_used);

        printf("\n");
    }

    return 0;
}
