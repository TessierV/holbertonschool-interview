#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 **/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heapify - Heapifies the array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @root: Index of the current root node.
 * @size_init: Original size of the array.
 **/
void heapify(int *array, size_t size, size_t root, size_t size_init) {
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != root) {
        swap(&array[root], &array[largest]);
        print_array(array, size_init);
        heapify(array, size, largest, size_init);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm.
 * @array: Pointer to the array.
 * @size: Size of the array.
 **/
void heap_sort(int *array, size_t size) {
    if (!array || size < 2)
        return;

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i, size);

    for (int i = size - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, i, 0, size);
    }
}
