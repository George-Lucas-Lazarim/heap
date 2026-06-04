#include "heap.h"

struct maxHeap* initHeap (int capacity) {
    if (capacity <= 0) {
        printf("\nError! Invalid capacity");
        return NULL;
    }

    struct maxHeap* heap = (struct maxHeap*) malloc (sizeof(struct maxHeap));

    if (heap == NULL) {
        printf("\nError! Memory allocation failed for heap");
        return NULL;
    }

    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (int*) malloc (capacity * sizeof(int));

    return heap;
}

int parent (int i) { return ((i - 1) / 2); }

int leftChild (int i) { return ((i * 2) + 1); }

int rightChild (int i) { return ((i * 2) + 2); }

void swap (int *x, int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;
}