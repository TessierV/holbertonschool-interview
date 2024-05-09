# Heap Sort

## Description
Heap Sort is a sorting algorithm that works by transforming an array into a data structure called a heap, then repeatedly extracting the root element of the heap (which is the maximum in the case of a max heap or the minimum in the case of a min heap) and rebuilding the heap. Here's an outline of the algorithm

## Usage
- To compile: `gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o heap_sort`
- To execute: `./heap_sort`

## Example

```
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    heap_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}```